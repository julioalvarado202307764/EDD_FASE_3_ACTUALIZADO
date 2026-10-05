# Manual Técnico - Sistema de Gestión de Cine (Fase 2)

Este documento detalla la arquitectura de software, la implementación de estructuras de datos no lineales y las decisiones de diseño adoptadas para la Fase 2 del Sistema de Gestión de Cine, desarrollado en C++ utilizando el framework Qt Widgets.

## 1. Árbol Binario de Búsqueda (BST) - Cartelera de Películas

El árbol binario de búsqueda administra el catálogo global de películas, utilizando el código de la película como llave de ordenamiento principal.

* **Implementación:** Estructura de nodos dinámicos con punteros `izquierdo` y `derecho`. Inserción iterativa/recursiva estándar que mantiene la propiedad del árbol (hijos izquierdos menores, hijos derechos mayores).
* **Decisiones de Diseño:**
  * **Integración de Fechas:** Se optó por almacenar las fechas en formato `std::string` y delegar la conversión lógica a la librería `QDate` de Qt únicamente en tiempo de ejecución (UI y reportes) para mantener la estructura de datos agnóstica al framework.
  * **Renderizado de Estados:** Para el reporte de Graphviz, se inyectó una validación matemática de días restantes (`diasRestantes <= 7`) para determinar dinámicamente el atributo `fillcolor` del nodo en el archivo `.dot`.

## 2. Árbol AVL - Funciones

El árbol AVL gestiona las funciones programadas en las distintas salas, garantizando tiempos de búsqueda de $O(\log n)$ al mantener un factor de equilibrio estricto.

* **Implementación:** Hereda la lógica del BST pero incorpora una variable `altura` en cada nodo. Durante cada inserción o eliminación, el sistema recalcula el factor de equilibrio (diferencia de alturas entre subárboles) y ejecuta rotaciones (Simples o Dobles, a la Izquierda o Derecha) si el factor sale del rango `[-1, 1]`.
* **Decisiones de Diseño:**
  * **Optimización de Carga Masiva:** Dado que las cargas masivas desde JSON suelen venir ordenadas o semi-ordenadas, un BST estándar se degradaría a una lista enlazada ($O(n)$). El AVL previene esto, lo cual es crítico porque el sistema consulta el AVL constantemente al poblar la matriz dispersa de cada función.
  * **Lógica de Tiempo Real:** El reporte utiliza `QTime` para evaluar en tiempo real si el horario de la función (`horaFuncion < horaActual`) ya transcurrió, alterando el grafo dinámicamente.

## 3. Árbol B (Orden 4) - Gestión de Clientes

Estructura de árbol de búsqueda n-ario auto-balanceado diseñado para el almacenamiento del padrón de usuarios y administradores.

* **Implementación:** Nodos que soportan hasta 3 claves (clientes) y 4 punteros a hijos. La inserción utiliza un algoritmo de partición (Split) proactivo: si al descender se detecta un nodo lleno, se divide y se promueve la clave mediana al padre antes de continuar.
* **Decisiones de Diseño:**
  * **Clave Foránea en Memoria RAM:** Para evitar copias masivas de objetos redundantes, el nodo del cliente guarda únicamente un vector estándar (`std::vector<std::string> codigos_reservas`). Este vector actúa como una clave foránea que apunta a la Tabla Hash de reservas.
  * **Sobrecarga del Constructor de Copia:** Durante la división de nodos (`dividirHijo`), se exige una "copia profunda" (`new Cliente(cliente)`) en lugar de una asignación directa de punteros, previniendo fugas de memoria y la pérdida del historial de reservas al reestructurar el árbol.

## 4. Tabla Hash - Almacenamiento de Reservas

Estructura de acceso directo en tiempo $O(1)$ para la búsqueda y validación de boletos.

* **Implementación:** Arreglo estático de punteros (`std::vector<NodoHash*>`) de capacidad 97. La dispersión se realiza sumando los valores ASCII del `codigo_reserva` y aplicando módulo contra la capacidad de la tabla.
* **Manejo de Colisiones:** Se implementó por medio de encadenamiento (Listas Simples Enlazadas). Si dos claves generan el mismo índice, se adjunta un nuevo `NodoHash` al final de la lista del respectivo bucket.
* **Decisiones de Diseño:**
  * **Número Primo:** La capacidad inicial de 97 reduce el índice natural de colisiones de la función hash modular.
  * **Diseño de Nodos Graphviz:** En lugar de renderizar arrays abstractos, el método generador de `.dot` aplica `rankdir=LR` e itera sobre los buckets mapeando cada colisión horizontalmente mediante `shape=record`, permitiendo auditar la eficiencia matemática de la función Hash visualmente.

## 5. Matriz Dispersa - Mapa de Asientos

Estructura bidimensional ortogonal que mapea la ocupación física de los asientos por cada sala y función.

* **Implementación:** Red de `NodoMatriz` enlazados mediante cuatro punteros (`arriba`, `abajo`, `izquierda`, `derecha`). Consta de nodos cabecera independientes para el eje X (Columnas) y el eje Y (Filas). Los nodos internos solo se instancian si un asiento es reservado.
* **Decisiones de Diseño:**
  * **Persistencia Dinámica por Función:** Para evitar colapsos de memoria al gestionar decenas de funciones, la clase `MatrizDispersa` carga a demanda el estado de la sala leyendo un JSON específico (ej. `F001_funcion.json`), opera sobre los punteros en RAM, y sobrescribe el archivo en el disco al finalizar la transacción (Reserva/Cancelación).
  * **Renderizado de Cuadrícula Perfecta:** Graphviz no está diseñado para dibujar matrices por defecto (las renderiza como árboles jerárquicos). Se forzó la renderización ortogonal utilizando agrupamientos (`group`) para las columnas y alineaciones de mismo nivel (`{ rank=same; }`) para las filas.

## 6. Integración Interfaz-Visualización (Qt y Graphviz)

Todo el sistema está encapsulado en una arquitectura orientada a eventos usando Qt Widgets.

* Para garantizar la estabilidad del hilo principal (Main Thread), la generación de diagramas se ejecuta llamando al sistema operativo nativo mediante `QProcess`, invocando el compilador binario `dot`.
* La salida se inyecta en la vista a través de `QPixmap` escalado paramétricamente (o redirigido al visor nativo del S.O. con `QDesktopServices` en caso de grafos de alta densidad, como la Tabla Hash con baja dispersión).
