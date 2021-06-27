#include <stdio.h>

// INSERTION SORT:

// A ordenação é feita analisando cada um dos elementos e comparando com os antecedentes: um elemento por vez
// O elemento a ser testado analisa com o elemento anterior, caso seja preciso trocar de posição
// O elemento a ser testado é guardado em uma variável temporária e testada com cada um dos elementos antes dele
// Se for maior, empurra todos o números para frente, até chegar na posição onde ele vai se encaixar

// O melhor caso: vetor já ordenado, ele não entra no while -> O(n): Linear
// O pior caso: vetor na ordem inversa, entrará todas as vezes no while -> O(n²): Quadrático

// É instável: depende de como os dados estão previamente organizados
// Mais eficiente/rápido do que selection e bubble sort
// Menos eficiente que quick, head e merge sort
// Fácil de implementar para pequenas quantidades de dados
// É eficiente em dados que já estão pacialmente ordenados
// Requere pouco espaço na memória
// Consegue ordernar uma lista mesmo recebendo novos elementos em tempo de execução

void insertion_sort(int arr[], int n) {
  int i, j, temp;

  for(i=1; i<n; i++) { // Laço 'pula' o index inicial (i = 1)
    j = i-1; // j recebe o index anterior (j = 0)
    temp = arr[i]; // temp recebe o elemento a ser analisado (i = 1)
      
    // Laço compara o temp com os anteriores: 
    // Se o temp for menor que seu anterior && o anterior for >= 0
    while((temp < arr[j]) && (j>=0)) {
      arr[j+1] = arr[j]; // O elemento anterior passa para frente
      j--; // Decrementa o j
    }
      
    arr[j+1] = temp; // Passa para o próximo elemento a ser analisado
  }
}

int main(int argc, char *argv[]) {
  int arr[5] = {500, 1, 50, 23, 76};
  insertion_sort(arr, 5); // Array e número de elementos

  printf("The sorted array is: \n");
  for(int i=0;i<5;i++) {
    printf("%d, ", arr[i]);
  }
}