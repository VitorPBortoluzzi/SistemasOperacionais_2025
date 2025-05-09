## Processos Cooperativos

- Dois threads concorrentes podem executar independentemente um do outro ou cooperativamente. Quando threads operam independentemente um do outro, mas ocasionamente devem se comunicar e se sincronizar para executar tarefas cooperativas, diz-se que executam assincronamente.

DEITEL, H. M.; DEITEL, P. J.; CHOFFNES, D. R. **Sistemas operacionais**. 3. ed. [Pg.113]; São Paulo, SP: Pearson, 2005. *E-book*. Disponível em: https://plataforma.bvirtual.com.br. Acesso em: 09 maio 2025.

## 5.2 Exclusão Mútua

- **Serialização do acesso à variável compartilhada:** "Quando o trhead que está executando terminar de acesar a variável compartilhada, o sistema permitirá que um dos processos à espera prossiga.”
    - Dessa maneira, threads não poderão acessar dados compartilhados simultaneamente. Enquanto cada thread estiver atualizando a variável compartilhada, todos os outros serão impedidos de fazê-lo simultaneamente, o que é denominado “**Exclusão Mútua**”.

## 5.2.2 Seção Crítica [(pg.120)]

- A exclusão mútua precisa ser imposta somente quando threads acessam dados que podem ser modificados. Quando threads realizam operações que não conflitam uma com a outra(por exemplo, leitura de variáveis), o sistema deve permitir que os trheads prossigam concorrentemente. Quando um trhead acessa dados modificáveis, diz-se que está em uma “**Seção crítica**”.

## 5.4 Soluções à Proteção da Seção da Seção Crítica.

### O algoritmo de Dekker [Pg.122]: 2 Threads

- Quinta versão (uma versão adequada):

Mudanças entre as versões & Problemas encontrados durante as versões anteriores:

- 1º versão -
    - Implementação de variável para controle de acesso da seção crítica
    
    Problemas
    
    - Espera ociosa
    - Sincronização de intertravamento - se um thread precisar entrar em sua seção crítica mais frequentemente do que outro, o thread mais veliz será obrigado a funcionar na velocidade do mais lento.
- 2º versão -
    - Implementação de uma segunda variável para controle de acesso hà sessão crítica; Uma para cada thread;
    
    Problemas
    
    - Violação da exclusão mútua - Ambas as threads podem estar em estádo de falso fazendo assim executarem suas threads concorrentemente suas sessões críticas violando a exclusão múltipla.
- 3º versão -
    - Assim que um entra em sua sessão crítica, bloqueia a entrada há sessão crítica do outro;
    
    Problemas:
    
    - Deadlock(Impasse): Se cada thread sinalizar seu flag antes de executar o teste while, cada um deles encontrará o flag de um outro thread sinalizado e ficará executando o laço para sempre em while”
        - Discutidos no capítulo 7, “Deadlock e adiamento indefinido”.
- 4º versão -
    - Força cada thread a definir sua flag em false durante curtos períodos, o que permite que outro thread prossiga com seu laço while com seu próprio flag colocado em true.
    
    Problemas:
    
    - Adiamento indefinido: Cada threadh pode colocar seu flag em verdadeiro, em seeguida fazer o teste while, depois entrar no corpo do laço while, colocar seu flag em falso, esperar durante um período de tempo aleatório, colocar seu flag em verdadeiro, e repetir a sequência começando no teste while. À medida que os threads fazem isso, as condições testadas permanecerão verdadeiras.
- 5º Versão - Algoritmo de Dekker uma solução adequada:

**{O texto a seguir foi transcrito do livro usando o DeepSeek}**

**Algoritmo de Dekker (uma solução adequada)**

A figura 5.10 ilustra o Algoritmo de Dekker - uma solução correta da exclusão mútua de dois threads implementada exclusivamente em software sem nenhuma instrução de hardware de uso especial. O algoritmo de Dekker ainda usa um flag de sinalização (flag) para indicar o desejo de um thread de entrar na sua seção crítica, mas também incorpora o conceito de 'thread favorecido' (favored_thread), que entrará na seção crítica no caso de ocorrer uma disputa (isto é, quando cada thread desejar entrar simultaneamente em sua seção crítica).

Vamos examinar como o Algoritmo de Dekker elimina a possibilidade de adiamento indefinido ocorrida na versão 4. Primeiramente observe que, nesse algoritmo, a primitiva enter_MutualExclusion é implementada pelas linhas 15-26 e 45-56; a primitiva exit_MutualExclusion é implementada pelas linhas 30-31, 60-61. T indica seu desejo de entrar em sua seção crítica simulando seu flag em true (linha 15).

O thread então prossegue até o teste while (linha 17) e determina se T₂ também quer entrar em sua seção crítica. Se o flag de T₂ estiver sinalizado em false, não haverá disputa entre threads que estão tentando entrar em suas seções críticas, portanto T₁ pulará o corpo do laço while e entrará em sua seção crítica (linha 28).

Suponha, porém, que, quando T₁ executar o teste while (linha 17), descubra que o flag de T₂ está sinalizado em true. Nesse caso, haverá disputa entre threads que estão tentando entrar em suas respectivas seções críticas. O thread T₁ entra no corpo do seu laço while, no qual examina o valor da variável favored_thread, que é usada para resolver esses conflitos (linha 19). Se o thread T₁ for o thread favorecido, ele pulará o corpo do if e executará repetidamente o teste while, esperando que T₂ coloque flag2 em false, o que, como veremos, ele eventualmente deverá fazer. Se T₁ determinar que T₂ é o thread favorecido (linha 19), T₁ será forçado a entrar no corpo do comando if, onde colocará flag1 em false (linha 21), e executará o laço dentro do while seguinte enquanto T₂ continuar como thread favorecido (linha 22). Colocando flag1 em false, T₁ permite que T₂ entre em sua própria seção crítica.

Eventualmente, T₂ sai de sua seção crítica e executa seu código de saída da exclusão mútua (linhas 60-61). Esses comandos colocam favored_thread de volta em T₁ e colocam flag2 em false. Agora T₁ pode passar o teste while interno (linha 22) e colocar flag1 em true (linha 23). Então T₁ executa o teste while mais externo (linha 17). Se flag2 (que foi recentemente colocado em false) ainda estiver false, T₁ entrará na sua seção crítica (linha 28) e seu acesso exclusivo ficará garantido. Entretanto, se T₂ tiver tentado rapidamente entrar mais uma vez na sua própria seção crítica, flag2 será colocado em true e T₁ mais uma vez será forçado novamente para o interior do corpo do while mais externo (linha 19).

Porém, dessa vez, T₁ é o thread favorecido. Portanto, T₁ pula o corpo do if e executa repetidamente o teste while mais externo (linha 17) até que T₂ coloque flag2 em false, permitindo que T₁ entre em sua seção crítica.

O Algoritmo de Dekker garante exclusão mútua, impedindo, ao mesmo tempo, deadlock e adiamento indefinido. Contudo, a prova dessa declaração não é imediatamente evidente devido à natureza complexa da exclusão mútua. Por exemplo, considere a seguinte possibilidade interessante. Quando T₁ sai do laço interno da espera ociosa (linha 22), o sistema pode tornar T₁ preemptivo (retirando a CPU de T₁ e designando-a para outro thread) antes de colocar flag1 em true, o que permitiria que T₂ ficasse executando o laço na tentativa de entrar novamente em sua própria seção crítica. Então T₂ colocaria flag2 em true e entraria novamente em sua seção crítica. Quando T₁ eventualmente retornar a execução, colocará flag1 em true. Como a vez é de T₁ (e porque flag1 agora está colocado em true), se T₂ tentar entrar novamente (linha 47), deverá colocar flag2 em false e entrar em sua espera ociosa interna (linha 52). Agora T₁ poderá entrar em sua seção crítica. Essa circunstância, que a princípio poderia parecer complicada, não resulta em adiamento indefinido. Uma prova rigorosa de que o algoritmo nunca resulta em adiamento indefinido é uma tarefa mais complicada (veja no site deste livro: "Curiosidades, Por que você deveria acreditar que seu software está funcionando corretamente?"), que o leitor pode consultar na literatura disponível.¹⁶
