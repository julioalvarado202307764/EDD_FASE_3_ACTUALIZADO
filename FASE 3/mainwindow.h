#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ArbolPeliculas.h" // Incluimos nuestro Árbol
#include "ListaSolicitudes.h"
#include "MatrizDispersa.h"
#include "ListaPromociones.h"
#include "ArbolAVL.h"
#include "ArbolB.h"
#include "TablaHash.h"
#include "GrafoSedes.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_btnCrearFuncion_clicked();

    void on_btnIniciarSesion_clicked();

    void on_btnReservar_clicked();

    void on_btnCerrarSesionUsuario_clicked();

    void on_btnCerrarSesionAdmin_clicked();

    void on_btnEnviarSolicitud_clicked();

    void on_btnProcesarPrimera_clicked();

    void on_btnAprobarSolicitud_clicked();

    void on_btnRechazarSolicitud_clicked();

    void on_comboTipoBeneficio_activated(int index);

    void on_btnReportePromos_clicked();

    void on_btnCrearPromo_clicked();

    void on_btnCancelarReserva_clicked();

    void on_btnBuscarPelicula_clicked();

    void on_btnAlertas_clicked();

    void on_btnEnProceso_clicked();

    void on_btnBuscarSolicitud_clicked();

    void on_btnReporteSolicitudes_clicked();

    void on_btnCargaMasivaClientes_clicked();

    void cargarCargaMasivaClientes(QString rutaArchivo);

    void on_btnBuscarIdCliente_clicked();

    void on_btnRegistrar_clicked();

    void on_btnActualizarTabla_clicked();

    void on_cbPeliculasDisponibles_currentTextChanged(const QString &arg1);

    void on_btnVerDisponibilidad_clicked();

    void on_btnActualizarHistorial_clicked();

    void on_btnCargarPeliculasJSON_clicked();

    void on_tablaCartelera_cellClicked(int row, int column);

    void on_btnAgregarPelicula_clicked();

    void on_btnEditarPelicula_clicked();

    void on_btnEliminarPelicula_clicked();

    void on_cbOrdenPeliculas_currentTextChanged(const QString &arg1);

    void on_tblFunciones_cellClicked(int row, int column);

    void on_btnBuscarFuncion_clicked();

    void on_btnGuardarEdicionFuncion_clicked();

    void on_btnEliminarFun_clicked();


    void on_btnActualizarFunciones_clicked();

    void on_btnEliminarCliente_clicked();

    void on_btnReportePeliculas_clicked();

    void on_btnReporteFunciones_clicked();

    void on_btnReporteClientes_clicked();

    void on_btnReporteReservas_clicked();

    void on_btnReporteMatriz_clicked();

    void on_cmbRecorridosClientes_currentTextChanged(const QString &arg1);

    void on_btnGuardarCambios_clicked();

    void on_cbOrdenFunciones_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;

    // Tu árbol principal de la cartelera
    ArbolPeliculas* arbolCartelera;
    ListaSolicitudes* listaSolicitudes;
    MatrizDispersa* matrizSala;
    ListaPromociones* listaPromos;
    //FASE 2
    ArbolAVL* arbolFunciones;
    ArbolB* arbolClientes;
    TablaHash* tablaReservas;
    // FASE 3
    GrafoSedes* grafoSedes;

    QString idUsuarioLogueado;
    int contadorGlobalFunciones;
    int idSolicitudEnProceso = -1;
    QString salaActiva = "";
    QString peliculaActiva = "";
    void cargarDatosPerfil();
    void sincronizarGrafoConFunciones();

};

#endif // MAINWINDOW_H
