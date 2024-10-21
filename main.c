#include "funciones.h"
#include <stdio.h>
#include <string.h>

int main() {
    char productos[10][50];
    float precios[10];
    int cantidad;


    // Solicitar la cantidad de productos y validar con do-while
    do {
        printf("¿Cuántos productos quieres ingresar?, Ingrese un numero entero (1 a 10): ");
        int validacion = scanf("%d", &cantidad);
        if (validacion != 1 || cantidad < 1 || cantidad > 10) {
            printf("Error: Solo puedes ingresar un número entero entre 1 y 10. Intenta de nuevo.\n");
            while (getchar() != '\n');  // Limpiar el buffer de entrada
        }
    } while (cantidad < 1 || cantidad > 10);

    ingresarProductos(productos, precios, cantidad);

    float total = calcularPrecioTotal(precios, cantidad);
    printf("Precio total del inventario: %.2f\n", total);

    encontrarProductoMasCaro(precios, productos, cantidad);
    encontrarProductoMasBarato(precios, productos, cantidad);

    float promedio = calcularPrecioPromedio(precios, cantidad);
    printf("El precio promedio es: %.2f\n", promedio);

    // Bucle para realizar múltiples búsquedas de productos
    char opcion;
    do {
        char nombreProducto[50];
        printf("Ingrese el nombre del producto a buscar: ");
        getchar(); // Limpiar el buffer antes de fgets
        fgets(nombreProducto, 50, stdin);
        nombreProducto[strcspn(nombreProducto, "\n")] = '\0'; // Eliminar el salto de línea

        buscarProducto(productos, precios, cantidad, nombreProducto);

        printf("¿Desea buscar otro producto? (s/n): ");
        scanf(" %c", &opcion);
    } while (opcion == 's' || opcion == 'S');

    printf("Gracias por usar el sistema de inventario.\n");

    return 0;

  
}
