#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct direccion
{
    int calle;
    int avenida;
};

struct empleado
{
    char posicion[20];
    char nombre[20];
    char apellido[20];
    int edad;
    int salario;
    struct direccion dir;
} emp[11];
int filled = 0;

// Prototipos de funciones
void ingresar();
void mostrar();
void editar();
void buscarPosicion();
void buscarSalario();
void analisis();
void menu();

short int n, flag;
int main() {
    do
    {
        printf("Ingrese la cantidad de empleados (hasta 10): ");
        scanf("%d", &n);
        if (n > 10 || n < 1)
        {
            printf("Error, ingrese un numero valido\n");
        }
    } while (n>10 || n<1);

    menu();
    return 0;
}

void ingresar() {
    for (int i=0; i < n; i++) {
        printf("________________________\n");
        printf("Empleado %d\n", i+1);
        fflush(stdin);
        printf("Ingrese la posicion del empleado: ");
        gets(emp[i].posicion);
        fflush(stdin);
        printf("Ingrese el nombre del empleado: ");
        gets(emp[i].nombre);
        fflush(stdin);
        printf("Ingrese el apellido del empleado: ");
        gets(emp[i].apellido);
        fflush(stdin);
        printf("Ingrese la edad del empleado: ");
        scanf("%d", &emp[i].edad);
        printf("Ingrese el salario del empleado: ");
        scanf("%d", &emp[i].salario);
        printf("Ingrese el numero de avenida de residencia del empleado: ");
        scanf("%d", &emp[i].dir.avenida);
        printf("Ingrese el numero de calle de residencia del empleado: ");
        scanf("%d", &emp[i].dir.calle);
    }
    filled = 1;
}

void mostrar() {
    if (!filled) {
        printf("No hay empleados registrados en el sistema\n");
        return;
    }
    for (int i=0; i < n; i++) {
        printf("____________________\n");
        printf("Empleado %d\n", i+1);
        printf("Posicion: %s\n", emp[i].posicion);
        printf("Nombre: %s\n", emp[i].nombre);
        printf("Apellido: %s\n", emp[i].apellido);
        printf("Edad: %d\n", emp[i].edad);
        printf("Salario: %d\n", emp[i].salario);
        printf("Calle: %d\n", emp[i].dir.calle);
        printf("Avenida: %d\n", emp[i].dir.avenida);
    }
}

void editar() {
    printf("Ingrese el numero de empleado a editar: ");
    int num;
    scanf("%d", &num);
    if (num > n) {
        printf("El numero de empleado no existe\n");
        return;
    }
    printf("________________________\n");
    fflush(stdin);
    printf("Ingrese la nueva posicion del empleado: ");
    gets(emp[num-1].posicion);
    fflush(stdin);
    printf("Ingrese el nuevo nombre del empleado: ");
    gets(emp[num-1].nombre);
    fflush(stdin);
    printf("Ingrese el nuevo apellido del empleado: ");
    gets(emp[num-1].apellido);
    fflush(stdin);
    printf("Ingrese la nueva edad del empleado: ");
    scanf("%d", &emp[num-1].edad);
    printf("Ingrese el nuevo salario del empleado: ");
    scanf("%d", &emp[num-1].salario);
    printf("Ingrese el nuevo numero de avenida de residencia del empleado: ");
    scanf("%d", &emp[num-1].dir.avenida);
    printf("Ingrese el nuevo numero de calle de residencia del empleado: ");
    scanf("%d", &emp[num-1].dir.calle);

}

void buscarPosicion() {
    char pos[20];
    fflush(stdin);
    printf("Ingrese la posicion a buscar: ");
    gets(pos);
    fflush(stdin);
    int found = 0;
    printf("Empleado(s) con la posicion %s:\n", pos);
    for (int i=0; i < n; i++) {
        if (strcmp(pos, emp[i].posicion) == 0) {
            found++;
            printf("____________________\n");
            printf("Empleado %d\n", found);
            printf("Posicion: %s\n", emp[i].posicion);
            printf("Nombre: %s\n", emp[i].nombre);
            printf("Apellido: %s\n", emp[i].apellido);
            printf("Edad: %d\n", emp[i].edad);
            printf("Salario: %d\n", emp[i].salario);
            printf("Calle: %d\n", emp[i].dir.calle);
            printf("Avenida: %d\n", emp[i].dir.avenida);
        }
    }
    if (!found) {
        printf("No se encontro ningun empleado con la posicion \"%s\"\n", pos);
    }
}
void buscarSalario() {
    int ls, li;
    printf("Ingrese el limite inferior del salario: ");
    scanf("%d", &li);
    printf("Ingrese el limite superior del salario: ");
    scanf("%d", &ls);
    int found = 0;
    printf("Empleados con salario entre %d Bs. y %d Bs.:\n", li, ls);
    for (int i=0; i < n; i++) {
        if (emp[i].salario >= li && emp[i].salario <= ls) {
            found++;
            printf("____________________\n");
            printf("Empleado %d\n", found);
            printf("Posicion: %s\n", emp[i].posicion);
            printf("Nombre: %s\n", emp[i].nombre);
            printf("Apellido: %s\n", emp[i].apellido);
            printf("Edad: %d\n", emp[i].edad);
            printf("Salario: %d\n", emp[i].salario);
            printf("Calle: %d\n", emp[i].dir.calle);
            printf("Avenida: %d\n", emp[i].dir.avenida);
        }
    }
    if (!found) {
        printf("No se encontro ningun empleado con salario entre %d Bs. y %d Bs.\n", li, ls);
    }
}

void analisis() {
    if (!filled) {
        printf("No hay empleados registrados en el sistema\n");
        return;
    }
    int total = 0;
    printf("Algunos datos pueden haber sido truncados por el sistema\n");
    printf("   n|Posicion            |Nombre    |Apellido            |Edad  |Salario   ");
    for (int i=0; i < n; i++) {
        total += emp[i].salario;
        printf("\n  %2d|%-20.20s|%-10.10s|%-20.20s|%2d    |%8d  ", i+1, emp[i].posicion, emp[i].nombre, emp[i].apellido, emp[i].edad%100, emp[i].salario%100000000);
    }

    printf("\nCosto mensual salarial: %d Bs.\n", total);


}

void menu() {
    int op;
    do
    {
        printf("____________________\n");
        printf("1. Registrar empleados\n");
        printf("2. Editar empleado\n");
        printf("3. Buscar empleado por posicion\n");
        printf("4. Buscar empleado por salario\n");
        printf("5. Analisis de los empleados\n");
        printf("6. Mostrar empleados\n");
        printf("7. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            ingresar();
            break;
        case 2:
            editar();
            break;
        case 3:
            buscarPosicion();
            break;
        case 4:
            buscarSalario();
            break;
        case 5:
            analisis();
            break;
        case 6:
            mostrar();
            break;
        case 7:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opcion invalida\n");
            break;
        }
    } while (op != 7);
         
}