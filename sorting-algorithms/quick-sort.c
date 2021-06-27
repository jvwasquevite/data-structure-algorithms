#include <stdio.h>

// QUICK SORT:

// A ordenação é feita por meio do paradigma dividir para conquistar
// O algoritmo escolhe um pivô e divide a lista ao meio, em duas sub-listas, onde:
// Antes do pivô (primeira lista) = valores menores que o pivô
// Depois do pivô (segunda lista) = valores maiores que o pivô
// O processo de ordenação e feito varrendo a lista da esquerda -> pivô e da direita -> pivô
// O processo de definição do pivô e divisão é feito de forma recursiva

// O melhor caso: o pivô é o elemento central, possui um valor central (mediana) -> O(n): Linear
// Caso médio: no melhor caso ao pegar um pivô aleatório o custo é de O(n*log n)
// O pior caso: pivô é o menor ou o maior do conjunto, possui um valor muito maior ou muito menor que os outros da lista (não ocorre divisão, apenas joga tudo de um lado para o outro), ou quando a lista já está ordenada -> O(n²): Quadrático

// É instável: depende da escolha do pivô e de como os dados estão previamente organizados
// Consome O(n) de memória por utlizar a recursão para a divisão e conquista
// No pior caso, o custo é de O(n²): precisa varrer toda a lista quando o pivô é o menor ou o maior do conjunto
// É mais rápido que algoritmos de bubble, selection e insertion sort
// Pode ser usado para ordenar listas que qualquer tamanho, entretando é extremamente recursivo

void quick_sort(int arr[], int left, int right) {
  int mid, tmp, i, j;
  i = left; // Index inicial
  j = right; // Index final

  // Identifica o pivô, index mais ao centro
  mid = arr[(left + right)/2];

  do {
    // PASSO 1: Faz a varredura, e encontra um elemento onde não deveria estar
    // Procura um elemento menor que o pivô pela esquerda
    while(arr[i] < mid)
      i++;
    // Procura um elemento maior que o pivô pela direita
    while(mid < arr[j])
      j--;

    // PASSO 2: Faz a troca (swap) quando um elemento está onde não deveria estar:
    // Direta -> esquerda do pivô
    // Esquerda -> direita do pivô
    if (i <= j) {
      tmp = arr[i];
      arr[i] = arr[j];
      arr[j] = tmp;

      i++;
      j--;
    }
  } while(i <= j); // Quando os elementos se cruzam, varreu toda a lista

  // Uso de recursão caso a ordenação ainda não tenha acabado
  if (left < j)
    quick_sort(arr, left, j);
  if (i < right)
    quick_sort(arr, i, right);
}

int main(int argc, char *argv[]) {
  int arr[5] = {500, 1, 50, 23, 76};
  quick_sort(arr, 0, 4); // Array, index inicial (0) e index final (5-1)

  printf("The sorted array is: \n");
  for(int i=0;i<5;i++) {
    printf("%d, ", arr[i]);
  }
}