apc@ufn.edu.br

# Sistemas Operacionais  
## Atividade em Grupo  
<u> Questionamentos iniciais</u>

## 1. Como vocês definem o que é um Sistema Operacional?  
     Sistema Operacional e a "interface" de comunicação entre Hardware e Usuario;  
    Ponte entre hardware e softwares;  

## 2. Descreva como acontece a execução dos vários programas “simultaneamente” em um computador?
    A execução "simultanea" de programas no computador se da por um processo de fila, baseado em parâmetros de prioridade,

    Várias threads em execução que dividem o serviço

## 3. Há necessidade dos diferentes programas trocarem dados entre si? Se sim, como isto pode acontecer?
     Sim. Através de arquivos temporários ou via dados armazenados na memória RAM/Cache

     Variaveis de Ambiente
     Banco de dados compartilhados
     Troca de mensagens (Sockets)

## 4. Há diferentes tipos de memórias em um sistema de computação moderno. Como está organizada a hierarquia de memória nesse sistema?
    Registradores - Cache - Ram - Armazenamento Secundário - 

    Ram--> Cache --> Flash --> Virtual --> Armazenamento

    Ram - Cache - Secundária - Virtual - VRAM - ROM

## 5. Para que é utilizada a Memória Virtual?
     É utilizada como memória adicional para armazenamentos de dados e troca de dados entre as memórias RAM's, Unidade de armazenamento e o Processador.

     Extenção da Memória RAM - Vai pegar parte da memória de Armazenamento para usar como "Memória RAM"
     Aumentar o grau de multiprogramação

## 6. Em um sistema de computação, há os dispositivos de armazenamento e de entrada/saída. Como acontece o uso destes dispositivos pelos vários programas que estão executando?
    SO gerencia os acessos
        --> Escalonamento

## 7. Qual a finalidade de um Sistema de Arquivos? Considere sua experiência e relate o uso que fez de Sistemas de Arquivos.
    Gerenciamento de Dados