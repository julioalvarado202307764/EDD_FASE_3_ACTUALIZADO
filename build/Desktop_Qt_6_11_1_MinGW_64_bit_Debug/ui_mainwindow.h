/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *pageLogin;
    QTabWidget *tabWidget_2;
    QWidget *tab_11;
    QPushButton *btnIniciarSesion;
    QLineEdit *txtPassword;
    QLabel *label_2;
    QLineEdit *txtCorreo;
    QLabel *label;
    QLabel *label_26;
    QLabel *label_3;
    QWidget *tab_12;
    QLabel *label_37;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_33;
    QLineEdit *txtRegNombre;
    QLabel *label_34;
    QLineEdit *txtRegCorreo;
    QLabel *label_35;
    QLineEdit *txtRegTelefono;
    QLabel *label_36;
    QLineEdit *txtRegPass;
    QPushButton *btnRegistrar;
    QWidget *pageAdmin;
    QPushButton *btnCerrarSesionAdmin;
    QTabWidget *tabWidgetAdmin;
    QWidget *tab_3;
    QTableWidget *tablaCartelera;
    QPushButton *btnCargarPeliculasJSON;
    QPushButton *btnAlertas;
    QComboBox *cbOrdenPeliculas;
    QWidget *formLayoutWidget_3;
    QFormLayout *formLayout_3;
    QLabel *label_41;
    QLineEdit *txtCodPelicula;
    QLabel *label_45;
    QLineEdit *txtTitulo;
    QLabel *label_46;
    QLineEdit *txtGenero;
    QLabel *label_47;
    QLineEdit *txtDuracion;
    QLabel *label_48;
    QLineEdit *txtClasificacion;
    QLabel *label_49;
    QLineEdit *txtIdioma;
    QLabel *label_50;
    QLineEdit *txtEstreno;
    QLabel *label_51;
    QLineEdit *txtFin;
    QLabel *label_27;
    QPushButton *btnAgregarPelicula;
    QPushButton *btnEditarPelicula;
    QPushButton *btnEliminarPelicula;
    QWidget *tab_13;
    QTableWidget *tblAdminClientes;
    QLabel *label_53;
    QLabel *label_67;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_38;
    QLineEdit *txtBuscarIdCliente;
    QPushButton *btnBuscarIdCliente;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btnCargaMasivaClientes;
    QPushButton *btnActualizarTabla;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_68;
    QLineEdit *txtDpiEliminar;
    QPushButton *btnEliminarCliente;
    QWidget *tab_10;
    QPushButton *btnCrearFuncion;
    QLabel *label_32;
    QLabel *label_65;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *label_9;
    QComboBox *comboPeliculas;
    QLabel *label_66;
    QComboBox *comboSala;
    QLabel *label_8;
    QLineEdit *txtHorario;
    QLabel *label_6;
    QSpinBox *spinFilas;
    QLabel *label_7;
    QSpinBox *spinColumnas;
    QWidget *tab_14;
    QLabel *label_56;
    QTableWidget *tblFunciones;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_57;
    QLineEdit *txtBuscarCodFuncion;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_58;
    QLineEdit *txtEditCodFuncion;
    QLabel *label_59;
    QLineEdit *txtEditPelicula;
    QLabel *label_60;
    QLineEdit *txtEditHorario;
    QLabel *label_61;
    QLineEdit *txtEditSala;
    QLabel *label_62;
    QSpinBox *spinEditFilas;
    QLabel *label_63;
    QSpinBox *spinEditColumnas;
    QPushButton *btnBuscarFuncion;
    QPushButton *btnActualizarFunciones;
    QLabel *label_64;
    QPushButton *btnGuardarEdicionFuncion;
    QPushButton *btnEliminarFun;
    QComboBox *cbOrdenFunciones;
    QLabel *label_74;
    QWidget *tab_7;
    QLabel *label_69;
    QLabel *lblVisorAdmin;
    QWidget *horizontalLayoutWidget_7;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *btnReportePeliculas;
    QPushButton *btnReporteFunciones;
    QPushButton *btnReporteClientes;
    QPushButton *btnReporteMatriz;
    QWidget *tab_17;
    QPushButton *btnReporteReservas;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *lblVisorHash;
    QLabel *label_73;
    QWidget *tab_4;
    QTableWidget *tablaAdminSolicitudes;
    QLabel *lblDetalleSolicitud;
    QPushButton *btnProcesarPrimera;
    QPushButton *btnAprobarSolicitud;
    QPushButton *btnRechazarSolicitud;
    QPushButton *btnEnProceso;
    QPushButton *btnReporteSolicitudes;
    QLabel *label_31;
    QComboBox *cmbRecorridosClientes;
    QLabel *label_43;
    QLabel *label_75;
    QWidget *tab_5;
    QLineEdit *txtCodigoPromo;
    QLineEdit *txtNombrePromo;
    QLineEdit *txtDiasPromo;
    QLineEdit *txtVigenciaPromo;
    QPushButton *btnCrearPromo;
    QLabel *label_4;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLineEdit *txtCodigoAsignar;
    QLabel *label_20;
    QComboBox *comboTipoBeneficio;
    QLineEdit *txtDescBeneficio;
    QLineEdit *txtValorBeneficio;
    QLabel *label_21;
    QLabel *label_22;
    QPushButton *pushButton_2;
    QPushButton *btnReportePromos;
    QLabel *label_23;
    QWidget *pageUsuario;
    QPushButton *btnCerrarSesionUsuario;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableWidget *tablaTaquilla;
    QLabel *label_28;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_24;
    QLineEdit *txtBuscarCodigo;
    QPushButton *btnBuscarPelicula;
    QLabel *label_42;
    QWidget *tab_9;
    QLabel *label_29;
    QTableWidget *tblMapaAsientos;
    QPushButton *btnVerDisponibilidad;
    QWidget *formLayoutWidget_4;
    QFormLayout *formLayout_4;
    QLabel *label_30;
    QComboBox *cbPeliculasDisponibles;
    QLabel *label_10;
    QComboBox *cbFuncionesDisponibles;
    QLabel *label_12;
    QSpinBox *spinReservaFila;
    QLabel *label_13;
    QSpinBox *spinReservaColumna;
    QPushButton *btnReservar;
    QLabel *label_52;
    QWidget *tab_15;
    QTableWidget *tblMisReservas;
    QLabel *label_40;
    QPushButton *btnActualizarHistorial;
    QLabel *label_55;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_39;
    QLineEdit *txtCodigoCancelar;
    QPushButton *btnCancelarReserva;
    QWidget *tab_16;
    QPushButton *btnGuardarCambios;
    QLabel *label_44;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_54;
    QLineEdit *txtEditNombre;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_71;
    QLineEdit *txtEditCorreo;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_70;
    QLineEdit *txtEditTelefono;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_72;
    QLineEdit *txtEditContrasena;
    QWidget *tab_2;
    QLineEdit *txtTelefono;
    QLabel *label_5;
    QComboBox *comboTipoSolicitud;
    QTextEdit *txtDescripcion;
    QPushButton *btnEnviarSolicitud;
    QLabel *label_11;
    QLineEdit *txtNombreSolicitud;
    QLabel *label_14;
    QLabel *label_15;
    QLineEdit *txtBuscarTelefonoSolicitud;
    QLabel *label_25;
    QPushButton *btnBuscarSolicitud;
    QWidget *tab_6;
    QTreeWidget *arbolPromos;
    QWidget *tab_8;
    QLabel *lblVisorUsuario;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(863, 745);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        pageLogin = new QWidget();
        pageLogin->setObjectName("pageLogin");
        tabWidget_2 = new QTabWidget(pageLogin);
        tabWidget_2->setObjectName("tabWidget_2");
        tabWidget_2->setGeometry(QRect(0, 0, 851, 671));
        tabWidget_2->setStyleSheet(QString::fromUtf8("QTabBar::tab:selected {\n"
"    background-color: #2c3e50;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}"));
        tab_11 = new QWidget();
        tab_11->setObjectName("tab_11");
        btnIniciarSesion = new QPushButton(tab_11);
        btnIniciarSesion->setObjectName("btnIniciarSesion");
        btnIniciarSesion->setGeometry(QRect(280, 500, 301, 41));
        btnIniciarSesion->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #8A2BE2;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 6px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #0f5091; \n"
"}"));
        txtPassword = new QLineEdit(tab_11);
        txtPassword->setObjectName("txtPassword");
        txtPassword->setGeometry(QRect(280, 440, 301, 41));
        txtPassword->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #2b2b2b;\n"
"    border: 1px solid #3d3d3d;\n"
"    border-radius: 5px;\n"
"    color: #ffffff;\n"
"    padding: 6px 10px;\n"
"    font-size: 13px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 1px solid #1E90FF;\n"
"}"));
        txtPassword->setEchoMode(QLineEdit::EchoMode::Password);
        label_2 = new QLabel(tab_11);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(280, 400, 121, 31));
        QFont font;
        font.setPointSize(16);
        label_2->setFont(font);
        txtCorreo = new QLineEdit(tab_11);
        txtCorreo->setObjectName("txtCorreo");
        txtCorreo->setGeometry(QRect(280, 350, 301, 41));
        txtCorreo->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #2b2b2b;\n"
"    border: 1px solid #3d3d3d;\n"
"    border-radius: 5px;\n"
"    color: #ffffff;\n"
"    padding: 6px 10px;\n"
"    font-size: 13px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 1px solid #1E90FF;\n"
"}"));
        label = new QLabel(tab_11);
        label->setObjectName("label");
        label->setGeometry(QRect(280, 310, 71, 31));
        label->setFont(font);
        label_26 = new QLabel(tab_11);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(320, 120, 211, 191));
        label_26->setPixmap(QPixmap(QString::fromUtf8(":/imgRegistro.png")));
        label_26->setScaledContents(true);
        label_3 = new QLabel(tab_11);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(280, 30, 281, 81));
        QFont font1;
        font1.setPointSize(36);
        label_3->setFont(font1);
        tabWidget_2->addTab(tab_11, QString());
        tab_12 = new QWidget();
        tab_12->setObjectName("tab_12");
        label_37 = new QLabel(tab_12);
        label_37->setObjectName("label_37");
        label_37->setGeometry(QRect(330, 10, 191, 181));
        label_37->setPixmap(QPixmap(QString::fromUtf8(":/imgRegistro.png")));
        label_37->setScaledContents(true);
        verticalLayoutWidget = new QWidget(tab_12);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(240, 150, 361, 401));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_33 = new QLabel(verticalLayoutWidget);
        label_33->setObjectName("label_33");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Segoe UI")});
        font2.setPointSize(16);
        label_33->setFont(font2);
        label_33->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #f0f0f0; /* Un blanco/gris muy claro para no cansar la vista */\n"
"    font-family: \"Segoe UI\", Helvetica, Arial, sans-serif; /* Tipograf\303\255a moderna y limpia */\n"
"    font-size: 13px; /* Tama\303\261o est\303\241ndar legible */\n"
"    background-color: transparent; /* Transparente para que se vea tu fondo oscuro */\n"
"    border: none;\n"
"font-size: 16pt;\n"
"}"));

        verticalLayout_2->addWidget(label_33);

        txtRegNombre = new QLineEdit(verticalLayoutWidget);
        txtRegNombre->setObjectName("txtRegNombre");
        txtRegNombre->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #2b2b2b;\n"
"    border: 1px solid #3d3d3d;\n"
"    border-radius: 5px;\n"
"    color: #ffffff;\n"
"    padding: 6px 10px;\n"
"    font-size: 13px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 1px solid #1E90FF;\n"
"}"));

        verticalLayout_2->addWidget(txtRegNombre);

        label_34 = new QLabel(verticalLayoutWidget);
        label_34->setObjectName("label_34");
        label_34->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #f0f0f0; /* Un blanco/gris muy claro para no cansar la vista */\n"
"    font-family: \"Segoe UI\", Helvetica, Arial, sans-serif; /* Tipograf\303\255a moderna y limpia */\n"
"    font-size: 13px; /* Tama\303\261o est\303\241ndar legible */\n"
"    background-color: transparent; /* Transparente para que se vea tu fondo oscuro */\n"
"    border: none;\n"
"font-size: 16pt;\n"
"}"));

        verticalLayout_2->addWidget(label_34);

        txtRegCorreo = new QLineEdit(verticalLayoutWidget);
        txtRegCorreo->setObjectName("txtRegCorreo");
        txtRegCorreo->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #2b2b2b;\n"
"    border: 1px solid #3d3d3d;\n"
"    border-radius: 5px;\n"
"    color: #ffffff;\n"
"    padding: 6px 10px;\n"
"    font-size: 13px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 1px solid #1E90FF;\n"
"}"));

        verticalLayout_2->addWidget(txtRegCorreo);

        label_35 = new QLabel(verticalLayoutWidget);
        label_35->setObjectName("label_35");
        label_35->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #f0f0f0; /* Un blanco/gris muy claro para no cansar la vista */\n"
"    font-family: \"Segoe UI\", Helvetica, Arial, sans-serif; /* Tipograf\303\255a moderna y limpia */\n"
"    font-size: 13px; /* Tama\303\261o est\303\241ndar legible */\n"
"    background-color: transparent; /* Transparente para que se vea tu fondo oscuro */\n"
"    border: none;\n"
"font-size: 16pt;\n"
"}"));

        verticalLayout_2->addWidget(label_35);

        txtRegTelefono = new QLineEdit(verticalLayoutWidget);
        txtRegTelefono->setObjectName("txtRegTelefono");
        txtRegTelefono->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #2b2b2b;\n"
"    border: 1px solid #3d3d3d;\n"
"    border-radius: 5px;\n"
"    color: #ffffff;\n"
"    padding: 6px 10px;\n"
"    font-size: 13px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 1px solid #1E90FF;\n"
"}"));

        verticalLayout_2->addWidget(txtRegTelefono);

        label_36 = new QLabel(verticalLayoutWidget);
        label_36->setObjectName("label_36");
        label_36->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #f0f0f0; /* Un blanco/gris muy claro para no cansar la vista */\n"
"    font-family: \"Segoe UI\", Helvetica, Arial, sans-serif; /* Tipograf\303\255a moderna y limpia */\n"
"    font-size: 13px; /* Tama\303\261o est\303\241ndar legible */\n"
"    background-color: transparent; /* Transparente para que se vea tu fondo oscuro */\n"
"    border: none;\n"
"font-size: 16pt;\n"
"}"));

        verticalLayout_2->addWidget(label_36);

        txtRegPass = new QLineEdit(verticalLayoutWidget);
        txtRegPass->setObjectName("txtRegPass");
        txtRegPass->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #2b2b2b;\n"
"    border: 1px solid #3d3d3d;\n"
"    border-radius: 5px;\n"
"    color: #ffffff;\n"
"    padding: 6px 10px;\n"
"    font-size: 13px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 1px solid #1E90FF;\n"
"}"));
        txtRegPass->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout_2->addWidget(txtRegPass);

        btnRegistrar = new QPushButton(tab_12);
        btnRegistrar->setObjectName("btnRegistrar");
        btnRegistrar->setGeometry(QRect(240, 560, 359, 41));
        btnRegistrar->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #8A2BE2;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 6px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #0f5091; \n"
"}"));
        tabWidget_2->addTab(tab_12, QString());
        stackedWidget->addWidget(pageLogin);
        pageAdmin = new QWidget();
        pageAdmin->setObjectName("pageAdmin");
        btnCerrarSesionAdmin = new QPushButton(pageAdmin);
        btnCerrarSesionAdmin->setObjectName("btnCerrarSesionAdmin");
        btnCerrarSesionAdmin->setGeometry(QRect(710, 670, 131, 31));
        btnCerrarSesionAdmin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #c0392b;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 6px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #e74c3c; \n"
"}"));
        tabWidgetAdmin = new QTabWidget(pageAdmin);
        tabWidgetAdmin->setObjectName("tabWidgetAdmin");
        tabWidgetAdmin->setGeometry(QRect(0, 0, 851, 651));
        tabWidgetAdmin->setStyleSheet(QString::fromUtf8("QTabBar::tab:selected {\n"
"    background-color: #2c3e50;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}"));
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        tablaCartelera = new QTableWidget(tab_3);
        if (tablaCartelera->columnCount() < 8)
            tablaCartelera->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tablaCartelera->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tablaCartelera->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tablaCartelera->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tablaCartelera->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tablaCartelera->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tablaCartelera->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tablaCartelera->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tablaCartelera->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        tablaCartelera->setObjectName("tablaCartelera");
        tablaCartelera->setGeometry(QRect(10, 320, 811, 281));
        tablaCartelera->horizontalHeader()->setStretchLastSection(true);
        btnCargarPeliculasJSON = new QPushButton(tab_3);
        btnCargarPeliculasJSON->setObjectName("btnCargarPeliculasJSON");
        btnCargarPeliculasJSON->setGeometry(QRect(620, 280, 201, 31));
        btnCargarPeliculasJSON->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #76529D;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 6px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #e67e22; \n"
"}"));
        btnAlertas = new QPushButton(tab_3);
        btnAlertas->setObjectName("btnAlertas");
        btnAlertas->setGeometry(QRect(620, 240, 201, 31));
        btnAlertas->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #9D7AC7;\n"
"    color: white; /* Texto negro para que se lea bien sobre el amarillo */\n"
"    border-radius: 5px;\n"
"    padding: 6px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #f1c40f; \n"
"}"));
        cbOrdenPeliculas = new QComboBox(tab_3);
        cbOrdenPeliculas->addItem(QString());
        cbOrdenPeliculas->addItem(QString());
        cbOrdenPeliculas->addItem(QString());
        cbOrdenPeliculas->setObjectName("cbOrdenPeliculas");
        cbOrdenPeliculas->setGeometry(QRect(620, 200, 201, 31));
        cbOrdenPeliculas->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #2b2b2b; /* Fondo gris oscuro */\n"
"    color: white;              /* Texto blanco */\n"
"    border: 1px solid #555555; /* Borde gris sutil */\n"
"    border-radius: 4px;        /* Bordes ligeramente redondeados */\n"
"    padding: 5px;              /* Espacio interno para que el texto respire */\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    border: 1px solid #888888; /* El borde se ilumina un poco al pasar el rat\303\263n */\n"
"}\n"
"\n"
"/* Estilo de la lista que se abre hacia abajo */\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #2b2b2b; \n"
"    color: white;              \n"
"    selection-background-color: #0984e3; /* Fondo azul (mismo del bot\303\263n) al seleccionar */\n"
"    selection-color: white;\n"
"}"));
        formLayoutWidget_3 = new QWidget(tab_3);
        formLayoutWidget_3->setObjectName("formLayoutWidget_3");
        formLayoutWidget_3->setGeometry(QRect(60, 20, 291, 291));
        formLayout_3 = new QFormLayout(formLayoutWidget_3);
        formLayout_3->setObjectName("formLayout_3");
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        label_41 = new QLabel(formLayoutWidget_3);
        label_41->setObjectName("label_41");
        label_41->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #f0f0f0; /* Un blanco/gris muy claro para no cansar la vista */\n"
"    font-family: \"Segoe UI\", Helvetica, Arial, sans-serif; /* Tipograf\303\255a moderna y limpia */\n"
"    font-size: 13px; /* Tama\303\261o est\303\241ndar legible */\n"
"    background-color: transparent; /* Transparente para que se vea tu fondo oscuro */\n"
"    border: none;\n"
"}"));

        formLayout_3->setWidget(0, QFormLayout::ItemRole::LabelRole, label_41);

        txtCodPelicula = new QLineEdit(formLayoutWidget_3);
        txtCodPelicula->setObjectName("txtCodPelicula");
        txtCodPelicula->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #2b2b2b;\n"
"    color: white;\n"
"    border: 1px solid #555555;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* Efecto cuando haces clic para escribir adentro */\n"
"QLineEdit:focus {\n"
"    border: 1px solid #0984e3; /* El borde se pone azul para indicar que est\303\241 activo */\n"
"    background-color: #333333; /* El fondo se aclara un poco */\n"
"}"));

        formLayout_3->setWidget(0, QFormLayout::ItemRole::FieldRole, txtCodPelicula);

        label_45 = new QLabel(formLayoutWidget_3);
        label_45->setObjectName("label_45");
        label_45->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #f0f0f0; /* Un blanco/gris muy claro para no cansar la vista */\n"
"    font-family: \"Segoe UI\", Helvetica, Arial, sans-serif; /* Tipograf\303\255a moderna y limpia */\n"
"    font-size: 13px; /* Tama\303\261o est\303\241ndar legible */\n"
"    background-color: transparent; /* Transparente para que se vea tu fondo oscuro */\n"
"    border: none;\n"
"}"));

        formLayout_3->setWidget(1, QFormLayout::ItemRole::LabelRole, label_45);

        txtTitulo = new QLineEdit(formLayoutWidget_3);
        txtTitulo->setObjectName("txtTitulo");
        txtTitulo->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #2b2b2b;\n"
"    color: white;\n"
"    border: 1px solid #555555;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* Efecto cuando haces clic para escribir adentro */\n"
"QLineEdit:focus {\n"
"    border: 1px solid #0984e3; /* El borde se pone azul para indicar que est\303\241 activo */\n"
"    background-color: #333333; /* El fondo se aclara un poco */\n"
"}"));

        formLayout_3->setWidget(1, QFormLayout::ItemRole::FieldRole, txtTitulo);

        label_46 = new QLabel(formLayoutWidget_3);
        label_46->setObjectName("label_46");
        label_46->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #f0f0f0; /* Un blanco/gris muy claro para no cansar la vista */\n"
"    font-family: \"Segoe UI\", Helvetica, Arial, sans-serif; /* Tipograf\303\255a moderna y limpia */\n"
"    font-size: 13px; /* Tama\303\261o est\303\241ndar legible */\n"
"    background-color: transparent; /* Transparente para que se vea tu fondo oscuro */\n"
"    border: none;\n"
"}"));

        formLayout_3->setWidget(2, QFormLayout::ItemRole::LabelRole, label_46);

        txtGenero = new QLineEdit(formLayoutWidget_3);
        txtGenero->setObjectName("txtGenero");
        txtGenero->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #2b2b2b;\n"
"    color: white;\n"
"    border: 1px solid #555555;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* Efecto cuando haces clic para escribir adentro */\n"
"QLineEdit:focus {\n"
"    border: 1px solid #0984e3; /* El borde se pone azul para indicar que est\303\241 activo */\n"
"    background-color: #333333; /* El fondo se aclara un poco */\n"
"}"));

        formLayout_3->setWidget(2, QFormLayout::ItemRole::FieldRole, txtGenero);

        label_47 = new QLabel(formLayoutWidget_3);
        label_47->setObjectName("label_47");
        label_47->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #f0f0f0; /* Un blanco/gris muy claro para no cansar la vista */\n"
"    font-family: \"Segoe UI\", Helvetica, Arial, sans-serif; /* Tipograf\303\255a moderna y limpia */\n"
"    font-size: 13px; /* Tama\303\261o est\303\241ndar legible */\n"
"    background-color: transparent; /* Transparente para que se vea tu fondo oscuro */\n"
"    border: none;\n"
"}"));

        formLayout_3->setWidget(3, QFormLayout::ItemRole::LabelRole, label_47);

        txtDuracion = new QLineEdit(formLayoutWidget_3);
        txtDuracion->setObjectName("txtDuracion");
        txtDuracion->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #2b2b2b;\n"
"    color: white;\n"
"    border: 1px solid #555555;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* Efecto cuando haces clic para escribir adentro */\n"
"QLineEdit:focus {\n"
"    border: 1px solid #0984e3; /* El borde se pone azul para indicar que est\303\241 activo */\n"
"    background-color: #333333; /* El fondo se aclara un poco */\n"
"}"));

        formLayout_3->setWidget(3, QFormLayout::ItemRole::FieldRole, txtDuracion);

        label_48 = new QLabel(formLayoutWidget_3);
        label_48->setObjectName("label_48");
        label_48->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #f0f0f0; /* Un blanco/gris muy claro para no cansar la vista */\n"
"    font-family: \"Segoe UI\", Helvetica, Arial, sans-serif; /* Tipograf\303\255a moderna y limpia */\n"
"    font-size: 13px; /* Tama\303\261o est\303\241ndar legible */\n"
"    background-color: transparent; /* Transparente para que se vea tu fondo oscuro */\n"
"    border: none;\n"
"}"));

        formLayout_3->setWidget(4, QFormLayout::ItemRole::LabelRole, label_48);

        txtClasificacion = new QLineEdit(formLayoutWidget_3);
        txtClasificacion->setObjectName("txtClasificacion");
        txtClasificacion->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #2b2b2b;\n"
"    color: white;\n"
"    border: 1px solid #555555;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* Efecto cuando haces clic para escribir adentro */\n"
"QLineEdit:focus {\n"
"    border: 1px solid #0984e3; /* El borde se pone azul para indicar que est\303\241 activo */\n"
"    background-color: #333333; /* El fondo se aclara un poco */\n"
"}"));

        formLayout_3->setWidget(4, QFormLayout::ItemRole::FieldRole, txtClasificacion);

        label_49 = new QLabel(formLayoutWidget_3);
        label_49->setObjectName("label_49");
        label_49->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #f0f0f0; /* Un blanco/gris muy claro para no cansar la vista */\n"
"    font-family: \"Segoe UI\", Helvetica, Arial, sans-serif; /* Tipograf\303\255a moderna y limpia */\n"
"    font-size: 13px; /* Tama\303\261o est\303\241ndar legible */\n"
"    background-color: transparent; /* Transparente para que se vea tu fondo oscuro */\n"
"    border: none;\n"
"}"));

        formLayout_3->setWidget(5, QFormLayout::ItemRole::LabelRole, label_49);

        txtIdioma = new QLineEdit(formLayoutWidget_3);
        txtIdioma->setObjectName("txtIdioma");
        txtIdioma->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #2b2b2b;\n"
"    color: white;\n"
"    border: 1px solid #555555;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* Efecto cuando haces clic para escribir adentro */\n"
"QLineEdit:focus {\n"
"    border: 1px solid #0984e3; /* El borde se pone azul para indicar que est\303\241 activo */\n"
"    background-color: #333333; /* El fondo se aclara un poco */\n"
"}"));

        formLayout_3->setWidget(5, QFormLayout::ItemRole::FieldRole, txtIdioma);

        label_50 = new QLabel(formLayoutWidget_3);
        label_50->setObjectName("label_50");
        label_50->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #f0f0f0; /* Un blanco/gris muy claro para no cansar la vista */\n"
"    font-family: \"Segoe UI\", Helvetica, Arial, sans-serif; /* Tipograf\303\255a moderna y limpia */\n"
"    font-size: 13px; /* Tama\303\261o est\303\241ndar legible */\n"
"    background-color: transparent; /* Transparente para que se vea tu fondo oscuro */\n"
"    border: none;\n"
"}"));

        formLayout_3->setWidget(6, QFormLayout::ItemRole::LabelRole, label_50);

        txtEstreno = new QLineEdit(formLayoutWidget_3);
        txtEstreno->setObjectName("txtEstreno");
        txtEstreno->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #2b2b2b;\n"
"    color: white;\n"
"    border: 1px solid #555555;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* Efecto cuando haces clic para escribir adentro */\n"
"QLineEdit:focus {\n"
"    border: 1px solid #0984e3; /* El borde se pone azul para indicar que est\303\241 activo */\n"
"    background-color: #333333; /* El fondo se aclara un poco */\n"
"}"));

        formLayout_3->setWidget(6, QFormLayout::ItemRole::FieldRole, txtEstreno);

        label_51 = new QLabel(formLayoutWidget_3);
        label_51->setObjectName("label_51");
        label_51->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #f0f0f0; /* Un blanco/gris muy claro para no cansar la vista */\n"
"    font-family: \"Segoe UI\", Helvetica, Arial, sans-serif; /* Tipograf\303\255a moderna y limpia */\n"
"    font-size: 13px; /* Tama\303\261o est\303\241ndar legible */\n"
"    background-color: transparent; /* Transparente para que se vea tu fondo oscuro */\n"
"    border: none;\n"
"}"));

        formLayout_3->setWidget(7, QFormLayout::ItemRole::LabelRole, label_51);

        txtFin = new QLineEdit(formLayoutWidget_3);
        txtFin->setObjectName("txtFin");
        txtFin->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #2b2b2b;\n"
"    color: white;\n"
"    border: 1px solid #555555;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* Efecto cuando haces clic para escribir adentro */\n"
"QLineEdit:focus {\n"
"    border: 1px solid #0984e3; /* El borde se pone azul para indicar que est\303\241 activo */\n"
"    background-color: #333333; /* El fondo se aclara un poco */\n"
"}"));

        formLayout_3->setWidget(7, QFormLayout::ItemRole::FieldRole, txtFin);

        label_27 = new QLabel(tab_3);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(620, 180, 101, 16));
        label_27->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #f0f0f0; /* Un blanco/gris muy claro para no cansar la vista */\n"
"    font-family: \"Segoe UI\", Helvetica, Arial, sans-serif; /* Tipograf\303\255a moderna y limpia */\n"
"    font-size: 13px; /* Tama\303\261o est\303\241ndar legible */\n"
"    background-color: transparent; /* Transparente para que se vea tu fondo oscuro */\n"
"    border: none;\n"
"}"));
        btnAgregarPelicula = new QPushButton(tab_3);
        btnAgregarPelicula->setObjectName("btnAgregarPelicula");
        btnAgregarPelicula->setGeometry(QRect(390, 200, 201, 28));
        btnAgregarPelicula->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #B388EB;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 6px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #218838;\n"
"}"));
        btnEditarPelicula = new QPushButton(tab_3);
        btnEditarPelicula->setObjectName("btnEditarPelicula");
        btnEditarPelicula->setGeometry(QRect(390, 240, 201, 28));
        btnEditarPelicula->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #7E57C2;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 6px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #e0a800;\n"
"}"));
        btnEliminarPelicula = new QPushButton(tab_3);
        btnEliminarPelicula->setObjectName("btnEliminarPelicula");
        btnEliminarPelicula->setGeometry(QRect(390, 280, 201, 28));
        btnEliminarPelicula->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #512DA8;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 6px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #e74c3c; \n"
"}"));
        tabWidgetAdmin->addTab(tab_3, QString());
        tab_13 = new QWidget();
        tab_13->setObjectName("tab_13");
        tblAdminClientes = new QTableWidget(tab_13);
        tblAdminClientes->setObjectName("tblAdminClientes");
        tblAdminClientes->setGeometry(QRect(130, 290, 621, 281));
        tblAdminClientes->horizontalHeader()->setStretchLastSection(true);
        label_53 = new QLabel(tab_13);
        label_53->setObjectName("label_53");
        label_53->setGeometry(QRect(330, 30, 191, 16));
        label_53->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #ffffff; /* Blanco puro para destacar m\303\241s */\n"
"    font-size: 18px; /* Tama\303\261o de letra m\303\241s grande */\n"
"    font-weight: bold; /* Negrita */\n"
"}"));
        label_67 = new QLabel(tab_13);
        label_67->setObjectName("label_67");
        label_67->setGeometry(QRect(140, 40, 231, 231));
        label_67->setPixmap(QPixmap(QString::fromUtf8(":/imgCustomer.png")));
        label_67->setScaledContents(true);
        horizontalLayoutWidget_2 = new QWidget(tab_13);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(250, 239, 498, 61));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_38 = new QLabel(horizontalLayoutWidget_2);
        label_38->setObjectName("label_38");
        label_38->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #f0f0f0; /* Un blanco/gris muy claro para no cansar la vista */\n"
"    font-family: \"Segoe UI\", Helvetica, Arial, sans-serif; /* Tipograf\303\255a moderna y limpia */\n"
"    font-size: 13px; /* Tama\303\261o est\303\241ndar legible */\n"
"    background-color: transparent; /* Transparente para que se vea tu fondo oscuro */\n"
"    border: none;\n"
"}"));

        horizontalLayout_2->addWidget(label_38);

        txtBuscarIdCliente = new QLineEdit(horizontalLayoutWidget_2);
        txtBuscarIdCliente->setObjectName("txtBuscarIdCliente");
        txtBuscarIdCliente->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #2b2b2b;\n"
"    color: white;\n"
"    border: 1px solid #555555;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* Efecto cuando haces clic para escribir adentro */\n"
"QLineEdit:focus {\n"
"    border: 1px solid #0984e3; /* El borde se pone azul para indicar que est\303\241 activo */\n"
"    background-color: #333333; /* El fondo se aclara un poco */\n"
"}"));

        horizontalLayout_2->addWidget(txtBuscarIdCliente);

        btnBuscarIdCliente = new QPushButton(horizontalLayoutWidget_2);
        btnBuscarIdCliente->setObjectName("btnBuscarIdCliente");
        btnBuscarIdCliente->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #8e44ad;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 6px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #9b59b6; /* Un tono un poco m\303\241s claro al pasar el rat\303\263n */\n"
"}"));

        horizontalLayout_2->addWidget(btnBuscarIdCliente);

        horizontalLayout_2->setStretch(1, 2);
        horizontalLayout_2->setStretch(2, 3);
        horizontalLayoutWidget_5 = new QWidget(tab_13);
        horizontalLayoutWidget_5->setObjectName("horizontalLayoutWidget_5");
        horizontalLayoutWidget_5->setGeometry(QRect(420, 160, 331, 41));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        btnCargaMasivaClientes = new QPushButton(horizontalLayoutWidget_5);
        btnCargaMasivaClientes->setObjectName("btnCargaMasivaClientes");
        btnCargaMasivaClientes->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #B388EB;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 6px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #2ecc71; \n"
"}"));

        horizontalLayout_5->addWidget(btnCargaMasivaClientes);

        btnActualizarTabla = new QPushButton(horizontalLayoutWidget_5);
        btnActualizarTabla->setObjectName("btnActualizarTabla");
        btnActualizarTabla->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #7E57C2;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 6px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #EC7063; /* Tono m\303\241s claro al pasar el rat\303\263n */\n"
"}"));

        horizontalLayout_5->addWidget(btnActualizarTabla);

        horizontalLayoutWidget_6 = new QWidget(tab_13);
        horizontalLayoutWidget_6->setObjectName("horizontalLayoutWidget_6");
        horizontalLayoutWidget_6->setGeometry(QRect(420, 200, 331, 41));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_6);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_68 = new QLabel(horizontalLayoutWidget_6);
        label_68->setObjectName("label_68");
        label_68->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #f0f0f0; /* Un blanco/gris muy claro para no cansar la vista */\n"
"    font-family: \"Segoe UI\", Helvetica, Arial, sans-serif; /* Tipograf\303\255a moderna y limpia */\n"
"    font-size: 13px; /* Tama\303\261o est\303\241ndar legible */\n"
"    background-color: transparent; /* Transparente para que se vea tu fondo oscuro */\n"
"    border: none;\n"
"}"));

        horizontalLayout_6->addWidget(label_68);

        txtDpiEliminar = new QLineEdit(horizontalLayoutWidget_6);
        txtDpiEliminar->setObjectName("txtDpiEliminar");

        horizontalLayout_6->addWidget(txtDpiEliminar);

        btnEliminarCliente = new QPushButton(horizontalLayoutWidget_6);
        btnEliminarCliente->setObjectName("btnEliminarCliente");
        btnEliminarCliente->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #512DA8;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 6px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #e74c3c; \n"
"}"));

        horizontalLayout_6->addWidget(btnEliminarCliente);

        horizontalLayout_6->setStretch(1, 2);
        horizontalLayout_6->setStretch(2, 3);
        tabWidgetAdmin->addTab(tab_13, QString());
        tab_10 = new QWidget();
        tab_10->setObjectName("tab_10");
        btnCrearFuncion = new QPushButton(tab_10);
        btnCrearFuncion->setObjectName("btnCrearFuncion");
        btnCrearFuncion->setGeometry(QRect(490, 410, 211, 31));
        btnCrearFuncion->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #8A2BE2;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 6px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #0f5091; \n"
"}"));
        label_32 = new QLabel(tab_10);
        label_32->setObjectName("label_32");
        label_32->setGeometry(QRect(350, 20, 161, 41));
        label_32->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #ffffff; /* Blanco puro para destacar m\303\241s */\n"
"    font-size: 18px; /* Tama\303\261o de letra m\303\241s grande */\n"
"    font-weight: bold; /* Negrita */\n"
"}"));
        label_65 = new QLabel(tab_10);
        label_65->setObjectName("label_65");
        label_65->setGeometry(QRect(110, 160, 221, 211));
        label_65->setPixmap(QPixmap(QString::fromUtf8(":/imgFuncion.png")));
        label_65->setScaledContents(true);
        formLayoutWidget_2 = new QWidget(tab_10);
        formLayoutWidget_2->setObjectName("formLayoutWidget_2");
        formLayoutWidget_2->setGeometry(QRect(420, 190, 321, 191));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setObjectName("formLayout_2");
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(formLayoutWidget_2);
        label_9->setObjectName("label_9");
        label_9->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #f0f0f0; /* Un blanco/gris muy claro para no cansar la vista */\n"
"    font-family: \"Segoe UI\", Helvetica, Arial, sans-serif; /* Tipograf\303\255a moderna y limpia */\n"
"    font-size: 13px; /* Tama\303\261o est\303\241ndar legible */\n"
"    background-color: transparent; /* Transparente para que se vea tu fondo oscuro */\n"
"    border: none;\n"
"}"));

        formLayout_2->setWidget(0, QFormLayout::ItemRole::LabelRole, label_9);

        comboPeliculas = new QComboBox(formLayoutWidget_2);
        comboPeliculas->setObjectName("comboPeliculas");
        comboPeliculas->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #2b2b2b; /* Fondo gris oscuro */\n"
"    color: white;              /* Texto blanco */\n"
"    border: 1px solid #555555; /* Borde gris sutil */\n"
"    border-radius: 4px;        /* Bordes ligeramente redondeados */\n"
"    padding: 5px;              /* Espacio interno para que el texto respire */\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    border: 1px solid #888888; /* El borde se ilumina un poco al pasar el rat\303\263n */\n"
"}\n"
"\n"
"/* Estilo de la lista que se abre hacia abajo */\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #2b2b2b; \n"
"    color: white;              \n"
"    selection-background-color: #0984e3; /* Fondo azul (mismo del bot\303\263n) al seleccionar */\n"
"    selection-color: white;\n"
"}"));

        formLayout_2->setWidget(0, QFormLayout::ItemRole::FieldRole, comboPeliculas);

        label_66 = new QLabel(formLayoutWidget_2);
        label_66->setObjectName("label_66");

        formLayout_2->setWidget(1, QFormLayout::ItemRole::LabelRole, label_66);

        comboSala = new QComboBox(formLayoutWidget_2);
        comboSala->addItem(QString());
        comboSala->addItem(QString());
        comboSala->addItem(QString());
        comboSala->addItem(QString());
        comboSala->setObjectName("comboSala");
        comboSala->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #2b2b2b; /* Fondo gris oscuro */\n"
"    color: white;              /* Texto blanco */\n"
"    border: 1px solid #555555; /* Borde gris sutil */\n"
"    border-radius: 4px;        /* Bordes ligeramente redondeados */\n"
"    padding: 5px;              /* Espacio interno para que el texto respire */\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    border: 1px solid #888888; /* El borde se ilumina un poco al pasar el rat\303\263n */\n"
"}\n"
"\n"
"/* Estilo de la lista que se abre hacia abajo */\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #2b2b2b; \n"
"    color: white;              \n"
"    selection-background-color: #0984e3; /* Fondo azul (mismo del bot\303\263n) al seleccionar */\n"
"    selection-color: white;\n"
"}"));

        formLayout_2->setWidget(1, QFormLayout::ItemRole::FieldRole, comboSala);

        label_8 = new QLabel(formLayoutWidget_2);
        label_8->setObjectName("label_8");
        label_8->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #f0f0f0; /* Un blanco/gris muy claro para no cansar la vista */\n"
"    font-family: \"Segoe UI\", Helvetica, Arial, sans-serif; /* Tipograf\303\255a moderna y limpia */\n"
"    font-size: 13px; /* Tama\303\261o est\303\241ndar legible */\n"
"    background-color: transparent; /* Transparente para que se vea tu fondo oscuro */\n"
"    border: none;\n"
"}"));

        formLayout_2->setWidget(2, QFormLayout::ItemRole::LabelRole, label_8);

        txtHorario = new QLineEdit(formLayoutWidget_2);
        txtHorario->setObjectName("txtHorario");
        txtHorario->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #2b2b2b;\n"
"    color: white;\n"
"    border: 1px solid #555555;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* Efecto cuando haces clic para escribir adentro */\n"
"QLineEdit:focus {\n"
"    border: 1px solid #0984e3; /* El borde se pone azul para indicar que est\303\241 activo */\n"
"    background-color: #333333; /* El fondo se aclara un poco */\n"
"}"));

        formLayout_2->setWidget(2, QFormLayout::ItemRole::FieldRole, txtHorario);

        label_6 = new QLabel(formLayoutWidget_2);
        label_6->setObjectName("label_6");
        label_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #f0f0f0; /* Un blanco/gris muy claro para no cansar la vista */\n"
"    font-family: \"Segoe UI\", Helvetica, Arial, sans-serif; /* Tipograf\303\255a moderna y limpia */\n"
"    font-size: 13px; /* Tama\303\261o est\303\241ndar legible */\n"
"    background-color: transparent; /* Transparente para que se vea tu fondo oscuro */\n"
"    border: none;\n"
"}"));

        formLayout_2->setWidget(3, QFormLayout::ItemRole::LabelRole, label_6);

        spinFilas = new QSpinBox(formLayoutWidget_2);
        spinFilas->setObjectName("spinFilas");
        spinFilas->setStyleSheet(QString::fromUtf8("/* Campo principal */\n"
"QSpinBox {\n"
"    background-color: #2b2b2b;\n"
"    border: 1px solid #3d3d3d;\n"
"    border-radius: 5px;\n"
"    color: #ffffff;\n"
"    padding: 4px 8px;\n"
"    font-size: 13px;\n"
"}\n"
"\n"
"QSpinBox:focus {\n"
"    border: 1px solid #1E90FF;\n"
"}\n"
"\n"
"/* Contenedor del bot\303\263n superior */\n"
"QSpinBox::up-button {\n"
"    subcontrol-origin: border;\n"
"    subcontrol-position: top right;\n"
"    width: 22px;\n"
"    background-color: #383838;\n"
"    border-top-right-radius: 4px;\n"
"    border-left: 1px solid #3d3d3d;\n"
"    border-bottom: 1px solid #2b2b2b;\n"
"}\n"
"\n"
"QSpinBox::up-button:hover {\n"
"    background-color: #1E90FF;\n"
"}\n"
"\n"
"QSpinBox::up-button:pressed {\n"
"    background-color: #1674cc;\n"
"}\n"
"\n"
"/* Tri\303\241ngulo Arriba mediante bordes puros */\n"
"QSpinBox::up-arrow {\n"
"    width: 0px;\n"
"    height: 0px;\n"
"    border-left: 4px solid transparent;\n"
"    border-right: 4px solid transparent;\n"
"    border-bottom: 5px solid "
                        "#ffffff;\n"
"}\n"
"\n"
"/* Contenedor del bot\303\263n inferior */\n"
"QSpinBox::down-button {\n"
"    subcontrol-origin: border;\n"
"    subcontrol-position: bottom right;\n"
"    width: 22px;\n"
"    background-color: #383838;\n"
"    border-bottom-right-radius: 4px;\n"
"    border-left: 1px solid #3d3d3d;\n"
"}\n"
"\n"
"QSpinBox::down-button:hover {\n"
"    background-color: #1E90FF;\n"
"}\n"
"\n"
"QSpinBox::down-button:pressed {\n"
"    background-color: #1674cc;\n"
"}\n"
"\n"
"/* Tri\303\241ngulo Abajo mediante bordes puros */\n"
"QSpinBox::down-arrow {\n"
"    width: 0px;\n"
"    height: 0px;\n"
"    border-left: 4px solid transparent;\n"
"    border-right: 4px solid transparent;\n"
"    border-top: 5px solid #ffffff;\n"
"}"));

        formLayout_2->setWidget(3, QFormLayout::ItemRole::FieldRole, spinFilas);

        label_7 = new QLabel(formLayoutWidget_2);
        label_7->setObjectName("label_7");
        label_7->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #f0f0f0; /* Un blanco/gris muy claro para no cansar la vista */\n"
"    font-family: \"Segoe UI\", Helvetica, Arial, sans-serif; /* Tipograf\303\255a moderna y limpia */\n"
"    font-size: 13px; /* Tama\303\261o est\303\241ndar legible */\n"
"    background-color: transparent; /* Transparente para que se vea tu fondo oscuro */\n"
"    border: none;\n"
"}"));

        formLayout_2->setWidget(4, QFormLayout::ItemRole::LabelRole, label_7);

        spinColumnas = new QSpinBox(formLayoutWidget_2);
        spinColumnas->setObjectName("spinColumnas");
        spinColumnas->setStyleSheet(QString::fromUtf8("/* Campo principal */\n"
"QSpinBox {\n"
"    background-color: #2b2b2b;\n"
"    border: 1px solid #3d3d3d;\n"
"    border-radius: 5px;\n"
"    color: #ffffff;\n"
"    padding: 4px 8px;\n"
"    font-size: 13px;\n"
"}\n"
"\n"
"QSpinBox:focus {\n"
"    border: 1px solid #1E90FF;\n"
"}\n"
"\n"
"/* Contenedor del bot\303\263n superior */\n"
"QSpinBox::up-button {\n"
"    subcontrol-origin: border;\n"
"    subcontrol-position: top right;\n"
"    width: 22px;\n"
"    background-color: #383838;\n"
"    border-top-right-radius: 4px;\n"
"    border-left: 1px solid #3d3d3d;\n"
"    border-bottom: 1px solid #2b2b2b;\n"
"}\n"
"\n"
"QSpinBox::up-button:hover {\n"
"    background-color: #1E90FF;\n"
"}\n"
"\n"
"QSpinBox::up-button:pressed {\n"
"    background-color: #1674cc;\n"
"}\n"
"\n"
"/* Tri\303\241ngulo Arriba mediante bordes puros */\n"
"QSpinBox::up-arrow {\n"
"    width: 0px;\n"
"    height: 0px;\n"
"    border-left: 4px solid transparent;\n"
"    border-right: 4px solid transparent;\n"
"    border-bottom: 5px solid "
                        "#ffffff;\n"
"}\n"
"\n"
"/* Contenedor del bot\303\263n inferior */\n"
"QSpinBox::down-button {\n"
"    subcontrol-origin: border;\n"
"    subcontrol-position: bottom right;\n"
"    width: 22px;\n"
"    background-color: #383838;\n"
"    border-bottom-right-radius: 4px;\n"
"    border-left: 1px solid #3d3d3d;\n"
"}\n"
"\n"
"QSpinBox::down-button:hover {\n"
"    background-color: #1E90FF;\n"
"}\n"
"\n"
"QSpinBox::down-button:pressed {\n"
"    background-color: #1674cc;\n"
"}\n"
"\n"
"/* Tri\303\241ngulo Abajo mediante bordes puros */\n"
"QSpinBox::down-arrow {\n"
"    width: 0px;\n"
"    height: 0px;\n"
"    border-left: 4px solid transparent;\n"
"    border-right: 4px solid transparent;\n"
"    border-top: 5px solid #ffffff;\n"
"}"));

        formLayout_2->setWidget(4, QFormLayout::ItemRole::FieldRole, spinColumnas);

        tabWidgetAdmin->addTab(tab_10, QString());
        tab_14 = new QWidget();
        tab_14->setObjectName("tab_14");
        label_56 = new QLabel(tab_14);
        label_56->setObjectName("label_56");
        label_56->setGeometry(QRect(310, 20, 261, 16));
        label_56->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #ffffff; /* Blanco puro para destacar m\303\241s */\n"
"    font-size: 18px; /* Tama\303\261o de letra m\303\241s grande */\n"
"    font-weight: bold; /* Negrita */\n"
"}"));
        tblFunciones = new QTableWidget(tab_14);
        tblFunciones->setObjectName("tblFunciones");
        tblFunciones->setGeometry(QRect(20, 280, 371, 331));
        tblFunciones->horizontalHeader()->setStretchLastSection(true);
        horizontalLayoutWidget = new QWidget(tab_14);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(20, 120, 371, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_57 = new QLabel(horizontalLayoutWidget);
        label_57->setObjectName("label_57");

        horizontalLayout->addWidget(label_57);

        txtBuscarCodFuncion = new QLineEdit(horizontalLayoutWidget);
        txtBuscarCodFuncion->setObjectName("txtBuscarCodFuncion");
        txtBuscarCodFuncion->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #2b2b2b;\n"
"    color: white;\n"
"    border: 1px solid #555555;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* Efecto cuando haces clic para escribir adentro */\n"
"QLineEdit:focus {\n"
"    border: 1px solid #0984e3; /* El borde se pone azul para indicar que est\303\241 activo */\n"
"    background-color: #333333; /* El fondo se aclara un poco */\n"
"}"));

        horizontalLayout->addWidget(txtBuscarCodFuncion);

        formLayoutWidget = new QWidget(tab_14);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(430, 330, 381, 231));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_58 = new QLabel(formLayoutWidget);
        label_58->setObjectName("label_58");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label_58);

        txtEditCodFuncion = new QLineEdit(formLayoutWidget);
        txtEditCodFuncion->setObjectName("txtEditCodFuncion");
        txtEditCodFuncion->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #2b2b2b;\n"
"    color: white;\n"
"    border: 1px solid #555555;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* Efecto cuando haces clic para escribir adentro */\n"
"QLineEdit:focus {\n"
"    border: 1px solid #0984e3; /* El borde se pone azul para indicar que est\303\241 activo */\n"
"    background-color: #333333; /* El fondo se aclara un poco */\n"
"}"));
        txtEditCodFuncion->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, txtEditCodFuncion);

        label_59 = new QLabel(formLayoutWidget);
        label_59->setObjectName("label_59");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_59);

        txtEditPelicula = new QLineEdit(formLayoutWidget);
        txtEditPelicula->setObjectName("txtEditPelicula");
        txtEditPelicula->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #2b2b2b;\n"
"    color: white;\n"
"    border: 1px solid #555555;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* Efecto cuando haces clic para escribir adentro */\n"
"QLineEdit:focus {\n"
"    border: 1px solid #0984e3; /* El borde se pone azul para indicar que est\303\241 activo */\n"
"    background-color: #333333; /* El fondo se aclara un poco */\n"
"}"));

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, txtEditPelicula);

        label_60 = new QLabel(formLayoutWidget);
        label_60->setObjectName("label_60");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_60);

        txtEditHorario = new QLineEdit(formLayoutWidget);
        txtEditHorario->setObjectName("txtEditHorario");
        txtEditHorario->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #2b2b2b;\n"
"    color: white;\n"
"    border: 1px solid #555555;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* Efecto cuando haces clic para escribir adentro */\n"
"QLineEdit:focus {\n"
"    border: 1px solid #0984e3; /* El borde se pone azul para indicar que est\303\241 activo */\n"
"    background-color: #333333; /* El fondo se aclara un poco */\n"
"}"));

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, txtEditHorario);

        label_61 = new QLabel(formLayoutWidget);
        label_61->setObjectName("label_61");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, label_61);

        txtEditSala = new QLineEdit(formLayoutWidget);
        txtEditSala->setObjectName("txtEditSala");
        txtEditSala->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #2b2b2b;\n"
"    color: white;\n"
"    border: 1px solid #555555;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* Efecto cuando haces clic para escribir adentro */\n"
"QLineEdit:focus {\n"
"    border: 1px solid #0984e3; /* El borde se pone azul para indicar que est\303\241 activo */\n"
"    background-color: #333333; /* El fondo se aclara un poco */\n"
"}"));

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, txtEditSala);

        label_62 = new QLabel(formLayoutWidget);
        label_62->setObjectName("label_62");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, label_62);

        spinEditFilas = new QSpinBox(formLayoutWidget);
        spinEditFilas->setObjectName("spinEditFilas");
        spinEditFilas->setStyleSheet(QString::fromUtf8("/* Campo principal */\n"
"QSpinBox {\n"
"    background-color: #2b2b2b;\n"
"    border: 1px solid #3d3d3d;\n"
"    border-radius: 5px;\n"
"    color: #ffffff;\n"
"    padding: 4px 8px;\n"
"    font-size: 13px;\n"
"}\n"
"\n"
"QSpinBox:focus {\n"
"    border: 1px solid #1E90FF;\n"
"}\n"
"\n"
"/* Contenedor del bot\303\263n superior */\n"
"QSpinBox::up-button {\n"
"    subcontrol-origin: border;\n"
"    subcontrol-position: top right;\n"
"    width: 22px;\n"
"    background-color: #383838;\n"
"    border-top-right-radius: 4px;\n"
"    border-left: 1px solid #3d3d3d;\n"
"    border-bottom: 1px solid #2b2b2b;\n"
"}\n"
"\n"
"QSpinBox::up-button:hover {\n"
"    background-color: #1E90FF;\n"
"}\n"
"\n"
"QSpinBox::up-button:pressed {\n"
"    background-color: #1674cc;\n"
"}\n"
"\n"
"/* Tri\303\241ngulo Arriba mediante bordes puros */\n"
"QSpinBox::up-arrow {\n"
"    width: 0px;\n"
"    height: 0px;\n"
"    border-left: 4px solid transparent;\n"
"    border-right: 4px solid transparent;\n"
"    border-bottom: 5px solid "
                        "#ffffff;\n"
"}\n"
"\n"
"/* Contenedor del bot\303\263n inferior */\n"
"QSpinBox::down-button {\n"
"    subcontrol-origin: border;\n"
"    subcontrol-position: bottom right;\n"
"    width: 22px;\n"
"    background-color: #383838;\n"
"    border-bottom-right-radius: 4px;\n"
"    border-left: 1px solid #3d3d3d;\n"
"}\n"
"\n"
"QSpinBox::down-button:hover {\n"
"    background-color: #1E90FF;\n"
"}\n"
"\n"
"QSpinBox::down-button:pressed {\n"
"    background-color: #1674cc;\n"
"}\n"
"\n"
"/* Tri\303\241ngulo Abajo mediante bordes puros */\n"
"QSpinBox::down-arrow {\n"
"    width: 0px;\n"
"    height: 0px;\n"
"    border-left: 4px solid transparent;\n"
"    border-right: 4px solid transparent;\n"
"    border-top: 5px solid #ffffff;\n"
"}"));

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, spinEditFilas);

        label_63 = new QLabel(formLayoutWidget);
        label_63->setObjectName("label_63");

        formLayout->setWidget(5, QFormLayout::ItemRole::LabelRole, label_63);

        spinEditColumnas = new QSpinBox(formLayoutWidget);
        spinEditColumnas->setObjectName("spinEditColumnas");
        spinEditColumnas->setStyleSheet(QString::fromUtf8("/* Campo principal */\n"
"QSpinBox {\n"
"    background-color: #2b2b2b;\n"
"    border: 1px solid #3d3d3d;\n"
"    border-radius: 5px;\n"
"    color: #ffffff;\n"
"    padding: 4px 8px;\n"
"    font-size: 13px;\n"
"}\n"
"\n"
"QSpinBox:focus {\n"
"    border: 1px solid #1E90FF;\n"
"}\n"
"\n"
"/* Contenedor del bot\303\263n superior */\n"
"QSpinBox::up-button {\n"
"    subcontrol-origin: border;\n"
"    subcontrol-position: top right;\n"
"    width: 22px;\n"
"    background-color: #383838;\n"
"    border-top-right-radius: 4px;\n"
"    border-left: 1px solid #3d3d3d;\n"
"    border-bottom: 1px solid #2b2b2b;\n"
"}\n"
"\n"
"QSpinBox::up-button:hover {\n"
"    background-color: #1E90FF;\n"
"}\n"
"\n"
"QSpinBox::up-button:pressed {\n"
"    background-color: #1674cc;\n"
"}\n"
"\n"
"/* Tri\303\241ngulo Arriba mediante bordes puros */\n"
"QSpinBox::up-arrow {\n"
"    width: 0px;\n"
"    height: 0px;\n"
"    border-left: 4px solid transparent;\n"
"    border-right: 4px solid transparent;\n"
"    border-bottom: 5px solid "
                        "#ffffff;\n"
"}\n"
"\n"
"/* Contenedor del bot\303\263n inferior */\n"
"QSpinBox::down-button {\n"
"    subcontrol-origin: border;\n"
"    subcontrol-position: bottom right;\n"
"    width: 22px;\n"
"    background-color: #383838;\n"
"    border-bottom-right-radius: 4px;\n"
"    border-left: 1px solid #3d3d3d;\n"
"}\n"
"\n"
"QSpinBox::down-button:hover {\n"
"    background-color: #1E90FF;\n"
"}\n"
"\n"
"QSpinBox::down-button:pressed {\n"
"    background-color: #1674cc;\n"
"}\n"
"\n"
"/* Tri\303\241ngulo Abajo mediante bordes puros */\n"
"QSpinBox::down-arrow {\n"
"    width: 0px;\n"
"    height: 0px;\n"
"    border-left: 4px solid transparent;\n"
"    border-right: 4px solid transparent;\n"
"    border-top: 5px solid #ffffff;\n"
"}"));

        formLayout->setWidget(5, QFormLayout::ItemRole::FieldRole, spinEditColumnas);

        btnBuscarFuncion = new QPushButton(tab_14);
        btnBuscarFuncion->setObjectName("btnBuscarFuncion");
        btnBuscarFuncion->setGeometry(QRect(20, 230, 171, 31));
        btnBuscarFuncion->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #1E90FF; /* Azul El\303\251ctrico Vibrante */\n"
"    color: #ffffff; /* Texto en blanco para buen contraste */\n"
"    border: 1px solid #1c8adb; /* Un borde un poco m\303\241s oscuro */\n"
"    border-radius: 5px; /* Bordes redondeados */\n"
"    padding: 6px 12px;\n"
"    font-weight: bold; /* Texto en negrita */\n"
"}\n"
"\n"
"/* Efecto cuando pasas el rat\303\263n por encima */\n"
"QPushButton:hover {\n"
"    background-color: #1a82e6; /* Un tono un poco m\303\241s oscuro */\n"
"}\n"
"\n"
"/* Efecto cuando presionas */\n"
"QPushButton:pressed {\n"
"    background-color: #1674cc; /* M\303\241s oscuro al presionar */\n"
"}"));
        btnActualizarFunciones = new QPushButton(tab_14);
        btnActualizarFunciones->setObjectName("btnActualizarFunciones");
        btnActualizarFunciones->setGeometry(QRect(210, 230, 181, 31));
        btnActualizarFunciones->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #8e44ad;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 6px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #9b59b6; /* Un tono un poco m\303\241s claro al pasar el rat\303\263n */\n"
"}"));
        label_64 = new QLabel(tab_14);
        label_64->setObjectName("label_64");
        label_64->setGeometry(QRect(540, 60, 211, 181));
        label_64->setPixmap(QPixmap(QString::fromUtf8(":/imgEdit.png")));
        label_64->setScaledContents(true);
        btnGuardarEdicionFuncion = new QPushButton(tab_14);
        btnGuardarEdicionFuncion->setObjectName("btnGuardarEdicionFuncion");
        btnGuardarEdicionFuncion->setGeometry(QRect(430, 580, 191, 28));
        btnGuardarEdicionFuncion->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #9D7AC7;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 6px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #218838;\n"
"}"));
        btnEliminarFun = new QPushButton(tab_14);
        btnEliminarFun->setObjectName("btnEliminarFun");
        btnEliminarFun->setGeometry(QRect(630, 580, 181, 28));
        btnEliminarFun->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #76529D;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 6px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #e74c3c; \n"
"}"));
        cbOrdenFunciones = new QComboBox(tab_14);
        cbOrdenFunciones->addItem(QString());
        cbOrdenFunciones->addItem(QString());
        cbOrdenFunciones->addItem(QString());
        cbOrdenFunciones->setObjectName("cbOrdenFunciones");
        cbOrdenFunciones->setGeometry(QRect(540, 290, 271, 31));
        cbOrdenFunciones->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #2b2b2b; /* Fondo gris oscuro */\n"
"    color: white;              /* Texto blanco */\n"
"    border: 1px solid #555555; /* Borde gris sutil */\n"
"    border-radius: 4px;        /* Bordes ligeramente redondeados */\n"
"    padding: 5px;              /* Espacio interno para que el texto respire */\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    border: 1px solid #888888; /* El borde se ilumina un poco al pasar el rat\303\263n */\n"
"}\n"
"\n"
"/* Estilo de la lista que se abre hacia abajo */\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #2b2b2b; \n"
"    color: white;              \n"
"    selection-background-color: #0984e3; /* Fondo azul (mismo del bot\303\263n) al seleccionar */\n"
"    selection-color: white;\n"
"}"));
        label_74 = new QLabel(tab_14);
        label_74->setObjectName("label_74");
        label_74->setGeometry(QRect(430, 300, 101, 16));
        label_74->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #f0f0f0; /* Un blanco/gris muy claro para no cansar la vista */\n"
"    font-family: \"Segoe UI\", Helvetica, Arial, sans-serif; /* Tipograf\303\255a moderna y limpia */\n"
"    font-size: 13px; /* Tama\303\261o est\303\241ndar legible */\n"
"    background-color: transparent; /* Transparente para que se vea tu fondo oscuro */\n"
"    border: none;\n"
"}"));
        tabWidgetAdmin->addTab(tab_14, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName("tab_7");
        label_69 = new QLabel(tab_7);
        label_69->setObjectName("label_69");
        label_69->setGeometry(QRect(10, 0, 471, 31));
        label_69->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #70757d; /* Blanco puro para destacar m\303\241s */\n"
"    font-size: 18px; /* Tama\303\261o de letra m\303\241s grande */\n"
"    font-weight: bold; /* Negrita */\n"
"}"));
        lblVisorAdmin = new QLabel(tab_7);
        lblVisorAdmin->setObjectName("lblVisorAdmin");
        lblVisorAdmin->setGeometry(QRect(10, 40, 811, 381));
        lblVisorAdmin->setScaledContents(true);
        horizontalLayoutWidget_7 = new QWidget(tab_7);
        horizontalLayoutWidget_7->setObjectName("horizontalLayoutWidget_7");
        horizontalLayoutWidget_7->setGeometry(QRect(10, 520, 821, 80));
        horizontalLayout_7 = new QHBoxLayout(horizontalLayoutWidget_7);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        btnReportePeliculas = new QPushButton(horizontalLayoutWidget_7);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName("buttonGroup");
        buttonGroup->addButton(btnReportePeliculas);
        btnReportePeliculas->setObjectName("btnReportePeliculas");
        btnReportePeliculas->setStyleSheet(QString::fromUtf8("/* Estilo base de los botones */\n"
"QPushButton {\n"
"    background-color: #76529D;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 14px;\n"
"}\n"
"\n"
"/* Efecto cuando pasas el mouse por encima */\n"
"QPushButton:hover {\n"
"    background-color: #9D7AC7;\n"
"}\n"
"\n"
"/* Estado ACTIVO/SELECCIONADO */\n"
"QPushButton:checked {\n"
"    background-color: #4A3267;\n"
"    border: 2px solid #9D7AC7;\n"
"    font-weight: bold;\n"
"}"));
        btnReportePeliculas->setCheckable(true);

        horizontalLayout_7->addWidget(btnReportePeliculas);

        btnReporteFunciones = new QPushButton(horizontalLayoutWidget_7);
        buttonGroup->addButton(btnReporteFunciones);
        btnReporteFunciones->setObjectName("btnReporteFunciones");
        btnReporteFunciones->setStyleSheet(QString::fromUtf8("/* Estilo base de los botones */\n"
"QPushButton {\n"
"    background-color: #76529D;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 14px;\n"
"}\n"
"\n"
"/* Efecto cuando pasas el mouse por encima */\n"
"QPushButton:hover {\n"
"    background-color: #9D7AC7;\n"
"}\n"
"\n"
"/* Estado ACTIVO/SELECCIONADO */\n"
"QPushButton:checked {\n"
"    background-color: #4A3267;\n"
"    border: 2px solid #9D7AC7;\n"
"    font-weight: bold;\n"
"}"));
        btnReporteFunciones->setCheckable(true);

        horizontalLayout_7->addWidget(btnReporteFunciones);

        btnReporteClientes = new QPushButton(horizontalLayoutWidget_7);
        buttonGroup->addButton(btnReporteClientes);
        btnReporteClientes->setObjectName("btnReporteClientes");
        btnReporteClientes->setStyleSheet(QString::fromUtf8("/* Estilo base de los botones */\n"
"QPushButton {\n"
"    background-color: #76529D;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 14px;\n"
"}\n"
"\n"
"/* Efecto cuando pasas el mouse por encima */\n"
"QPushButton:hover {\n"
"    background-color: #9D7AC7;\n"
"}\n"
"\n"
"/* Estado ACTIVO/SELECCIONADO */\n"
"QPushButton:checked {\n"
"    background-color: #4A3267;\n"
"    border: 2px solid #9D7AC7;\n"
"    font-weight: bold;\n"
"}"));
        btnReporteClientes->setCheckable(true);

        horizontalLayout_7->addWidget(btnReporteClientes);

        btnReporteMatriz = new QPushButton(horizontalLayoutWidget_7);
        buttonGroup->addButton(btnReporteMatriz);
        btnReporteMatriz->setObjectName("btnReporteMatriz");
        btnReporteMatriz->setStyleSheet(QString::fromUtf8("/* Estilo base de los botones */\n"
"QPushButton {\n"
"    background-color: #76529D;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 14px;\n"
"}\n"
"\n"
"/* Efecto cuando pasas el mouse por encima */\n"
"QPushButton:hover {\n"
"    background-color: #9D7AC7;\n"
"}\n"
"\n"
"/* Estado ACTIVO/SELECCIONADO */\n"
"QPushButton:checked {\n"
"    background-color: #4A3267;\n"
"    border: 2px solid #9D7AC7;\n"
"    font-weight: bold;\n"
"}"));
        btnReporteMatriz->setCheckable(true);

        horizontalLayout_7->addWidget(btnReporteMatriz);

        tabWidgetAdmin->addTab(tab_7, QString());
        tab_17 = new QWidget();
        tab_17->setObjectName("tab_17");
        btnReporteReservas = new QPushButton(tab_17);
        buttonGroup->addButton(btnReporteReservas);
        btnReporteReservas->setObjectName("btnReporteReservas");
        btnReporteReservas->setGeometry(QRect(350, 550, 159, 28));
        btnReporteReservas->setStyleSheet(QString::fromUtf8("/* Estilo base de los botones */\n"
"QPushButton {\n"
"    background-color: #76529D;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 14px;\n"
"}\n"
"\n"
"/* Efecto cuando pasas el mouse por encima */\n"
"QPushButton:hover {\n"
"    background-color: #9D7AC7;\n"
"}\n"
"\n"
"/* Estado ACTIVO/SELECCIONADO */\n"
"QPushButton:checked {\n"
"    background-color: #4A3267;\n"
"    border: 2px solid #9D7AC7;\n"
"    font-weight: bold;\n"
"}"));
        btnReporteReservas->setCheckable(true);
        scrollArea = new QScrollArea(tab_17);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(30, 40, 791, 491));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 789, 489));
        lblVisorHash = new QLabel(scrollAreaWidgetContents);
        lblVisorHash->setObjectName("lblVisorHash");
        lblVisorHash->setGeometry(QRect(10, 10, 761, 441));
        scrollArea->setWidget(scrollAreaWidgetContents);
        label_73 = new QLabel(tab_17);
        label_73->setObjectName("label_73");
        label_73->setGeometry(QRect(10, 10, 301, 16));
        label_73->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #70757d; /* Blanco puro para destacar m\303\241s */\n"
"    font-size: 18px; /* Tama\303\261o de letra m\303\241s grande */\n"
"    font-weight: bold; /* Negrita */\n"
"}"));
        tabWidgetAdmin->addTab(tab_17, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        tablaAdminSolicitudes = new QTableWidget(tab_4);
        if (tablaAdminSolicitudes->columnCount() < 5)
            tablaAdminSolicitudes->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tablaAdminSolicitudes->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tablaAdminSolicitudes->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tablaAdminSolicitudes->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tablaAdminSolicitudes->setHorizontalHeaderItem(3, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tablaAdminSolicitudes->setHorizontalHeaderItem(4, __qtablewidgetitem12);
        tablaAdminSolicitudes->setObjectName("tablaAdminSolicitudes");
        tablaAdminSolicitudes->setGeometry(QRect(180, 310, 501, 191));
        lblDetalleSolicitud = new QLabel(tab_4);
        lblDetalleSolicitud->setObjectName("lblDetalleSolicitud");
        lblDetalleSolicitud->setGeometry(QRect(180, 130, 421, 141));
        btnProcesarPrimera = new QPushButton(tab_4);
        btnProcesarPrimera->setObjectName("btnProcesarPrimera");
        btnProcesarPrimera->setGeometry(QRect(530, 50, 151, 41));
        btnProcesarPrimera->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #17a2b8;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 6px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #138496; /* Cyan m\303\241s oscuro al pasar el rat\303\263n */\n"
"}"));
        btnAprobarSolicitud = new QPushButton(tab_4);
        btnAprobarSolicitud->setObjectName("btnAprobarSolicitud");
        btnAprobarSolicitud->setGeometry(QRect(530, 110, 151, 41));
        btnAprobarSolicitud->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #28a745;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 6px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #218838;\n"
"}"));
        btnRechazarSolicitud = new QPushButton(tab_4);
        btnRechazarSolicitud->setObjectName("btnRechazarSolicitud");
        btnRechazarSolicitud->setGeometry(QRect(530, 170, 151, 41));
        btnRechazarSolicitud->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #dc3545;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 6px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #c82333;\n"
"}"));
        btnEnProceso = new QPushButton(tab_4);
        btnEnProceso->setObjectName("btnEnProceso");
        btnEnProceso->setGeometry(QRect(530, 230, 151, 41));
        btnEnProceso->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #ffc107;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 6px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #e0a800;\n"
"}"));
        btnReporteSolicitudes = new QPushButton(tab_4);
        btnReporteSolicitudes->setObjectName("btnReporteSolicitudes");
        btnReporteSolicitudes->setGeometry(QRect(530, 520, 151, 51));
        btnReporteSolicitudes->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #17a2b8;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 6px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #138496; /* Cyan m\303\241s oscuro al pasar el rat\303\263n */\n"
"}"));
        label_31 = new QLabel(tab_4);
        label_31->setObjectName("label_31");
        label_31->setGeometry(QRect(330, 0, 181, 41));
        label_31->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #ffffff; /* Blanco puro para destacar m\303\241s */\n"
"    font-size: 18px; /* Tama\303\261o de letra m\303\241s grande */\n"
"    font-weight: bold; /* Negrita */\n"
"}"));
        cmbRecorridosClientes = new QComboBox(tab_4);
        cmbRecorridosClientes->addItem(QString());
        cmbRecorridosClientes->addItem(QString());
        cmbRecorridosClientes->addItem(QString());
        cmbRecorridosClientes->setObjectName("cmbRecorridosClientes");
        cmbRecorridosClientes->setGeometry(QRect(130, 573, 161, 31));
        cmbRecorridosClientes->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #2b2b2b; /* Fondo gris oscuro */\n"
"    color: white;              /* Texto blanco */\n"
"    border: 1px solid #555555; /* Borde gris sutil */\n"
"    border-radius: 4px;        /* Bordes ligeramente redondeados */\n"
"    padding: 5px;              /* Espacio interno para que el texto respire */\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    border: 1px solid #888888; /* El borde se ilumina un poco al pasar el rat\303\263n */\n"
"}"));
        label_43 = new QLabel(tab_4);
        label_43->setObjectName("label_43");
        label_43->setGeometry(QRect(30, 580, 101, 16));
        label_43->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #f0f0f0; /* Un blanco/gris muy claro para no cansar la vista */\n"
"    font-family: \"Segoe UI\", Helvetica, Arial, sans-serif; /* Tipograf\303\255a moderna y limpia */\n"
"    font-size: 13px; /* Tama\303\261o est\303\241ndar legible */\n"
"    background-color: transparent; /* Transparente para que se vea tu fondo oscuro */\n"
"    border: none;\n"
"}"));
        label_75 = new QLabel(tab_4);
        label_75->setObjectName("label_75");
        label_75->setGeometry(QRect(30, 550, 211, 16));
        tabWidgetAdmin->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        txtCodigoPromo = new QLineEdit(tab_5);
        txtCodigoPromo->setObjectName("txtCodigoPromo");
        txtCodigoPromo->setGeometry(QRect(350, 40, 201, 24));
        txtCodigoPromo->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #2b2b2b;\n"
"    color: white;\n"
"    border: 1px solid #555555;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* Efecto cuando haces clic para escribir adentro */\n"
"QLineEdit:focus {\n"
"    border: 1px solid #0984e3; /* El borde se pone azul para indicar que est\303\241 activo */\n"
"    background-color: #333333; /* El fondo se aclara un poco */\n"
"}"));
        txtNombrePromo = new QLineEdit(tab_5);
        txtNombrePromo->setObjectName("txtNombrePromo");
        txtNombrePromo->setGeometry(QRect(350, 70, 201, 24));
        txtNombrePromo->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #2b2b2b;\n"
"    color: white;\n"
"    border: 1px solid #555555;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* Efecto cuando haces clic para escribir adentro */\n"
"QLineEdit:focus {\n"
"    border: 1px solid #0984e3; /* El borde se pone azul para indicar que est\303\241 activo */\n"
"    background-color: #333333; /* El fondo se aclara un poco */\n"
"}"));
        txtDiasPromo = new QLineEdit(tab_5);
        txtDiasPromo->setObjectName("txtDiasPromo");
        txtDiasPromo->setGeometry(QRect(350, 130, 201, 24));
        txtDiasPromo->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #2b2b2b;\n"
"    color: white;\n"
"    border: 1px solid #555555;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* Efecto cuando haces clic para escribir adentro */\n"
"QLineEdit:focus {\n"
"    border: 1px solid #0984e3; /* El borde se pone azul para indicar que est\303\241 activo */\n"
"    background-color: #333333; /* El fondo se aclara un poco */\n"
"}"));
        txtVigenciaPromo = new QLineEdit(tab_5);
        txtVigenciaPromo->setObjectName("txtVigenciaPromo");
        txtVigenciaPromo->setGeometry(QRect(350, 100, 201, 24));
        txtVigenciaPromo->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #2b2b2b;\n"
"    color: white;\n"
"    border: 1px solid #555555;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* Efecto cuando haces clic para escribir adentro */\n"
"QLineEdit:focus {\n"
"    border: 1px solid #0984e3; /* El borde se pone azul para indicar que est\303\241 activo */\n"
"    background-color: #333333; /* El fondo se aclara un poco */\n"
"}"));
        btnCrearPromo = new QPushButton(tab_5);
        btnCrearPromo->setObjectName("btnCrearPromo");
        btnCrearPromo->setGeometry(QRect(290, 170, 261, 31));
        btnCrearPromo->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #8e44ad;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 6px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #9b59b6; /* Un tono un poco m\303\241s claro al pasar el rat\303\263n */\n"
"}"));
        label_4 = new QLabel(tab_5);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(290, 40, 91, 16));
        label_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #f0f0f0; /* Un blanco/gris muy claro para no cansar la vista */\n"
"    font-family: \"Segoe UI\", Helvetica, Arial, sans-serif; /* Tipograf\303\255a moderna y limpia */\n"
"    font-size: 13px; /* Tama\303\261o est\303\241ndar legible */\n"
"    background-color: transparent; /* Transparente para que se vea tu fondo oscuro */\n"
"    border: none;\n"
"}"));
        label_16 = new QLabel(tab_5);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(290, 70, 91, 16));
        label_16->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #f0f0f0; /* Un blanco/gris muy claro para no cansar la vista */\n"
"    font-family: \"Segoe UI\", Helvetica, Arial, sans-serif; /* Tipograf\303\255a moderna y limpia */\n"
"    font-size: 13px; /* Tama\303\261o est\303\241ndar legible */\n"
"    background-color: transparent; /* Transparente para que se vea tu fondo oscuro */\n"
"    border: none;\n"
"}"));
        label_17 = new QLabel(tab_5);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(290, 100, 101, 16));
        label_17->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #f0f0f0; /* Un blanco/gris muy claro para no cansar la vista */\n"
"    font-family: \"Segoe UI\", Helvetica, Arial, sans-serif; /* Tipograf\303\255a moderna y limpia */\n"
"    font-size: 13px; /* Tama\303\261o est\303\241ndar legible */\n"
"    background-color: transparent; /* Transparente para que se vea tu fondo oscuro */\n"
"    border: none;\n"
"}"));
        label_18 = new QLabel(tab_5);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(290, 130, 49, 16));
        label_18->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #f0f0f0; /* Un blanco/gris muy claro para no cansar la vista */\n"
"    font-family: \"Segoe UI\", Helvetica, Arial, sans-serif; /* Tipograf\303\255a moderna y limpia */\n"
"    font-size: 13px; /* Tama\303\261o est\303\241ndar legible */\n"
"    background-color: transparent; /* Transparente para que se vea tu fondo oscuro */\n"
"    border: none;\n"
"}"));
        label_19 = new QLabel(tab_5);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(340, 10, 161, 21));
        label_19->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #ffffff; /* Blanco puro para destacar m\303\241s */\n"
"    font-size: 18px; /* Tama\303\261o de letra m\303\241s grande */\n"
"    font-weight: bold; /* Negrita */\n"
"}"));
        txtCodigoAsignar = new QLineEdit(tab_5);
        txtCodigoAsignar->setObjectName("txtCodigoAsignar");
        txtCodigoAsignar->setGeometry(QRect(380, 260, 171, 31));
        txtCodigoAsignar->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #2b2b2b;\n"
"    color: white;\n"
"    border: 1px solid #555555;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* Efecto cuando haces clic para escribir adentro */\n"
"QLineEdit:focus {\n"
"    border: 1px solid #0984e3; /* El borde se pone azul para indicar que est\303\241 activo */\n"
"    background-color: #333333; /* El fondo se aclara un poco */\n"
"}"));
        label_20 = new QLabel(tab_5);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(280, 260, 101, 16));
        label_20->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #f0f0f0; /* Un blanco/gris muy claro para no cansar la vista */\n"
"    font-family: \"Segoe UI\", Helvetica, Arial, sans-serif; /* Tipograf\303\255a moderna y limpia */\n"
"    font-size: 13px; /* Tama\303\261o est\303\241ndar legible */\n"
"    background-color: transparent; /* Transparente para que se vea tu fondo oscuro */\n"
"    border: none;\n"
"}"));
        comboTipoBeneficio = new QComboBox(tab_5);
        comboTipoBeneficio->addItem(QString());
        comboTipoBeneficio->addItem(QString());
        comboTipoBeneficio->addItem(QString());
        comboTipoBeneficio->setObjectName("comboTipoBeneficio");
        comboTipoBeneficio->setGeometry(QRect(290, 300, 261, 41));
        comboTipoBeneficio->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #2b2b2b; /* Fondo gris oscuro */\n"
"    color: white;              /* Texto blanco */\n"
"    border: 1px solid #555555; /* Borde gris sutil */\n"
"    border-radius: 4px;        /* Bordes ligeramente redondeados */\n"
"    padding: 5px;              /* Espacio interno para que el texto respire */\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    border: 1px solid #888888; /* El borde se ilumina un poco al pasar el rat\303\263n */\n"
"}\n"
"\n"
"/* Estilo de la lista que se abre hacia abajo */\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #2b2b2b; \n"
"    color: white;              \n"
"    selection-background-color: #0984e3; /* Fondo azul (mismo del bot\303\263n) al seleccionar */\n"
"    selection-color: white;\n"
"}"));
        txtDescBeneficio = new QLineEdit(tab_5);
        txtDescBeneficio->setObjectName("txtDescBeneficio");
        txtDescBeneficio->setGeometry(QRect(380, 353, 171, 31));
        txtDescBeneficio->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #2b2b2b;\n"
"    color: white;\n"
"    border: 1px solid #555555;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* Efecto cuando haces clic para escribir adentro */\n"
"QLineEdit:focus {\n"
"    border: 1px solid #0984e3; /* El borde se pone azul para indicar que est\303\241 activo */\n"
"    background-color: #333333; /* El fondo se aclara un poco */\n"
"}"));
        txtValorBeneficio = new QLineEdit(tab_5);
        txtValorBeneficio->setObjectName("txtValorBeneficio");
        txtValorBeneficio->setGeometry(QRect(380, 390, 171, 31));
        txtValorBeneficio->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #2b2b2b;\n"
"    color: white;\n"
"    border: 1px solid #555555;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* Efecto cuando haces clic para escribir adentro */\n"
"QLineEdit:focus {\n"
"    border: 1px solid #0984e3; /* El borde se pone azul para indicar que est\303\241 activo */\n"
"    background-color: #333333; /* El fondo se aclara un poco */\n"
"}"));
        label_21 = new QLabel(tab_5);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(290, 400, 91, 16));
        label_21->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #f0f0f0; /* Un blanco/gris muy claro para no cansar la vista */\n"
"    font-family: \"Segoe UI\", Helvetica, Arial, sans-serif; /* Tipograf\303\255a moderna y limpia */\n"
"    font-size: 13px; /* Tama\303\261o est\303\241ndar legible */\n"
"    background-color: transparent; /* Transparente para que se vea tu fondo oscuro */\n"
"    border: none;\n"
"}"));
        label_22 = new QLabel(tab_5);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(290, 360, 71, 16));
        label_22->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #f0f0f0; /* Un blanco/gris muy claro para no cansar la vista */\n"
"    font-family: \"Segoe UI\", Helvetica, Arial, sans-serif; /* Tipograf\303\255a moderna y limpia */\n"
"    font-size: 13px; /* Tama\303\261o est\303\241ndar legible */\n"
"    background-color: transparent; /* Transparente para que se vea tu fondo oscuro */\n"
"    border: none;\n"
"}"));
        pushButton_2 = new QPushButton(tab_5);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(290, 450, 261, 41));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #00b894;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 6px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #01a384; /* Un verde esmeralda ligeramente m\303\241s oscuro/intenso */\n"
"}"));
        btnReportePromos = new QPushButton(tab_5);
        btnReportePromos->setObjectName("btnReportePromos");
        btnReportePromos->setGeometry(QRect(290, 510, 261, 41));
        btnReportePromos->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #0984e3;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 6px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #74b9ff; /* Un azul m\303\241s claro e iluminado al pasar el rat\303\263n */\n"
"}"));
        label_23 = new QLabel(tab_5);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(350, 230, 131, 16));
        label_23->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #ffffff; /* Blanco puro para destacar m\303\241s */\n"
"    font-size: 18px; /* Tama\303\261o de letra m\303\241s grande */\n"
"    font-weight: bold; /* Negrita */\n"
"}"));
        tabWidgetAdmin->addTab(tab_5, QString());
        stackedWidget->addWidget(pageAdmin);
        pageUsuario = new QWidget();
        pageUsuario->setObjectName("pageUsuario");
        btnCerrarSesionUsuario = new QPushButton(pageUsuario);
        btnCerrarSesionUsuario->setObjectName("btnCerrarSesionUsuario");
        btnCerrarSesionUsuario->setGeometry(QRect(720, 630, 121, 31));
        btnCerrarSesionUsuario->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #c0392b;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 6px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #e74c3c; \n"
"}"));
        tabWidget = new QTabWidget(pageUsuario);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 851, 611));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabBar::tab:selected {\n"
"    background-color: #2c3e50;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}"));
        tab = new QWidget();
        tab->setObjectName("tab");
        tablaTaquilla = new QTableWidget(tab);
        if (tablaTaquilla->columnCount() < 8)
            tablaTaquilla->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tablaTaquilla->setHorizontalHeaderItem(0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tablaTaquilla->setHorizontalHeaderItem(1, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tablaTaquilla->setHorizontalHeaderItem(2, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tablaTaquilla->setHorizontalHeaderItem(3, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tablaTaquilla->setHorizontalHeaderItem(4, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tablaTaquilla->setHorizontalHeaderItem(5, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tablaTaquilla->setHorizontalHeaderItem(6, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tablaTaquilla->setHorizontalHeaderItem(7, __qtablewidgetitem20);
        tablaTaquilla->setObjectName("tablaTaquilla");
        tablaTaquilla->setGeometry(QRect(20, 210, 811, 361));
        tablaTaquilla->horizontalHeader()->setStretchLastSection(true);
        label_28 = new QLabel(tab);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(100, 10, 201, 191));
        label_28->setPixmap(QPixmap(QString::fromUtf8(":/imgTaquilla.png")));
        label_28->setScaledContents(true);
        horizontalLayoutWidget_4 = new QWidget(tab);
        horizontalLayoutWidget_4->setObjectName("horizontalLayoutWidget_4");
        horizontalLayoutWidget_4->setGeometry(QRect(370, 110, 361, 80));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_24 = new QLabel(horizontalLayoutWidget_4);
        label_24->setObjectName("label_24");
        label_24->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #f0f0f0; /* Un blanco/gris muy claro para no cansar la vista */\n"
"    font-family: \"Segoe UI\", Helvetica, Arial, sans-serif; /* Tipograf\303\255a moderna y limpia */\n"
"    font-size: 13px; /* Tama\303\261o est\303\241ndar legible */\n"
"    background-color: transparent; /* Transparente para que se vea tu fondo oscuro */\n"
"    border: none;\n"
"}"));

        horizontalLayout_4->addWidget(label_24);

        txtBuscarCodigo = new QLineEdit(horizontalLayoutWidget_4);
        txtBuscarCodigo->setObjectName("txtBuscarCodigo");
        txtBuscarCodigo->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #2b2b2b;\n"
"    color: white;\n"
"    border: 1px solid #555555;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* Efecto cuando haces clic para escribir adentro */\n"
"QLineEdit:focus {\n"
"    border: 1px solid #0984e3; /* El borde se pone azul para indicar que est\303\241 activo */\n"
"    background-color: #333333; /* El fondo se aclara un poco */\n"
"}"));

        horizontalLayout_4->addWidget(txtBuscarCodigo);

        btnBuscarPelicula = new QPushButton(horizontalLayoutWidget_4);
        btnBuscarPelicula->setObjectName("btnBuscarPelicula");
        btnBuscarPelicula->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #8A2BE2;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 6px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #0f5091; \n"
"}"));

        horizontalLayout_4->addWidget(btnBuscarPelicula);

        horizontalLayout_4->setStretch(1, 1);
        horizontalLayout_4->setStretch(2, 2);
        label_42 = new QLabel(tab);
        label_42->setObjectName("label_42");
        label_42->setGeometry(QRect(330, 20, 201, 21));
        label_42->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #ffffff; /* Blanco puro para destacar m\303\241s */\n"
"    font-size: 18px; /* Tama\303\261o de letra m\303\241s grande */\n"
"    font-weight: bold; /* Negrita */\n"
"}"));
        tabWidget->addTab(tab, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName("tab_9");
        label_29 = new QLabel(tab_9);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(310, 10, 261, 51));
        QFont font3;
        font3.setBold(true);
        label_29->setFont(font3);
        label_29->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #ffffff; /* Blanco puro para destacar m\303\241s */\n"
"    font-size: 18px; /* Tama\303\261o de letra m\303\241s grande */\n"
"    font-weight: bold; /* Negrita */\n"
"}"));
        tblMapaAsientos = new QTableWidget(tab_9);
        tblMapaAsientos->setObjectName("tblMapaAsientos");
        tblMapaAsientos->setGeometry(QRect(410, 100, 391, 331));
        btnVerDisponibilidad = new QPushButton(tab_9);
        btnVerDisponibilidad->setObjectName("btnVerDisponibilidad");
        btnVerDisponibilidad->setGeometry(QRect(490, 450, 221, 31));
        btnVerDisponibilidad->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #007bff;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"\n"
"    font-weight: bold;\n"
"    font-size: 13px; /* Opcional: letra ligeramente m\303\241s grande */\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #0056b3; /* Azul m\303\241s profundo al interactuar */\n"
"}"));
        formLayoutWidget_4 = new QWidget(tab_9);
        formLayoutWidget_4->setObjectName("formLayoutWidget_4");
        formLayoutWidget_4->setGeometry(QRect(72, 290, 311, 151));
        formLayout_4 = new QFormLayout(formLayoutWidget_4);
        formLayout_4->setObjectName("formLayout_4");
        formLayout_4->setContentsMargins(0, 0, 0, 0);
        label_30 = new QLabel(formLayoutWidget_4);
        label_30->setObjectName("label_30");
        label_30->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #f0f0f0; /* Un blanco/gris muy claro para no cansar la vista */\n"
"    font-family: \"Segoe UI\", Helvetica, Arial, sans-serif; /* Tipograf\303\255a moderna y limpia */\n"
"    font-size: 13px; /* Tama\303\261o est\303\241ndar legible */\n"
"    background-color: transparent; /* Transparente para que se vea tu fondo oscuro */\n"
"    border: none;\n"
"}"));

        formLayout_4->setWidget(0, QFormLayout::ItemRole::LabelRole, label_30);

        cbPeliculasDisponibles = new QComboBox(formLayoutWidget_4);
        cbPeliculasDisponibles->setObjectName("cbPeliculasDisponibles");
        cbPeliculasDisponibles->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #2b2b2b; /* Fondo gris oscuro */\n"
"    color: white;              /* Texto blanco */\n"
"    border: 1px solid #555555; /* Borde gris sutil */\n"
"    border-radius: 4px;        /* Bordes ligeramente redondeados */\n"
"    padding: 5px;              /* Espacio interno para que el texto respire */\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    border: 1px solid #888888; /* El borde se ilumina un poco al pasar el rat\303\263n */\n"
"}\n"
"\n"
"/* Estilo de la lista que se abre hacia abajo */\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #2b2b2b; \n"
"    color: white;              \n"
"    selection-background-color: #0984e3; /* Fondo azul (mismo del bot\303\263n) al seleccionar */\n"
"    selection-color: white;\n"
"}"));

        formLayout_4->setWidget(0, QFormLayout::ItemRole::FieldRole, cbPeliculasDisponibles);

        label_10 = new QLabel(formLayoutWidget_4);
        label_10->setObjectName("label_10");
        label_10->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #f0f0f0; /* Un blanco/gris muy claro para no cansar la vista */\n"
"    font-family: \"Segoe UI\", Helvetica, Arial, sans-serif; /* Tipograf\303\255a moderna y limpia */\n"
"    font-size: 13px; /* Tama\303\261o est\303\241ndar legible */\n"
"    background-color: transparent; /* Transparente para que se vea tu fondo oscuro */\n"
"    border: none;\n"
"}"));

        formLayout_4->setWidget(1, QFormLayout::ItemRole::LabelRole, label_10);

        cbFuncionesDisponibles = new QComboBox(formLayoutWidget_4);
        cbFuncionesDisponibles->setObjectName("cbFuncionesDisponibles");
        cbFuncionesDisponibles->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #2b2b2b; /* Fondo gris oscuro */\n"
"    color: white;              /* Texto blanco */\n"
"    border: 1px solid #555555; /* Borde gris sutil */\n"
"    border-radius: 4px;        /* Bordes ligeramente redondeados */\n"
"    padding: 5px;              /* Espacio interno para que el texto respire */\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    border: 1px solid #888888; /* El borde se ilumina un poco al pasar el rat\303\263n */\n"
"}\n"
"\n"
"/* Estilo de la lista que se abre hacia abajo */\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #2b2b2b; \n"
"    color: white;              \n"
"    selection-background-color: #0984e3; /* Fondo azul (mismo del bot\303\263n) al seleccionar */\n"
"    selection-color: white;\n"
"}"));

        formLayout_4->setWidget(1, QFormLayout::ItemRole::FieldRole, cbFuncionesDisponibles);

        label_12 = new QLabel(formLayoutWidget_4);
        label_12->setObjectName("label_12");
        label_12->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #f0f0f0; /* Un blanco/gris muy claro para no cansar la vista */\n"
"    font-family: \"Segoe UI\", Helvetica, Arial, sans-serif; /* Tipograf\303\255a moderna y limpia */\n"
"    font-size: 13px; /* Tama\303\261o est\303\241ndar legible */\n"
"    background-color: transparent; /* Transparente para que se vea tu fondo oscuro */\n"
"    border: none;\n"
"}"));

        formLayout_4->setWidget(2, QFormLayout::ItemRole::LabelRole, label_12);

        spinReservaFila = new QSpinBox(formLayoutWidget_4);
        spinReservaFila->setObjectName("spinReservaFila");
        spinReservaFila->setStyleSheet(QString::fromUtf8("/* Campo principal */\n"
"QSpinBox {\n"
"    background-color: #2b2b2b;\n"
"    border: 1px solid #3d3d3d;\n"
"    border-radius: 5px;\n"
"    color: #ffffff;\n"
"    padding: 4px 8px;\n"
"    font-size: 13px;\n"
"}\n"
"\n"
"QSpinBox:focus {\n"
"    border: 1px solid #1E90FF;\n"
"}\n"
"\n"
"/* Contenedor del bot\303\263n superior */\n"
"QSpinBox::up-button {\n"
"    subcontrol-origin: border;\n"
"    subcontrol-position: top right;\n"
"    width: 22px;\n"
"    background-color: #383838;\n"
"    border-top-right-radius: 4px;\n"
"    border-left: 1px solid #3d3d3d;\n"
"    border-bottom: 1px solid #2b2b2b;\n"
"}\n"
"\n"
"QSpinBox::up-button:hover {\n"
"    background-color: #1E90FF;\n"
"}\n"
"\n"
"QSpinBox::up-button:pressed {\n"
"    background-color: #1674cc;\n"
"}\n"
"\n"
"/* Tri\303\241ngulo Arriba mediante bordes puros */\n"
"QSpinBox::up-arrow {\n"
"    width: 0px;\n"
"    height: 0px;\n"
"    border-left: 4px solid transparent;\n"
"    border-right: 4px solid transparent;\n"
"    border-bottom: 5px solid "
                        "#ffffff;\n"
"}\n"
"\n"
"/* Contenedor del bot\303\263n inferior */\n"
"QSpinBox::down-button {\n"
"    subcontrol-origin: border;\n"
"    subcontrol-position: bottom right;\n"
"    width: 22px;\n"
"    background-color: #383838;\n"
"    border-bottom-right-radius: 4px;\n"
"    border-left: 1px solid #3d3d3d;\n"
"}\n"
"\n"
"QSpinBox::down-button:hover {\n"
"    background-color: #1E90FF;\n"
"}\n"
"\n"
"QSpinBox::down-button:pressed {\n"
"    background-color: #1674cc;\n"
"}\n"
"\n"
"/* Tri\303\241ngulo Abajo mediante bordes puros */\n"
"QSpinBox::down-arrow {\n"
"    width: 0px;\n"
"    height: 0px;\n"
"    border-left: 4px solid transparent;\n"
"    border-right: 4px solid transparent;\n"
"    border-top: 5px solid #ffffff;\n"
"}"));

        formLayout_4->setWidget(2, QFormLayout::ItemRole::FieldRole, spinReservaFila);

        label_13 = new QLabel(formLayoutWidget_4);
        label_13->setObjectName("label_13");
        label_13->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #f0f0f0; /* Un blanco/gris muy claro para no cansar la vista */\n"
"    font-family: \"Segoe UI\", Helvetica, Arial, sans-serif; /* Tipograf\303\255a moderna y limpia */\n"
"    font-size: 13px; /* Tama\303\261o est\303\241ndar legible */\n"
"    background-color: transparent; /* Transparente para que se vea tu fondo oscuro */\n"
"    border: none;\n"
"}"));

        formLayout_4->setWidget(3, QFormLayout::ItemRole::LabelRole, label_13);

        spinReservaColumna = new QSpinBox(formLayoutWidget_4);
        spinReservaColumna->setObjectName("spinReservaColumna");
        spinReservaColumna->setStyleSheet(QString::fromUtf8("/* Campo principal */\n"
"QSpinBox {\n"
"    background-color: #2b2b2b;\n"
"    border: 1px solid #3d3d3d;\n"
"    border-radius: 5px;\n"
"    color: #ffffff;\n"
"    padding: 4px 8px;\n"
"    font-size: 13px;\n"
"}\n"
"\n"
"QSpinBox:focus {\n"
"    border: 1px solid #1E90FF;\n"
"}\n"
"\n"
"/* Contenedor del bot\303\263n superior */\n"
"QSpinBox::up-button {\n"
"    subcontrol-origin: border;\n"
"    subcontrol-position: top right;\n"
"    width: 22px;\n"
"    background-color: #383838;\n"
"    border-top-right-radius: 4px;\n"
"    border-left: 1px solid #3d3d3d;\n"
"    border-bottom: 1px solid #2b2b2b;\n"
"}\n"
"\n"
"QSpinBox::up-button:hover {\n"
"    background-color: #1E90FF;\n"
"}\n"
"\n"
"QSpinBox::up-button:pressed {\n"
"    background-color: #1674cc;\n"
"}\n"
"\n"
"/* Tri\303\241ngulo Arriba mediante bordes puros */\n"
"QSpinBox::up-arrow {\n"
"    width: 0px;\n"
"    height: 0px;\n"
"    border-left: 4px solid transparent;\n"
"    border-right: 4px solid transparent;\n"
"    border-bottom: 5px solid "
                        "#ffffff;\n"
"}\n"
"\n"
"/* Contenedor del bot\303\263n inferior */\n"
"QSpinBox::down-button {\n"
"    subcontrol-origin: border;\n"
"    subcontrol-position: bottom right;\n"
"    width: 22px;\n"
"    background-color: #383838;\n"
"    border-bottom-right-radius: 4px;\n"
"    border-left: 1px solid #3d3d3d;\n"
"}\n"
"\n"
"QSpinBox::down-button:hover {\n"
"    background-color: #1E90FF;\n"
"}\n"
"\n"
"QSpinBox::down-button:pressed {\n"
"    background-color: #1674cc;\n"
"}\n"
"\n"
"/* Tri\303\241ngulo Abajo mediante bordes puros */\n"
"QSpinBox::down-arrow {\n"
"    width: 0px;\n"
"    height: 0px;\n"
"    border-left: 4px solid transparent;\n"
"    border-right: 4px solid transparent;\n"
"    border-top: 5px solid #ffffff;\n"
"}"));

        formLayout_4->setWidget(3, QFormLayout::ItemRole::FieldRole, spinReservaColumna);

        btnReservar = new QPushButton(tab_9);
        btnReservar->setObjectName("btnReservar");
        btnReservar->setGeometry(QRect(70, 450, 311, 28));
        btnReservar->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #8A2BE2;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 6px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #0f5091; \n"
"}"));
        label_52 = new QLabel(tab_9);
        label_52->setObjectName("label_52");
        label_52->setGeometry(QRect(110, 90, 201, 181));
        label_52->setPixmap(QPixmap(QString::fromUtf8(":/imgCinema.png")));
        label_52->setScaledContents(true);
        tabWidget->addTab(tab_9, QString());
        tab_15 = new QWidget();
        tab_15->setObjectName("tab_15");
        tblMisReservas = new QTableWidget(tab_15);
        tblMisReservas->setObjectName("tblMisReservas");
        tblMisReservas->setGeometry(QRect(110, 300, 651, 271));
        tblMisReservas->horizontalHeader()->setStretchLastSection(true);
        label_40 = new QLabel(tab_15);
        label_40->setObjectName("label_40");
        label_40->setGeometry(QRect(350, 20, 231, 31));
        label_40->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #ffffff; /* Blanco puro para destacar m\303\241s */\n"
"    font-size: 18px; /* Tama\303\261o de letra m\303\241s grande */\n"
"    font-weight: bold; /* Negrita */\n"
"}"));
        btnActualizarHistorial = new QPushButton(tab_15);
        btnActualizarHistorial->setObjectName("btnActualizarHistorial");
        btnActualizarHistorial->setGeometry(QRect(590, 170, 171, 31));
        btnActualizarHistorial->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #1abc9c;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 6px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #16a085; /* Turquesa un poco m\303\241s oscuro al pasar el rat\303\263n */\n"
"}"));
        label_55 = new QLabel(tab_15);
        label_55->setObjectName("label_55");
        label_55->setGeometry(QRect(150, 70, 231, 211));
        label_55->setPixmap(QPixmap(QString::fromUtf8(":/imgTicket.png")));
        label_55->setScaledContents(true);
        horizontalLayoutWidget_3 = new QWidget(tab_15);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(410, 210, 351, 80));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_39 = new QLabel(horizontalLayoutWidget_3);
        label_39->setObjectName("label_39");

        horizontalLayout_3->addWidget(label_39);

        txtCodigoCancelar = new QLineEdit(horizontalLayoutWidget_3);
        txtCodigoCancelar->setObjectName("txtCodigoCancelar");
        txtCodigoCancelar->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #2b2b2b;\n"
"    color: white;\n"
"    border: 1px solid #555555;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* Efecto cuando haces clic para escribir adentro */\n"
"QLineEdit:focus {\n"
"    border: 1px solid #0984e3; /* El borde se pone azul para indicar que est\303\241 activo */\n"
"    background-color: #333333; /* El fondo se aclara un poco */\n"
"}"));

        horizontalLayout_3->addWidget(txtCodigoCancelar);

        btnCancelarReserva = new QPushButton(horizontalLayoutWidget_3);
        btnCancelarReserva->setObjectName("btnCancelarReserva");
        btnCancelarReserva->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #8B3A62;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 6px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #0f5091; \n"
"}"));

        horizontalLayout_3->addWidget(btnCancelarReserva);

        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 2);
        tabWidget->addTab(tab_15, QString());
        tab_16 = new QWidget();
        tab_16->setObjectName("tab_16");
        btnGuardarCambios = new QPushButton(tab_16);
        btnGuardarCambios->setObjectName("btnGuardarCambios");
        btnGuardarCambios->setGeometry(QRect(250, 520, 291, 31));
        btnGuardarCambios->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #6A1FB5;\n"
"    color: white;\n"
"    border: 2px solid #8A2BE2;\n"
"    border-radius: 8px;\n"
"    padding: 8px 14px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #FF8C00;\n"
"    border: 2px solid #FF9800;\n"
"    color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #E67600;\n"
"    border: 2px solid #E67600;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #4A4A4A;\n"
"    color: #A0A0A0;\n"
"    border: 2px solid #666666;\n"
"}"));
        label_44 = new QLabel(tab_16);
        label_44->setObjectName("label_44");
        label_44->setGeometry(QRect(310, 20, 181, 161));
        label_44->setPixmap(QPixmap(QString::fromUtf8(":/imgEditProfile.png")));
        label_44->setScaledContents(true);
        verticalLayoutWidget_2 = new QWidget(tab_16);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(240, 200, 301, 301));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setSpacing(12);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(4);
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_54 = new QLabel(verticalLayoutWidget_2);
        label_54->setObjectName("label_54");
        label_54->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #f0f0f0; /* Un blanco/gris muy claro para no cansar la vista */\n"
"    font-family: \"Segoe UI\", Helvetica, Arial, sans-serif; /* Tipograf\303\255a moderna y limpia */\n"
"    font-size: 13px; /* Tama\303\261o est\303\241ndar legible */\n"
"    background-color: transparent; /* Transparente para que se vea tu fondo oscuro */\n"
"    border: none;\n"
"}"));

        verticalLayout_4->addWidget(label_54);

        txtEditNombre = new QLineEdit(verticalLayoutWidget_2);
        txtEditNombre->setObjectName("txtEditNombre");
        txtEditNombre->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #2b2b2b;\n"
"    color: white;\n"
"    border: 1px solid #555555;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* Efecto cuando haces clic para escribir adentro */\n"
"QLineEdit:focus {\n"
"    border: 1px solid #0984e3; /* El borde se pone azul para indicar que est\303\241 activo */\n"
"    background-color: #333333; /* El fondo se aclara un poco */\n"
"}"));

        verticalLayout_4->addWidget(txtEditNombre);


        verticalLayout_3->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(4);
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_71 = new QLabel(verticalLayoutWidget_2);
        label_71->setObjectName("label_71");
        label_71->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #f0f0f0; /* Un blanco/gris muy claro para no cansar la vista */\n"
"    font-family: \"Segoe UI\", Helvetica, Arial, sans-serif; /* Tipograf\303\255a moderna y limpia */\n"
"    font-size: 13px; /* Tama\303\261o est\303\241ndar legible */\n"
"    background-color: transparent; /* Transparente para que se vea tu fondo oscuro */\n"
"    border: none;\n"
"}"));

        verticalLayout_5->addWidget(label_71);

        txtEditCorreo = new QLineEdit(verticalLayoutWidget_2);
        txtEditCorreo->setObjectName("txtEditCorreo");
        txtEditCorreo->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #2b2b2b;\n"
"    color: white;\n"
"    border: 1px solid #555555;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* Efecto cuando haces clic para escribir adentro */\n"
"QLineEdit:focus {\n"
"    border: 1px solid #0984e3; /* El borde se pone azul para indicar que est\303\241 activo */\n"
"    background-color: #333333; /* El fondo se aclara un poco */\n"
"}"));

        verticalLayout_5->addWidget(txtEditCorreo);


        verticalLayout_3->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(4);
        verticalLayout_6->setObjectName("verticalLayout_6");
        label_70 = new QLabel(verticalLayoutWidget_2);
        label_70->setObjectName("label_70");
        label_70->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #f0f0f0; /* Un blanco/gris muy claro para no cansar la vista */\n"
"    font-family: \"Segoe UI\", Helvetica, Arial, sans-serif; /* Tipograf\303\255a moderna y limpia */\n"
"    font-size: 13px; /* Tama\303\261o est\303\241ndar legible */\n"
"    background-color: transparent; /* Transparente para que se vea tu fondo oscuro */\n"
"    border: none;\n"
"}"));

        verticalLayout_6->addWidget(label_70);

        txtEditTelefono = new QLineEdit(verticalLayoutWidget_2);
        txtEditTelefono->setObjectName("txtEditTelefono");
        txtEditTelefono->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #2b2b2b;\n"
"    color: white;\n"
"    border: 1px solid #555555;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* Efecto cuando haces clic para escribir adentro */\n"
"QLineEdit:focus {\n"
"    border: 1px solid #0984e3; /* El borde se pone azul para indicar que est\303\241 activo */\n"
"    background-color: #333333; /* El fondo se aclara un poco */\n"
"}"));

        verticalLayout_6->addWidget(txtEditTelefono);


        verticalLayout_3->addLayout(verticalLayout_6);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(4);
        verticalLayout_8->setObjectName("verticalLayout_8");
        label_72 = new QLabel(verticalLayoutWidget_2);
        label_72->setObjectName("label_72");
        label_72->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #f0f0f0; /* Un blanco/gris muy claro para no cansar la vista */\n"
"    font-family: \"Segoe UI\", Helvetica, Arial, sans-serif; /* Tipograf\303\255a moderna y limpia */\n"
"    font-size: 13px; /* Tama\303\261o est\303\241ndar legible */\n"
"    background-color: transparent; /* Transparente para que se vea tu fondo oscuro */\n"
"    border: none;\n"
"}"));

        verticalLayout_8->addWidget(label_72);

        txtEditContrasena = new QLineEdit(verticalLayoutWidget_2);
        txtEditContrasena->setObjectName("txtEditContrasena");
        txtEditContrasena->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #2b2b2b;\n"
"    color: white;\n"
"    border: 1px solid #555555;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* Efecto cuando haces clic para escribir adentro */\n"
"QLineEdit:focus {\n"
"    border: 1px solid #0984e3; /* El borde se pone azul para indicar que est\303\241 activo */\n"
"    background-color: #333333; /* El fondo se aclara un poco */\n"
"}"));
        txtEditContrasena->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout_8->addWidget(txtEditContrasena);


        verticalLayout_3->addLayout(verticalLayout_8);

        tabWidget->addTab(tab_16, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        txtTelefono = new QLineEdit(tab_2);
        txtTelefono->setObjectName("txtTelefono");
        txtTelefono->setGeometry(QRect(210, 180, 321, 31));
        txtTelefono->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #2b2b2b;\n"
"    color: white;\n"
"    border: 1px solid #555555;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* Efecto cuando haces clic para escribir adentro */\n"
"QLineEdit:focus {\n"
"    border: 1px solid #0984e3; /* El borde se pone azul para indicar que est\303\241 activo */\n"
"    background-color: #333333; /* El fondo se aclara un poco */\n"
"}"));
        label_5 = new QLabel(tab_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(210, 160, 131, 16));
        label_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #f0f0f0; /* Un blanco/gris muy claro para no cansar la vista */\n"
"    font-family: \"Segoe UI\", Helvetica, Arial, sans-serif; /* Tipograf\303\255a moderna y limpia */\n"
"    font-size: 13px; /* Tama\303\261o est\303\241ndar legible */\n"
"    background-color: transparent; /* Transparente para que se vea tu fondo oscuro */\n"
"    border: none;\n"
"}"));
        comboTipoSolicitud = new QComboBox(tab_2);
        comboTipoSolicitud->addItem(QString());
        comboTipoSolicitud->addItem(QString());
        comboTipoSolicitud->addItem(QString());
        comboTipoSolicitud->addItem(QString());
        comboTipoSolicitud->addItem(QString());
        comboTipoSolicitud->setObjectName("comboTipoSolicitud");
        comboTipoSolicitud->setGeometry(QRect(210, 220, 321, 31));
        comboTipoSolicitud->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #2b2b2b; /* Fondo gris oscuro */\n"
"    color: white;              /* Texto blanco */\n"
"    border: 1px solid #555555; /* Borde gris sutil */\n"
"    border-radius: 4px;        /* Bordes ligeramente redondeados */\n"
"    padding: 5px;              /* Espacio interno para que el texto respire */\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    border: 1px solid #888888; /* El borde se ilumina un poco al pasar el rat\303\263n */\n"
"}"));
        txtDescripcion = new QTextEdit(tab_2);
        txtDescripcion->setObjectName("txtDescripcion");
        txtDescripcion->setGeometry(QRect(210, 300, 331, 141));
        txtDescripcion->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    background-color: #2b2b2b;\n"
"    color: white;\n"
"    border: 1px solid #555555;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"QTextEdit:focus {\n"
"    border: 1px solid #007bff; /* Borde azul que combina con tu bot\303\263n de Enviar */\n"
"    background-color: #333333;\n"
"}"));
        btnEnviarSolicitud = new QPushButton(tab_2);
        btnEnviarSolicitud->setObjectName("btnEnviarSolicitud");
        btnEnviarSolicitud->setGeometry(QRect(210, 470, 331, 31));
        btnEnviarSolicitud->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #007bff;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 8px; /* Un poco m\303\241s de relleno (padding) para que se vea m\303\241s grande e importante */\n"
"    font-weight: bold;\n"
"    font-size: 13px; /* Opcional: letra ligeramente m\303\241s grande */\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #0056b3; /* Azul m\303\241s profundo al interactuar */\n"
"}"));
        label_11 = new QLabel(tab_2);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(220, 260, 91, 21));
        label_11->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #f0f0f0; /* Un blanco/gris muy claro para no cansar la vista */\n"
"    font-family: \"Segoe UI\", Helvetica, Arial, sans-serif; /* Tipograf\303\255a moderna y limpia */\n"
"    font-size: 13px; /* Tama\303\261o est\303\241ndar legible */\n"
"    background-color: transparent; /* Transparente para que se vea tu fondo oscuro */\n"
"    border: none;\n"
"}"));
        txtNombreSolicitud = new QLineEdit(tab_2);
        txtNombreSolicitud->setObjectName("txtNombreSolicitud");
        txtNombreSolicitud->setGeometry(QRect(210, 120, 321, 31));
        txtNombreSolicitud->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #2b2b2b;\n"
"    color: white;\n"
"    border: 1px solid #555555;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* Efecto cuando haces clic para escribir adentro */\n"
"QLineEdit:focus {\n"
"    border: 1px solid #0984e3; /* El borde se pone azul para indicar que est\303\241 activo */\n"
"    background-color: #333333; /* El fondo se aclara un poco */\n"
"}"));
        label_14 = new QLabel(tab_2);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(210, 90, 131, 21));
        label_14->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #f0f0f0; /* Un blanco/gris muy claro para no cansar la vista */\n"
"    font-family: \"Segoe UI\", Helvetica, Arial, sans-serif; /* Tipograf\303\255a moderna y limpia */\n"
"    font-size: 13px; /* Tama\303\261o est\303\241ndar legible */\n"
"    background-color: transparent; /* Transparente para que se vea tu fondo oscuro */\n"
"    border: none;\n"
"}"));
        label_15 = new QLabel(tab_2);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(330, 20, 141, 41));
        label_15->setFont(font3);
        label_15->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #ffffff; /* Blanco puro para destacar m\303\241s */\n"
"    font-size: 18px; /* Tama\303\261o de letra m\303\241s grande */\n"
"    font-weight: bold; /* Negrita */\n"
"}"));
        txtBuscarTelefonoSolicitud = new QLineEdit(tab_2);
        txtBuscarTelefonoSolicitud->setObjectName("txtBuscarTelefonoSolicitud");
        txtBuscarTelefonoSolicitud->setGeometry(QRect(560, 120, 251, 31));
        txtBuscarTelefonoSolicitud->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #2b2b2b;\n"
"    color: white;\n"
"    border: 1px solid #555555;\n"
"    border-radius: 4px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* Efecto cuando haces clic para escribir adentro */\n"
"QLineEdit:focus {\n"
"    border: 1px solid #0984e3; /* El borde se pone azul para indicar que est\303\241 activo */\n"
"    background-color: #333333; /* El fondo se aclara un poco */\n"
"}"));
        label_25 = new QLabel(tab_2);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(560, 100, 201, 16));
        label_25->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #f0f0f0; /* Un blanco/gris muy claro para no cansar la vista */\n"
"    font-family: \"Segoe UI\", Helvetica, Arial, sans-serif; /* Tipograf\303\255a moderna y limpia */\n"
"    font-size: 13px; /* Tama\303\261o est\303\241ndar legible */\n"
"    background-color: transparent; /* Transparente para que se vea tu fondo oscuro */\n"
"    border: none;\n"
"}"));
        btnBuscarSolicitud = new QPushButton(tab_2);
        btnBuscarSolicitud->setObjectName("btnBuscarSolicitud");
        btnBuscarSolicitud->setGeometry(QRect(620, 160, 151, 31));
        btnBuscarSolicitud->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #1abc9c;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 6px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #16a085; /* Turquesa un poco m\303\241s oscuro al pasar el rat\303\263n */\n"
"}"));
        tabWidget->addTab(tab_2, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName("tab_6");
        arbolPromos = new QTreeWidget(tab_6);
        arbolPromos->setObjectName("arbolPromos");
        arbolPromos->setGeometry(QRect(0, 0, 841, 581));
        tabWidget->addTab(tab_6, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName("tab_8");
        lblVisorUsuario = new QLabel(tab_8);
        lblVisorUsuario->setObjectName("lblVisorUsuario");
        lblVisorUsuario->setGeometry(QRect(20, 20, 801, 541));
        lblVisorUsuario->setScaledContents(true);
        tabWidget->addTab(tab_8, QString());
        stackedWidget->addWidget(pageUsuario);

        verticalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 863, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(1);
        tabWidgetAdmin->setCurrentIndex(3);
        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnIniciarSesion->setText(QCoreApplication::translate("MainWindow", "Iniciar Sesi\303\263n", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Contrase\303\261a:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Correo: ", nullptr));
        label_26->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "Iniciar Sesi\303\263n", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_11), QCoreApplication::translate("MainWindow", "Iniciar Sesi\303\263n", nullptr));
        label_37->setText(QString());
        label_33->setText(QCoreApplication::translate("MainWindow", "Nombre:", nullptr));
        label_34->setText(QCoreApplication::translate("MainWindow", "Correo Electronico: ", nullptr));
        label_35->setText(QCoreApplication::translate("MainWindow", "N\303\272mero de tel\303\251fono:", nullptr));
        label_36->setText(QCoreApplication::translate("MainWindow", "Contrase\303\261a:  ", nullptr));
        btnRegistrar->setText(QCoreApplication::translate("MainWindow", "Registrarse", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_12), QCoreApplication::translate("MainWindow", "Registrarse", nullptr));
        btnCerrarSesionAdmin->setText(QCoreApplication::translate("MainWindow", "Cerrar Sesi\303\263n", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tablaCartelera->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Co. PELICULA", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tablaCartelera->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "TITULO", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tablaCartelera->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "GENERO", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tablaCartelera->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "DURACION", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tablaCartelera->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "CLASIFICACION", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tablaCartelera->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "IDIOMA", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tablaCartelera->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "FECHA ESTRENO", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tablaCartelera->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "FECHA FIN", nullptr));
        btnCargarPeliculasJSON->setText(QCoreApplication::translate("MainWindow", "Cargar Peliculas", nullptr));
        btnAlertas->setText(QCoreApplication::translate("MainWindow", "Ver Alertas de Cartelera", nullptr));
        cbOrdenPeliculas->setItemText(0, QCoreApplication::translate("MainWindow", "Inorden", nullptr));
        cbOrdenPeliculas->setItemText(1, QCoreApplication::translate("MainWindow", "Preorden", nullptr));
        cbOrdenPeliculas->setItemText(2, QCoreApplication::translate("MainWindow", "Postorden", nullptr));

        label_41->setText(QCoreApplication::translate("MainWindow", "C\303\263digo Pel\303\255cula:", nullptr));
        label_45->setText(QCoreApplication::translate("MainWindow", "T\303\255tulo: ", nullptr));
        label_46->setText(QCoreApplication::translate("MainWindow", "G\303\251nero:", nullptr));
        label_47->setText(QCoreApplication::translate("MainWindow", "Duraci\303\263n:", nullptr));
        label_48->setText(QCoreApplication::translate("MainWindow", "Clasificaci\303\263n", nullptr));
        label_49->setText(QCoreApplication::translate("MainWindow", "Idioma:", nullptr));
        label_50->setText(QCoreApplication::translate("MainWindow", "Fecha Estreno:", nullptr));
        label_51->setText(QCoreApplication::translate("MainWindow", "Fecha Fin:", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "Orden Cartelera:", nullptr));
        btnAgregarPelicula->setText(QCoreApplication::translate("MainWindow", "Agregar Pel\303\255cula", nullptr));
        btnEditarPelicula->setText(QCoreApplication::translate("MainWindow", "Editar Pelicula", nullptr));
        btnEliminarPelicula->setText(QCoreApplication::translate("MainWindow", "Eliminar Pelicula", nullptr));
        tabWidgetAdmin->setTabText(tabWidgetAdmin->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Cartelera", nullptr));
        label_53->setText(QCoreApplication::translate("MainWindow", "GESTI\303\223N DE CLIENTES", nullptr));
        label_67->setText(QString());
        label_38->setText(QCoreApplication::translate("MainWindow", "Buscar Cliente:", nullptr));
        btnBuscarIdCliente->setText(QCoreApplication::translate("MainWindow", "Buscar Cliente", nullptr));
        btnCargaMasivaClientes->setText(QCoreApplication::translate("MainWindow", "Cargar Clientes", nullptr));
        btnActualizarTabla->setText(QCoreApplication::translate("MainWindow", "Actualizar Tabla", nullptr));
        label_68->setText(QCoreApplication::translate("MainWindow", "ID Cliente:", nullptr));
        btnEliminarCliente->setText(QCoreApplication::translate("MainWindow", "Eliminar", nullptr));
        tabWidgetAdmin->setTabText(tabWidgetAdmin->indexOf(tab_13), QCoreApplication::translate("MainWindow", "Clientes", nullptr));
        btnCrearFuncion->setText(QCoreApplication::translate("MainWindow", "Crear Funci\303\263n", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "FUNCIONES", nullptr));
        label_65->setText(QString());
        label_9->setText(QCoreApplication::translate("MainWindow", "Pel\303\255cula:", nullptr));
        label_66->setText(QCoreApplication::translate("MainWindow", "Sala:", nullptr));
        comboSala->setItemText(0, QCoreApplication::translate("MainWindow", "Sala 1", nullptr));
        comboSala->setItemText(1, QCoreApplication::translate("MainWindow", "Sala 2", nullptr));
        comboSala->setItemText(2, QCoreApplication::translate("MainWindow", "Sala 3", nullptr));
        comboSala->setItemText(3, QCoreApplication::translate("MainWindow", "Sala 4", nullptr));

        label_8->setText(QCoreApplication::translate("MainWindow", "Horario:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Filas:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Columnas:", nullptr));
        tabWidgetAdmin->setTabText(tabWidgetAdmin->indexOf(tab_10), QCoreApplication::translate("MainWindow", "Funciones", nullptr));
        label_56->setText(QCoreApplication::translate("MainWindow", "GESTI\303\223N DE FUNCIONES", nullptr));
        label_57->setText(QCoreApplication::translate("MainWindow", "C\303\263digo:", nullptr));
        label_58->setText(QCoreApplication::translate("MainWindow", "C\303\263digo:", nullptr));
        label_59->setText(QCoreApplication::translate("MainWindow", "Pel\303\255cula:", nullptr));
        label_60->setText(QCoreApplication::translate("MainWindow", "Horario:", nullptr));
        label_61->setText(QCoreApplication::translate("MainWindow", "Sala:", nullptr));
        label_62->setText(QCoreApplication::translate("MainWindow", "Fila:", nullptr));
        label_63->setText(QCoreApplication::translate("MainWindow", "Columnas:", nullptr));
        btnBuscarFuncion->setText(QCoreApplication::translate("MainWindow", "Buscar", nullptr));
        btnActualizarFunciones->setText(QCoreApplication::translate("MainWindow", "Actualizar ", nullptr));
        label_64->setText(QString());
        btnGuardarEdicionFuncion->setText(QCoreApplication::translate("MainWindow", "Guardar Cambios", nullptr));
        btnEliminarFun->setText(QCoreApplication::translate("MainWindow", "Eliminar ", nullptr));
        cbOrdenFunciones->setItemText(0, QCoreApplication::translate("MainWindow", "Inorden", nullptr));
        cbOrdenFunciones->setItemText(1, QCoreApplication::translate("MainWindow", "Postorden", nullptr));
        cbOrdenFunciones->setItemText(2, QCoreApplication::translate("MainWindow", "Preorden", nullptr));

        label_74->setText(QCoreApplication::translate("MainWindow", "Orden Funciones:", nullptr));
        tabWidgetAdmin->setTabText(tabWidgetAdmin->indexOf(tab_14), QCoreApplication::translate("MainWindow", "Gesti\303\263n Funciones", nullptr));
        label_69->setText(QCoreApplication::translate("MainWindow", "Selecciona un reporte abajo para generar el diagrama", nullptr));
        lblVisorAdmin->setText(QString());
        btnReportePeliculas->setText(QCoreApplication::translate("MainWindow", "Cartelera", nullptr));
        btnReporteFunciones->setText(QCoreApplication::translate("MainWindow", "Funciones", nullptr));
        btnReporteClientes->setText(QCoreApplication::translate("MainWindow", "Clientes", nullptr));
        btnReporteMatriz->setText(QCoreApplication::translate("MainWindow", "Mapa Asientos", nullptr));
        tabWidgetAdmin->setTabText(tabWidgetAdmin->indexOf(tab_7), QCoreApplication::translate("MainWindow", "Visor de Reportes", nullptr));
        btnReporteReservas->setText(QCoreApplication::translate("MainWindow", "Reservas", nullptr));
        lblVisorHash->setText(QString());
        label_73->setText(QCoreApplication::translate("MainWindow", "Generar Tabla Hash de Reservas\n"
"", nullptr));
        tabWidgetAdmin->setTabText(tabWidgetAdmin->indexOf(tab_17), QCoreApplication::translate("MainWindow", "Reporte Hash", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tablaAdminSolicitudes->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tablaAdminSolicitudes->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "CLIENTE", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tablaAdminSolicitudes->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "TELEFONO", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tablaAdminSolicitudes->horizontalHeaderItem(3);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "TIPO", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tablaAdminSolicitudes->horizontalHeaderItem(4);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "ESTADO", nullptr));
        lblDetalleSolicitud->setText(QCoreApplication::translate("MainWindow", "Selecciona procesar...", nullptr));
        btnProcesarPrimera->setText(QCoreApplication::translate("MainWindow", "Detalles Solicitud", nullptr));
        btnAprobarSolicitud->setText(QCoreApplication::translate("MainWindow", "Aprobar Solicitud", nullptr));
        btnRechazarSolicitud->setText(QCoreApplication::translate("MainWindow", "Rechazar Solicitud", nullptr));
        btnEnProceso->setText(QCoreApplication::translate("MainWindow", "Marcar en Proceso", nullptr));
        btnReporteSolicitudes->setText(QCoreApplication::translate("MainWindow", "Reporte Solicitudes", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "Gesti\303\263n Solicitudes", nullptr));
        cmbRecorridosClientes->setItemText(0, QCoreApplication::translate("MainWindow", "Inorden", nullptr));
        cmbRecorridosClientes->setItemText(1, QCoreApplication::translate("MainWindow", "Preorden", nullptr));
        cmbRecorridosClientes->setItemText(2, QCoreApplication::translate("MainWindow", "Postorden", nullptr));

        label_43->setText(QCoreApplication::translate("MainWindow", "Orden Clientes:", nullptr));
        label_75->setText(QCoreApplication::translate("MainWindow", "ESTO VA EN \"Clientes\"", nullptr));
        tabWidgetAdmin->setTabText(tabWidgetAdmin->indexOf(tab_4), QCoreApplication::translate("MainWindow", "Gestion de Solicitudes", nullptr));
        btnCrearPromo->setText(QCoreApplication::translate("MainWindow", "Crear Promoci\303\263n", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Codigo:", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Nombre:", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Vigencia:", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "D\303\255as:", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Crear Promoci\303\263n", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "Codigo Asignar", nullptr));
        comboTipoBeneficio->setItemText(0, QCoreApplication::translate("MainWindow", "Descuento", nullptr));
        comboTipoBeneficio->setItemText(1, QCoreApplication::translate("MainWindow", "2x1", nullptr));
        comboTipoBeneficio->setItemText(2, QCoreApplication::translate("MainWindow", "Combo Regalo", nullptr));

        label_21->setText(QCoreApplication::translate("MainWindow", "Valor Beneficio", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "Descuento", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Agregar Beneficio", nullptr));
        btnReportePromos->setText(QCoreApplication::translate("MainWindow", "Generar Grafo de Promociones", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "Crear Beneficios", nullptr));
        tabWidgetAdmin->setTabText(tabWidgetAdmin->indexOf(tab_5), QCoreApplication::translate("MainWindow", "Gesti\303\263n de Promociones", nullptr));
        btnCerrarSesionUsuario->setText(QCoreApplication::translate("MainWindow", "Cerrar Sesion", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tablaTaquilla->horizontalHeaderItem(0);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "CO. PELICULA", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tablaTaquilla->horizontalHeaderItem(1);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "TITULO", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tablaTaquilla->horizontalHeaderItem(2);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "GENERO", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tablaTaquilla->horizontalHeaderItem(3);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "DURACION", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tablaTaquilla->horizontalHeaderItem(4);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "CLASIFICACION", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tablaTaquilla->horizontalHeaderItem(5);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "IDIOMA", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tablaTaquilla->horizontalHeaderItem(6);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "FECHA ESTRENO", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tablaTaquilla->horizontalHeaderItem(7);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("MainWindow", "FECHA FIN", nullptr));
        label_28->setText(QString());
        label_24->setText(QCoreApplication::translate("MainWindow", "Codigo Pelicula:", nullptr));
        btnBuscarPelicula->setText(QCoreApplication::translate("MainWindow", "Buscar Pelicula", nullptr));
        label_42->setText(QCoreApplication::translate("MainWindow", "Cartelera de Pel\303\255culas", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Taquilla", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "Realizar reserva de Asiento", nullptr));
        btnVerDisponibilidad->setText(QCoreApplication::translate("MainWindow", "Ver disponibilidad", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "Pelicula:", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Funcion:", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Fila:", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Columna:", nullptr));
        btnReservar->setText(QCoreApplication::translate("MainWindow", "Reservar Asiento", nullptr));
        label_52->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_9), QCoreApplication::translate("MainWindow", "Reservar Asiento", nullptr));
        label_40->setText(QCoreApplication::translate("MainWindow", "Historial de Reservas", nullptr));
        btnActualizarHistorial->setText(QCoreApplication::translate("MainWindow", "Actualizar Historial", nullptr));
        label_55->setText(QString());
        label_39->setText(QCoreApplication::translate("MainWindow", "C\303\263digo Reserva:", nullptr));
        btnCancelarReserva->setText(QCoreApplication::translate("MainWindow", "Cancelar Reserva", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_15), QCoreApplication::translate("MainWindow", "Mis Reservas", nullptr));
        btnGuardarCambios->setText(QCoreApplication::translate("MainWindow", "Guardar Cambios", nullptr));
        label_44->setText(QString());
        label_54->setText(QCoreApplication::translate("MainWindow", "Nombre:", nullptr));
        label_71->setText(QCoreApplication::translate("MainWindow", "Correo Electronico:", nullptr));
        label_70->setText(QCoreApplication::translate("MainWindow", "N\303\272mero de Tel\303\251fono:", nullptr));
        label_72->setText(QCoreApplication::translate("MainWindow", "Contrase\303\261a:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_16), QCoreApplication::translate("MainWindow", "Editar Perfil", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Numero de Telefono:", nullptr));
        comboTipoSolicitud->setItemText(0, QCoreApplication::translate("MainWindow", "Cumplea\303\261os", nullptr));
        comboTipoSolicitud->setItemText(1, QCoreApplication::translate("MainWindow", "Aniversario", nullptr));
        comboTipoSolicitud->setItemText(2, QCoreApplication::translate("MainWindow", "Requerimiento especial", nullptr));
        comboTipoSolicitud->setItemText(3, QCoreApplication::translate("MainWindow", "Queja", nullptr));
        comboTipoSolicitud->setItemText(4, QCoreApplication::translate("MainWindow", "Sugerencia", nullptr));

        btnEnviarSolicitud->setText(QCoreApplication::translate("MainWindow", "Enviar Solicitud", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Descripci\303\263n", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Nombre del Cliente:", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Solicitudes", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "Ingresa tu tel\303\251fono para buscar:", nullptr));
        btnBuscarSolicitud->setText(QCoreApplication::translate("MainWindow", "Consultar Estado", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Solicitudes Especiales", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = arbolPromos->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("MainWindow", "Promociones Disponibles", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("MainWindow", "Promociones", nullptr));
        lblVisorUsuario->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_8), QCoreApplication::translate("MainWindow", "Visor Reportes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
