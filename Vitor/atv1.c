#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
int a = 0, b = 0, area = 0, perimetro = 0;

printf("Digite o comprimento do terreno: ");
scanf("%d",&a);

printf("Digite a altura do terreno: ");
scanf("%d",&b);

pid_t procID;
procID = fork();
if (procID < 0)
{
printf("Erro na criação do novo processo\n");
return -1;
	}
	else if (procID == 0)
	{
		printf("Processo filho - PID = %d\n", getpid());
		area = a * b;
		printf("A area do terreno é: %d\n", area);
		return 0;
	}
	else
		{
		printf("Processo Pai - PID = %d\n", getpid());
		printf("O perimetro do terreno é: %d\n", perimetro = (a+b)*2);
		
		return 0;
	}
}
