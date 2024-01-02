#include <stdio.h>
#include <stdlib.h>

struct Nodo
{
    int dato;
    struct Nodo *p_sig;
};

typedef struct Nodo Nodo_t;

void insertar_elemento_pila(Nodo_t **p_pila, int dato);
void imprimir_pila(Nodo_t *p);
void sacar_elemento_pila(Nodo_t **p_pila);

int main()
{
    Nodo_t *p_pila = NULL;
//    int dato = 0;
//    char rpt[1] = {0}, car = 0;

    insertar_elemento_pila(&p_pila,5);
    insertar_elemento_pila(&p_pila,10);
    insertar_elemento_pila(&p_pila,15);

//    do
//    {
//        printf("Inserte un numero: ");
//        scanf("%d",&dato);
//        insertar_elemento_pila(&p_pila,dato);

//        printf("\nQuiere seguir introduciendo datos (s/n)? ");
//        scanf("%s",rpt);
//        car = rpt[0];
//    } while ((car == 's') || (car == 'S'));

    //imprimir_pila(p_pila);

    //printf("\n*** ELEMENTOS DE LA PILA ***\n");
    //while(p_pila != NULL)
        sacar_elemento_pila(&p_pila);

    return 0;
}

void insertar_elemento_pila(Nodo_t **p_pila, int dato)
{
    Nodo_t *nuevo_nodo = (Nodo_t *)malloc(sizeof(Nodo_t));
    nuevo_nodo->dato = dato;
    nuevo_nodo->p_sig = *p_pila;
    *p_pila = nuevo_nodo;
}

void imprimir_pila(Nodo_t *p)
{
    //Enviamos una copia de pila así que podemos modifica su contenido
    //sin que se modifique el original
    printf("\n*** MOSTRANDO LOS ELEMENTOS DE LA PILA ***\n");
    while(p != NULL)
    {
        printf(" %d ", p->dato);
        p = p->p_sig;
        if(p != NULL) printf(" - ");
    }

    printf("\n\n");
}


//void sacar_elemento_pila(Nodo_t **p_pila)
//{
//    Nodo_t *aux = *p_pila;

//    printf(" %d ", aux->dato);
//    *p_pila = aux->p_sig;
//    if(*p_pila != NULL) printf(" - ");
//    free(aux);
//}

void sacar_elemento_pila(Nodo_t **p_pila)
{
    Nodo_t *aux = NULL;
    printf("\n*** ELEMENTOS DE LA PILA ***\n");

    while(*p_pila != NULL)
    {
        aux = *p_pila;
        printf(" %d ", (*p_pila)->dato);
        *p_pila = (*p_pila)->p_sig;
        if(*p_pila != NULL) printf(" - ");
        free(aux);
    }

    printf("\n\n");
}
