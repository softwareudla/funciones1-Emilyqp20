#include <stdio.h>
#include <string.h>
#include "funciones.h"

void ingresarProductos(char productos[10][50], float precios[10], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        printf("Ingrese el nombre del producto %d: ", i + 1);
        getchar(); // Limpiar el buffer antes de fgets
        fgets(productos[i], 50, stdin);
        productos[i][strcspn(productos[i], "\n")] = '\0'; // Eliminar el salto de línea

        // Validación del precio para evitar valores no válidos
        int validacion;
        do {
            printf("Ingrese el precio del producto %d (valor mayor que 0 y menor o igual a 1000): ", i + 1);
            validacion = scanf("%f", &precios[i]);

            if (validacion != 1) {
                printf("Error: Debe ingresar un número válido. Intente de nuevo.\n");
                while (getchar() != '\n');  // Limpiar el buffer de entrada
                precios[i] = 0;  // Si el usuario deja vacío o introduce un valor no numérico, asigna 0
            } else if (precios[i] <= 0 || precios[i] > 1000) {
                printf("Advertencia: El precio debe ser mayor a 0 y menor a 1000\n");
            }
        } while (validacion != 1 || precios[i] <= 0 || precios[i] > 1000);
    }
}

float calcularPrecioTotal(float precios[10], int cantidad) {
    float total = 0;
    for (int i = 0; i < cantidad; i++) {
        total += precios[i];
    }
    return total;
}

void encontrarProductoMasCaro(float precios[10], char productos[10][50], int cantidad) {

    float max = 0;
    for (int i = 0; i < cantidad; i++)
    {
        if (precios[i]>max) {
            max=precios[i];
        }
    }
    printf("El o los productos mas caros son:\n");

    for (int i = 0; i < cantidad; i++)
    {
        if (precios[i]==max) {
            printf("%s precio:\t%.2f\n", productos[i], precios[i]);
        }
    }
}

void encontrarProductoMasBarato(float precios[10], char productos[10][50], int cantidad) {

    float min=1000;

    for (int i = 0; i < cantidad; i++)
    {
        if (precios[i]<min) {
            min=precios[i];
        }
    }
    printf("El o los productos mas baratos son:\n");

    for (int i = 0; i < cantidad; i++)
    {
        if (precios[i]==min) {
            printf("%s precio:\t%.2f\n", productos[i], precios[i]);
        }
    }
}

float calcularPrecioPromedio(float precios[10], int cantidad) {
    float total = calcularPrecioTotal(precios, cantidad);
    return total / cantidad;
}

void buscarProducto(char productos[10][50], float precios[10], int cantidad, char nombre[50]) {
    int encontrado = 0;  // Variable para indicar si se encontró el producto
    
    for (int i = 0; i < cantidad; i++) {
        if (strcmp(productos[i], nombre) == 0) {   //Comparar cadenas
            printf("El precio del producto %s es: %.2f\n", productos[i], precios[i]);
            encontrado = 1;  // Se marca como encontrado
            break;  // Detener la búsqueda una vez encontrado
        }
    }

    if (!encontrado) {  // Si no se encontró el producto
        printf("Producto no encontrado\n");
    }
}
