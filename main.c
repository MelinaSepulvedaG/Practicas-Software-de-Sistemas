#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
struct Nodo {
    int dato;
    struct Nodo *izquierda;
    struct Nodo *derecha;
};

static struct Nodo *prev = NULL;

struct Nodo *nuevoNodo(int dato) {
    size_t tamanioNodo = sizeof(struct Nodo);
    struct Nodo *nodo = (struct Nodo *) malloc(tamanioNodo);
    // Asignar el dato
    nodo->dato = dato;
    nodo->izquierda = nodo->derecha = NULL;
    return nodo;
}

void insertar(struct Nodo *nodo, int dato) {

    // Si es mayor va a la derecha
    if (dato > nodo->dato) {
        // Tienes espacio a la derecha?
        if (nodo->derecha == NULL) {
            nodo->derecha = nuevoNodo(dato);
        } else {
            //si la derecha esta ocupada vuelve a verificar
            insertar(nodo->derecha, dato);
        }
    } else {
        // Si no, a la izquierda
        if (nodo->izquierda == NULL) {
            nodo->izquierda = nuevoNodo(dato);
        } else {
            //si la izquierda esta ocupada vuelve a verificar
            insertar(nodo->izquierda, dato);
        }
    }
}
//verifica si el arbol es valido
bool verificar(struct Nodo *nodo) {
 if (nodo)
    {
        if (!verificar(nodo->izquierda)) return false; //toma el nodo mas abajo de la izquierda

        if (prev != NULL && nodo->dato <= prev->dato) return false;
        prev = nodo;
        return verificar(nodo->derecha);    //toma el nodo derecho y comprueba
    }
    return true;
}
void display_derecha(struct Nodo *rama){
    printf("DERECHA: %d",rama->dato);
}
void display_izq(struct Nodo *rama){
    printf("IZQUIERDA: %d ",rama->dato);
}
void display_nodo(struct Nodo *nodo){
    printf("NODO: %d ",nodo->dato);
    if(nodo->izquierda != NULL){
        display_izq(nodo->izquierda);
    }if(nodo->derecha != NULL){
        display_derecha(nodo->derecha);
    }
    printf("\n");
}

//metodo para el recorrido post orden de izquiera a derecha
void postorden(struct Nodo *nodo ) {
    if (nodo != NULL) {
        postorden(nodo->izquierda);
        display_nodo(nodo);
        postorden(nodo->derecha);
    }
}
//metodo para buscar un nodo y muestra sus hijos
void buscar(struct Nodo *nodo, int data){
    if( data== nodo->dato){
            display_nodo(nodo);
     }else{
        if(data < nodo->dato){
            buscar(nodo->izquierda,data);
        }
        else{
            buscar(nodo->derecha,data);
        }
}
}

int main(void) {
    struct Nodo *Newnode = nuevoNodo(10);
    Newnode->derecha = nuevoNodo(15);
    Newnode->izquierda = nuevoNodo(8);
    if(verificar(Newnode)){
        printf("\n ARBOL BINARIO VALIDO\n");
    }else{
     printf("\n ARBOL BINARIO NO VALIDO\n");
    }
    prev = NULL;
    //DISPLAY EN POSTORDEN
    printf("\n POSTORDEN\n");
    postorden(Newnode);
    //BUSCAR
     printf("\n BUSCAR\n");
    buscar(Newnode,10);





}
