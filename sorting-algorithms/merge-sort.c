#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// MERGE SORT:

// A ordenação é feita dividindo a lista ao meio em partes iguais e depois juntando de forma ordenada: dividir para conquistar
// A lista é dividida ao meio de forma recursiva até sobrar apenas elementos isolados: merge_sort
// Com os elementos isolados, vai juntando de dois em dois de forma ordenada, até chegar em uma lista final ordenada: merge

// Não possui melhor e pior caso: sempre realiza o mesmo processamento independendo dos dados

// É estável: independentemente de como os dados estão previamente organizados, o tempo de execução e o processamento será o mesmo
// Consome O(n) de memória se implementado com linked lists (precisa apenas de um vetor temporário para armazenar os ponteiros de cada elemento) -> linear
// Consome O(n*log(n)) de processamento e tempo no pior e médio caso, pois realiza diversas divisões
// Não é adaptativo: mesmo com os dados quase ordenados, vai ter o mesmo tempo e custo computacional de um totalmente desordenado
// O selection e isertion sort não adaptativos, pois diminui o custo e tempo computacional se os dados já estão quase ordenados
// Não precisa de acesso aleatório: não precisa fazer buscas de elementos, apenas divide eles

void merge(int *arr, int beg, int mid, int end) {
  int *temp, size, ptr1, ptr2;

  // Controla quando a ordenação chega ao fim: end1 e end2 = 1
  int end1=0, end2=0;

  // Aponta para os dois arrays que quero comparar
  ptr1 = beg;
  ptr2 = mid+1;

  // Aloca um array temporário com o array ptr1 + ptr2
  size = end-beg+1;
  temp = (int*)malloc(size*sizeof(int));

  if(temp != NULL) {
    for(int i = 0; i < size; i++){
      if(!end1 && !end2){
        // Combina e ordena todos os elementos incrementando ptr1 e ptr2
        if(arr[ptr1] < arr[ptr2]) {
          temp[i] = arr[ptr1++];
        } else {
          temp[i] = arr[ptr2++];
        }

        // Testa seo vator chegou ao fim para sair do if
        if(ptr1>mid) end1 = 1;
        if(ptr2>end) end2 = 1;
      } else {
        // Realiza a união de forma ordenada: copia a sobra
        if(!end1) {
          temp[i] = arr[ptr1++];
        } else {
          temp[i] = arr[ptr2++];
        }
      }
    }

    // Copia do auxiliar temp para o original quando a lista já está 100% finalizada e ordenada
    for(int j = 0, k = beg; j < size; j++, k++) {
      arr[k] = temp[j];
    }
  }

  free(temp);
}

void merge_sort(int *arr, int beg, int end) {
  int mid;

  if(beg < end) {
  mid = floor((beg+end)/2); // Encontra o index central
  
  // Divisões do array por recursão
  merge_sort(arr, beg, mid);
  merge_sort(arr, mid+1, end);

  // Conquista: ordenação dos elementos divididos
  merge(arr, beg, mid, end);
  }
}

int main(int argc, char *argv[]) {
  int arr[5] = {500, 1, 50, 23, 76};
  merge_sort(arr, 0, 4); // Array, index inicial (0) e index final (5-1)

  printf("The sorted array is: \n");
  for(int i=0;i<5;i++) {
    printf("%d, ", arr[i]);
  }
}