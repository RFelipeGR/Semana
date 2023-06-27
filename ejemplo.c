#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

void mostrarMenu();
void verProductos(int *id, char nombre[][50], char descripcion[][150], int *cantidad, float *precio);
void ingresarProducto(int *id, char nombre[][50], char descripcion[][150], int *cantidad, float *precio);
void modificarProducto(int *id, char nombre[][50], char descripcion[][150], int *cantidad, float *precio);
void eliminarProducto(int *id, char nombre[][50], char descripcion[][150], int *cantidad, float *precio);
int numProductos = 0;

int main() {
    int opcion;
    int id[N];
    char nombre[N][50];
    char descripcion[N][150];
    int cantidad[N];
    float precio[N];

    int *usuario_id = id;
    char (*nproducto)[50] = nombre;
    char (*ndescripcion)[150] = descripcion;
    int *ncantidad = cantidad;
    float *nprecio = precio;

    do {
        mostrarMenu();
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                verProductos(usuario_id, nproducto, ndescripcion, ncantidad, nprecio);
                break;
            case 2:
                ingresarProducto(usuario_id, nproducto, ndescripcion, ncantidad, nprecio);
                numProductos++;
                break;
            case 3:
                modificarProducto(usuario_id, nproducto, ndescripcion, ncantidad, nprecio);
                break;
            case 4:
                eliminarProducto(usuario_id, nproducto, ndescripcion, ncantidad, nprecio);
                numProductos--;
                break;
            case 5:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion invalida. Por favor, intente nuevamente.\n");
                break;
        }
    } while (opcion != 5);

    return 0;
}

void mostrarMenu() {
    printf("Menu:\n");
    printf("1. Ver productos\n");
    printf("2. Ingresar producto\n");
    printf("3. Modificar producto\n");
    printf("4. Eliminar producto\n");
    printf("5. Salir\n");
}

void verProductos(int *id, char nombre[][50], char descripcion[][150], int *cantidad, float *precio) {
    int productoId;
    printf("Ingrese el ID del producto a buscar: ");
    scanf("%d", &productoId);

    for (int i = 0; i < numProductos; i++) {
        if (id[i] == productoId) {
            printf("ID: %d\n", id[i]);
            printf("Nombre: %s\n", nombre[i]);
            printf("Descripcion: %s\n", descripcion[i]);
            printf("Cantidad: %d\n", cantidad[i]);
            printf("Precio: %.2f\n", precio[i]);
            return;
        }
    }

    printf("No se encontró ningún producto con el ID ingresado.\n");
}

void ingresarProducto(int *id, char nombre[][50], char descripcion[][150], int *cantidad, float *precio) {
    int nuevoId;
    printf("Ingrese el ID del producto: ");
    scanf("%d", &nuevoId);

    for (int i = 0; i < numProductos; i++) {
        if (id[i] == nuevoId) {
            printf("Ya existe un producto con el ID ingresado.\n");
            return;
        }
    }

    id[numProductos] = nuevoId;

    printf("Ingrese el nombre del producto: ");
    scanf("%s", nombre[numProductos]);

    printf("Ingrese la descripcion del producto: ");
    scanf("%s", descripcion[numProductos]);

    printf("Ingrese la cantidad del producto: ");
    scanf("%d", &cantidad[numProductos]);

    printf("Ingrese el precio del producto: ");
    scanf("%f", &precio[numProductos]);

    printf("Producto ingresado correctamente.\n");
}

void modificarProducto(int *id, char nombre[][50], char descripcion[][150], int *cantidad, float *precio) {
    int productoId;
    printf("Ingrese el ID del producto a modificar: ");
    scanf("%d", &productoId);

    for (int i = 0; i < numProductos; i++) {
        if (id[i] == productoId) {
            printf("ID: %d\n", id[i]);
            printf("1. Modificar nombre\n");
            printf("2. Modificar descripcion\n");
            printf("3. Modificar cantidad\n");
            printf("4. Modificar precio\n");
            printf("Ingrese una opcion: ");

            int opcion;
            scanf("%d", &opcion);

            switch (opcion) {
                case 1:
                    printf("Ingrese el nuevo nombre del producto: ");
                    scanf("%s", nombre[i]);
                    break;
                case 2:
                    printf("Ingrese la nueva descripcion del producto: ");
                    scanf("%s", descripcion[i]);
                    break;
                case 3:
                    printf("Ingrese la nueva cantidad del producto: ");
                    scanf("%d", &cantidad[i]);
                    break;
                case 4:
                    printf("Ingrese el nuevo precio del producto: ");
                    scanf("%f", &precio[i]);
                    break;
                default:
                    printf("Opcion invalida. No se realizaron modificaciones.\n");
                    break;
            }

            printf("Producto modificado correctamente.\n");
            return;
        }
    }

    printf("No se encontró ningún producto con el ID ingresado.\n");
}

void eliminarProducto(int *id, char nombre[][50], char descripcion[][150], int *cantidad, float *precio) {
    int productoId;
    printf("Ingrese el ID del producto a eliminar: ");
    scanf("%d", &productoId);

    for (int i = 0; i < numProductos; i++) {
        if (id[i] == productoId) {
            for (int j = i; j < numProductos - 1; j++) {
                id[j] = id[j + 1];
            }

            printf("Producto eliminado correctamente.\n");
            return;
        }
    }

    printf("No se encontró ningún producto con el ID ingresado.\n");
}

/*
nombre[j], nombre[j + 1];
descripcion[j], descripcion[j + 1];
cantidad[j] = cantidad[j + 1];
precio[j] = precio[j + 1];
*/