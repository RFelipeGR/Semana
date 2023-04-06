#include<stdio.h>
#include<conio.h>

int main(){

char nombre[100];
char cedula[20];
float precioA=150, precioB=55, precioC=180, precioD=70, precioE=120;
float numA=0, numB=0, numC=0, numD=0, numE=0;
float subtotalA=0, subtotalB=0, subtotalC=0, subtotalD=0, subtotalE=0;
float subtotal=0, total=0;

char opcion='f';
printf("*****ESCOGA EL PRODUCTO QUE DESEA FACTURAR*****\n");
printf("a) Llantas (Precio: 150)\n");
printf("b) Kit Pastillas de freno (Precio: 55)\n");
printf("c) Kit de embrague (Precio: 180)\n");
printf("b) Faro (Precio: 70)\n");
printf("b) Radiador (Precio: 120)\n");
printf("  Opcion: ");
scanf("%c",&opcion);

switch (opcion)
{
case 'a':
   printf("Ingrese el numero de llantas: ");
   scanf("%f",&numA);
    break;
    case 'b':
    printf("Ingrese el numero de kits de pastilas de freno: ");
   scanf("%f",&numB);
    break;
    case 'c':
    printf("Ingrese el numero de kit de embrague: ");
   scanf("%f",&numC);
    break;
    case 'd':
    printf("Ingrese el numero de faros: ");
   scanf("%f",&numD);
    break;
    case 'e':
    printf("Ingrese el numero de radiadores: ");
   scanf("%f",&numE);
    break;

default:
    break;
}

subtotalA=precioA*numA;
subtotalB=precioB*numB;
subtotalC=precioC*numC;
subtotalD=precioD*numD;
subtotalE=precioE*numE;

subtotal=subtotalA+subtotalB+subtotalC+subtotalD+subtotalE;

if (subtotal>100 && subtotal<=500)
{
    total=subtotal-subtotal*0.05;
}
else if (subtotal>500 && subtotal<=1000)
{
    total=subtotal-subtotal*0.07;
}
else if(subtotal>1000)
{
    total=subtotal-subtotal*0.1;
}

printf("Ingrese el nombre de clientes: \n");
scanf("%s",&nombre);

printf("Ingrese la cedula del cliente: \n");
scanf("%s",&cedula);

printf("**********FACTURA**********\n");
printf("nombre: %s \n",nombre);
printf("cedua: %s \n",cedula);

printf("Producto            Cantidad        Precio Unitario     Precio Total\n");

if (numA!=0)
{
    printf("Llantas             %0.f        %0.f        %0.2f\n",numA, precioA, subtotalA);
}
if (numA!=0)
{
    printf("Kit Pastillas freno     %0.f        %0.f        %0.2f\n",numB, precioB, subtotalB);
}
if (numA!=0)
{
    printf("Kit de embrague       %0.f        %0.f        %0.2f\n",numC, precioC, subtotalC);
}
if (numA!=0)
{
    printf("Faro                %0.f        %0.f        %0.2f\n",numD, precioD, subtotalD);
}
if (numA!=0)
{
    printf("Radiador            %0.f        %0.f        %0.2f\n",numE, precioE, subtotalE);
}

printf("El subtotal es: %f",subtotal);
printf("El total es: %f",total);

printf("**********FACTURA**********\n");

getch ();
return 0;
 
}