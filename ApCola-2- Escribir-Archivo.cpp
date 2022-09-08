/* Ejemplo de una COLA. 
Cargar 15 valores numericos enteros generado automaticamente a una lista implementada como COLA.
El nodo de la Lista posee un valor entero y la direccion al siguiente elemento. Imprimir en un archivo del 
tipo texto llamado numerosC.dat*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{ 
	int x;
}T_Elemento;

struct cola{
  T_Elemento Dato;
  struct cola *sig;
};

typedef struct cola T_Cola;
typedef T_Cola *Ptr_Cola;

void insertar(Ptr_Cola *, Ptr_Cola *, T_Elemento);
void imprimir(T_Cola *);

main() /* Insertar e imprimir */
{
	T_Cola *L=NULL, *F=NULL;  
	T_Elemento N;
    int i;
	srand(time(NULL));
	
	for (i=1; i<=15; i++){ 
		N.x = (rand() % 20) + 1;
		insertar(&L,&F,N); 
	}

	imprimir(L);
	
	printf("\n\n");
	system("pause");
}	


void insertar(Ptr_Cola *Q, Ptr_Cola *QF, T_Elemento X)
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

void imprimir(T_Cola *Q)
{
    if (Q==NULL) 
		return;
    system("cls");
    FILE *Ar;
    if ((Ar=fopen("numerosC.dat","w"))==NULL)
       {printf("\nError en apertura......\n");
        getch();
        exit(0);}
    
	printf ("Elementos de la Cola:\n") ;  
    while (Q!=NULL){
	    fprintf(Ar,"%6d\n",Q->Dato.x);
	    printf("%6d\n",Q->Dato.x);
	    Q=Q->sig;
    }
    fclose(Ar);

}
