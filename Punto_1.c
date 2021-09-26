#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// pre procesador

//Clase IntArray
typedef struct IntArray{
    int *parr;//posicion en memoria del primer elemento
    int length;//Tamaño del arreglo
}IntArray;

//Metodos 
IntArray *createIntArray(int size); //Crea el array recibiendo por parametro el tamaño
void initIntArray(IntArray *);//rellena el array, recibiendo un puntero por parametro
void destroyIntArray(IntArray *);//destruye el array recibiendo por parametro la posicion de memoria 
void printArray(IntArray *);// imprime el array, recibiendo un puntero por parametro

int main(){
    IntArray *pIntArray = createIntArray(100);
    initIntArray(pIntArray);
    printArray(pIntArray);
    destroyIntArray(pIntArray);
}

IntArray *createIntArray(int size){
        IntArray *pIntArray = malloc(sizeof(IntArray)); //Se crea una variable de tipo IntArray y reserva en memoria espacio para el array
        pIntArray->parr =   malloc( sizeof(int) * size); // En pIntArray accede a parr y reserva en memoria el tamaño total de array
        pIntArray->length = size; // Accede a pIntArray a su propiedad length y guarda el size pasado por parametro
        return pIntArray; //Retorna pIntArray
}

void initIntArray(IntArray *this){
    for(int i = 0; i < 100; i++){
        this->parr[i] = i;
    }
}

void printArray(IntArray *this){
    for(int i = 0; i < this->length; i++){
        printf("parr[%d]: %d\n", i, this->parr[i]);
    }
}

void destroyIntArray(IntArray *this){
    free(this->parr);
    free(this);
}