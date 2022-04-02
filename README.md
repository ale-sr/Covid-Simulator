# Proyecto Final - POO2
# Pandemic Simulator

## Integrantes ✒️

* **Alexandra Shulca Romero** - [Alexandra-SR - alexandra.shulca@utec.edu.pe]
* **Alexis Elefteriu** - [Nordevor - alexis.elefteriu@utec.edu.pe]
* **Harlop Flores** - [HarlopFlores - jorge.flores.b@utec.edu.pe]
* **Esteban Principe** - [Miunmn - esteban.principe@utec.edu.pe]

## Descripción del Proyecto :book:
En este proyecto final del curso, se buscó implementar en C++ un simulador de partículas basado en eventos, utilizando la librería de SFML. Es así, que nuestro grupo propone utilizar esta base para la creación de un simulador epidemiológico en el contexto de la pandemia del COVID-19.

De este modo, el proyecto tiene como objetivo simular la rapidez de contagio del COVID-19 en tres escenarios distintos: 

* **Personas Libres (Sin distanciamiento Social):**

  Entorno en donde no existen políticas y concienciación sobre el distanciamiento social para frenar la tasa de contagios en lugares públicos.

* **Distanciamiento Social Promedio:**

  Entorno en donde existen ciertos sectores en donde se practica y fomenta el distanciamiento social. Sin embargo, también existen personas que no desean realizar esta práctica   y se desplazan libremente y sin preocupaciones en espacios públicos.

* **Distanciamiento Social Extensivo**

  Entorno en donde existe una gran concienciación sobre la importancia del distanciamiento social y es practicada por la gran mayoría de la población.

## Objetivos Principales :dart:

- Permitir una clara visualización de los contagios en los diferentes escenarios.
- Diseñar e implementar dentro del proyecto un simulador basado en eventos.
- Añadir un menú básico para facilitar la interacción con el sistema.

## Comenzando 🚀

### Pre-requisitos 📋

```
C++ 17 , SFML 2.5.1
```

### Despliegue 📦

**1**. Clonar el repositorio del proyecto.

**2.** Realizar el Build del proyecto utilizando el IDE CLion.

**3.** Ejecutar el programa y escoger el escenario de la simulación en el menú mostrado en la terminal.

**4.** Simular los contagios :smile:

**5.** Finalizar la simulación presionando la tecla **Esc** 

## Video Explicatorio :clapper:

https://youtu.be/KzfgH-dzP2k

## Archivos 📄

### >main.cpp
Archivo central de nuestro proyecto en donde se define la población para la simulación y se llaman a las funciones de los otros archivos para la implementación de los tres escenarios y la creación del menú.

### >Particle.h
Definición de la clase **particle** que representa a la partícula moviéndose en la ventana. A esta clase se le da una posición, radio y masa. Además, se crean métodos para predecir una de las leyes del movimiento elástico.

### >Particle.cpp
Archivo en donde se implementan las funciones encargadas de registrar colisiones entre partículas (personas) y los bordes de la ventana. También se implementa el dibujado de las partículas.

### >Event.h
Definición de la clase **event** que será fundamental para desarrollar el simulador basado en eventos. 

### >Event.cpp
Implementación de las funciones de la clase **event**. El evento participa en la colisión de partículas y cada evento contiene el momento en que ocurre, como también las partículas involucradas.

### >Menu.h
Implementación de un Menú que permite la interacción del usuario con el programa. Este menú permite escoger el tipo de simulación que se desea realizar.

### >CollisionSystem.h
En este archivo se desarrolla la creación de la clase **CollisionSystem**. Esta clase representa una colección de partículas que se mueven en una ventana de acuerdo con las leyes de la colisión elástica. De este modo, esta simulación basada en eventos utiliza una cola de prioridad.

### >CollisionSystem.cpp
Archivo en donde se implementan las funciones de la clase **CollisionSystem**. Además, se crean funciones que permiten que las partículas (personas) cambien de color de acuerdo a su estado (Azul = Inicial, Rojo = Infectado, Verde = Curado, Negro = Fallecido) y otras funciones que añaden a la complejidad de la simulación.


## Diagrama de clases (UML) :triangular_ruler:

![ovovovsd](https://user-images.githubusercontent.com/71047903/102668051-f9466600-4158-11eb-9f43-2a6b9bc0653b.PNG)


## Construido con 🛠️

* [CLion](https://www.jetbrains.com/clion/) - Utilizado para la compilación y testeo del proyecto
* [Replit](https://repl.it/~) - Utilizado para la compilación y testeo del proyecto
* [SFML](https://www.sfml-dev.org) - Libreria utilizada para los gráficos del proyecto

## Bibliografia :books:

* [Event-Driven Simulation](https://algs4.cs.princeton.edu/61event/) - Fuente Consultada 
* [Coronavirus](https://www.washingtonpost.com/graphics/2020/world/corona-simulator/) - Inspiración
* [Data](https://covid19.minsa.gob.pe/sala_situacional.asp) - Datos consultados del MINSA
* [Paper](https://arxiv.org/ftp/physics/papers/0405/0405089.pdf) - Paper consultado para la implementación de las colisiones

## Licencia 📄

Universidad de Ingenieria y Tecnología - UTEC

---
