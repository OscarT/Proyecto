#include<stdio.h>
#include<stdlib.h>
#include <conio.h>
#include "pro.h"





int main(){
	int opc,a;
	
	do{
		printf("\t\t\t\t+-----+-----+-----+-----+-----+-----+-----+-----+-----+\n");
		printf("\t\t\t\t+-----+-----+-----+-----+-----+-----+-----+-----+-----+\n");
		printf("\t\t\t\t+-----+-----+        MEGA-LIBRERIA        +-----+-----+\n");
		printf("\t\t\t\t+-----+-----+-----+-----+-----+-----+-----+-----+-----+\n");
		printf("\t\t\t\t+-----+-----+-----+-----+-----+-----+-----+-----+-----+\n\n");
		printf("\t\t\t\t                    >>BIENVENIDO<<\n\n\n\n");
		
		printf("1>> Administrador\n\n");
		printf("2>> Cliente\n\n");
		printf("3>> Salir\n\n");
		scanf("%d",&opc);
		system("cls");
		if(opc>=1 && opc<=2){
		system("cls");	
		printf("\n\n\n\n\t\t\t\t                      ACCEDIENDO");
		time();
		}
		
		
		switch(opc){
			case 1:
				
				do{
					printf("\t\t\t\t+-----+-----+-----+-----+-----+-----+----+-----+--+\n");
					printf("\t\t\t\t+-----+| 1.Nuevo libro                     |+-----+\n");
					printf("\t\t\t\t+-----+| 2.Dar de baja un libro            |+-----+\n");
					printf("\t\t\t\t+-----+| 3.Agregar existencias             |+-----+\n");
					printf("\t\t\t\t+-----+| 4.Regresar a la pagina principal  |+-----+\n");
					printf("\t\t\t\t+-----+-----+-----+-----+-----+-----+----+-----+--+\n");
					scanf("%d",&a);
					system("cls");
					switch(a){
						case 1:
							insertarlib();
						break;
						
						case 2:
							baja();
						break;
						
						case 3:
							existencias();
						break;
						
						case 4:
						break;
					}
					
				}while(a!=4);			
			break;
				
			case 2:
				do{				
					printf("\t\t\t\t+-----+-----+-----+-----+-----+-----+-----+-----+---+-----+\n");
					printf("\t\t\t\t+-----+| 1.Ver lista de libros primero a ultimo    |+-----+\n");
					printf("\t\t\t\t+-----+| 2.Ver lista de libros ultimo a primero    |+-----+\n");
					printf("\t\t\t\t+-----+| 3.Buscar por titulo                       |+-----+\n");
					printf("\t\t\t\t+-----+| 4.Buscar por autor                        |+-----+\n");
					printf("\t\t\t\t+-----+| 5.Buscar por ISBN                         |+-----+\n");
					printf("\t\t\t\t+-----+| 6.Regresar a la pagina principal          |+-----+\n");
					printf("\t\t\t\t+-----+-----+-----+-----+-----+-----+-----+-----+---+-----+\n");
					scanf("%d",&a);
					system("cls");
					switch(a){
						case 1:
							mostrarPU();
						break;
							
						case 2:
							mostrarUP();
						break;
						
						case 3:
							
						break;
						
						case 4:
							
						break;
						case 5:
							buscarISBN();
						break;
						
						case 6:
						break;
					}
					
				}while(a!=6);
				
				break;
				
	 	}
		 }while(opc!=3);
 	return 0;
}
