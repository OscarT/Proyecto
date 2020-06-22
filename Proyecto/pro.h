#ifndef DNODE_H
#define DNODE_H


typedef struct nodo{
	char titulo[80];
	char autor[80];
	char formato[80];
	char editorial[80];
	int ISBN,exi;
	float precio;
	struct nodo* siguiente;
	struct nodo* atras;
} nodo;



void time();				//Esta funcion hace que el programa se detenga por un segundo para los efectos de accediendo y actualizando 
void insertarlib(); 		//Funcion para agregar libros 
void mostrarPU();			//Muestra la lista del primero al ultimo 
void mostrarUP();			//Muestra la lista del ultimo al primero 
void buscarISBN();          //Busca el libro por ISBN 
void baja();				//Da de baja el libro 
void existencias();			//Agrega existencias a los libros que esten en la lista 


#endif