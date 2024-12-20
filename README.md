# Analizador Léxico, Sintáctico y Semántico de ANSI C (C89/C90)

Este proyecto es un analizador **léxico, sintáctico y semántico** para el estándar **ANSI C (C89/C90)** implementado en lenguaje **C**. El programa toma como entrada un archivo fuente **preprocesado** (.i) y produce un **reporte detallado** en la salida estándar (stdout), identificando errores léxicos, sintácticos y semánticos.

---

## **Características principales**
- **Análisis Léxico**: Implementado utilizando **Flex**, identifica los componentes básicos del lenguaje (tokens).
- **Análisis Sintáctico**: Utiliza **Bison** para definir y validar las estructuras sintácticas mínimas de ANSI C, incluyendo:
  - Expresiones: primarias, postfijas, unarias, multiplicativas, aditivas, relacionales, lógicas y de asignación.
  - Declaraciones: variables y prototipos de funciones.
  - Sentencias: de expresión, compuestas, de selección, de iteración, etiquetadas y de salto.
  - Definiciones externas: funciones y declaraciones globales.
- **Análisis Semántico**: Valida errores comunes como:
  - Tipos de datos incompatibles.
  - Declaración y redefinición de símbolos.
  - Invocaciones de funciones con argumentos incorrectos.
  - Asignaciones inválidas y valores de retorno incorrectos.

---

## **Requisitos**
- **Flex** y **Bison** instalados.
- Compilador **GCC** para construir el programa.

---

## **Estructura del proyecto**
```plaintext
.
├── src/              # Código fuente del analizador
├── obj/              # Archivos objeto
├── bin/              # Ejecutables
├── tests/            # Casos de prueba
├── archivo.i         # Archivo de ejemplo (preprocesado)
├── GNUmakefile       # Script de compilación
└── README.md         # Este archivo
```
## **Autores ✍️**

- **Gonzalo Garcia Fontenla**    
  *GitHub*: [usuario](https://github.com/GonGarciaFontenla))  

- **Leonel Contreras**   
  *GitHub*: [usuario](https://github.com/LeonelArianContreras)

- **Martin Federico Aguirre Ruiz**   
  *GitHub*: [usuario](https://github.com/martinAguirreRuiz)

- **Ivan Jose Kociman**   
  *GitHub*: [usuario](https://github.com/ikociman)

- **Maria Vectoria Massaini**   
  *GitHub*: [usuario](https://github.com/victoriamass)

- **Tomas Ignacio Ferreyra**   
  *GitHub*: [usuario](https://github.com/TomasIFerreyra)

## **Make file**
Este proyecto utiliza el Makefile de [**Fernando Daniel Maqueda**](https://github.com/fernandodanielmaqueda) para facilitar la construcción del proyecto.  
