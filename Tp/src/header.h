#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define TAM 50 //tamanho do vetor inicial
#define TRUE 1
#define FALSE 0

int* iniciaVetor();
int buscaBinaria(int *S, int x);
int resolveSoma(int *vet, int x);
void selection_sort(int num[]);
void shellSort(int *vet);
