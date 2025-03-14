#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

void processoF(int id ,int a, int b) {
    for (int i = a; i < b; i++) {
        printf("Processo %d (PID: %d) - Iteração: %d\n", id, getpid(), i);
        sleep(1);
    }
}

void processoP(int id ,int a, int b) {
    for (int i = a; i < b; i++) {
        printf("Processo %d (PID: %d) - Iteração: %d\n", id, getpid(), i);
        sleep(2);
    }
}

int main() {
    pid_t procID_1, procID_2;

    procID_1 = fork();
    if (procID_1 < 0) {
        printf("Falha na criação do processo 1\n");
        return -1;
    } else if (procID_1 == 0) {
        processoF(1, 100, 200);
        printf("Processo filho 1 (PID: %d) terminou\n",getpid());
        return 0;
    }

    procID_2 = fork();
    if (procID_2 < 0) {
        printf("Falha na criação do processo 2\n");
        return -1;
    } else if (procID_2 == 0) {
        processoF(2, 250,350);
        printf("Processo filho 2 (PID: %d) terminou\n",getpid());
        return 0;
    }

    printf("Processo Pai (PID = %d)\n", getpid());
    processoP(10, 1 , 50);

    printf("Processo Pai (PID = %d) finalizou.\n", getpid());

    return 0;
}

