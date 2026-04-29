#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Definición del tamaño de bloque estándar y el tipo de dato para los bytes 
const int BLOCK_SIZE = 512;
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Validar que se haya proporcionado exactamente un argumento por línea de comandos
    if (argc != 2)
    {
        printf("Uso: ./recover imagen\n");
        return 1;
    }

    // Abrir el archivo de entrada en modo lectura, verificando que se haya abierto correctamente
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    // Declarar un buffer para almacenar los datos leídos
    BYTE buffer[BLOCK_SIZE];
    // Declarar un puntero para el archivo de salida
    FILE *output = NULL;
    // Espacio para "###.jpg" y el carácter nulo terminal
    char img_name[8]; 
    // Contador para numerar las imágenes recuperadas de forma secuencial
    int counter = 0;

    // Iterar sobre el archivo origen leyendo bloques de 512 bytes
    while (fread(buffer, BLOCK_SIZE, 1, input) != 0)
    {
        /* Verificar si el bloque actual contiene la firma de inicio de un JPEG.
           El cuarto byte se valida mediante una máscara de bits (0xf0) para 
           confirmar que los primeros 4 bits coinciden con el patrón técnico.
        */
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && 
            (buffer[3] & 0xf0) == 0xe0)
        {
            // Si ya existe un archivo abierto, cerrarlo antes de iniciar el nuevo
            if (output != NULL)
            {
                fclose(output);
            }

            // Generar el nombre del archivo con formato numérico secuencial de tres dígitos
            sprintf(img_name, "%03i.jpg", counter);
            
            // Abrir un nuevo archivo de salida para escribir la imagen recuperada, verificando que se haya abierto correctamente
            output = fopen(img_name, "w");
            if (output == NULL)
            {
                fclose(input);
                return 1;
            }

            counter++;
        }

        // Si se ha detectado un archivo JPEG válido, escribir el bloque actual en el archivo de salida
        if (output != NULL)
        {
            fwrite(buffer, BLOCK_SIZE, 1, output);
        }
    }

    // Cerrar cualquier archivo abierto antes de finalizar el programa
    if (output != NULL)
    {
        fclose(output);
    }
    fclose(input);

    return 0;
}