# 📂 Recuperador de archivos JPEG 
![C](https://img.shields.io/badge/Language-C-A8B9CC.svg)
![Memory Management](https://img.shields.io/badge/Focus-Memory%20Management-green.svg)
![Binary Data](https://img.shields.io/badge/Data-card.raw-orange.svg)
![Harvard CS50](https://img.shields.io/badge/Course-CS50%20Harvard-red.svg)

Este proyecto es una solución al reto técnico propuesto por la Universidad de Harvard de su curso **CS50: Introduction to Computer Science**.

## 📖 El Problema
El objetivo es recuperar imágenes borradas de una unidad de almacenamiento. Para este ejercicio, el curso nos proporciona un archivo llamado `card.raw`, que es una "imagen" o copia bit a bit de una tarjeta de memoria real. Aunque los archivos no son visibles, los datos siguen grabados en los bloques de memoria y el programa debe escanear este archivo para reconstruir cada imagen.

## 🛠️ Conceptos Aplicados
Para resolver este problema, implementé una solución en **C** que demuestra conceptos fundamentales de computación y manejo de memoria:
- **Identificación de Patrones:** Localización de archivos mediante firmas digitales. Los JPEGs siempre comienzan con la secuencia específica `0xff 0xd8 0xff`.
- **Gestión de Memoria y Punteros:** Uso de punteros a archivos (`FILE *`) para gestionar la lectura del origen y la escritura de los resultados.
- **Estructura de Bloques:** Trabajo con bloques de memoria de 512 bytes, alineando la lógica de lectura con la estructura física del almacenamiento (sistema FAT).
- **Control de Flujo:** Gestión de estados para abrir, escribir y cerrar archivos dinámicamente a medida que se encuentran nuevos datos.

## 🚀 Cómo funciona
1. El programa toma el archivo `card.raw` y lo lee en bloques constantes de **512 bytes**.
2. Analiza el inicio de cada bloque buscando la firma técnica de un JPEG.
3. Al detectar una firma, el programa entiende que comienza una nueva foto: cierra la anterior (si existía) y crea un nuevo archivo llamado `###.jpg`.
4. Escribe los datos del bloque actual y los siguientes en ese archivo hasta que encuentra la firma de la siguiente imagen o llega al final del archivo de datos.
5. El resultado final es la recuperación exitosa de **50 imágenes** que vuelven a ser totalmente legibles.

## 📦 Recursos
- **`card.raw`**: Archivo de datos proporcionado por CS50 que contiene la información binaria de la tarjeta de memoria a recuperar.
- **`recover.c`**: Código fuente con la lógica de recuperación desarrollada.

## 🛠️ Tecnologías utilizadas
- Lenguaje C
- Librerías estándar: `stdio.h`, `stdlib.h`, `stdint.h`

---

## 🤝 Contribuciones

Este proyecto está abierto a sugerencias y feedback. Si tienes ideas de mejora o encuentras algún bug, no dudes en abrir un issue.

---

## 👨‍💻 Autor

David Cereceda Pérez  
[GitHub](https://github.com/dcerecedaa) | [LinkedIn](https://linkedin.com/in/david-cereceda-perez-3ba0962b6)

*Este proyecto forma parte del curso de CS50 de Harvard University.*
