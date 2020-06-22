#include<stdio.h>
#include<stdlib.h>
#include <conio.h> 		//Libreria para usar getch
#include "pro.h"

nodo* primero = NULL;
nodo* ultimo = NULL;



void time(){
	int n=0;
	while(n<=0){
	sleep(1);
	printf(".");
	sleep(1);
	printf(".");
	sleep(1);
	printf(".");
	sleep(1);
	n=n+1;
}
system("cls"); 		 //Limpiar pantalla
}

void insertarlib(){
	nodo* nuevo = (nodo*) malloc(sizeof(nodo));  //Creamos un nuevo nodo para la lista 
	printf("\nTitulo: ");						//Los datos se guardaran en las variables de la estructura con ayuda del nodo nuevo 
	scanf("%s", &nuevo->titulo);
	printf("Autor: ");
	scanf("%s", &nuevo->autor);
	printf("Editorial: ");
	scanf("%s", &nuevo->editorial);
	printf("Formato: ");
	scanf("%s", &nuevo->formato);
	printf("ISBN: ");
	scanf("%d", &nuevo->ISBN);
	printf("Precio: ");
	scanf("%f", &nuevo->precio);
	printf("Existencias: ");
	scanf("%d", &nuevo->exi);
	
	if(primero==NULL){								//Si la lista esta vacia agregamos el primer nodo 
		primero = nuevo;
		primero->siguiente = primero;
		ultimo = primero;
		primero->atras = ultimo;
	}else{
		ultimo->siguiente = nuevo;					//Si la lista ya tiene elementos agregamos despues del nodo ya existente 
		nuevo->siguiente = primero;
		nuevo->atras = ultimo;
		ultimo = nuevo;
		primero->atras = ultimo;
	}
	printf("\nLibro ingresado!\n\n");
	getch();
	system("cls");
}

void mostrarPU(){
	nodo* actual = (nodo*) malloc(sizeof(nodo));		//Creamos un nodo actual para recorrer la lista 
	actual = primero;
	if(primero!=NULL){         						 	//Comprobamos que la lista no este vacia 
		do{ 											//De tener datos imprimimos del primer libro 
			printf("\nTitulo: %s\nAutor: %s\nEditorial: %s", actual->titulo, actual->autor, actual->editorial);
			printf("\nFormato: %s\nISBN: %d", actual->formato, actual->ISBN);
			printf("\nPrecio: %.2f\nExitencias: %d\n", actual->precio,actual->exi);
			actual = actual->siguiente;    // Recorremos el nodo actual al siguiente y repetimos el ciclo
		}while(actual != primero);         //Si al recorrer el nodo actual y este apunta de nuevo al primero nos salimos del ciclo 
	}else{
		printf("\n La Lista se encuentra vacia\n\n");
	}
	getch();
	system("cls");
}

void mostrarUP(){
	nodo* actual = (nodo*) malloc(sizeof(nodo));				//Creamos un nodo actual para recorrer la lista
	actual = ultimo;
	if(primero!=NULL){											//Comprobamos que la lista no este vacia 
		do{														//De tener datos imprimimos del ultimo libro 
			printf("\nTitulo: %s\nAutor: %s\nEditorial: %s", actual->titulo, actual->autor, actual->editorial);
			printf("\nFormato: %s\nISBN: %d", actual->formato, actual->ISBN);
			printf("\nPrecio: %.2f\nExitencias: %d\n", actual->precio,actual->exi);
			actual = actual->atras;								// Recorremos el nodo actual al anterior y repetimos el ciclo
		}while(actual != ultimo);								//Si al recorrer el nodo actual  y este apunta de nuevo al iltimo nos salimos del ciclo
	}else{
		printf("\n La Lista se encuentra vacia\n\n");
	}
	getch();
	system("cls");
}

void buscarISBN(){
	int nodoBuscado = 0;       										//Variable que contendra el dato a buscar 
	int encontrado = 0;
	nodo* actual = (nodo*) malloc(sizeof(nodo));     				// Creamos un nodo
	actual = primero;
	if(primero!=NULL){												//Comprobamos que la lista no este vacia 
		do{
			printf("Ingrese el ISBN del libro: ");
			scanf("%d", &nodoBuscado);
			if(actual->ISBN == nodoBuscado){					
				printf("\nTitulo: %s\nAutor: %s\nEditorial: %s\n", actual->titulo,actual->autor,actual->editorial);
				printf("Formato: %s\nISBN: %d\nPrecio: %.2f\nExistencias: %d\n", actual->formato,actual->ISBN,actual->precio,actual->exi);
				encontrado = 1;
			}
			actual = actual->siguiente;							//Recorremos la lista en caso de que el primer nodo no sea igual al buscado 
		}while(actual != primero && encontrado != 1);
		if(encontrado == 0){
			printf("\nLibro no encontrado\n\n");
		}
	}else{
		printf("\n La Lista se encuentra vacia\n\n");
	}	
	getch();
	system("cls");
}

void baja(){
	int cont = 0;
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;
	nodo* anterior = (nodo*) malloc(sizeof(nodo));
	anterior = NULL;
	int nodoBuscado = 0;
	int encontrado = 0;
	
	if(primero!=NULL){															//Comprobamos que la lista no este vacia 
		do{
			printf(" Ingrese el ISBN del libro: ");
			scanf("%d", &nodoBuscado);
			if(actual->ISBN == nodoBuscado){									//Buscamos el ISBN del libro 
				printf("\nLibro %s dado de baja \n", actual->titulo);			//Si el ISBN es igual al buscado imprimimos el libro al que correspondia el ISBN
				actual->exi = 0;												//e  igualamos las existencia a cero
				cont = 1;
				printf("Existencias actualizadas: %d\n\n", actual->exi);
				if(actual==primero){                                             //Recorremos la lista 
					primero = primero->siguiente;
					primero->atras = ultimo;
					ultimo->siguiente = primero;
				}else if(actual==ultimo){
					ultimo = anterior;
					ultimo->siguiente = primero;
					primero->atras = ultimo;
				}else{
					anterior->siguiente = actual->siguiente;
					actual->siguiente->atras = anterior;
				}
				encontrado = 1;
			}
			anterior = actual;
			actual = actual->siguiente;
		}while(actual != primero && encontrado != 1);
		if(encontrado == 0){
			printf("\n Libro no encontrado\n\n");
		}else{
			free(anterior);                                                        //Borramos el nodo que contenia el dato del ISBN 
		} 
	}else{                                                                         //De ser el primro igual a nulo, la lista estaria vacia 
		printf("\n La Lista se encuentra vacia\n\n");
	}
	getch();
	system("cls");
}

void existencias(){
	int add = 0;
	int nodoBuscado = 0; 										//Varible que se usara para buscar el libro y guardara el dato a buscar 
	int encontrado = 0;											//Variable que servira para que al momento de encontrar el dato se detenga 
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;
											
	if(primero!=NULL){ 											//Comprobamos que la lista no este vacia 
		do{
			printf("Ingrese el ISBN del libro: ");				//El dato a buscar sera por ISBN 
			scanf("%d", &nodoBuscado); 
			if(actual->ISBN== nodoBuscado){ 					
				
				printf("Ingrese las existencias a agregar: ");
				scanf("%d", &add);								//Guardamos el numero de existencias que se agregaran 
				actual->exi = actual->exi + add;				// y actualizamos el dato de exi 
				printf("\n\n\n\n\t\t\t\t                      ACTUALIZANDO");
				time();
				printf("\n\n\n\n\t\t\t\t                      ACTUALIZADO");
				encontrado = 1; 
			}
			actual = actual->siguiente;                     // Recorremos la lista en caso de que el primer nodo no sea igual al buscado 
		}while(actual != primero && encontrado != 1);
		if(encontrado == 0){									 
			printf("\n Libro no encontrado\n\n");
		}
	}else{
		printf("\n La Lista se encuentra vacia\n\n");		//De haber sido falsa la sentencia if, decimoso que la lista esta vacia 
	}	
	getch(); 					// Continuar despues de presionar una tecla
	system("cls");
}
