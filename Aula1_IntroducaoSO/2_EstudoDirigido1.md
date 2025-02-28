```
o Capítulo 2 – Conceitos de Hardware e Software
de DEITEL, Harvey M.; DEITEL, Paul J.; CHOFFNES, David R. Sistemas operacionais. São Paulo: Pearson,
2005. Disponível na biblioteca virtual da UFN: https://plataforma.bvirtual.com.br/Acervo/Publicacao/315
```

## 1. Caracterize um sistema de computação moderno:
    "Os computadores hoje permitem que usuários acessem a Internet, consultem páginas Web, apresentem gráficos e veideos, ouçam músicas, joguem - e muito mais.
    Consiste em um ou mais processadores, memória principal, relógios, terminais, discos, interfaces de rede e outros dispositivos de entrada/saída."

## 2. Quais a etapas de inicialização do computador? pg 44
    Antes que um sistema operacional possa começar a gerenciar recursos, ele deve ser carregado na memória. Quando um sistema de computador é ligado, o BIOS inicializa o hardware do sistema e tenta carregar instruções na memória principal em uma região de armazenamento secundário (por exemplo, um disco flexível, um disco rígido ou um CD), denominada setor de inicialização (boot sector), uma técnica chamada autocarregamento (Figura 2.6). O processador é forçado a executar essas instruções que normalmente carregam componentes do sistema operacional na memória, inicializam registradores de processador e preparam o sistema para executar aplicações de usuários.

    Em muitos sistemas o BIOS pode carregar um sistema operacional em uma localização predefinida em um número limitado de dispositivos (por exemplo, o setor de inicialização de um disco rígido ou de um disco compacto). Se o setor de inicialização não for encontrado em um dispositivo suportado, o sistema não será carregado, e o usuário não conseguirá acessar nenhum hardware do computador. Para proporcionar maior funcionalidade na hora da inicialização, a Intel Corporation desenvolveu a interface extensível de firmware (Extensive Firmware Interface – EFI) em substituição ao BIOS. A EFI suporta um interpretador de comandos, por meio do qual usuários podem acessar diretamente dispositivos do computador, e incorpora unidades de dispositivos para suportar acesso a unidades de disco rígido e redes, imediatamente após ligar o sistema.²⁶

## 3. O que é interrupção? Como os Sistemas Operacionais tratam as interrupções?
    Processadores informam a sistemas operacionais sobre eventos como erros na execução de programas e mudanças no estado de dispositivos (por exemplo, chegou um pacote de rede ou foi concluída uma entrada/saída por disco). Um processador pode fazer isso consultando repetidamente o status de cada dispositivo, uma técnica denominada sondagem (polling). Entretanto, isso pode gerar um significativo custo adicional de execução quando os dispositivos sondados não tiverem mudado de status.

    Em vez disso, a maioria dos dispositivos envia ao processador um sinal denominado interrupção quando ocorre um evento. O sistema operacional pode responder a uma mudança no status do dispositivo notificando os processos que estão à espera desses eventos. Exceções são interrupções geradas em resposta a erros, como falhas de hardware, erros de lógica e violações de proteção (veja no site deste livro: "Curiosidades — Origens do Termo 'Glitch'"). Em vez de provocar a falha do sistema, o processador tipicamente invocará o sistema operacional para que este determine como ele deve reagir.

## 4. Defina I/O síncrona e I/O assíncrona. Qual permite melhor uso da CPU?


## 5. Qual a finalidade da DMA – Direct Memory Access?
    O Acesso Direto à Memória (DMA) permite que dispositivos transfiram dados diretamente para a memória principal sem envolver o processador, liberando-o para outras tarefas. Um controlador de E/S gerencia essa transferência e gera uma interrupção ao final do processo, melhorando o desempenho em sistemas com muitas operações de E/S, como servidores.
    
## 6. Como funciona a RAM? Qual o ciclo básico de execução de uma instrução?
    Memória principal consiste em memória volátil de acesso aleatório (Random Access Memory - RAM); ‘aleatório’ no sentido de que os processos podem acessar localizações de dados em qualquer ordem. Ao contrário, as localizações de dados em um meio de armazenamento sequencial (por exemplo, fita) devem ser lidas em seqüência. 
    

## 7. Caracterize a estrutura de armazenamento de um sistema de computação.
## 8. Em que consiste o uso de cache?
    Para melhorar o desempenho, a maioria dos sistemas executa caching colocando cópias das informações as quais os processos se referem em armazenameto mais rápido.
## 9. Caracterize os diferentes tipos de proteção de hardware suportados em um sistema de computação