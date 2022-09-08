/* Ejemplo de una COLA. 
Cargar los valores desde un archivo del tipo texto llamado numerosC.dat el cual contiene una columnas de enteros, 
estos valores colocar en una lista implementada como COLA. El nodo de la Lista posee un valor entero y la direccion al siguiente 
elemento. Imprimir la lista en pantalla*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{ 
	int x;
} T_Elemento;

struct cola{
  T_Elemento Dato;
  struct cola *sig;
};

typedef struct cola T_Cola;
typedef T_Cola *Ptr_Cola;

void insertar(Ptr_Cola *, Ptr_Cola *, T_Elemento);
void visualizar(T_Cola *);

main() /* Insertar y visualizar */
{
	T_Cola *L=NULL, *F=NULL;
	T_Elemento N;
    int i;
	srand(time(NULL));
	FILE *Ar;
    if ((Ar=fopen("numerosC.dat","r"))==NULL)
       {printf("\nError en apertura......\n");
        getch();
        exit(0);}
	fscanf(Ar,"%d",&N.x);
    while (!feof(Ar)){	
		insertar(&L,&F,N);
        fscanf(Ar,"%d",&N.x); 
	}

	visualizar(L);
}	


void insertar(Ptr_Cola *Q, Ptr_Cola *QF,T_Elemento X)
{
   T_Cola *AUX;
   AUX = (T_Cola *)malloc(sizeof(struct cola));
   AUX->Dato= X;
   AUX->sig =NULL;
   if ((*Q)==NULL)
     { (*Q)=(*QF) = AUX;     }
   else
     {
       (*QF)->sig = AUX;
       (*QF)=AUX;
     }
}

void visualizar(T_Cola *Q)
{
    if (Q==NULL) return;
    system("cls");
    printf("\n\nValores de la Lista\n\n");
    while (Q!=NULL){
		printf("\t%d\n",Q->Dato.x);
		Q=Q->sig;
    }
    getch( );
}
