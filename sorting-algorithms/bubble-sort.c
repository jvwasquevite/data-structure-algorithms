#include <stdio.h>

// BUBBLE SORT:

// Move repetidamente o maior elemento para o maior index do array (para ordenação crescente)
// Move repetidamente o menor elemento para o maior index do array (para ordenação decrescente)

// Sua complecidade é de O(n²) em todos os casos
// Não possui melhor e pior caso: sempre realiza o mesmo processamento independendo dos dados

// É estável: independentemente de como os dados estão previamente organizados, o tempo de execução e o processamento será o mesmo

// OPTIMIZED BUBBLE SORT:

// Identifica se o array já está ordenado pela flag
// Após cada passo: flag = 1 (true)
// Após cada troca: flag = 0 (false)

// O melhor caso: vetor já ordenado -> O(n): Linear
// Pior caso: algoritmo será mais lento que o original
// Caso médio: performance será mais rápido que o original

void bubble_sort(int arr[], int n) {
  int temp;
  
  for(int i=0; i<n; i++) { // Percorre todo a lista: index 0 -> index 4
    for(int j=0; j<n-i-1; j++) { // A frequência desse laço diminui após cada passo (n-i), pois um elemento já estará em sua posição correta
      // Compara um par consecutivo de elementos
      if(arr[j] > arr[j+1]) { // Faz a troca (swap) se o elemento de menor index (arr[j]) é maior que o elemento de maior index (arr[j+1])
        temp = arr[j];	
        arr[j] = arr[j+1];		
        arr[j+1] = temp;	
      }
    }
  }
}

void optimized_bubble_sort(int arr[], int n) {
  int temp, flag = 0;
  
  for(int i=0; i<n; i++) {
    for(int j=0; j<n-i-1; j++) {
      if(arr[j] > arr[j+1]) {
        flag = 1;
        temp = arr[j];	
        arr[j] = arr[j+1];		
        arr[j+1] = temp;	
      }
    }

    if(flag == 0) // When array is already sorted
      return;
  }
}

int main(int argc, char *argv[]) {
  int arr[5] = {500, 1, 50, 23, 76};
  bubble_sort(arr, 5); // Array e número de elementos

  printf("The sorted array is: \n");
  for(int i=0;i<5;i++) {
    printf("%d, ", arr[i]);
  }

  optimized_bubble_sort(arr, 5); // Array e número de elementos
  printf("\nThe optimized sorted array is: \n");
  for(int i=0;i<5;i++) {
    printf("%d, ", arr[i]);
  }
}