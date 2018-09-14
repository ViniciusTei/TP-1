#include "header.h"

/* Aloca um vetor de tamanho TAM e
 * inicia seus indices com um valor aleatório.
 */
int* iniciaVetor(){
  int *vetor;
  int i;

  srand(time(NULL));

  vetor = (int *) malloc(sizeof(int) * TAM);

  for(i = 0; i < TAM; i++){
    vetor[i] = 1 + (rand() % 100);
    //printf("%d ", vetor[i]);
  }
  //printf("\n");
  return vetor;
}

/* Resolve o problema usando busca binaria.
 */
int buscaBinaria(int *vet, int x){
  int esq = 0;
  int dir = TAM - 1;
  int i, j;

  while(esq < dir){
    if(vet[esq] + vet[dir] == x){
      return TRUE;
    }
    else if (vet[esq] + vet[dir] < x){
      esq++;
    }
    else{
      dir--;
    }
  }

  return FALSE;
}

/* Resolve o problema usando força bruta.
 */
int resolveSoma(int *vet, int x){
  int i, j;

  for(i = 0; i < TAM; i++){
    for(j = i+1; j < TAM; j++){
      if(vet[i] + vet[j] == x)
        return 1;
    }
  }

  return 0;
}

/********** ALGORITMOS DE ORDENAÇÃO ***********/

void selection_sort(int num[]) {
  int i, j, min, aux;
  for (i = 0; i < (TAM-1); i++)
  {
     min = i;
     for (j = (i+1); j < TAM; j++) {
       if(num[j] < num[min])
         min = j;
     }
     if (num[i] != num[min]) {
       aux = num[i];
       num[i] = num[min];
       num[min] = aux;
     }
  }
}

void shellSort(int *vet) {
    int i , j , value;
    int gap = 1;
    while(gap < TAM) {
        gap = 3*gap+1;
    }
    while ( gap > 1) {
        gap /= 3;
        for(i = gap; i < TAM; i++) {
            value = vet[i];
            j = i;
            while (j >= gap && value < vet[j - gap]) {
                vet[j] = vet [j - gap];
                j = j - gap;
            }
            vet [j] = value;
        }
    }
}
