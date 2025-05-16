#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <time.h>

#define N 3

int buffer[N];
int proxima_insercao = 0;
int proxima_remocao = 0;

sem_t exclusao_mutua;
sem_t espera_vaga;
sem_t espera_dado;

void imprimir_buff(){
	printf("Buffer: [");
	for (int i = 0; i < N; i++){
	printf("%d, ",buffer[i]);
	}
	printf("]\n");
}

void produtor(void* nome){
	sem_wait(&espera_vaga);
	sem_wait(&exclusao_mutua);
	
	int dado_produzido = rand() % 1000;
	buffer[proxima_insercao] = dado_produzido;
	imprimir_buff();
	proxima_insercao = (proxima_insercao + 1) % 3;
	
	sem_post(&exclusao_mutua);
	sem_post(&espera_dado);
	
	pthread_exit(0);
}

void consumidor(void* nome){
	int dado_a_consumir;
	
	sem_wait(&espera_dado);
	sem_wait(&exclusao_mutua);
	
	dado_a_consumir = buffer[proxima_remocao];
	imprimir_buff();
	proxima_remocao = (proxima_remocao + 1) % N;
	
	sem_post(&exclusao_mutua);
	sem_post(&espera_vaga);
	
	pthread_exit(0);
}


int main(){
	srand(time(NULL));
	int i;
	pthread_t thUm, thDois, thTres,thQuatro, thCinco;

	sem_init(&exclusao_mutua, 0, 1);
	sem_init(&espera_vaga,0 , N);
	sem_init(&espera_dado,0 , 0);
	
	pthread_create(&thUm, 0, (void *) produtor, "Um");
	pthread_create(&thDois, 0, (void *) produtor, "Dois");
	pthread_create(&thTres, 0, (void *) produtor, "Tres");
	pthread_create(&thQuatro, 0, (void *) consumidor, "Quatro");
	pthread_create(&thCinco, 0, (void *) produtor, "Cinco");
	
	pthread_join(thUm, NULL);
	pthread_join(thDois, NULL);
	pthread_join(thTres, NULL);
	pthread_join(thQuatro, NULL);
	pthread_join(thCinco, NULL);
	
	sem_destroy(&exclusao_mutua);
	sem_destroy(&espera_vaga);
	sem_destroy(&espera_dado);
	
	printf("Fim do Thread Principal\n");

	return 1;
}
