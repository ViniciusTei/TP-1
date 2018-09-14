#include "header.h"

int main (){

  int *vetorEntrada;
  int x;

  //variaveis para calculo do tempo
  clock_t t_exec, t_ordena;
  double time_exec, time_ordena;

  vetorEntrada = iniciaVetor();

  t_ordena = clock();//start
  selection_sort(vetorEntrada);
  //shellSort(S);
  t_ordena = clock() - t_ordena;//end

  /*for(int i = 0; i < TAM; i++){
    printf("%d ", S[i]);
  }

  printf("\n");*/

  //recebe o valor de x
  printf("Entre com um valor x: ");
  scanf("%d", &x);

  t_exec = clock(); //start
  /*if (buscaBinaria(S, x)){
    printf("Sim!\n");
  }
  else{
    printf("Nao!\n");
  }*/
  if (resolveSoma(vetorEntrada, x)){
    printf("Sim!\n");
  }
  else{
    printf("Nao!\n");
  }
  t_exec = clock() - t_exec; //end

  //faz o calculo do tempo gasto em cada funcao
  //tempo mostrado em segundos
  time_ordena = ((double)t_ordena)/CLOCKS_PER_SEC;
  time_exec = ((double)t_exec)/CLOCKS_PER_SEC;

  printf("Tempo gasto na ordenacao: %.3lfs\n", time_ordena);
  printf("Tempo gasto na execucao: %.3lfs\n", time_exec);

  return 0;
}
