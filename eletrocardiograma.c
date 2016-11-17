#include <stdio.h>

#define TAMANHO 10

//int medicoes[TAMANHO] = {10, 15, 20, 15, 10, 15, 20, 15, 10, 15};

int medicoes[TAMANHO] = {1,2,3,444,33,22,50,50, 200, 1};
int posicao = 0;

int leitura() {
    if (posicao < TAMANHO){
        return medicoes[posicao++];
    } else {
        return -1;
    }
}

/* lembre que voc� n�o pode acessar o vetor de medi��es nem o seu TAMANHO.
   O �nico acesso �s medi��es � atrav�s da chamada da fun��o leitura()*/

int main() {
    int batidas = 0;

    int ant1 = leitura(); //obtem o 1o valor do vetor
    int ant2 = leitura(); //obtem o 2o valor do vetor
    int atual = leitura(); //obtem o 3o valor do vetor

    while(atual != -1){ //condi��o para o for continuar rodando (at� o vetor ser lido completamente)
        if(ant2 >= ant1){
            if(ant2 > atual){
                batidas++;
            }
        } else {
            if(ant2 <= atual){
                batidas++;
            }
        } //verifica��o se � pico ou vale e a partir disso somar mais uma batida

        ant1 = ant2;
        ant2 = atual;
        atual = leitura(); //permutar valores e ler o proximo
    }

    printf("Batidas: %i\n", batidas);
    return 0;
}

/* Verifcar em um array quantas batidas de cora��o existem.
Uma batida � um "pico" ou um "vale", acima ou abaixo do gr�fico.
Um pico (acima) tem os valores vizinhos menores
Um vale (abaixo) tem os valores vizinhos maiores
Exemplo: [1,2,3,444,33,22,50,100, 200, 1] => picos: 444, 22, 200; resposta: 3

Qual a complexidade do seu algor�tmo no pior caso? Ou seja, quantas vezes seu programa executa a��es, relativo ao tamanho N do vetor de medi��es?
Quantas leituras ser�o realizadas para um n�mero N de medi��es? Uma leitura � um acesso � uma posi��o do vetor.

Se as leituras s� puderem ser acessadas sequencialmente e n�o em qualquer ordem, como voc� resolveria esse problema? (altere seu c�digo para refletir essa realidade)
Para enteder o que � um acesso sequencial, considere que voc� n�o pode acessar diretamente o vetor de medi��es, por�m ter� dispon�vel uma fun��o que retorna a pr�xima medi��o.
*/
