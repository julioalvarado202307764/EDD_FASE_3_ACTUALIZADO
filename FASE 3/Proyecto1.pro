QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ArbolAVL.cpp \
    ArbolB.cpp \
    ArbolPeliculas.cpp \
    GrafoSedes.cpp \
    ListaPromociones.cpp \
    ListaSolicitudes.cpp \
    MatrizDispersa.cpp \
    NodoAVL.cpp \
    NodoB.cpp \
    TablaHash.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    ArbolAVL.h \
    ArbolB.h \
    ArbolPeliculas.h \
    Beneficio.h \
    GrafoSedes.h \
    ListaPromociones.h \
    ListaSolicitudes.h \
    MatrizDispersa.h \
    NodoAVL.h \
    NodoB.h \
    NodoBST.h \
    NodoHash.h \
    NodoMatriz.h \
    NodoSolicitud.h \
    Pelicula.h \
    Promocion.h \
    Sede.h \
    Solicitud.h \
    TablaHash.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
