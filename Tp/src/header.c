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
    vetor[i] = rand() % 100;
  }

  return vetor;
}

int buscaSoma(int *S, int x){
  int esq = 0;
  int dir = TAM - 1;
  int i, j;

  while(esq < dir){
    if(S[esq] + S[dir] == x){
      return TRUE;
    }
    else if (S[esq] + S[dir] < x){
      esq++;
    }
    else{
      dir--;
    }
  }

  return FALSE;
}

/* Utiliza o algoritmo BubbleSort */
void ordenaVetor(int *vet){
  int i, j, aux;

  for(i = 0; i < TAM-1; i++){
    for(j = i+1; j < TAM; j++){
      if(vet[j] < vet[i]){
        aux = vet[i];
        vet[i] = vet[j];
        vet[j] = vet[i];
      }
    }
  }
}
