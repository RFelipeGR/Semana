#include<stdio.h>
#include "menus.h"
#include "modulos.h"

int main(){

char nombre[100];
char cedula[20];
float precioA=150, precioB=55, precioC=180, precioD=70, precioE=120;
float numA=0, numB=0, numC=0, numD=0, numE=0;
float subtotalA=0, subtotalB=0, subtotalC=0, subtotalD=0, subtotalE=0;
float subtotal=0, total=0;
int cont;
char opcion;
int opc1;

do{
			opc1=menuPrincipal();
			switch (opc1 ){
				case 1:
					do{
                    opcion=menuProductos();
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
    		}
							
			printf("\n ¿Desea seguir Facturando productos? ");
			printf("\n 1>SI       2>NO");
			scanf("%d",&cont);
	
		}while (cont==1);

	
			break;
	case 2:
		do{
	
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

            //*******************
imprimirFactura( numA,  numB,  numC,  numD,  numE,
                     precioA,  precioB,  precioC,  precioD,  precioE,
                     subtotalA,  subtotalB,  subtotalC,  subtotalD,  subtotalE,
                     nombre,  cedula );
			//********************
            printf("El subtotal es: %0.f",subtotal);
			
                

            // subtotal
            subtotal=calculoDescuento(subtotal);


			printf("\nEl total es: %0.f",total);
			printf("\n**********FACTURA**********\n");
			printf("\n ¿Desea seguir imprimiendo facturas? ");
			printf("\n 1>SI       2>NO");
			scanf("%d",&cont);
		}while (cont==1);
    		break;
    		case 3: 
				printf("\n Gracias por visitarnos");
    			return 0;
		}
		
	}while(cont==2);
	
	return 0;
}




