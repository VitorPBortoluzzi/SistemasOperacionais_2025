#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct{
    int **matriz;
    int *vetor;
    int *resultado;
    int tamanho;
    int inicio;
    int fim;
} Dados;

void *multiplicaMatriz(void *arg){
    Dados *dados = (Dados *)arg;

    for (int i = dados->inicio; i < dados->fim; i++)
    {
        dados->resultado[i]=0;
        for (int j = 0; j < dados->tamanho; j++)
        {
            dados->resultado[i] += dados->matriz[i][j] * dados->vetor[j];
        }
    }
    
    pthread_exit(NULL);
}

int main(){
    int N, numThreads;
    printf("Digite o tamanho N da matriz NxN & Vetor(N):");
    scanf("%d",&N);
    printf("Digite o número de threads: ");
    scanf("%d",&numThreads);

    int **matriz = (int **)malloc(N * sizeof(int *));
    int *vetor = (int *)malloc(N * sizeof(int));
    int *resultado = (int *)malloc(N * sizeof(int));
    
    for (int i = 0; i < N; i++) {
        matriz[i] = (int *)malloc(N * sizeof(int));
    }

    printf("\nPreenchendo matriz:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = rand() % 5;
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    
    printf("\nPreenchendo vetor:\n");
    for (int i = 0; i < N; i++) {
        vetor[i] = rand() % 5;
        printf("%d\n", vetor[i]);
    }

    pthread_t threads[numThreads];
    Dados dadosThread[numThreads];
    int linhaPThread = N / numThreads;
    int linhaExtra = N % numThreads;
    int linhaAtual = 0;

    for (int i = 0; i < numThreads; i++) {
        dadosThread[i].matriz = matriz;
        dadosThread[i].vetor = vetor;
        dadosThread[i].resultado = resultado;
        dadosThread[i].tamanho = N;
        dadosThread[i].inicio = linhaAtual;
        
        int linhaThread = linhaPThread + (i < linhaExtra ? 1 : 0);
        dadosThread[i].fim = linhaAtual + linhaThread;
        linhaAtual = dadosThread[i].fim;

        pthread_create(&threads[i],NULL,multiplicaMatriz,&dadosThread[i]);
    }

    for (int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printf("\nResultado da multiplicação matriz-vetor:\n");
    for (int i = 0; i < N; i++) {
        printf("%d\n", resultado[i]);
    }
    
    for (int i = 0; i < N; i++) {
        free(matriz[i]);
    }
    free(matriz);
    free(vetor);
    free(resultado);
    
    return 0;
}