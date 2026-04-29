# Recuperador de archivos JPEG 

Este proyecto es una solución al reto técnico propuesto por la Universidad de Harvard de su curso **CS50: Introduction to Computer Science**.

## 📖 El Problema
El objetivo es recuperar imágenes borradas de una unidad de almacenamiento que simula ser una tarjeta de memoria. Aunque los archivos no son visibles a simple vista, los datos siguen grabados en los bloques de memoria. El programa debe escanear el archivo de la tarjeta bloque a bloque para identificar y reconstruir cada imagen.

## 🛠️ Conceptos Aplicados
Para resolver este problema, implementé una solución en **C** que demuestra conceptos fundamentales de computación y manejo de memoria:
- **Identificación de Patrones:** Localización de archivos mediante "bytes mágicos" o firmas digitales. Los JPEGs siempre comienzan con la secuencia específica `0xff 0xd8 0xff`.
- **Gestión de Memoria y Punteros:** Uso de punteros a archivos (`FILE *`) para gestionar de forma eficiente la lectura y escritura de datos.
- **Estructura de Bloques:** Trabajo con bloques de memoria de 512 bytes, alineando la lógica de lectura con la estructura física del almacenamiento (sistema FAT).
- **Control de Flujo:** Gestión de estados para abrir, escribir y cerrar archivos dinámicamente a medida que se encuentran nuevos datos.

## 🚀 Cómo funciona
1. El programa lee la tarjeta de memoria en bloques constantes de **512 bytes**.
2. Analiza el inicio de cada bloque buscando la firma técnica de un JPEG.
3. Al detectar una firma, el programa entiende que comienza una nueva foto: cierra la anterior (si existía) y crea un nuevo archivo llamado `###.jpg`.
4. Escribe los datos del bloque actual y los siguientes en ese archivo hasta que encuentra la firma de la siguiente imagen o llega al final del almacenamiento.
5. El resultado final es la recuperación exitosa de **50 imágenes** que vuelven a ser totalmente legibles.

## 🛠️ Tecnologías utilizadas
- Lenguaje C
- Librerías estándar: `stdio.h`, `stdlib.h`, `stdint.h`

---
*Este proyecto forma parte del curso de CS50 de Harvard University.*
