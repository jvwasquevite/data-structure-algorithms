#include <stdio.h>

// SELECTION SORT:

// A ordenação é feita encontrando os menores valores e posicionando nas primeiras posições:
// Encontra o menor valor e insere na primeira posição
// Encontra o segundo menor valor e insere na segunda posição

// Sua complecidade é de O(n²) em todos os casos
// Não possui melhor e pior caso: sempre realiza o mesmo processamento independendo dos dados

// É estável: independentemente de como os dados estão previamente organizados, o tempo de execução e o processamento será o mesmo
// É usado em listas com poucos dados, mas com objetos (valores) grandes armazenado em cada index
// É pior do que o insertion sort

int smallest(int arr[], int k, int n) {
  int pos = k, small = arr[k];

  for(int i=k+1;i<n;i++) {
    if(arr[i] < small) {
      small = arr[i];
      pos = i;
    }
  }
  return pos;
}

void selection_sort(int arr[], int n) {
  int pos, temp;

  for(int k=0;k<n;k++) {
  pos = smallest(arr, k, n); // Retorna o menor elemento

  // Faz a troca (swap)
  temp = arr[k];
  arr[k] = arr[pos];
  arr[pos] = temp;
  }
}

int main(int argc, char *argv[]) {
  int arr[5] = {500, 1, 50, 23, 76};
  selection_sort(arr, 5); // Array e número de elementos

  printf("The sorted array is: \n");
  for(int i=0;i<5;i++) {
    printf("%d, ", arr[i]);
  }
}