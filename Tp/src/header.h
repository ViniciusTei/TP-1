#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

int TAM; //tamanho do vetor

int* iniciaVetor();
int buscaBinaria(int *S, int x);
int resolveSoma(int *vet, int x);
void selection_sort(int num[]);
void heapsort(int a[], int n);
void fazTestes(int x);
void imprimeResultado (int x, double time_ordena, double time_exec1, double time_exec2, int resBin, int resFor);
