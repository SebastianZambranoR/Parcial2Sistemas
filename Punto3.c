#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define sizeA 20

int min(int *pVal, int arrSize);

int max(int *pVal, int arrSize);

float promedio(int *pVal, int arrSize);

int main(void){

    FILE *inFile = fopen("./in.txt","r"); //abre el archivo y se prepara para leerlo

    if(inFile == NULL){//validador
        perror("Open file fails: ");
        return(EXIT_FAILURE);
    }
    char tmpArr[sizeA];

    fgets(tmpArr, sizeA, inFile); //lee el archivo de texto y almacena los datos
    fclose(inFile);

    int *dinArr = malloc(sizeof(int) * sizeA); //arreglo de enteros en memoria dinamica
    char *token = strtok(tmpArr, " "); //divide el arreglo tmpArr por los espacios y guarda cada caracter dividido en token
    int i = 0; //Permite saber el tamaño del arreglo
    while(token != NULL){

        sscanf(token, "%d", &dinArr[i]); //convierte los datos que hay en token, de char a int y los guarda en el dinArr
        token = strtok(NULL," ");//evita que se sobreescriban los datos
        i++;
    }

    int minValue = min(dinArr, i);
    printf(" %d\n", minValue); 

        int maxValue = max(dinArr, i);
    printf(" %d\n", maxValue); 

    float avgValue = promedio(dinArr, i);
    printf(" %.2f\n", avgValue); 


    FILE *outFile = fopen("./out.txt","w"); //abre el archivo y se prepara para sobreescribirlo

    if(outFile == NULL){//validador
        perror("Open file fails: ");
        return(EXIT_FAILURE);
    }
    //escribe en el archivo de texto los datos
    fprintf(outFile,"El minValue es %d, el maxValue es %d, el promedio es %.2f", minValue, maxValue, avgValue);

    fclose(outFile);
    free(dinArr);
    return(EXIT_SUCCESS);


}

    int min(int *pVal, int sizeArr){
        int min = pVal[0];
        for(int i = 0; i < sizeArr; i++){
            if(pVal[i] < min){
                min = pVal[i];
            }
        }
        return min;
    }

        int max(int *pVal, int sizeArr){
        int max = pVal[0];
        for(int i = 0; i < sizeArr; i++){
            if(pVal[i] > max){
                max = pVal[i];
            }
        }
        return max;
    }

        float promedio(int *pVal, int sizeArr){
        int prom = 0;
        for(int i = 0; i < sizeArr; i++){
            prom += pVal[i];
        }
        return (float)prom/sizeArr;
    }