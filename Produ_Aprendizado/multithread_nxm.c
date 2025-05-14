#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct 
{
    int **matrizA;
    int **matrizB;
    int **matrizResultado;
    int linhas;
    int colunas;
    int linhaInicial;
    int linhaFinal;
}Dados;

void *somaMatrizesTh(void *arg) {
    Dados *dados = (Dados *)arg;

    for (int i = dados -> linhaInicial; i < dados->linhaFinal; i++){
        for (int j = 0; j < dados->colunas; j++)
        {
            dados->matrizResultado[i][j] = dados->matrizA[i][j] + dados->matrizB[i][j];
        } 
    }
    pthread_exit(NULL);
}

int main(){
    int N,M, numThreads;

    printf("Digite o número de linhas (N): ");
    scanf("%d",&N);
    printf("Digite o número de colunas (M): ");
    scanf("%d",&M);
    printf("Digite o número de threads: ");
    scanf("%d",&numThreads);

    int **matrizA = (int **)malloc(N * sizeof(int *));
    int **matrizB = (int **)malloc(N * sizeof(int *));
    int **matrizResultado = (int **)malloc(N * sizeof(int *));

    for (size_t i = 0; i < N; i++)
    {
        matrizA[i] = (int *)malloc(M * sizeof(int));
        matrizB[i] = (int *)malloc(M * sizeof(int));
        matrizResultado[i] = (int *)malloc(M * sizeof(int));
    }

    // Preenchimento das matrizes (pode ser substituído por entrada do usuário)
    printf("Preenchendo matriz A:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matrizA[i][j] = rand() % 10;
            printf("%d ", matrizA[i][j]);
        }
        printf("\n");
    }
    
    printf("\nPreenchendo matriz B:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matrizB[i][j] = rand() % 10;
            printf("%d ", matrizB[i][j]);
        }
        printf("\n");
    }
    

    pthread_t threads[numThreads];
    Dados dadosThread[numThreads];
    int linhasPThread = N / numThreads;
    int linhaExtra = N % numThreads;
    int linhaAtual = 0;

    for (size_t i = 0; i < numThreads; i++)
    {
        dadosThread[i].matrizA = matrizA;
        dadosThread[i].matrizB = matrizB;
        dadosThread[i].matrizResultado = matrizResultado;
        dadosThread[i].linhas = N;
        dadosThread[i].colunas = M;
        dadosThread[i].linhaInicial = linhaAtual;

        int linhasThread = linhasPThread + (i < linhaExtra ? 1 : 0);
        dadosThread[i].linhaFinal = linhaAtual + linhasThread;
        linhaAtual = dadosThread[i].linhaFinal;

        pthread_create(&threads[i],NULL,somaMatrizesTh,&dadosThread[i]);
    }
    
    for (int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printf("\nResultado da soma:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", matrizResultado[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < N; i++) {
        free(matrizA[i]);
        free(matrizB[i]);
        free(matrizResultado[i]);
    }
    free(matrizA);
    free(matrizB);
    free(matrizResultado);
    
    return 0;
}