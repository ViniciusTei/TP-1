#include "header.h"

void fazTestes() {
  int control = 0;
  int *vetIn;
  int x, resBin, resFor;

  TAM = 500;

  srand(time(NULL));

  //variaveis para calculo do tempo
  clock_t t_exec1, t_exec2, t_ordena;
  double time_exec1, time_exec2, time_ordena;

  while (TAM <= 5000) {

    printf("Tamanho:  %d\n", TAM);

    if (control) {
      vetIn = iniciaVetor();

      t_ordena = clock();//start
      heapsort(vetIn, TAM);
      t_ordena = clock() - t_ordena;//end

      x = rand() % 200;

      t_exec1 = clock(); //start
      resBin = buscaBinaria(vetIn, x);
      t_exec1 = clock() - t_exec1; //end

      t_exec2 = clock(); //start
      resFor = resolveSoma(vetIn, x);
      t_exec2 = clock() - t_exec2; //end

      time_ordena = ((double)t_ordena)/CLOCKS_PER_SEC;
      time_exec1 = ((double)t_exec1)/CLOCKS_PER_SEC;
      time_exec2 = ((double)t_exec2)/CLOCKS_PER_SEC;

      printf("Algoritmo de ordenacao: Heap Sort\n");
      imprimeResultado(x, time_ordena, time_exec1, time_exec2, resBin, resFor);

      control = 0;
      TAM += 1500;
    }
    else {
      vetIn = iniciaVetor();

      t_ordena = clock();//start
      selection_sort(vetIn);
      t_ordena = clock() - t_ordena;//end

      x = rand() % 200;

      t_exec1 = clock(); //start
      resBin = buscaBinaria(vetIn, x);
      t_exec1 = clock() - t_exec1; //end

      t_exec2 = clock(); //start
      resFor = resolveSoma(vetIn, x);
      t_exec2 = clock() - t_exec2; //end

      time_ordena = ((double)t_ordena)/CLOCKS_PER_SEC;
      time_exec1 = ((double)t_exec1)/CLOCKS_PER_SEC;
      time_exec2 = ((double)t_exec2)/CLOCKS_PER_SEC;

      printf("Algoritmo de ordenacao: Selection Sort\n");
      imprimeResultado(x, time_ordena, time_exec1, time_exec2, resBin, resFor);

      control = 1;
    }
  }
}

void imprimeResultado(int x, double time_ordena, double time_exec1, double time_exec2, int resBin, int resFor) {
  if (resBin == 1 && resFor == 1) {
    printf("Valor de x: %d\n", x);
    printf("Tempo gasto na ordenacao: %lfs\n", time_ordena);
    printf("Tempo resolucao busca binaria: %lfs\n", time_exec1);
    printf("Tempo resolucao froca bruta: %lfs\n", time_exec2);
    printf("\n");
  }
}
