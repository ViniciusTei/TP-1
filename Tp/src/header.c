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
        return TRUE;
    }
  }

  return FALSE;
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

void heapsort(int a[], int n) {
   int i = n / 2, pai, filho, t;
   while(TRUE) {
      if (i > 0) {
          i--;
          t = a[i];
      } else {
          n--;
          if (n == 0) return;
          t = a[n];
          a[n] = a[0];
      }
      pai = i;
      filho = i * 2 + 1;
      while (filho < n) {
          if ((filho + 1 < n)  &&  (a[filho + 1] > a[filho]))
              filho++;
          if (a[filho] > t) {
             a[pai] = a[filho];
             pai = filho;
             filho = pai * 2 + 1;
          } else {
             break;
          }
      }
      a[pai] = t;
   }
}
