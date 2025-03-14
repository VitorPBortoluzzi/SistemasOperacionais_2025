#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>  // Para a função wait()

void processo(int id) {
    for (int i = 0; i < 10; i++) {
        printf("Processo %d (PID: %d) - Iteração: %d\n", id, getpid(), i);
        usleep(100000);  // Pausa de 100 milissegundos (100000 microsegundos) para simulação de tempo de execução
    }
}

int main() {
    pid_t procID_1, procID_2, procID_3;

    // Criando o primeiro processo filho
    procID_1 = fork();
    if (procID_1 < 0) {
        printf("Falha na criação do processo 1\n");
        return -1;
    } else if (procID_1 == 0) {
        // Processo filho 1
        processo(1);
        return 0;
    }

    // Criando o segundo processo filho
    procID_2 = fork();
    if (procID_2 < 0) {
        printf("Falha na criação do processo 2\n");
        return -1;
    } else if (procID_2 == 0) {
        // Processo filho 2
        processo(2);
        return 0;
    }

    // Criando o terceiro processo filho
    procID_3 = fork();
    if (procID_3 < 0) {
        printf("Falha na criação do processo 3\n");
        return -1;
    } else if (procID_3 == 0) {
        // Processo filho 3
        processo(3);
        return 0;
    }

    // Processo Pai
    printf("Processo Pai (PID = %d) aguardando os filhos terminarem...\n", getpid());

    // Espera a finalização dos filhos
    wait(NULL);
    wait(NULL);
    wait(NULL);

    printf("Processo Pai (PID = %d) finalizou.\n", getpid());

/*
waitpid(procID_1, &status, 0);
    if (WIFEXITED(status)) {
        printf("Processo 1 terminou com código de saída %d\n", WEXITSTATUS(status));
    }

    // Espera o processo filho 2
    waitpid(procID_2, &status, 0);
    if (WIFEXITED(status)) {
        printf("Processo 2 terminou com código de saída %d\n", WEXITSTATUS(status));
    }

    // Espera o processo filho 3
    waitpid(procID_3, &status, 0);
    if (WIFEXITED(status)) {
        printf("Processo 3 terminou com código de saída %d\n", WEXITSTATUS(status));
    }
*/


    return 0;
}
