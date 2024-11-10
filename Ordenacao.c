#include  <stdlib.h>
#include  <stdio.h>
#include  <math.h>
#include <unistd.h>

void clearScreen() {
    #ifdef _WIN32
        system("cls"); // Comando para Windows
    #else
        system("clear"); // Comando para Linux/Unix
    #endif
}

void delay(int segundos) {
    usleep(segundos * 1000000); // Em Linux: converte segundos para microssegundos
    // Sleep(seconds * 1000); // Em Windows: converte segundos para milissegundos
}

void displayMenu() {
    printf("===== MENU DE ALGORITMOS DE ORDENAÇÃO =====\n");
    printf("Selecione o algoritmo de ordenação desejado:\n");
    printf("1. Selection Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. QuickSort\n");
    printf("4. MergeSort\n");
    printf("5. HeapSort\n");
    printf("6. Bubble Sort\n");
    printf("7. BucketSort\n");
    printf("8. RadixSort\n");
    printf("0. Sair\n");
    printf("===========================================\n");
    printf("Digite a opção desejada: ");
}

void PrintVet(int *vet, int tamanho){
    int i=0;
    while (i<tamanho)
    {
        printf("%i",vet[i]);
        i++;
    }
    printf("\n");
}

void SelectionSort(int *vet, int tamanho){
    int min;
    for(int j=0;j < tamanho-1;j++){
        min = j;
        for(int i = j+1; i < tamanho;i++){
            if(vet[min]>vet[i]){
                min = i;
            }
        }
        int temp = vet[min];
        vet[min] = vet[j];
        vet[j] = temp;
    }
}

int main() {
    int opcao;
    do {
        displayMenu();
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                clearScreen();
                printf("Você escolheu Selection Sort.\n\n");
                delay(1);
                printf("Esse algoritmo percorre o vetor repetidamente, procurando\n");
                delay(1);
                printf("o menor elemento e o trocando com o de menor posição possível\n");
                delay(1);
                printf("Complexidade: O(n^2) no pior e melhor caso,\npois o algoritmo sempre faz o mesmo número de comparações\nindependentemente da ordem inicial dos elementos..\n");
                delay(1);
                printf("Estável: Não, pois ao fazer a troca de elementos iguais, a ordem relativa pode ser alterada.\n");
                delay(1);
                printf("In-place: Sim, pois não requer espaço extra proporcional ao tamanho do vetor.\n");
                delay(1);
                int vet[5] = {7,8,2,1,5};
                int tamanhoVet = 5;
                int opcao;
                PrintVet(vet,tamanhoVet);
                SelectionSort(vet,tamanhoVet);
                PrintVet(vet,tamanhoVet);
                delay(5);
                clearScreen();
                break;
            case 2:
                printf("Você escolheu Insertion Sort.\n");
                break;
            case 3:
                printf("Você escolheu QuickSort.\n");
                break;
            case 4:
                printf("Você escolheu MergeSort.\n");
                break;
            case 5:
                printf("Você escolheu HeapSort.\n");
                break;
            case 6:
                printf("Você escolheu Bubble Sort.\n");
                break;
            case 7:
                printf("Você escolheu BucketSort.\n");
                break;
            case 8:
                printf("Você escolheu RadixSort.\n");
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while(opcao != 0);

    return 0;
}