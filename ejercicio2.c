/* 
 * Objetivo: Utilizar el comportamiento LIFO para invertir cadenas.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Definición de tipos básicos
typedef char DATA;
typedef struct elemento {
    DATA d;
    struct elemento *siguiente;
} ELEMENTO;

typedef struct {
    int cnt;
    ELEMENTO *tope;
} PILA;

// --- Funciones de Pila (A completar por el alumno) ---
void inicializar(PILA *s){
    s->cnt=0;
    s->tope=NULL;
}
void push(PILA *s, DATA x){
    ELEMENTO *nuevo=(ELEMENTO*)malloc(sizeof(ELEMENTO));
    nuevo->d=x;
    nuevo->siguiente=s->tope;
    s->tope=nuevo;
    s->cnt++;
}
DATA pop(PILA *s){
    if(s->tope==NULL)
        return'\0';
    ELEMENTO*temp=s->tope;
    DATA dato=temp->d;
    s->tope=temp->siguiente;
    free(temp);
    s->cnt--;
    return dato;
}
int estavacia(PILA *s){
    return(s->tope==NULL);
}

/**
 * TAREA PRINCIPAL: Determinar si la cadena es palíndromo.
 * Estrategia sugerida:
 * 1. Recorrer la cadena y meter cada letra en la PILA A.
 * 2. Pasar la mitad de la PILA A a una PILA B para comparar 
 * (o usar una estrategia de inversión total).
 */
int esPalindromo(char cadena[]) {
    PILA original, invertida;
    inicializar(&original);
    inicializar(&invertida);

    int i, longitud = strlen(cadena);

    // 1. Filtrar y llenar la pila original
    for (i = 0; i < longitud; i++) {
        if (isalpha(cadena[i])) { // Solo letras
            char letra = tolower(cadena[i]);
            push(&original, letra);
        }
    }

    // 2. Crear la versión invertida
    // TIP: Al pasar elementos de una pila a otra, el orden se invierte.
    // Pero para comparar, necesitamos que una mantenga el orden original.
    // ¿Cómo usarías las dos pilas para tener la cadena al derecho y al revés?
    
    /* TODO: Implementar lógica de comparación usando las dos pilas */
    ELEMENTO *aux = original.tope;
    while(aux!=NULL){
        push(&invertida,aux->d);
        aux=aux->siguiente;
    }

    ELEMENTO *aux1=original.tope;
    ELEMENTO *aux2=invertida.tope;

    while(aux1!=NULL && aux2!= NULL){
        if(aux1->d != aux2->d)
            return 0;
        aux1=aux1->siguiente;
        aux2=aux2->siguiente;
    }
    return 1; // Retornar 1 si es palíndromo, 0 si no.
}

int main() {
    char prueba1[] = "Anita lava la tina";
    char prueba2[] = "Estructuras de Datos";

    printf("--- TEST DE PALINDROMOS ---\n");
    
    printf("Prueba 1: '%s' -> %s\n", prueba1, 
           esPalindromo(prueba1) ? "ES PALINDROMO" : "NO ES PALINDROMO");
           
    printf("Prueba 2: '%s' -> %s\n", prueba2, 
           esPalindromo(prueba2) ? "ES PALINDROMO" : "NO ES PALINDROMO");

    return 0;
}
