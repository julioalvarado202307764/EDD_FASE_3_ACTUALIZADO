#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDate>
#include <QPixmap>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QString>
#include <QDateTime> // Añadir en los includes de mainwindow.cpp
#include <QTableWidgetItem>
#include <QColor>
#include <QTableWidgetItem>
#include <QBrush>
#include <algorithm> // Necesario para std::remove
#include <QImage>
#include <QRegularExpression>
#include <QStringList>
#include <QJsonParseError>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    contadorGlobalFunciones = 1;
    // Estructuras Fase 1
    arbolCartelera = new ArbolPeliculas();
    listaSolicitudes = new ListaSolicitudes();
    matrizSala = new MatrizDispersa();
    listaPromos = new ListaPromociones();

    // Nuevas Estructuras Fase 2
    arbolFunciones = new ArbolAVL();
    arbolClientes = new ArbolB();
    tablaReservas = new TablaHash();
    // Fase 3
    grafoSedes = new GrafoSedes();

    ui->dateFechaFuncion->setDate(
        QDate::currentDate()
        );

    ui->dateEditFechaFuncion->setDate(
        QDate::currentDate()
        );

    refrescarControlesE4();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete arbolCartelera;
    delete listaSolicitudes;
    delete matrizSala;
    delete listaPromos;

    // Limpieza Fase 2[cite: 1]
    delete arbolFunciones;
    delete arbolClientes;
    delete tablaReservas;

    // Fase 3
    delete grafoSedes;
}

void MainWindow::sincronizarGrafoConFunciones()
{
    if (grafoSedes == nullptr || arbolFunciones == nullptr) {
        return;
    }

    grafoSedes->recalcularRelaciones(*arbolFunciones);
}

void MainWindow::poblarComboSedes(
    QComboBox* combo)
{
    if (combo == nullptr ||
        grafoSedes == nullptr) {
        return;
    }

    combo->clear();

    const NodoGrafo* actual =
        grafoSedes->obtenerPrimeraSede();

    while (actual != nullptr) {

        QString codigo =
            QString::fromStdString(
                actual->sede.codigo
                );

        QString nombre =
            QString::fromStdString(
                actual->sede.nombre
                );

        combo->addItem(
            codigo + " - " + nombre,
            codigo
            );

        actual =
            actual->siguiente;
    }
}


void MainWindow::poblarSedesPorPelicula(
    QComboBox* combo,
    const QString& codigoPelicula)
{
    if (combo == nullptr) {
        return;
    }

    combo->clear();

    if (grafoSedes == nullptr ||
        arbolFunciones == nullptr ||
        codigoPelicula.isEmpty()) {
        return;
    }

    struct ContextoSedePelicula {
        std::string codigoPelicula;
        std::string codigoSede;
        bool encontrada;
    };

    auto visitarFuncion =
        [](const NodoAVL* funcion,
           void* datos) {

            if (funcion == nullptr ||
                datos == nullptr) {
                return;
            }

            ContextoSedePelicula* contexto =
                static_cast<
                    ContextoSedePelicula*
                    >(datos);

            if (
                funcion->codigo_pelicula_real ==
                    contexto->codigoPelicula &&
                funcion->codigo_sede ==
                    contexto->codigoSede
                ) {
                contexto->encontrada = true;
            }
        };

    const NodoGrafo* sede =
        grafoSedes->obtenerPrimeraSede();

    while (sede != nullptr) {

        ContextoSedePelicula contexto {
            codigoPelicula.toStdString(),
            sede->sede.codigo,
            false
        };

        arbolFunciones->recorrerFunciones(
            visitarFuncion,
            &contexto
            );

        if (contexto.encontrada) {

            QString codigo =
                QString::fromStdString(
                    sede->sede.codigo
                    );

            QString nombre =
                QString::fromStdString(
                    sede->sede.nombre
                    );

            combo->addItem(
                codigo + " - " + nombre,
                codigo
                );
        }

        sede =
            sede->siguiente;
    }
}


void MainWindow::poblarFuncionesPorPeliculaYSede(
    QComboBox* combo,
    const QString& codigoPelicula,
    const QString& codigoSede)
{
    if (combo == nullptr) {
        return;
    }

    combo->clear();

    if (arbolFunciones == nullptr ||
        codigoPelicula.isEmpty() ||
        codigoSede.isEmpty()) {
        return;
    }

    struct ContextoFuncionesCombo {
        std::string codigoPelicula;
        std::string codigoSede;
        QComboBox* combo;
    };

    ContextoFuncionesCombo contexto {
        codigoPelicula.toStdString(),
        codigoSede.toStdString(),
        combo
    };

    auto visitarFuncion =
        [](const NodoAVL* funcion,
           void* datos) {

            if (funcion == nullptr ||
                datos == nullptr) {
                return;
            }

            ContextoFuncionesCombo* contexto =
                static_cast<
                    ContextoFuncionesCombo*
                    >(datos);

            if (
                funcion->codigo_pelicula_real !=
                    contexto->codigoPelicula ||
                funcion->codigo_sede !=
                    contexto->codigoSede
                ) {
                return;
            }

            QString fecha =
                QString::fromStdString(
                    funcion->fecha
                    );

            if (fecha.isEmpty()) {
                fecha = "Sin fecha";
            }

            QString texto =
                QString::fromStdString(
                    funcion->codigo_funcion
                    ) +
                " - " +
                fecha +
                " - " +
                QString::fromStdString(
                    funcion->horario
                    ) +
                " - " +
                QString::fromStdString(
                    funcion->sala
                    );

            contexto->combo->addItem(
                texto,
                QString::fromStdString(
                    funcion->codigo_funcion
                    )
                );
        };

    arbolFunciones->recorrerFunciones(
        visitarFuncion,
        &contexto
        );
}


void MainWindow::refrescarControlesE4()
{
    if (arbolCartelera == nullptr ||
        grafoSedes == nullptr) {
        return;
    }

    // =====================================================
    // PELÍCULAS — identidad lógica mediante código real
    // =====================================================

    arbolCartelera->poblarComboCodigoTitulo(
        ui->comboPeliculas
        );

    arbolCartelera->poblarComboCodigoTitulo(
        ui->cmbEditPelicula
        );

    arbolCartelera->poblarComboCodigoTitulo(
        ui->cbPeliculasDisponibles
        );

    arbolCartelera->poblarComboCodigoTitulo(
        ui->cmbPeliculaSedesCliente
        );

    arbolCartelera->poblarComboCodigoTitulo(
        ui->cmbPeliculaFuncionesCliente
        );


    // =====================================================
    // COMBOS GENERALES DE SEDES
    // =====================================================

    poblarComboSedes(
        ui->cmbSedeFuncion
        );

    poblarComboSedes(
        ui->cmbEditSedeFuncion
        );

    poblarComboSedes(
        ui->cmbSedePeliculasAdmin
        );

    poblarComboSedes(
        ui->cmbSedeOrigenBFS
        );

    poblarComboSedes(
        ui->cmbSedeDestinoBFS
        );

    poblarComboSedes(
        ui->cmbSedeSimilarCliente
        );


    // =====================================================
    // CLIENTE — SEDES FILTRADAS POR PELÍCULA
    // =====================================================

    QString peliculaReserva =
        ui->cbPeliculasDisponibles
            ->currentData()
            .toString();

    poblarSedesPorPelicula(
        ui->cmbSedeReserva,
        peliculaReserva
        );

    poblarFuncionesPorPeliculaYSede(
        ui->cbFuncionesDisponibles,
        peliculaReserva,
        ui->cmbSedeReserva
            ->currentData()
            .toString()
        );


    QString peliculaConsulta =
        ui->cmbPeliculaFuncionesCliente
            ->currentData()
            .toString();

    poblarSedesPorPelicula(
        ui->cmbSedeFuncionesCliente,
        peliculaConsulta
        );


    // La edición no debe seleccionar arbitrariamente
    // una película/sede si aún no se cargó una función.
    ui->cmbEditPelicula->setCurrentIndex(-1);
    ui->cmbEditSedeFuncion->setCurrentIndex(-1);
}

void MainWindow::on_btnIniciarSesion_clicked()
{
    QString correo = ui->txtCorreo->text().trimmed();
    QString password = ui->txtPassword->text().trimmed();

    if (correo.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Campos Vacíos", "Ingrese su correo y contraseña.");
        return;
    }

    // 1. Validación de credenciales oficiales del Administrador[cite: 1]
    if (correo == "AdminCine@gmail.com" && password == "admin123Pass") {
        ui->stackedWidget->setCurrentIndex(1); // Cambiar a pageAdmin
        refrescarControlesE4();
        QMessageBox::information(this, "Bienvenido", "Sesión iniciada como Administrador.");
        return;
    }

    // 2. Buscar al cliente en el Árbol B[cite: 1]
    Cliente* clienteActual = arbolClientes->buscarPorCorreo(correo.toStdString());

    if (clienteActual != nullptr) {
        // Validar contraseña
        if (clienteActual->password == password.toStdString()) {
            ui->stackedWidget->setCurrentIndex(2); // Cambiar a pageUsuario

            idUsuarioLogueado = QString::fromStdString(clienteActual->id);
            // Cargar datos en la vista del cliente
            cargarDatosPerfil();
            arbolCartelera->poblarTablaInOrden(ui->tablaTaquilla);            listaPromos->poblarArbolUI(ui->arbolPromos);
            refrescarControlesE4();
            QMessageBox::information(this, "Bienvenido", "Hola, " + QString::fromStdString(clienteActual->nombre) + ". Sesión iniciada correctamente.");

            ui->txtCorreo->clear();
            ui->txtPassword->clear();
        } else {
            QMessageBox::warning(this, "Error de Autenticación", "La contraseña es incorrecta.");
        }
    } else {
        QMessageBox::warning(this, "Error", "El correo ingresado no está registrado.");
    }
}
//FUNCIONES ADMINISTRADOR

void MainWindow::on_btnCerrarSesionAdmin_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

    // Limpiar los campos
    ui->txtCorreo->clear();
    ui->txtPassword->clear();
}

//PESTAÑA GESTION SOLICITUDES
void MainWindow::on_btnProcesarPrimera_clicked()
{
    NodoSolicitud* pendiente = listaSolicitudes->getPrimeraPendiente();
    if (pendiente != nullptr) {
        idSolicitudEnProceso = pendiente->solicitud.id;

        // Mostrar los detalles en la etiqueta[cite: 1]
        QString detalles = "ID: " + QString::number(pendiente->solicitud.id) +
                           "\nCliente: " + pendiente->solicitud.cliente +
                           "\nTipo: " + pendiente->solicitud.tipo +
                           "\nDescripción: " + pendiente->solicitud.descripcion;

        ui->lblDetalleSolicitud->setText(detalles);
    } else {
        ui->lblDetalleSolicitud->setText("No hay solicitudes pendientes.");
        idSolicitudEnProceso = -1;
    }

    // Actualizamos la tabla
    listaSolicitudes->poblarTablaAdmin(ui->tablaAdminSolicitudes);
}


void MainWindow::on_btnAprobarSolicitud_clicked()
{
    if (idSolicitudEnProceso != -1) {
        listaSolicitudes->marcarComoAtendida(idSolicitudEnProceso);
        QMessageBox::information(this, "Éxito", "Solicitud marcada como Atendida.");
        ui->lblDetalleSolicitud->setText("Selecciona procesar...");
        idSolicitudEnProceso = -1;
        listaSolicitudes->poblarTablaAdmin(ui->tablaAdminSolicitudes);
    }
}


void MainWindow::on_btnRechazarSolicitud_clicked()
{
    if (idSolicitudEnProceso != -1) {
        listaSolicitudes->eliminarSolicitud(idSolicitudEnProceso);
        QMessageBox::warning(this, "Eliminada", "Solicitud rechazada y eliminada de la lista.");
        ui->lblDetalleSolicitud->setText("Selecciona procesar...");
        idSolicitudEnProceso = -1;
        listaSolicitudes->poblarTablaAdmin(ui->tablaAdminSolicitudes);
    }
}


//FUNCIONES DE USUARIOS

void MainWindow::on_btnCerrarSesionUsuario_clicked()
{
    ui->stackedWidget->setCurrentIndex(0); // Volver al Login

    // Borrar de la memoria quién estaba logueado
    idUsuarioLogueado = "";

    // Limpiar los campos del login
    ui->txtCorreo->clear();
    ui->txtPassword->clear();
}
void MainWindow::on_btnEnviarSolicitud_clicked()
{
    // Capturamos los datos de la interfaz
    QString cliente = ui->txtNombreSolicitud->text();
    QString telefono = ui->txtTelefono->text();
    QString tipo = ui->comboTipoSolicitud->currentText();
    QString descripcion = ui->txtDescripcion->toPlainText(); // toPlainText() se usa para QTextEdit

    // Obtenemos la fecha actual del sistema automáticamente
    QString fechaActual = QDate::currentDate().toString("yyyy-MM-dd");

    if (cliente.isEmpty() || telefono.isEmpty() || descripcion.isEmpty()) {
        QMessageBox::warning(this, "Campos vacíos", "Por favor, llena tu nombre, teléfono y descripción.");
        return;
    }

    // Insertamos la solicitud en nuestra Lista Circular Doblemente Enlazada
    listaSolicitudes->registrarSolicitud(cliente, telefono, tipo, descripcion, fechaActual);

    QMessageBox::information(this, "Éxito", "Tu solicitud de '" + tipo + "' ha sido enviada al administrador.");

    // Limpiamos los campos para dejar la interfaz limpia
    ui->txtTelefono->clear();
    ui->txtDescripcion->clear();

    //Opcional para depuración: Generamos el reporte inmediatamente para ver cómo crece la lista
    listaSolicitudes->generarReporteDOT();
}

void MainWindow::on_btnCrearPromo_clicked()
{
    QString codigo = ui->txtCodigoPromo->text();
    QString nombre = ui->txtNombrePromo->text();
    QString vigencia = ui->txtVigenciaPromo->text();
    QString dias = ui->txtDiasPromo->text();

    if(codigo.isEmpty() || nombre.isEmpty()) {
        QMessageBox::warning(this, "Error", "El código y el nombre son obligatorios.");
        return;
    }

    // Llamamos a la lista circular
    listaPromos->agregarPromocion(codigo, nombre, vigencia, dias);

    QMessageBox::information(this, "Éxito", "Promoción " + codigo + " creada. Ahora puedes agregarle beneficios.");

    ui->txtCodigoPromo->clear();
    ui->txtNombrePromo->clear();
    ui->txtVigenciaPromo->clear();
    ui->txtDiasPromo->clear();
}


void MainWindow::on_comboTipoBeneficio_activated(int index)
{
    QString codigoPromo = ui->txtCodigoAsignar->text();
    QString tipo = ui->comboTipoBeneficio->currentText();
    QString desc = ui->txtDescBeneficio->text();
    QString valor = ui->txtValorBeneficio->text();

    if(codigoPromo.isEmpty()) {
        QMessageBox::warning(this, "Error", "Ingresa el código de la promoción a la que pertenece este beneficio.");
        return;
    }

    // Llamamos a la sub-lista doblemente enlazada
    listaPromos->agregarBeneficioAPromo(codigoPromo, tipo, desc, valor);

    QMessageBox::information(this, "Éxito", "Beneficio agregado a la promoción " + codigoPromo + ".");

    ui->txtDescBeneficio->clear();
    ui->txtValorBeneficio->clear();
}


void MainWindow::on_btnReportePromos_clicked()
{
    listaPromos->generarReporteDOT();

    // 2. Cargamos ese archivo en un objeto QPixmap
    QPixmap imagenReporte("reporte_promociones.png");

    // 3. Se lo pasamos al Label que acabamos de crear
    ui->lblVisorAdmin->setPixmap(imagenReporte);

    // 4. (Opcional) Cambiamos a la pestaña del visor automáticamente
    // Asumiendo que tu "Visor de Reportes" es la pestaña índice 3
    ui->tabWidgetAdmin->setCurrentIndex(4);

    QMessageBox::information(this, "Éxito", "Grafo generado y mostrado en el visor.");
}


void MainWindow::on_btnBuscarPelicula_clicked()
{
    QString codigo = ui->txtBuscarCodigo->text();
    if (codigo.isEmpty()) {
        QMessageBox::warning(this, "Atención", "Ingrese un código de película.");
        return;
    }

    Pelicula* p = arbolCartelera->buscarPelicula(codigo);

    if (p != nullptr) {
        QString info = "Título: " + p->titulo + "\n" +
                       "Género: " + p->genero + "\n" +
                       "Duración: " + QString::number(p->duracion) + " min\n" +
                       "Clasificación: " + p->clasificacion;
        QMessageBox::information(this, "Película Encontrada", info);
    } else {
        QMessageBox::warning(this, "No encontrada", "No existe ninguna película con el código " + codigo);
    }
}
void MainWindow::on_btnAlertas_clicked()
{
    // Llamamos a nuestro recorrido mágico en el árbol
    QString reporteAlertas = arbolCartelera->obtenerAlertasExpiracion();

    QMessageBox::information(this, "Alertas de Cartelera", reporteAlertas);
}


// --- BOTÓN DEL ADMINISTRADOR ---
void MainWindow::on_btnEnProceso_clicked()
{
    if (idSolicitudEnProceso != -1) {
        // Cambiamos el estado en la lista circular doble
        listaSolicitudes->marcarComoEnProceso(idSolicitudEnProceso);

        QMessageBox::information(this, "Actualizado", "La solicitud pasó a estado: En Proceso.");

        // Limpiamos la selección y actualizamos la tabla visual
        ui->lblDetalleSolicitud->setText("Selecciona procesar...");
        idSolicitudEnProceso = -1;
        listaSolicitudes->poblarTablaAdmin(ui->tablaAdminSolicitudes);
    } else {
        QMessageBox::warning(this, "Atención", "Primero debes procesar una solicitud pendiente.");
    }
}

// --- BOTÓN DEL CLIENTE ---
void MainWindow::on_btnBuscarSolicitud_clicked()
{
    QString telefono = ui->txtBuscarTelefonoSolicitud->text();

    if (telefono.isEmpty()) {
        QMessageBox::warning(this, "Atención", "Ingresa tu número de teléfono para buscar tus solicitudes.");
        return;
    }

    // Buscamos en la lista circular y mostramos el resultado
    QString reporte = listaSolicitudes->buscarEstadoPorTelefono(telefono);

    QMessageBox::information(this, "Tus Solicitudes", reporte);

    ui->txtBuscarTelefonoSolicitud->clear();
}

void MainWindow::on_btnReporteSolicitudes_clicked()
{
    // 1. Llamamos a tu método para que Graphviz construya el .png
    listaSolicitudes->generarReporteDOT();

    // 2. Instanciamos el QPixmap con el nombre exacto del archivo generado
    QPixmap imagenSolicitudes("reporte_solicitudes.png");

    // 3. Validación de seguridad (¡A los auxiliares les encanta esto!)
    if (imagenSolicitudes.isNull()) {
        QMessageBox::warning(this, "Error", "No se pudo cargar la imagen. Verifica que Graphviz se haya ejecutado correctamente.");
        return;
    }

    // 4. Inyectamos la imagen en el Label del visor
    ui->lblVisorAdmin->setPixmap(imagenSolicitudes);

    // 5. Avisamos que todo salió bien
    QMessageBox::information(this, "Reporte Generado", "El reporte de Solicitudes se cargó correctamente en el visor.");
}

//-----------------------------
//COMIENZO FASE 2
//-----------------------------

void MainWindow::on_btnCargaMasivaClientes_clicked()
{
    // 1. Abrir explorador de archivos nativo filtrando por .json
    QString rutaArchivo = QFileDialog::getOpenFileName(this, "Seleccionar JSON de Clientes", "", "Archivos JSON (*.json)");

    if(rutaArchivo.isEmpty()){
        return; // El usuario canceló la ventana
    }

    // 2. Llamar al método de procesamiento
    cargarCargaMasivaClientes(rutaArchivo);
}

void MainWindow::cargarCargaMasivaClientes(QString rutaArchivo)
{
    QFile file(rutaArchivo);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "No se pudo abrir el archivo JSON de clientes.");
        return;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (doc.isNull() || !doc.isObject()) {
        QMessageBox::warning(this, "Error de Formato", "El archivo no tiene un formato JSON válido.");
        return;
    }

    QJsonObject root = doc.object();
    QJsonArray clientesArray = root["clientes"].toArray();
    int clientesCargados = 0;
    int reservasCargadas = 0;

    for (int i = 0; i < clientesArray.size(); i++) {
        QJsonObject clienteObj = clientesArray[i].toObject();

        std::string id = clienteObj["id"].toString().toStdString();
        std::string nombre = clienteObj["nombre"].toString().toStdString();
        std::string correo = clienteObj["correo"].toString().toStdString();
        std::string telefono = clienteObj["telefono"].toString().toStdString();
        std::string password = clienteObj["password"].toString().toStdString();
        std::string tipo = clienteObj["tipo"].toString().toStdString();

        Cliente nuevoCliente(id, nombre, correo, telefono, password, tipo);

        QJsonArray reservasArray = clienteObj["reservas"].toArray();
        for (int j = 0; j < reservasArray.size(); j++) {
            QJsonObject reservaObj = reservasArray[j].toObject();

            std::string cod_reserva = reservaObj["codigo_reserva"].toString().toStdString();
            std::string cod_funcion = reservaObj["codigo_funcion"].toString().toStdString();
            int fila = reservaObj["fila"].toInt();
            int columna = reservaObj["columna"].toInt();
            std::string fecha = reservaObj["fecha_reserva"].toString().toStdString();

            // 1. Insertar en la Tabla Hash
            Reserva* nuevaReserva = new Reserva(cod_reserva, cod_funcion, id, fila, columna, fecha);
            tablaReservas->insertar(nuevaReserva);
            reservasCargadas++;

            // 2. Almacenar referencia en el Cliente (Árbol B)
            nuevoCliente.codigos_reservas.push_back(cod_reserva);

            // ================================================================
            // ---> FIX: INSERCIÓN DINÁMICA EN LA MATRIZ DISPERSA <---
            // ================================================================
            QString qCodFuncion = QString::fromStdString(cod_funcion);
            QString qCodReserva = QString::fromStdString(cod_reserva);
            QString archivoJSON = qCodFuncion + "_funcion.json";

            // Buscar la función en el AVL para saber sus dimensiones (filas x columnas)
            NodoAVL* nodoFuncion = arbolFunciones->buscarFuncion(qCodFuncion);

            if (nodoFuncion != nullptr) {
                int filasSala = nodoFuncion->filas;
                int columnasSala = nodoFuncion->columnas;

                // Cargar la matriz de esa función específica
                matrizSala->cargarDesdeArchivo(archivoJSON, filasSala, columnasSala);

                // Ocupar el asiento físicamente en la matriz
                matrizSala->reservarAsiento(fila, columna, qCodReserva);

                // Sobrescribir el JSON para que el cambio persista
                matrizSala->guardarEnArchivo(archivoJSON, qCodFuncion);
            } else {
                qDebug() << "Advertencia: Función" << qCodFuncion << "no encontrada en el AVL.";
            }
            // ================================================================
        }

        // Insertar cliente en el Árbol B
        arbolClientes->insertar(nuevoCliente);
        clientesCargados++;
    }

    // Actualizamos la UI
    arbolClientes->poblarTablaUI(ui->tblAdminClientes);

    QMessageBox::information(this, "Carga Exitosa",
                             QString("Se cargaron %1 clientes y %2 reservas en el sistema.")
                                 .arg(clientesCargados).arg(reservasCargadas));
}

void MainWindow::on_btnBuscarIdCliente_clicked()
{
    QString idBusqueda = ui->txtBuscarIdCliente->text().trimmed();

    if (idBusqueda.isEmpty()) {
        QMessageBox::warning(this, "Atención", "Por favor, ingresa el ID del cliente a buscar.");
        return;
    }

    // 1. Buscamos al cliente en el Árbol B
    Cliente* clienteEncontrado = arbolClientes->buscar(idBusqueda.toStdString());

    if (clienteEncontrado != nullptr) {
        // 2. Formateamos su información básica
        QString info = "🎟️ CLIENTE ENCONTRADO\n";
        info += "ID: " + QString::fromStdString(clienteEncontrado->id) + "\n";
        info += "Nombre: " + QString::fromStdString(clienteEncontrado->nombre) + "\n";
        info += "Correo: " + QString::fromStdString(clienteEncontrado->correo) + "\n";
        info += "----------------------------------------\n";
        info += "📦 RESERVAS ASOCIADAS:\n";

        // 3. Verificamos si tiene reservas[cite: 1]
        if (clienteEncontrado->codigos_reservas.empty()) {
            info += "Este cliente no tiene reservas registradas.\n";
        } else {
            // 4. Utilizamos la Tabla Hash para recuperar los detalles[cite: 1]
            for (const std::string& cod : clienteEncontrado->codigos_reservas) {
                Reserva* detalleReserva = tablaReservas->buscar(cod);

                if (detalleReserva != nullptr) {
                    info += "• Código: " + QString::fromStdString(detalleReserva->codigo_reserva) + "\n";
                    info += "  Función: " + QString::fromStdString(detalleReserva->codigo_funcion) + "\n";
                    info += "  Fecha: " + QString::fromStdString(detalleReserva->fecha_reserva) + "\n";
                    info += "  Asiento: Fila " + QString::number(detalleReserva->fila) + ", Col " + QString::number(detalleReserva->columna) + "\n\n";
                } else {
                    info += "• Código: " + QString::fromStdString(cod) + " (Datos no encontrados en Hash)\n\n";
                }
            }
        }

        // Mostramos el reporte completo en pantalla
        QMessageBox::information(this, "Resultado de Búsqueda", info);
        ui->txtBuscarIdCliente->clear(); // Limpiamos el input

    } else {
        QMessageBox::warning(this, "No Encontrado", "No existe ningún cliente registrado con el ID: " + idBusqueda);
    }
}

void MainWindow::on_btnRegistrar_clicked()
{
    QString nombre = ui->txtRegNombre->text().trimmed();
    QString correo = ui->txtRegCorreo->text().trimmed();
    QString telefono = ui->txtRegTelefono->text().trimmed();
    QString password = ui->txtRegPass->text().trimmed();

    if (nombre.isEmpty() || correo.isEmpty() || telefono.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Campos Vacíos", "Por favor, llena todos los campos para registrarte.");
        return;
    }

    // Validación obligatoria: Rechazar si el correo ya existe[cite: 1]
    if (arbolClientes->buscarPorCorreo(correo.toStdString()) != nullptr) {
        QMessageBox::warning(this, "Correo Inválido", "Este correo ya está registrado en el sistema.");
        return;
    }

    // Generar un ID único automáticamente (Ej: U12345)
    QString nuevoId = "U" + QString::number(QDateTime::currentMSecsSinceEpoch()).right(5);

    // Creamos el cliente e insertamos en el Árbol B por ID[cite: 1]
    Cliente nuevoCliente(nuevoId.toStdString(), nombre.toStdString(), correo.toStdString(), telefono.toStdString(), password.toStdString(), "cliente");
    arbolClientes->insertar(nuevoCliente);

    QMessageBox::information(this, "Registro Exitoso", "¡Bienvenido " + nombre + "! Tu ID asignado es " + nuevoId + ".\nYa puedes iniciar sesión.");

    // Limpiar formulario
    ui->txtRegNombre->clear();
    ui->txtRegCorreo->clear();
    ui->txtRegTelefono->clear();
    ui->txtRegPass->clear();

    // Refrescar tabla del admin si la tienes cargada
    arbolClientes->poblarTablaUI(ui->tblAdminClientes);
}


void MainWindow::on_btnActualizarTabla_clicked()
{
    // Verificamos por seguridad que el árbol esté instanciado
    if (arbolClientes != nullptr) {

        // Llamamos al método que programamos anteriormente
        arbolClientes->poblarTablaUI(ui->tblAdminClientes);

        QMessageBox::information(this, "Actualizado", "La tabla de clientes ha sido actualizada con los registros más recientes.");
    } else {
        QMessageBox::warning(this, "Error", "El sistema de clientes no está inicializado.");
    }
}

void MainWindow::on_btnCrearFuncion_clicked()
{
    QString codigoPelicula =
        ui->comboPeliculas
            ->currentData()
            .toString();

    QString codigoSede =
        ui->cmbSedeFuncion
            ->currentData()
            .toString();

    QString fecha =
        ui->dateFechaFuncion
            ->date()
            .toString("yyyy-MM-dd");

    QString horario =
        ui->txtHorario
            ->text()
            .trimmed();

    QString sala =
        ui->comboSala
            ->currentText()
            .trimmed();

    int filas =
        ui->spinFilas->value();

    int columnas =
        ui->spinColumnas->value();


    if (codigoPelicula.isEmpty()) {

        QMessageBox::warning(
            this,
            "Película",
            "Seleccione una película válida."
            );

        return;
    }


    Pelicula* pelicula =
        arbolCartelera->buscarPelicula(
            codigoPelicula
            );

    if (pelicula == nullptr) {

        QMessageBox::warning(
            this,
            "Película",
            "La película seleccionada ya no existe."
            );

        return;
    }


    if (codigoSede.isEmpty() ||
        grafoSedes->buscarSede(
            codigoSede.toStdString()
            ) == nullptr) {

        QMessageBox::warning(
            this,
            "Sede",
            "Seleccione una sede válida."
            );

        return;
    }


    if (horario.isEmpty() ||
        sala.isEmpty() ||
        filas <= 0 ||
        columnas <= 0) {

        QMessageBox::warning(
            this,
            "Datos inválidos",
            "Complete horario, sala y dimensiones válidas."
            );

        return;
    }


    QString codigoFuncion =
        "F" +
        QString("%1")
            .arg(
                contadorGlobalFunciones,
                3,
                10,
                QChar('0')
                );


    arbolFunciones->insertar(
        codigoFuncion.toStdString(),
        pelicula->titulo.toStdString(),
        pelicula->codigo.toStdString(),
        fecha.toStdString(),
        codigoSede.toStdString(),
        horario.toStdString(),
        sala.toStdString(),
        filas,
        columnas
        );

    contadorGlobalFunciones++;

    sincronizarGrafoConFunciones();

    arbolFunciones->poblarTablaUI(
        ui->tblFunciones
        );

    refrescarControlesE4();

    ui->dateFechaFuncion->setDate(
        QDate::currentDate()
        );

    QMessageBox::information(
        this,
        "Función Creada",
        "Función " +
            codigoFuncion +
            " (" +
            pelicula->titulo +
            ") creada correctamente en " +
            codigoSede +
            "."
        );
}


void MainWindow::on_cbPeliculasDisponibles_currentTextChanged(
    const QString &arg1)
{
    Q_UNUSED(arg1);

    QString codigoPelicula =
        ui->cbPeliculasDisponibles
            ->currentData()
            .toString();

    poblarSedesPorPelicula(
        ui->cmbSedeReserva,
        codigoPelicula
        );

    poblarFuncionesPorPeliculaYSede(
        ui->cbFuncionesDisponibles,
        codigoPelicula,
        ui->cmbSedeReserva
            ->currentData()
            .toString()
        );
}

void MainWindow::on_btnReservar_clicked()
{
    // 1. Validar sesión activa
    if (idUsuarioLogueado.isEmpty()) {
        QMessageBox::warning(this, "Sesión Inválida", "Debes iniciar sesión para realizar una reserva.");
        return;
    }

    // 2. Capturar datos de la interfaz
    int fila = ui->spinReservaFila->value();
    int columna = ui->spinReservaColumna->value();

    // Obtenemos el código oculto "F00X" que guardamos previamente en el userData del ComboBox
    QString codFuncion = ui->cbFuncionesDisponibles->currentData().toString();

    if (codFuncion.isEmpty()) {
        QMessageBox::warning(this, "Atención", "Seleccione una función válida de la cartelera.");
        return;
    }

    if (fila <= 0 || columna <= 0) {
        QMessageBox::warning(this, "Atención", "Seleccione una fila y columna válidas.");
        return;
    }

    // 3. Generar un código de reserva único (ej. R + Timestamp)
    QString codigoReserva = "R" + QString::number(QDateTime::currentMSecsSinceEpoch()).right(5);
    QString archivoJSON = codFuncion + "_funcion.json";

    // 4. Cargar la Matriz Dispersa con los datos de la función seleccionada
    NodoAVL* funcionActiva = arbolFunciones->buscarFuncion(codFuncion);
    int totalFilas = (funcionActiva != nullptr) ? funcionActiva->filas : 10;
    int totalColumnas = (funcionActiva != nullptr) ? funcionActiva->columnas : 20;

    matrizSala->cargarDesdeArchivo(archivoJSON, totalFilas, totalColumnas);

    // 5. Intentar reservar el asiento en la Matriz Dispersa
    // Recuerda que ahora la matriz solo recibe el codigo_reserva, no el nombre[cite: 1]
    if (matrizSala->reservarAsiento(fila, columna, codigoReserva)) {

        // 6. Persistir el cambio sobreescribiendo el archivo JSON de la función[cite: 1]
        matrizSala->guardarEnArchivo(archivoJSON, codFuncion);

        // 7. Registrar la reserva globalmente en la Tabla Hash[cite: 1]
        QString fechaActual = QDateTime::currentDateTime().toString("yyyy-MM-dd");
        Reserva* nuevaReserva = new Reserva(codigoReserva.toStdString(), codFuncion.toStdString(), idUsuarioLogueado.toStdString(), fila, columna, fechaActual.toStdString());
        tablaReservas->insertar(nuevaReserva);

        // 8. Asociar el código de reserva al Cliente en el Árbol B[cite: 1]
        Cliente* clienteActual = arbolClientes->buscar(idUsuarioLogueado.toStdString());
        if (clienteActual != nullptr) {
            clienteActual->codigos_reservas.push_back(codigoReserva.toStdString());
        }

        QMessageBox::information(this, "Reserva Confirmada",
                                 "¡Asiento reservado con éxito!\n\n"
                                 "Código de Reserva: " + codigoReserva + "\n"
                                                       "Función: " + codFuncion + "\n"
                                                    "Asiento: (" + QString::number(fila) + "," + QString::number(columna) + ")");
    } else {
        // La matriz devolvió false porque el asiento ya está ocupado en el JSON
        QMessageBox::warning(this, "Asiento No Disponible",
                             "El asiento (" + QString::number(fila) + "," + QString::number(columna) +
                                 ") ya se encuentra ocupado. Por favor, elige otro.");
    }
}

void MainWindow::on_btnVerDisponibilidad_clicked()
{
    // 1. Extraer el código "F00X" almacenado en el userData del ComboBox
    QString codFuncion = ui->cbFuncionesDisponibles->currentData().toString();

    if (codFuncion.isEmpty()) {
        QMessageBox::warning(this, "Atención", "Seleccione una función válida de la cartelera.");
        return;
    }

    // Extraemos las dimensiones reales de nuestro árbol AVL
    NodoAVL* funcionActiva = arbolFunciones->buscarFuncion(codFuncion);
    int totalFilas = (funcionActiva != nullptr) ? funcionActiva->filas : 10;
    int totalColumnas = (funcionActiva != nullptr) ? funcionActiva->columnas : 20;

    QString archivoJSON = codFuncion + "_funcion.json";
    matrizSala->cargarDesdeArchivo(archivoJSON, totalFilas, totalColumnas);

    // 3. Cargar la matriz con los asientos ocupados de ese archivo
    matrizSala->cargarDesdeArchivo(archivoJSON, totalFilas, totalColumnas);

    // 4. Configurar el QTableWidget
    ui->tblMapaAsientos->setRowCount(totalFilas);
    ui->tblMapaAsientos->setColumnCount(totalColumnas);

    // 5. Pintar la cuadrícula iterando sobre las dimensiones totales
    for (int f = 1; f <= totalFilas; f++) {
        for (int c = 1; c <= totalColumnas; c++) {

            QTableWidgetItem* celda = new QTableWidgetItem();

            // Consultamos a nuestro método auxiliar
            if (matrizSala->estaOcupado(f, c)) {
                celda->setBackground(QColor("#ff4c4c")); // Rojo para ocupado
                celda->setText("X");
            } else {
                celda->setBackground(QColor("#90ee90")); // Verde claro para libre
                celda->setText(QString::number(f) + "," + QString::number(c));
            }

            celda->setTextAlignment(Qt::AlignCenter);

            // Qt indexa las tablas desde 0, restamos 1 a las coordenadas reales
            ui->tblMapaAsientos->setItem(f - 1, c - 1, celda);
        }
    }

    // Ajustar visualmente el tamaño de las celdas
    ui->tblMapaAsientos->resizeColumnsToContents();
    ui->tblMapaAsientos->resizeRowsToContents();
}

void MainWindow::on_btnActualizarHistorial_clicked()
{
    if (idUsuarioLogueado.isEmpty()) {
        QMessageBox::warning(this, "Sesión", "Debes iniciar sesión para ver tu historial.");
        return;
    }

    // 1. Limpiar y configurar la tabla
    ui->tblMisReservas->setRowCount(0);
    if (ui->tblMisReservas->columnCount() == 0) {
        ui->tblMisReservas->setColumnCount(6);
        ui->tblMisReservas->setHorizontalHeaderLabels({"Código", "Función", "Fecha", "Fila", "Columna", "Estado"});
    }

    // 2. Búsqueda robusta del cliente (Limpiando espacios basura)
    QString idBuscado = idUsuarioLogueado.trimmed();
    Cliente* clienteActual = arbolClientes->buscar(idBuscado.toStdString());

    // PLAN B: Si no lo encuentra por ID, intentar buscarlo por correo
    // (Muy útil si programaste el login pidiendo el correo)
    if (clienteActual == nullptr) {
        clienteActual = arbolClientes->buscarPorCorreo(idBuscado.toStdString());
    }

    // Si sigue siendo nulo, aquí saltará la alerta en lugar del return silencioso
    if (clienteActual == nullptr) {
        QMessageBox::critical(this, "Error de Sesión", "No se encontró tu usuario ('" + idBuscado + "') en el Árbol B.");
        return;
    }

    // 3. Verificar si el cliente realmente tiene códigos guardados
    if (clienteActual->codigos_reservas.empty()) {
        QMessageBox::information(this, "Historial", "Actualmente no tienes reservas registradas.");
        return;
    }

    QDate fechaActual = QDate::currentDate();
    int reservasEncontradasEnHash = 0;

    // 4. Iterar sobre los códigos del cliente
    for (const std::string& codReserva : clienteActual->codigos_reservas) {

        // Limpiamos el código de la reserva por si el JSON traía espacios fantasma
        std::string codLimpio = QString::fromStdString(codReserva).trimmed().toStdString();

        // Buscar en la Tabla Hash
        Reserva* reserva = tablaReservas->buscar(codLimpio);

        if (reserva != nullptr) {
            reservasEncontradasEnHash++;
            int filaTabla = ui->tblMisReservas->rowCount();
            ui->tblMisReservas->insertRow(filaTabla);

            ui->tblMisReservas->setItem(filaTabla, 0, new QTableWidgetItem(QString::fromStdString(reserva->codigo_reserva)));
            ui->tblMisReservas->setItem(filaTabla, 1, new QTableWidgetItem(QString::fromStdString(reserva->codigo_funcion)));

            QString fechaRes = QString::fromStdString(reserva->fecha_reserva);
            ui->tblMisReservas->setItem(filaTabla, 2, new QTableWidgetItem(fechaRes));
            ui->tblMisReservas->setItem(filaTabla, 3, new QTableWidgetItem(QString::number(reserva->fila)));
            ui->tblMisReservas->setItem(filaTabla, 4, new QTableWidgetItem(QString::number(reserva->columna)));

            // 5. Lógica de estado a prueba de fallos de formato de fecha
            QDate fechaFuncion = QDate::fromString(fechaRes, "yyyy-MM-dd");
            if (!fechaFuncion.isValid()) {
                fechaFuncion = QDate::fromString(fechaRes, "dd/MM/yyyy"); // Fallback por si el JSON viene distinto
            }

            QString estado = "VÁLIDA";
            if (fechaFuncion.isValid() && fechaFuncion < fechaActual) {
                estado = "VENCIDA";
            }

            QTableWidgetItem* itemEstado = new QTableWidgetItem(estado);
            itemEstado->setForeground(estado == "VÁLIDA" ? QBrush(Qt::darkGreen) : QBrush(Qt::red));

            // Negrita y centrado para que se vea más profesional
            QFont font = itemEstado->font();
            font.setBold(true);
            itemEstado->setFont(font);
            itemEstado->setTextAlignment(Qt::AlignCenter);

            ui->tblMisReservas->setItem(filaTabla, 5, itemEstado);
        }
    }

    // 6. Alerta si el Hash falla
    if (reservasEncontradasEnHash == 0) {
        QMessageBox::warning(this, "Error de Datos", "Tienes reservas en tu perfil, pero no se encontraron en la Tabla Hash. ¡Revisa tu método buscar() de la Tabla Hash!");
    }

    // Ajustar columnas visualmente
    ui->tblMisReservas->resizeColumnsToContents();
    ui->tblMisReservas->horizontalHeader()->setStretchLastSection(true);
}


void MainWindow::on_btnCancelarReserva_clicked()
{
    if (idUsuarioLogueado.isEmpty()) {
        QMessageBox::warning(this, "Atención", "Debes iniciar sesión.");
        return;
    }

    // 1. Capturamos el código que el usuario escribió (ej. "R54321")
    QString codigoCancelacion = ui->txtCodigoCancelar->text().trimmed();

    if (codigoCancelacion.isEmpty()) {
        QMessageBox::warning(this, "Campos Vacíos", "Ingresa el código de la reserva que deseas cancelar.");
        return;
    }

    // 2. Buscamos al cliente actual para confirmar que la reserva es suya
    Cliente* clienteActual = arbolClientes->buscar(idUsuarioLogueado.toStdString());
    if (clienteActual == nullptr) return;

    // Verificar si el código pertenece a este cliente
    auto it = std::find(clienteActual->codigos_reservas.begin(), clienteActual->codigos_reservas.end(), codigoCancelacion.toStdString());
    if (it == clienteActual->codigos_reservas.end()) {
        QMessageBox::critical(this, "Error de Seguridad", "Ese código de reserva no existe o no te pertenece.");
        return;
    }

    // 3. Consultamos la Tabla Hash para obtener los datos de la Matriz
    Reserva* datosReserva = tablaReservas->buscar(codigoCancelacion.toStdString());
    if (datosReserva == nullptr) {
        QMessageBox::warning(this, "Error", "La reserva no se encontró en la base de datos central.");
        return;
    }

    QString codFuncion = QString::fromStdString(datosReserva->codigo_funcion);
    QString archivoJSON = codFuncion + "_funcion.json";
    int fila = datosReserva->fila;
    int columna = datosReserva->columna;

    // ---> NUEVO: Buscamos la función en el AVL para extraer sus dimensiones reales <---
    NodoAVL* funcionActiva = arbolFunciones->buscarFuncion(codFuncion);
    int totalFilas = (funcionActiva != nullptr) ? funcionActiva->filas : 10;
    int totalColumnas = (funcionActiva != nullptr) ? funcionActiva->columnas : 20;

    // 4. Operación en la Matriz Dispersa
    // Cargamos el estado actual de esa función con su tamaño dinámico
    matrizSala->cargarDesdeArchivo(archivoJSON, totalFilas, totalColumnas);

    // Eliminamos el nodo de la matriz
    int resultadoMatriz = matrizSala->cancelarReserva(fila, columna, codigoCancelacion);

    if (resultadoMatriz == 1) {
        // Sobreescribimos el JSON para reflejar que el asiento está libre de nuevo
        matrizSala->guardarEnArchivo(archivoJSON, codFuncion);

        // 5. Eliminamos la reserva de la Tabla Hash
        tablaReservas->eliminar(codigoCancelacion.toStdString());

        // 6. Eliminamos el código del vector del Cliente en el Árbol B
        clienteActual->codigos_reservas.erase(
            std::remove(clienteActual->codigos_reservas.begin(), clienteActual->codigos_reservas.end(), codigoCancelacion.toStdString()),
            clienteActual->codigos_reservas.end()
            );

        QMessageBox::information(this, "Cancelada", "Tu reserva " + codigoCancelacion + " ha sido cancelada exitosamente y el asiento ha sido liberado.");
        ui->txtCodigoCancelar->clear();

        // (Opcional) Llamar automáticamente al botón de actualizar historial para que desaparezca de la tabla
        on_btnActualizarHistorial_clicked();

    } else {
        QMessageBox::warning(this, "Error Interno", "No se pudo liberar el asiento en la matriz.");
    }
}

void MainWindow::on_btnCargarPeliculasJSON_clicked()
{
    QString rutaArchivo = QFileDialog::getOpenFileName(
        this,
        "Seleccionar JSON de Películas",
        "",
        "Archivos JSON (*.json)"
        );

    if (rutaArchivo.isEmpty()) {
        return;
    }

    QFile file(rutaArchivo);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(
            this,
            "Error",
            "No se pudo abrir el archivo JSON."
            );
        return;
    }

    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(
        file.readAll(),
        &parseError
        );

    file.close();

    if (parseError.error != QJsonParseError::NoError ||
        !doc.isObject()) {

        QMessageBox::warning(
            this,
            "Error",
            "Formato JSON inválido."
            );

        return;
    }

    QJsonObject root = doc.object();

    // =========================================================
    // VALIDAR ESTRUCTURA PRINCIPAL FASE 3
    // =========================================================

    if (!root.contains("sedes") ||
        !root["sedes"].isArray()) {

        QMessageBox::warning(
            this,
            "Error",
            "El JSON no contiene un arreglo válido llamado 'sedes'."
            );

        return;
    }

    if (!root.contains("peliculas") ||
        !root["peliculas"].isArray()) {

        QMessageBox::warning(
            this,
            "Error",
            "El JSON no contiene un arreglo válido llamado 'peliculas'."
            );

        return;
    }

    QJsonArray sedesArray =
        root["sedes"].toArray();

    QJsonArray peliculasArray =
        root["peliculas"].toArray();


    // =========================================================
    // CONTADORES
    // =========================================================

    int sedesCargadas = 0;
    int sedesRechazadas = 0;
    int sedesDuplicadas = 0;

    int peliculasCargadas = 0;
    int peliculasRechazadas = 0;
    int peliculasDuplicadas = 0;

    int funcionesCargadas = 0;
    int funcionesRechazadas = 0;

    QStringList errores;


    // =========================================================
    // 1. CARGAR SEDES
    // =========================================================

    for (int i = 0; i < sedesArray.size(); i++) {

        if (!sedesArray[i].isObject()) {

            sedesRechazadas++;

            errores.append(
                QString(
                    "Sede #%1: el elemento no es un objeto JSON válido."
                    ).arg(i + 1)
                );

            continue;
        }

        QJsonObject sObj =
            sedesArray[i].toObject();

        QStringList erroresSede;

        QString codigo =
            sObj["codigo"].toString().trimmed();

        QString nombre =
            sObj["nombre"].toString().trimmed();

        QString direccion =
            sObj["direccion"].toString().trimmed();

        QString telefono =
            sObj["telefono"].toString().trimmed();

        int cantidadSalas = 0;


        // Código
        if (!sObj.contains("codigo") ||
            !sObj["codigo"].isString() ||
            codigo.isEmpty()) {

            erroresSede.append(
                "El código de sede es obligatorio y debe ser texto."
                );
        }


        // Nombre
        if (!sObj.contains("nombre") ||
            !sObj["nombre"].isString() ||
            nombre.isEmpty()) {

            erroresSede.append(
                "El nombre de la sede es obligatorio y debe ser texto."
                );
        }


        // Dirección
        if (!sObj.contains("direccion") ||
            !sObj["direccion"].isString() ||
            direccion.isEmpty()) {

            erroresSede.append(
                "La dirección de la sede es obligatoria y debe ser texto."
                );
        }


        // Cantidad de salas
        if (!sObj.contains("cantidad_salas") ||
            !sObj["cantidad_salas"].isDouble()) {

            erroresSede.append(
                "La cantidad de salas debe ser un número entero."
                );

        } else {

            double cantidadJSON =
                sObj["cantidad_salas"].toDouble();

            if (cantidadJSON <= 0 ||
                cantidadJSON !=
                    static_cast<int>(cantidadJSON)) {

                erroresSede.append(
                    "La cantidad de salas debe ser un entero mayor que 0."
                    );

            } else {

                cantidadSalas =
                    static_cast<int>(cantidadJSON);
            }
        }


        // Teléfono
        if (!sObj.contains("telefono") ||
            !sObj["telefono"].isString() ||
            telefono.isEmpty()) {

            erroresSede.append(
                "El teléfono de la sede es obligatorio y debe ser texto."
                );
        }


        // Si la sede no es válida, no crear vértice.
        if (!erroresSede.isEmpty()) {

            sedesRechazadas++;

            QString identificador =
                codigo.isEmpty()
                    ? QString("Sede #%1").arg(i + 1)
                    : codigo;

            errores.append(
                identificador + ":\n - " +
                erroresSede.join("\n - ")
                );

            continue;
        }


        // =====================================================
        // CREAR SEDE
        // =====================================================

        Sede nuevaSede(
            codigo.toStdString(),
            nombre.toStdString(),
            direccion.toStdString(),
            cantidadSalas,
            telefono.toStdString()
            );


        // insertarSede() también evita códigos duplicados.
        if (!grafoSedes->insertarSede(nuevaSede)) {

            sedesDuplicadas++;

            errores.append(
                codigo +
                ": la sede ya existe; se conserva el vértice registrado previamente."
                );

            continue;
        }

        sedesCargadas++;
    }


    // =========================================================
    // 2. CARGAR PELÍCULAS Y SUS FUNCIONES
    // =========================================================

    ui->comboPeliculas->clear();

    QRegularExpression regexCodigo(
        "^P\\d{3}$"
        );


    for (int i = 0; i < peliculasArray.size(); i++) {

        // =====================================================
        // VALIDAR QUE LA PELÍCULA SEA OBJETO
        // =====================================================

        if (!peliculasArray[i].isObject()) {

            peliculasRechazadas++;

            errores.append(
                QString(
                    "Película #%1: el elemento no es un objeto JSON válido."
                    ).arg(i + 1)
                );

            continue;
        }

        QJsonObject pObj =
            peliculasArray[i].toObject();

        QStringList erroresPelicula;


        // =====================================================
        // EXTRAER CAMPOS DE PELÍCULA
        // =====================================================

        QString codigo =
            pObj["codigo"].toString();

        QString titulo =
            pObj["titulo"].toString();

        QString genero =
            pObj["genero"].toString();

        QString clasificacion =
            pObj["clasificacion"].toString();

        QString idioma =
            pObj["idioma"].toString();

        QString estreno =
            pObj["fecha_estreno"].toString();

        QString fin =
            pObj["fecha_fin"].toString();


        // Código
        if (!pObj.contains("codigo") ||
            !pObj["codigo"].isString() ||
            !regexCodigo.match(codigo).hasMatch()) {

            erroresPelicula.append(
                "El código debe tener el formato P###, por ejemplo P009."
                );
        }


        // Título
        if (!pObj.contains("titulo") ||
            !pObj["titulo"].isString() ||
            titulo.trimmed().isEmpty()) {

            erroresPelicula.append(
                "El título es obligatorio y debe ser texto."
                );
        }


        // Género
        if (!pObj.contains("genero") ||
            !pObj["genero"].isString() ||
            genero.trimmed().isEmpty()) {

            erroresPelicula.append(
                "El género es obligatorio y debe ser texto."
                );
        }


        // Duración
        int duracion = 0;

        if (!pObj.contains("duracion") ||
            !pObj["duracion"].isDouble()) {

            erroresPelicula.append(
                "La duración debe ser un número entero."
                );

        } else {

            double duracionJSON =
                pObj["duracion"].toDouble();

            if (duracionJSON <= 0 ||
                duracionJSON !=
                    static_cast<int>(duracionJSON)) {

                erroresPelicula.append(
                    "La duración debe ser un número entero mayor que 0."
                    );

            } else {

                duracion =
                    static_cast<int>(duracionJSON);
            }
        }


        // Clasificación
        if (!pObj.contains("clasificacion") ||
            !pObj["clasificacion"].isString() ||
            clasificacion.trimmed().isEmpty()) {

            erroresPelicula.append(
                "La clasificación es obligatoria y debe ser texto."
                );
        }


        // Idioma
        if (!pObj.contains("idioma") ||
            !pObj["idioma"].isString() ||
            idioma.trimmed().isEmpty()) {

            erroresPelicula.append(
                "El idioma es obligatorio y debe ser texto."
                );
        }


        // Fecha estreno
        QDate fechaEstreno =
            QDate::fromString(
                estreno,
                "yyyy-MM-dd"
                );

        if (!pObj.contains("fecha_estreno") ||
            !pObj["fecha_estreno"].isString() ||
            !fechaEstreno.isValid()) {

            erroresPelicula.append(
                "La fecha de estreno debe ser una fecha válida YYYY-MM-DD."
                );
        }


        // Fecha fin
        QDate fechaFin =
            QDate::fromString(
                fin,
                "yyyy-MM-dd"
                );

        if (!pObj.contains("fecha_fin") ||
            !pObj["fecha_fin"].isString() ||
            !fechaFin.isValid()) {

            erroresPelicula.append(
                "La fecha de fin debe ser una fecha válida YYYY-MM-DD."
                );
        }


        // Relación entre fechas
        if (fechaEstreno.isValid() &&
            fechaFin.isValid() &&
            fechaFin < fechaEstreno) {

            erroresPelicula.append(
                "La fecha de fin no puede ser anterior a la fecha de estreno."
                );
        }


        // =====================================================
        // PELÍCULA INVÁLIDA:
        // tampoco se procesan sus funciones.
        // =====================================================

        if (!erroresPelicula.isEmpty()) {

            peliculasRechazadas++;

            QString identificador =
                codigo.isEmpty()
                    ? QString("Película #%1").arg(i + 1)
                    : codigo;

            errores.append(
                identificador + ":\n - " +
                erroresPelicula.join("\n - ")
                );

            continue;
        }


        // =====================================================
        // INSERTAR / CONSERVAR PELÍCULA
        // =====================================================

        QString tituloParaFunciones =
            titulo;

        Pelicula* peliculaExistente =
            arbolCartelera->buscarPelicula(codigo);

        if (peliculaExistente == nullptr) {

            Pelicula nuevaPeli(
                codigo,
                titulo,
                genero,
                duracion,
                clasificacion,
                idioma,
                estreno,
                fin
                );

            arbolCartelera->insertar(
                nuevaPeli
                );

            peliculasCargadas++;

        } else {

            /*
             * La política del BST de Fase 2 ya era no insertar
             * códigos duplicados.
             *
             * Conservamos esa política y además usamos el título
             * real de la película que ya existe en memoria.
             */
            peliculasDuplicadas++;

            tituloParaFunciones =
                peliculaExistente->titulo;

            errores.append(
                codigo +
                ": la película ya existe; se conserva el registro previo."
                );
        }


        // =====================================================
        // 3. FUNCIONES DE LA PELÍCULA
        // =====================================================

        if (!pObj.contains("funciones") ||
            !pObj["funciones"].isArray()) {

            continue;
        }

        QJsonArray funcionesArray =
            pObj["funciones"].toArray();


        for (int j = 0;
             j < funcionesArray.size();
             j++) {

            if (!funcionesArray[j].isObject()) {

                funcionesRechazadas++;

                errores.append(
                    QString(
                        "%1 - función #%2: no es un objeto JSON válido."
                        )
                        .arg(codigo)
                        .arg(j + 1)
                    );

                continue;
            }

            QJsonObject fObj =
                funcionesArray[j].toObject();

            QStringList erroresFuncion;


            // =================================================
            // EXTRAER CAMPOS
            // =================================================

            QString codFuncion =
                fObj["codigo_funcion"]
                    .toString()
                    .trimmed();

            QString fecha =
                fObj["fecha"]
                    .toString()
                    .trimmed();

            QString horario =
                fObj["horario"]
                    .toString()
                    .trimmed();

            QString codigoSede =
                fObj["sede"]
                    .toString()
                    .trimmed();

            QString sala =
                fObj["sala"]
                    .toString()
                    .trimmed();

            int filas = 10;
            int columnas = 20;


            // =================================================
            // CÓDIGO DE FUNCIÓN
            // =================================================

            if (!fObj.contains("codigo_funcion") ||
                !fObj["codigo_funcion"].isString() ||
                codFuncion.isEmpty()) {

                erroresFuncion.append(
                    "El código de función es obligatorio y debe ser texto."
                    );

            } else if (
                arbolFunciones->buscarFuncion(
                    codFuncion
                    ) != nullptr) {

                erroresFuncion.append(
                    "Ya existe una función con ese código."
                    );
            }


            // =================================================
            // FECHA FASE 3
            // =================================================

            QDate fechaFuncion =
                QDate::fromString(
                    fecha,
                    "yyyy-MM-dd"
                    );

            if (!fObj.contains("fecha") ||
                !fObj["fecha"].isString() ||
                !fechaFuncion.isValid()) {

                erroresFuncion.append(
                    "La fecha debe tener formato válido YYYY-MM-DD."
                    );
            }


            // =================================================
            // HORARIO
            // =================================================

            if (!fObj.contains("horario") ||
                !fObj["horario"].isString() ||
                horario.isEmpty()) {

                erroresFuncion.append(
                    "El horario es obligatorio y debe ser texto."
                    );
            }


            // =================================================
            // SEDE FASE 3
            // =================================================

            if (!fObj.contains("sede") ||
                !fObj["sede"].isString() ||
                codigoSede.isEmpty()) {

                erroresFuncion.append(
                    "La sede es obligatoria y debe ser texto."
                    );

            } else if (
                grafoSedes->buscarSede(
                    codigoSede.toStdString()
                    ) == nullptr) {

                erroresFuncion.append(
                    "La sede " +
                    codigoSede +
                    " no existe. La función completa será rechazada."
                    );
            }


            // =================================================
            // SALA
            // =================================================

            if (!fObj.contains("sala") ||
                !fObj["sala"].isString() ||
                sala.isEmpty()) {

                erroresFuncion.append(
                    "La sala es obligatoria y debe ser texto."
                    );
            }


            // =================================================
            // FILAS
            //
            // Conservamos el comportamiento histórico:
            // si no viene el campo, valor por defecto 10.
            // =================================================

            if (fObj.contains("filas")) {

                if (!fObj["filas"].isDouble()) {

                    erroresFuncion.append(
                        "Las filas deben ser un número entero."
                        );

                } else {

                    double filasJSON =
                        fObj["filas"].toDouble();

                    if (filasJSON <= 0 ||
                        filasJSON !=
                            static_cast<int>(filasJSON)) {

                        erroresFuncion.append(
                            "Las filas deben ser un entero mayor que 0."
                            );

                    } else {

                        filas =
                            static_cast<int>(filasJSON);
                    }
                }
            }


            // =================================================
            // COLUMNAS
            //
            // Si no viene el campo, conserva default 20.
            // =================================================

            if (fObj.contains("columnas")) {

                if (!fObj["columnas"].isDouble()) {

                    erroresFuncion.append(
                        "Las columnas deben ser un número entero."
                        );

                } else {

                    double columnasJSON =
                        fObj["columnas"].toDouble();

                    if (columnasJSON <= 0 ||
                        columnasJSON !=
                            static_cast<int>(columnasJSON)) {

                        erroresFuncion.append(
                            "Las columnas deben ser un entero mayor que 0."
                            );

                    } else {

                        columnas =
                            static_cast<int>(columnasJSON);
                    }
                }
            }


            // =================================================
            // RECHAZAR COMPLETAMENTE LA FUNCIÓN
            // =================================================

            if (!erroresFuncion.isEmpty()) {

                funcionesRechazadas++;

                QString identificador =
                    codFuncion.isEmpty()
                        ? QString(
                              "%1 - función #%2"
                              )
                              .arg(codigo)
                              .arg(j + 1)
                        : codFuncion;

                errores.append(
                    identificador +
                    ":\n - " +
                    erroresFuncion.join("\n - ")
                    );

                /*
                 * MUY IMPORTANTE:
                 *
                 * Hasta este punto NO se llamó insertar().
                 *
                 * Por tanto:
                 *
                 * - no existe nodo AVL parcial;
                 * - no existe archivo de asientos creado;
                 * - no cambia el grafo.
                 */
                continue;
            }


            // =================================================
            // FUNCIÓN VÁLIDA
            // =================================================

            arbolFunciones->insertar(
                codFuncion.toStdString(),
                tituloParaFunciones.toStdString(),
                codigo.toStdString(),
                fecha.toStdString(),
                codigoSede.toStdString(),
                horario.toStdString(),
                sala.toStdString(),
                filas,
                columnas
                );

            funcionesCargadas++;


            // =================================================
            // ACTUALIZAR CONTADOR GLOBAL SOLO DESPUÉS DE
            // INSERTAR UNA FUNCIÓN VÁLIDA
            // =================================================

            if (codFuncion.startsWith("F")) {

                bool numeroValido = false;

                int numeroActual =
                    codFuncion
                        .mid(1)
                        .toInt(&numeroValido);

                if (numeroValido &&
                    numeroActual >=
                        contadorGlobalFunciones) {

                    contadorGlobalFunciones =
                        numeroActual + 1;
                }
            }
        }
    }


    // =========================================================
    // RECÁLCULO ÚNICO DEL GRAFO AL FINAL DEL LOTE
    // =========================================================

    sincronizarGrafoConFunciones();

    // =========================================================
    // ACTUALIZAR INTERFAZ EXISTENTE
    // =========================================================

    arbolCartelera->poblarTablaInOrden(
        ui->tablaCartelera
        );

    arbolFunciones->poblarTablaUI(
        ui->tblFunciones
        );

    refrescarControlesE4();


    // =========================================================
    // RESULTADO
    // =========================================================

    QString mensaje =
        QString(
            "Sedes cargadas: %1\n"
            "Sedes rechazadas: %2\n"
            "Sedes duplicadas: %3\n\n"
            "Películas cargadas: %4\n"
            "Películas rechazadas: %5\n"
            "Películas duplicadas: %6\n\n"
            "Funciones cargadas: %7\n"
            "Funciones rechazadas: %8"
            )
            .arg(sedesCargadas)
            .arg(sedesRechazadas)
            .arg(sedesDuplicadas)
            .arg(peliculasCargadas)
            .arg(peliculasRechazadas)
            .arg(peliculasDuplicadas)
            .arg(funcionesCargadas)
            .arg(funcionesRechazadas);


    if (!errores.isEmpty()) {

        mensaje +=
            "\n\nObservaciones / registros no cargados:\n\n";

        mensaje +=
            errores.join("\n\n");
    }


    QMessageBox::information(
        this,
        "Carga Masiva",
        mensaje
        );
}

void MainWindow::on_tablaCartelera_cellClicked(int row, int column)
{
    // Validamos por seguridad que la celda principal no sea nula
    if (ui->tablaCartelera->item(row, 0) != nullptr) {

        // Extraemos el texto de cada columna de la fila seleccionada (0 a 7)
        ui->txtCodPelicula->setText(ui->tablaCartelera->item(row, 0)->text());
        ui->txtTitulo->setText(ui->tablaCartelera->item(row, 1)->text());
        ui->txtGenero->setText(ui->tablaCartelera->item(row, 2)->text());
        ui->txtDuracion->setText(ui->tablaCartelera->item(row, 3)->text());
        ui->txtClasificacion->setText(ui->tablaCartelera->item(row, 4)->text());
        ui->txtIdioma->setText(ui->tablaCartelera->item(row, 5)->text());

        // Dependiendo de cómo armaste tu tabla, ajusta los índices 6 y 7
        ui->txtEstreno->setText(ui->tablaCartelera->item(row, 6)->text());
        ui->txtFin->setText(ui->tablaCartelera->item(row, 7)->text());
    }
}

void MainWindow::on_btnAgregarPelicula_clicked()
{
    // 1. Capturamos todos los inputs de la interfaz
    QString codigo = ui->txtCodPelicula->text().trimmed();
    QString titulo = ui->txtTitulo->text().trimmed();
    QString genero = ui->txtGenero->text().trimmed();
    int duracion = ui->txtDuracion->text().toInt(); // Convertimos a entero
    QString clasificacion = ui->txtClasificacion->text().trimmed();
    QString idioma = ui->txtIdioma->text().trimmed();
    QString estreno = ui->txtEstreno->text().trimmed();
    QString fin = ui->txtFin->text().trimmed();

    // 2. Validación básica
    if (codigo.isEmpty() || titulo.isEmpty()) {
        QMessageBox::warning(this, "Atención", "El código y el título son obligatorios.");
        return;
    }

    // 3. Validar si ya existe
    if (arbolCartelera->buscarPelicula(codigo) != nullptr) {
        QMessageBox::warning(this, "Error", "Ya existe una película con el código: " + codigo);
        return;
    }

    // 4. Instanciar e insertar
    Pelicula nuevaPeli(codigo, titulo, genero, duracion, clasificacion, idioma, estreno, fin);
    arbolCartelera->insertar(nuevaPeli);

    // 5. Actualizar interfaz
    arbolCartelera->poblarTablaInOrden(ui->tablaCartelera);
    refrescarControlesE4();

    QMessageBox::information(this, "Éxito", "Película agregada a la cartelera.");

    // 6. Limpiar los inputs
    ui->txtCodPelicula->clear();
    ui->txtTitulo->clear();
    ui->txtGenero->clear();
    ui->txtDuracion->clear();
    ui->txtClasificacion->clear();
    ui->txtIdioma->clear();
    ui->txtEstreno->clear();
    ui->txtFin->clear();
}

void MainWindow::on_btnEditarPelicula_clicked()
{
    QString codigo = ui->txtCodPelicula->text().trimmed();

    if (codigo.isEmpty()) {
        QMessageBox::warning(this, "Atención", "Ingrese el código de la película que desea editar.");
        return;
    }

    // 1. Buscamos el puntero directo a la película en tu Árbol de Películas
    Pelicula* peliEdit = arbolCartelera->buscarPelicula(codigo);

    if (peliEdit != nullptr) {
        // 2. Actualizamos los atributos con lo que haya en las cajas de texto
        // Nota: El código no se edita porque es la llave principal del árbol
        peliEdit->titulo = ui->txtTitulo->text();
        peliEdit->genero = ui->txtGenero->text();
        peliEdit->duracion = ui->txtDuracion->text().toInt();
        peliEdit->clasificacion = ui->txtClasificacion->text();
        peliEdit->idioma = ui->txtIdioma->text();
        // Las fechas podrían guardarse como QString dependiendo de cómo las usaste en Fase 1
        // Si tu struct usa QDate, habría que convertirlas, pero asumiendo QString:
        peliEdit->fechaEstreno = ui->txtEstreno->text();
        peliEdit->fechaFin = ui->txtFin->text();

        // 3. Refrescamos la vista
        arbolCartelera->poblarTablaInOrden(ui->tablaCartelera);

        refrescarControlesE4();

        QMessageBox::information(this, "Actualizado", "Datos de la película " + codigo + " actualizados.");

        // Limpiamos los inputs
        ui->txtCodPelicula->clear();
        ui->txtTitulo->clear();
        ui->txtGenero->clear();
        ui->txtDuracion->clear();
        ui->txtClasificacion->clear();
        ui->txtIdioma->clear();
        ui->txtEstreno->clear();
        ui->txtFin->clear();
    } else {
        QMessageBox::warning(this, "No encontrada", "No se encontró ninguna película con el código " + codigo);
    }
}


void MainWindow::on_btnEliminarPelicula_clicked()
{
    QString codigo = ui->txtCodPelicula->text().trimmed();

    if (codigo.isEmpty()) {
        QMessageBox::warning(this, "Atención", "Ingrese el código de la película a eliminar.");
        return;
    }

    // Confirmación de seguridad
    QMessageBox::StandardButton resp = QMessageBox::question(this, "Eliminar",
                                                             "¿Seguro que deseas eliminar la película " + codigo + "?",
                                                             QMessageBox::Yes | QMessageBox::No);

    if (resp == QMessageBox::Yes) {

        // Llamamos al método eliminar de tu Árbol Binario de Películas
        bool eliminada = arbolCartelera->eliminarPelicula(codigo);

        if (eliminada) {
            // Actualizamos la tabla
            arbolCartelera->poblarTablaInOrden(ui->tablaCartelera);
            refrescarControlesE4();

            QMessageBox::information(this, "Eliminada", "La película ha sido retirada de la cartelera.");

            ui->txtCodPelicula->clear();
        } else {
            QMessageBox::warning(this, "Error", "La película no existe o ya fue eliminada.");
        }
    }
}


void MainWindow::on_cbOrdenPeliculas_currentTextChanged(const QString &arg1)
{
    // Evaluamos el texto seleccionado y llamamos al método correspondiente
    if (arg1 == "Preorden") {
        arbolCartelera->poblarTablaPreOrden(ui->tablaCartelera);
    }
    else if (arg1 == "Postorden") {
        arbolCartelera->poblarTablaPostOrden(ui->tablaCartelera);
    }
    else {
        // Por defecto, o si dice "Inorden"
        arbolCartelera->poblarTablaInOrden(ui->tablaCartelera);
    }
}


void MainWindow::on_tblFunciones_cellClicked(
    int row,
    int column)
{
    Q_UNUSED(column);

    if (ui->tblFunciones->item(row, 0) == nullptr) {
        return;
    }

    QString codigo =
        ui->tblFunciones
            ->item(row, 0)
            ->text();

    NodoAVL* funcion =
        arbolFunciones->buscarFuncion(
            codigo
            );

    if (funcion == nullptr) {
        return;
    }

    ui->txtEditCodFuncion->setText(
        QString::fromStdString(
            funcion->codigo_funcion
            )
        );

    int indicePelicula =
        ui->cmbEditPelicula->findData(
            QString::fromStdString(
                funcion->codigo_pelicula_real
                )
            );

    ui->cmbEditPelicula->setCurrentIndex(
        indicePelicula
        );


    QDate fecha =
        QDate::fromString(
            QString::fromStdString(
                funcion->fecha
                ),
            "yyyy-MM-dd"
            );

    ui->dateEditFechaFuncion->setDate(
        fecha.isValid()
            ? fecha
            : QDate::currentDate()
        );


    int indiceSede =
        ui->cmbEditSedeFuncion->findData(
            QString::fromStdString(
                funcion->codigo_sede
                )
            );

    ui->cmbEditSedeFuncion->setCurrentIndex(
        indiceSede
        );


    ui->txtEditHorario->setText(
        QString::fromStdString(
            funcion->horario
            )
        );

    ui->txtEditSala->setText(
        QString::fromStdString(
            funcion->sala
            )
        );

    ui->spinEditFilas->setValue(
        funcion->filas
        );

    ui->spinEditColumnas->setValue(
        funcion->columnas
        );
}


void MainWindow::on_btnBuscarFuncion_clicked()
{
    QString codigo =
        ui->txtBuscarCodFuncion
            ->text()
            .trimmed();

    if (codigo.isEmpty()) {
        return;
    }

    NodoAVL* funcion =
        arbolFunciones->buscarFuncion(
            codigo
            );

    if (funcion == nullptr) {

        QMessageBox::warning(
            this,
            "No encontrada",
            "No existe la función " +
                codigo
            );

        return;
    }


    ui->txtEditCodFuncion->setText(
        QString::fromStdString(
            funcion->codigo_funcion
            )
        );


    int indicePelicula =
        ui->cmbEditPelicula->findData(
            QString::fromStdString(
                funcion->codigo_pelicula_real
                )
            );

    ui->cmbEditPelicula->setCurrentIndex(
        indicePelicula
        );


    QDate fecha =
        QDate::fromString(
            QString::fromStdString(
                funcion->fecha
                ),
            "yyyy-MM-dd"
            );

    ui->dateEditFechaFuncion->setDate(
        fecha.isValid()
            ? fecha
            : QDate::currentDate()
        );


    int indiceSede =
        ui->cmbEditSedeFuncion->findData(
            QString::fromStdString(
                funcion->codigo_sede
                )
            );

    ui->cmbEditSedeFuncion->setCurrentIndex(
        indiceSede
        );


    ui->txtEditHorario->setText(
        QString::fromStdString(
            funcion->horario
            )
        );

    ui->txtEditSala->setText(
        QString::fromStdString(
            funcion->sala
            )
        );

    ui->spinEditFilas->setValue(
        funcion->filas
        );

    ui->spinEditColumnas->setValue(
        funcion->columnas
        );

    QMessageBox::information(
        this,
        "Encontrada",
        "Función cargada para edición."
        );
}

void MainWindow::on_btnGuardarEdicionFuncion_clicked()
{
    QString codigo =
        ui->txtEditCodFuncion
            ->text()
            .trimmed();

    if (codigo.isEmpty()) {

        QMessageBox::warning(
            this,
            "Atención",
            "Seleccione una función para editar."
            );

        return;
    }


    NodoAVL* funcion =
        arbolFunciones->buscarFuncion(
            codigo
            );

    if (funcion == nullptr) {

        QMessageBox::warning(
            this,
            "Error",
            "La función ya no existe."
            );

        return;
    }


    QString codigoPelicula =
        ui->cmbEditPelicula
            ->currentData()
            .toString();

    Pelicula* pelicula =
        arbolCartelera->buscarPelicula(
            codigoPelicula
            );

    if (pelicula == nullptr) {

        QMessageBox::warning(
            this,
            "Película inválida",
            "Seleccione una película válida."
            );

        return;
    }


    QString codigoSede =
        ui->cmbEditSedeFuncion
            ->currentData()
            .toString();

    if (codigoSede.isEmpty() ||
        grafoSedes->buscarSede(
            codigoSede.toStdString()
            ) == nullptr) {

        QMessageBox::warning(
            this,
            "Sede inválida",
            "Seleccione una sede válida."
            );

        return;
    }


    QString fecha =
        ui->dateEditFechaFuncion
            ->date()
            .toString("yyyy-MM-dd");

    QString horario =
        ui->txtEditHorario
            ->text()
            .trimmed();

    QString sala =
        ui->txtEditSala
            ->text()
            .trimmed();

    int filas =
        ui->spinEditFilas->value();

    int columnas =
        ui->spinEditColumnas->value();


    if (horario.isEmpty() ||
        sala.isEmpty() ||
        filas <= 0 ||
        columnas <= 0) {

        QMessageBox::warning(
            this,
            "Datos inválidos",
            "Complete los datos de la función correctamente."
            );

        return;
    }


    funcion->codigo_pelicula =
        pelicula->titulo.toStdString();

    funcion->codigo_pelicula_real =
        pelicula->codigo.toStdString();

    funcion->fecha =
        fecha.toStdString();

    funcion->codigo_sede =
        codigoSede.toStdString();

    funcion->horario =
        horario.toStdString();

    funcion->sala =
        sala.toStdString();

    funcion->filas =
        filas;

    funcion->columnas =
        columnas;


    sincronizarGrafoConFunciones();

    arbolFunciones->poblarTablaUI(
        ui->tblFunciones
        );

    refrescarControlesE4();

    QMessageBox::information(
        this,
        "Éxito",
        "Función " +
            codigo +
            " actualizada correctamente."
        );
}

void MainWindow::on_btnEliminarFun_clicked()
{
    QString codigo = ui->txtEditCodFuncion->text();
    if (codigo.isEmpty()) {
        QMessageBox::warning(this, "Atención", "Seleccione la función que desea eliminar.");
        return;
    }

    QMessageBox::StandardButton resp = QMessageBox::question(this, "Eliminar",
                                                             "¿Seguro que deseas eliminar la función " + codigo + " y todos sus asientos?",
                                                             QMessageBox::Yes | QMessageBox::No);

    if (resp == QMessageBox::Yes) {

        // 1. ELIMINAR ARCHIVO FÍSICO JSON
        QString archivoJSON = codigo + "_funcion.json";
        QFile archivo(archivoJSON);
        if (archivo.exists()) {
            archivo.remove(); // Destruye el archivo del sistema
        }

        // 2. ELIMINAR DEL ÁRBOL AVL
        arbolFunciones->eliminar(codigo.toStdString());
        // Recalcular relaciones con el estado final del AVL.
        // Esto puede disminuir pesos o eliminar completamente una arista.
        sincronizarGrafoConFunciones();

        // 3. ACTUALIZAR INTERFAZ
        arbolFunciones->poblarTablaUI(ui->tblFunciones);
        refrescarControlesE4();
        // Limpiamos los inputs
        ui->txtEditCodFuncion->clear();

        ui->cmbEditPelicula->setCurrentIndex(-1);

        ui->dateEditFechaFuncion->setDate(
            QDate::currentDate()
            );

        ui->cmbEditSedeFuncion->setCurrentIndex(-1);

        ui->txtEditHorario->clear();
        ui->txtEditSala->clear();
        ui->txtBuscarCodFuncion->clear();

        QMessageBox::information(this, "Eliminada", "La función y su archivo de asientos han sido destruidos.");
    }
}

void MainWindow::on_btnActualizarFunciones_clicked()
{
    // Llama al Árbol AVL para que vuelva a pintar toda la tabla
    arbolFunciones->poblarTablaUI(ui->tblFunciones);
}

void MainWindow::on_btnEliminarCliente_clicked()
{
    QString dpi = ui->txtDpiEliminar->text().trimmed();

    if (dpi.isEmpty()) {
        QMessageBox::warning(this, "Atención", "Ingresa el DPI o ID del cliente a eliminar.");
        return;
    }

    // 1. Buscar al cliente ANTES de eliminarlo
    Cliente* cliente = arbolClientes->buscar(dpi.toStdString());
    if (cliente == nullptr) {
        QMessageBox::warning(this, "Error", "Cliente no encontrado en el sistema.");
        return;
    }

    QMessageBox::StandardButton resp = QMessageBox::question(this, "Alerta Crítica",
                                                             "¿Eliminar al cliente " + QString::fromStdString(cliente->nombre) + " y destruir TODAS sus reservas en cascada?",
                                                             QMessageBox::Yes | QMessageBox::No);

    if (resp == QMessageBox::Yes) {

        // 2. BAJA EN CASCADA (Matriz Dispersa y Tabla Hash)
        // Recorremos todos los códigos de reserva que tiene el cliente
        for (const std::string& codReserva : cliente->codigos_reservas) {

            Reserva* datosReserva = tablaReservas->buscar(codReserva);

            if (datosReserva != nullptr) {
                QString codFuncion = QString::fromStdString(datosReserva->codigo_funcion);
                QString archivoJSON = codFuncion + "_funcion.json";

                // Consultar dimensiones dinámicas al AVL
                NodoAVL* funcionActiva = arbolFunciones->buscarFuncion(codFuncion);
                int filas = (funcionActiva != nullptr) ? funcionActiva->filas : 10;
                int columnas = (funcionActiva != nullptr) ? funcionActiva->columnas : 20;

                // Cargar matriz, liberar asiento y guardar
                matrizSala->cargarDesdeArchivo(archivoJSON, filas, columnas);
                matrizSala->cancelarReserva(datosReserva->fila, datosReserva->columna, QString::fromStdString(codReserva));
                matrizSala->guardarEnArchivo(archivoJSON, codFuncion);

                // Eliminar de la Tabla Hash central
                tablaReservas->eliminar(codReserva);
            }
        }

        // 3. ELIMINACIÓN EN EL ÁRBOL B
        arbolClientes->eliminar(dpi.toStdString());

        // 4. ACTUALIZAR INTERFAZ
        // Si tienes un método para actualizar la tabla de clientes, llámalo aquí:
        // arbolClientes->poblarTablaClientes(ui->tblClientes);

        QMessageBox::information(this, "Éxito", "Cliente y reservas eliminados en cascada correctamente.");
        ui->txtDpiEliminar->clear();
    }
}

void MainWindow::on_btnReportePeliculas_clicked()
{
    // 1. Ejecutamos la generación del archivo físico
    arbolCartelera->generarReporteDOT();

    // 2. Cargamos el PNG generado
    QPixmap pixmap("reporte_cartelera.png");

    if (!pixmap.isNull()) {
        // Redimensionamos la imagen para que encaje perfectamente en el QLabel sin deformarse
        ui->lblVisorAdmin->setPixmap(pixmap.scaled(ui->lblVisorAdmin->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

        QMessageBox::information(this, "Reporte Generado", "El árbol de cartelera ha sido renderizado.");
    } else {
        QMessageBox::warning(this, "Error", "No se pudo cargar la imagen del reporte. Asegúrate de tener Graphviz instalado y en el PATH de Windows.");
    }
}

//Arreglar
void MainWindow::on_btnReporteFunciones_clicked()
{
    // 1. Limpiar el label por si acaso
    ui->lblVisorAdmin->clear();

    // 2. Ejecutar la generación del reporte
    arbolFunciones->generarReporteGraphviz(arbolCartelera);

    // 3. Cargar la imagen evadiendo la caché de Qt
    QImage imagen("reporte_avl.png");

    if (!imagen.isNull()) {
        ui->lblVisorAdmin->setPixmap(QPixmap::fromImage(imagen).scaled(ui->lblVisorAdmin->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    } else {
        // Si entra aquí, descubrimos al culpable: Graphviz está fallando
        QMessageBox::critical(this, "Error de Graphviz", "Graphviz falló al generar la imagen. Es muy probable que el JSON tenga caracteres especiales o espacios invisibles que rompen la sintaxis del archivo .dot.");
    }
}

void MainWindow::on_btnReporteClientes_clicked()
{
    // 1. Ejecutamos la generación del reporte del Árbol B
    arbolClientes->generarReporteGraphviz();

    // 2. Cargamos el PNG generado de los clientes
    QPixmap pixmap("reporte_clientes.png");

    if (!pixmap.isNull()) {
        // Reutilizamos el mismo visor del Administrador
        ui->lblVisorAdmin->setPixmap(pixmap.scaled(ui->lblVisorAdmin->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

        QMessageBox::information(this, "Reporte Generado", "El Árbol B de clientes ha sido renderizado.");
    } else {
        QMessageBox::warning(this, "Error", "No se pudo cargar la imagen del reporte de clientes. Asegúrate de que el árbol no esté vacío.");
    }
}

void MainWindow::on_btnReporteReservas_clicked()
{
    // 1. Ejecutamos la generación del reporte
    tablaReservas->generarReporteGraphviz();

    // 2. Cargamos el PNG generado de la Tabla Hash
    QPixmap pixmap("reporte_hash.png");

    if (!pixmap.isNull()) {

        // 3. Mostrar la imagen en su tamaño ORIGINAL
        ui->lblVisorHash->setPixmap(pixmap);

        // 4. El QLabel toma exactamente el tamaño de la imagen
        ui->lblVisorHash->setFixedSize(pixmap.size());

        // 5. Alinear el contenido desde la esquina superior izquierda
        ui->lblVisorHash->setAlignment(Qt::AlignTop | Qt::AlignLeft);

        // 6. Hacer que el contenido interno del ScrollArea
        // tenga como mínimo el tamaño del reporte
        ui->scrollAreaWidgetContents->setMinimumSize(pixmap.size());

        // 7. Mostrar las barras solamente cuando sean necesarias
        ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

        QMessageBox::information(
            this,
            "Reporte Generado",
            "El mapa de la Tabla Hash de reservas ha sido renderizado."
            );

    } else {
        QMessageBox::warning(
            this,
            "Error",
            "No se pudo cargar la imagen de la Tabla Hash."
            );
    }
}

void MainWindow::on_btnReporteMatriz_clicked()
{
    // 1. Verificar qué función está seleccionada en la UI
    QString codFuncion = ui->txtEditCodFuncion->text();

    if (codFuncion.isEmpty()) {
        QMessageBox::warning(this, "Atención", "Selecciona una función de la tabla primero.");
        return;
    }

    // 2. Extraer metadatos para el reporte
    NodoAVL* funcion =
        arbolFunciones->buscarFuncion(
            codFuncion
            );

    if (funcion == nullptr) {

        QMessageBox::warning(
            this,
            "Error",
            "La función seleccionada ya no existe."
            );

        return;
    }

    // 2. Extraer metadatos directamente de la función real
    QString pelicula =
        QString::fromStdString(
            funcion->codigo_pelicula
            );

    QString horario =
        QString::fromStdString(
            funcion->horario
            );

    QString sala =
        QString::fromStdString(
            funcion->sala
            );

    int filas =
        funcion->filas;

    int columnas =
        funcion->columnas;

    // 3. Cargar la matriz actualizada desde su JSON
    QString archivoJSON = codFuncion + "_funcion.json";
    matrizSala->cargarDesdeArchivo(archivoJSON, filas, columnas);

    // 4. Generar el reporte con Graphviz
    matrizSala->generarReporteDOT(pelicula, horario, sala);

    // 5. Cargar la imagen generada en el visor de la aplicación
    QPixmap pixmap("reporte_matriz.png");

    if (!pixmap.isNull()) {
        // Renderizamos y ajustamos la imagen al tamaño del lblVisorAdmin
        ui->lblVisorAdmin->setPixmap(pixmap.scaled(ui->lblVisorAdmin->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

        QMessageBox::information(this, "Reporte Generado", "El mapa de asientos de la función ha sido renderizado.");
    } else {
        QMessageBox::warning(this, "Error", "No se pudo cargar la imagen de la Matriz Dispersa.");
    }
}

void MainWindow::on_cmbRecorridosClientes_currentTextChanged(const QString &arg1)
{
    // Llamamos al método pasándole la tabla y el texto actual del combobox (arg1)
    arbolClientes->poblarTablaUI(ui->tblAdminClientes, arg1);
}

void MainWindow::cargarDatosPerfil()
{
    if (idUsuarioLogueado.isEmpty()) return;

    // Buscamos al usuario usando su ID de sesión
    Cliente* clienteActual = arbolClientes->buscar(idUsuarioLogueado.toStdString());

    if (clienteActual != nullptr) {
        // Llenamos los QLineEdit con los datos actuales
        ui->txtEditNombre->setText(QString::fromStdString(clienteActual->nombre));
        ui->txtEditCorreo->setText(QString::fromStdString(clienteActual->correo));
        ui->txtEditTelefono->setText(QString::fromStdString(clienteActual->telefono));
        ui->txtEditContrasena->setText(QString::fromStdString(clienteActual->password));
    }
}
void MainWindow::on_btnGuardarCambios_clicked()
{
    if (idUsuarioLogueado.isEmpty()) {
        QMessageBox::warning(this, "Error de Sesión", "Debes iniciar sesión para editar tu perfil.");
        return;
    }

    // 1. Capturar y limpiar los textos ingresados
    QString nuevoNombre = ui->txtEditNombre->text().trimmed();
    QString nuevoCorreo = ui->txtEditCorreo->text().trimmed();
    QString nuevoTelefono = ui->txtEditTelefono->text().trimmed();
    QString nuevaContrasena = ui->txtEditContrasena->text().trimmed();

    // 2. Validación básica de campos vacíos
    if (nuevoNombre.isEmpty() || nuevoCorreo.isEmpty() || nuevoTelefono.isEmpty() || nuevaContrasena.isEmpty()) {
        QMessageBox::warning(this, "Campos Vacíos", "Por favor, llena todos los campos para actualizar.");
        return;
    }

    // 3. Buscar el cliente en el Árbol B
    Cliente* clienteActual = arbolClientes->buscar(idUsuarioLogueado.toStdString());

    if (clienteActual != nullptr) {
        // 4. Actualizar los datos directamente en el puntero del árbol
        clienteActual->nombre = nuevoNombre.toStdString();
        clienteActual->correo = nuevoCorreo.toStdString();
        clienteActual->telefono = nuevoTelefono.toStdString();
        clienteActual->password = nuevaContrasena.toStdString();

        // (Opcional) Refrescar la tabla del administrador por si acaso la tiene abierta
        arbolClientes->poblarTablaUI(ui->tblAdminClientes);

        QMessageBox::information(this, "Perfil Actualizado", "Datos actualizados correctamente.");
    } else {
        QMessageBox::critical(this, "Error Fatal", "No se encontró tu usuario en la base de datos del Árbol B.");
    }
}


void MainWindow::on_cbOrdenFunciones_currentTextChanged(const QString &arg1)
{
    // Verificamos que el árbol de funciones exista antes de intentar pintarlo
    if (arbolFunciones != nullptr) {
        arbolFunciones->poblarTablaFuncionesUI(ui->tblFunciones, arg1);
    }
}

void MainWindow::on_cmbSedeReserva_currentIndexChanged(
    int index)
{
    Q_UNUSED(index);

    poblarFuncionesPorPeliculaYSede(
        ui->cbFuncionesDisponibles,
        ui->cbPeliculasDisponibles
            ->currentData()
            .toString(),
        ui->cmbSedeReserva
            ->currentData()
            .toString()
        );
}


void MainWindow::on_btnRegistrarSede_clicked()
{
    QString codigo =
        ui->txtCodigoSedeAdmin
            ->text()
            .trimmed();

    QString nombre =
        ui->txtNombreSedeAdmin
            ->text()
            .trimmed();

    QString direccion =
        ui->txtDireccionSedeAdmin
            ->text()
            .trimmed();

    QString telefono =
        ui->txtTelefonoSedeAdmin
            ->text()
            .trimmed();

    int cantidadSalas =
        ui->spinCantidadSalasSedeAdmin
            ->value();


    if (codigo.isEmpty() ||
        nombre.isEmpty() ||
        direccion.isEmpty() ||
        telefono.isEmpty() ||
        cantidadSalas <= 0) {

        QMessageBox::warning(
            this,
            "Datos incompletos",
            "Complete correctamente todos los datos de la sede."
            );

        return;
    }


    Sede nuevaSede(
        codigo.toStdString(),
        nombre.toStdString(),
        direccion.toStdString(),
        cantidadSalas,
        telefono.toStdString()
        );


    if (!grafoSedes->insertarSede(
            nuevaSede)) {

        QMessageBox::warning(
            this,
            "Sede duplicada",
            "Ya existe una sede con el código " +
                codigo +
                "."
            );

        return;
    }


    /*
     * No se recalcula el grafo:
     * registrar una sede crea un vértice aislado.
     */
    refrescarControlesE4();


    ui->txtCodigoSedeAdmin->clear();
    ui->txtNombreSedeAdmin->clear();
    ui->txtDireccionSedeAdmin->clear();
    ui->txtTelefonoSedeAdmin->clear();

    ui->spinCantidadSalasSedeAdmin
        ->setValue(1);


    QMessageBox::information(
        this,
        "Sede registrada",
        "La sede " +
            codigo +
            " fue registrada correctamente."
        );
}


void MainWindow::on_btnConsultarPeliculasSede_clicked()
{
    ui->tblPeliculasSedeAdmin
        ->setRowCount(0);

    QString codigoSede =
        ui->cmbSedePeliculasAdmin
            ->currentData()
            .toString();

    if (codigoSede.isEmpty()) {

        QMessageBox::warning(
            this,
            "Sede",
            "Seleccione una sede."
            );

        return;
    }


    struct ContextoPeliculasSede {
        std::string codigoSede;
        QStringList codigosPeliculas;
    };

    ContextoPeliculasSede contexto {
        codigoSede.toStdString(),
        QStringList()
    };


    auto visitarFuncion =
        [](const NodoAVL* funcion,
           void* datos) {

            if (funcion == nullptr ||
                datos == nullptr) {
                return;
            }

            ContextoPeliculasSede* contexto =
                static_cast<
                    ContextoPeliculasSede*
                    >(datos);

            if (
                funcion->codigo_sede !=
                    contexto->codigoSede ||
                funcion->codigo_pelicula_real
                    .empty()
                ) {
                return;
            }

            QString codigoPelicula =
                QString::fromStdString(
                    funcion
                        ->codigo_pelicula_real
                    );

            if (!contexto
                     ->codigosPeliculas
                     .contains(
                         codigoPelicula
                         )) {

                contexto
                    ->codigosPeliculas
                    .append(
                        codigoPelicula
                        );
            }
        };


    arbolFunciones->recorrerFunciones(
        visitarFuncion,
        &contexto
        );

    contexto.codigosPeliculas.sort();


    for (const QString& codigoPelicula :
         contexto.codigosPeliculas) {

        int fila =
            ui->tblPeliculasSedeAdmin
                ->rowCount();

        ui->tblPeliculasSedeAdmin
            ->insertRow(fila);


        Pelicula* pelicula =
            arbolCartelera
                ->buscarPelicula(
                    codigoPelicula
                    );


        ui->tblPeliculasSedeAdmin
            ->setItem(
                fila,
                0,
                new QTableWidgetItem(
                    codigoPelicula
                    )
                );


        QString titulo =
            pelicula != nullptr
                ? pelicula->titulo
                : "(sin datos en BST)";

        ui->tblPeliculasSedeAdmin
            ->setItem(
                fila,
                1,
                new QTableWidgetItem(
                    titulo
                    )
                );
    }


    if (contexto.codigosPeliculas.isEmpty()) {

        QMessageBox::information(
            this,
            "Sin películas",
            "La sede seleccionada no posee películas programadas."
            );
    }
}


void MainWindow::on_btnBuscarRutaSedes_clicked()
{
    QString origen =
        ui->cmbSedeOrigenBFS
            ->currentData()
            .toString();

    QString destino =
        ui->cmbSedeDestinoBFS
            ->currentData()
            .toString();


    if (origen.isEmpty() ||
        destino.isEmpty()) {

        QMessageBox::warning(
            this,
            "Ruta",
            "Seleccione origen y destino."
            );

        return;
    }


    ResultadoBFS resultado =
        grafoSedes->buscarCaminoBFS(
            origen.toStdString(),
            destino.toStdString()
            );


    if (!resultado.origenEncontrado ||
        !resultado.destinoEncontrado) {

        ui->lblResultadoBFS->setText(
            "Una de las sedes ya no existe."
            );

        return;
    }


    if (!resultado.existeCamino) {

        ui->lblResultadoBFS->setText(
            "No existe un camino entre " +
            origen +
            " y " +
            destino +
            "."
            );

        return;
    }


    QStringList ruta;

    for (const std::string& codigo :
         resultado.ruta) {

        ruta.append(
            QString::fromStdString(
                codigo
                )
            );
    }


    int saltos =
        ruta.isEmpty()
            ? 0
            : ruta.size() - 1;


    ui->lblResultadoBFS->setText(
        "Ruta: " +
        ruta.join(" → ") +
        "\nSaltos: " +
        QString::number(
            saltos
            )
        );
}


void MainWindow::on_btnActualizarRankingSedes_clicked()
{
    ui->tblRankingSedesAdmin
        ->setRowCount(0);

    std::vector<RelacionGrafo> ranking =
        grafoSedes
            ->obtenerRankingRelaciones();

    for (const RelacionGrafo& relacion :
         ranking) {

        int fila =
            ui->tblRankingSedesAdmin
                ->rowCount();

        ui->tblRankingSedesAdmin
            ->insertRow(fila);

        ui->tblRankingSedesAdmin
            ->setItem(
                fila,
                0,
                new QTableWidgetItem(
                    QString::fromStdString(
                        relacion.sedeA
                        )
                    )
                );

        ui->tblRankingSedesAdmin
            ->setItem(
                fila,
                1,
                new QTableWidgetItem(
                    QString::fromStdString(
                        relacion.sedeB
                        )
                    )
                );

        ui->tblRankingSedesAdmin
            ->setItem(
                fila,
                2,
                new QTableWidgetItem(
                    QString::number(
                        relacion.peso
                        )
                    )
                );
    }


    if (ranking.empty()) {

        QMessageBox::information(
            this,
            "Ranking",
            "Actualmente no existen relaciones entre sedes."
            );
    }
}


void MainWindow::on_btnConsultarSedesPeliculaCliente_clicked()
{
    ui->tblSedesPeliculaCliente
        ->setRowCount(0);

    QString codigoPelicula =
        ui->cmbPeliculaSedesCliente
            ->currentData()
            .toString();

    if (codigoPelicula.isEmpty()) {

        QMessageBox::warning(
            this,
            "Película",
            "Seleccione una película."
            );

        return;
    }


    const NodoGrafo* sede =
        grafoSedes
            ->obtenerPrimeraSede();

    int sedesEncontradas = 0;


    while (sede != nullptr) {

        struct ContextoDetalleSede {
            std::string codigoPelicula;
            std::string codigoSede;
            QStringList detalles;
        };


        ContextoDetalleSede contexto {
            codigoPelicula.toStdString(),
            sede->sede.codigo,
            QStringList()
        };


        auto visitarFuncion =
            [](const NodoAVL* funcion,
               void* datos) {

                if (funcion == nullptr ||
                    datos == nullptr) {
                    return;
                }

                ContextoDetalleSede* contexto =
                    static_cast<
                        ContextoDetalleSede*
                        >(datos);

                if (
                    funcion->codigo_pelicula_real !=
                        contexto->codigoPelicula ||
                    funcion->codigo_sede !=
                        contexto->codigoSede
                    ) {
                    return;
                }


                QString detalle =
                    QString::fromStdString(
                        funcion->codigo_funcion
                        ) +
                    " | " +
                    QString::fromStdString(
                        funcion->fecha
                        ) +
                    " | " +
                    QString::fromStdString(
                        funcion->horario
                        ) +
                    " | " +
                    QString::fromStdString(
                        funcion->sala
                        );

                contexto
                    ->detalles
                    .append(
                        detalle
                        );
            };


        arbolFunciones->recorrerFunciones(
            visitarFuncion,
            &contexto
            );


        if (!contexto.detalles.isEmpty()) {

            int fila =
                ui->tblSedesPeliculaCliente
                    ->rowCount();

            ui->tblSedesPeliculaCliente
                ->insertRow(fila);

            ui->tblSedesPeliculaCliente
                ->setItem(
                    fila,
                    0,
                    new QTableWidgetItem(
                        QString::fromStdString(
                            sede->sede.codigo
                            )
                        )
                    );

            ui->tblSedesPeliculaCliente
                ->setItem(
                    fila,
                    1,
                    new QTableWidgetItem(
                        QString::fromStdString(
                            sede->sede.nombre
                            )
                        )
                    );

            ui->tblSedesPeliculaCliente
                ->setItem(
                    fila,
                    2,
                    new QTableWidgetItem(
                        contexto
                            .detalles
                            .join(" ; ")
                        )
                    );

            sedesEncontradas++;
        }


        sede =
            sede->siguiente;
    }


    if (sedesEncontradas == 0) {

        QMessageBox::information(
            this,
            "Disponibilidad",
            "La película seleccionada no tiene funciones programadas."
            );
    }
}


void MainWindow::on_cmbPeliculaFuncionesCliente_currentIndexChanged(
    int index)
{
    Q_UNUSED(index);

    poblarSedesPorPelicula(
        ui->cmbSedeFuncionesCliente,
        ui->cmbPeliculaFuncionesCliente
            ->currentData()
            .toString()
        );

    ui->tblFuncionesClienteGrafo
        ->setRowCount(0);
}


void MainWindow::on_btnConsultarFuncionesCliente_clicked()
{
    ui->tblFuncionesClienteGrafo
        ->setRowCount(0);

    QString codigoPelicula =
        ui->cmbPeliculaFuncionesCliente
            ->currentData()
            .toString();

    QString codigoSede =
        ui->cmbSedeFuncionesCliente
            ->currentData()
            .toString();


    if (codigoPelicula.isEmpty() ||
        codigoSede.isEmpty()) {

        QMessageBox::warning(
            this,
            "Consulta",
            "Seleccione una película y una sede válidas."
            );

        return;
    }


    struct ContextoTablaFunciones {
        std::string codigoPelicula;
        std::string codigoSede;
        QTableWidget* tabla;
        int cantidad;
    };


    ContextoTablaFunciones contexto {
        codigoPelicula.toStdString(),
        codigoSede.toStdString(),
        ui->tblFuncionesClienteGrafo,
        0
    };


    auto visitarFuncion =
        [](const NodoAVL* funcion,
           void* datos) {

            if (funcion == nullptr ||
                datos == nullptr) {
                return;
            }


            ContextoTablaFunciones* contexto =
                static_cast<
                    ContextoTablaFunciones*
                    >(datos);


            if (
                funcion->codigo_pelicula_real !=
                    contexto->codigoPelicula ||
                funcion->codigo_sede !=
                    contexto->codigoSede
                ) {
                return;
            }


            int fila =
                contexto->tabla
                    ->rowCount();

            contexto->tabla
                ->insertRow(fila);


            contexto->tabla->setItem(
                fila,
                0,
                new QTableWidgetItem(
                    QString::fromStdString(
                        funcion->codigo_funcion
                        )
                    )
                );

            contexto->tabla->setItem(
                fila,
                1,
                new QTableWidgetItem(
                    QString::fromStdString(
                        funcion->fecha
                        )
                    )
                );

            contexto->tabla->setItem(
                fila,
                2,
                new QTableWidgetItem(
                    QString::fromStdString(
                        funcion->horario
                        )
                    )
                );

            contexto->tabla->setItem(
                fila,
                3,
                new QTableWidgetItem(
                    QString::fromStdString(
                        funcion->sala
                        )
                    )
                );


            contexto->cantidad++;
        };


    arbolFunciones->recorrerFunciones(
        visitarFuncion,
        &contexto
        );


    if (contexto.cantidad == 0) {

        QMessageBox::information(
            this,
            "Funciones",
            "No existen funciones para esa combinación de película y sede."
            );
    }
}


void MainWindow::on_btnConsultarSedesSimilaresCliente_clicked()
{
    ui->tblSedesSimilaresCliente
        ->setRowCount(0);

    QString codigoSede =
        ui->cmbSedeSimilarCliente
            ->currentData()
            .toString();


    if (codigoSede.isEmpty()) {

        QMessageBox::warning(
            this,
            "Sede",
            "Seleccione una sede."
            );

        return;
    }


    std::vector<SedeSimilar> similares =
        grafoSedes->obtenerSedesSimilares(
            codigoSede.toStdString()
            );


    for (const SedeSimilar& similar :
         similares) {

        int fila =
            ui->tblSedesSimilaresCliente
                ->rowCount();

        ui->tblSedesSimilaresCliente
            ->insertRow(fila);


        ui->tblSedesSimilaresCliente
            ->setItem(
                fila,
                0,
                new QTableWidgetItem(
                    QString::fromStdString(
                        similar.sede.codigo
                        )
                    )
                );

        ui->tblSedesSimilaresCliente
            ->setItem(
                fila,
                1,
                new QTableWidgetItem(
                    QString::fromStdString(
                        similar.sede.nombre
                        )
                    )
                );

        ui->tblSedesSimilaresCliente
            ->setItem(
                fila,
                2,
                new QTableWidgetItem(
                    QString::number(
                        similar.peso
                        )
                    )
                );
    }


    if (similares.empty()) {

        QMessageBox::information(
            this,
            "Sedes similares",
            "La sede seleccionada no posee sedes adyacentes."
            );
    }
}


void MainWindow::on_btnReporteGrafoSedes_clicked()
{
    ui->lblVisorAdmin->clear();

    if (!grafoSedes
             ->generarReporteGrafoGraphviz()) {

        QMessageBox::warning(
            this,
            "Graphviz",
            "No se pudo generar el reporte del grafo de sedes."
            );

        return;
    }


    QImage imagen(
        "reporte_grafo_sedes.png"
        );


    if (imagen.isNull()) {

        QMessageBox::warning(
            this,
            "Reporte",
            "No se pudo cargar reporte_grafo_sedes.png."
            );

        return;
    }


    ui->lblVisorAdmin->setPixmap(
        QPixmap::fromImage(imagen)
            .scaled(
                ui->lblVisorAdmin->size(),
                Qt::KeepAspectRatio,
                Qt::SmoothTransformation
                )
        );


    QMessageBox::information(
        this,
        "Reporte Generado",
        "El grafo de sedes ha sido renderizado."
        );
}


void MainWindow::on_btnReporteListaAdyacencia_clicked()
{
    ui->lblVisorAdmin->clear();

    if (!grafoSedes
             ->generarReporteListaAdyacenciaGraphviz()) {

        QMessageBox::warning(
            this,
            "Graphviz",
            "No se pudo generar el reporte de la lista de adyacencia."
            );

        return;
    }


    QImage imagen(
        "reporte_lista_adyacencia.png"
        );


    if (imagen.isNull()) {

        QMessageBox::warning(
            this,
            "Reporte",
            "No se pudo cargar reporte_lista_adyacencia.png."
            );

        return;
    }


    ui->lblVisorAdmin->setPixmap(
        QPixmap::fromImage(imagen)
            .scaled(
                ui->lblVisorAdmin->size(),
                Qt::KeepAspectRatio,
                Qt::SmoothTransformation
                )
        );


    QMessageBox::information(
        this,
        "Reporte Generado",
        "La lista de adyacencia ha sido renderizada."
        );
}

