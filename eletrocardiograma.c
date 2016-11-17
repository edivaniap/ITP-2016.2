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

/* lembre que você não pode acessar o vetor de medições nem o seu TAMANHO.
   O único acesso às medições é através da chamada da função leitura()*/

int main() {
    int batidas = 0;

    int ant1 = leitura(); //obtem o 1o valor do vetor
    int ant2 = leitura(); //obtem o 2o valor do vetor
    int atual = leitura(); //obtem o 3o valor do vetor

    while(atual != -1){ //condição para o for continuar rodando (até o vetor ser lido completamente)
        if(ant2 >= ant1){
            if(ant2 > atual){
                batidas++;
            }
        } else {
            if(ant2 <= atual){
                batidas++;
            }
        } //verificação se é pico ou vale e a partir disso somar mais uma batida

        ant1 = ant2;
        ant2 = atual;
        atual = leitura(); //permutar valores e ler o proximo
    }

    printf("Batidas: %i\n", batidas);
    return 0;
}

/* Verifcar em um array quantas batidas de coração existem.
Uma batida é um "pico" ou um "vale", acima ou abaixo do gráfico.
Um pico (acima) tem os valores vizinhos menores
Um vale (abaixo) tem os valores vizinhos maiores
Exemplo: [1,2,3,444,33,22,50,100, 200, 1] => picos: 444, 22, 200; resposta: 3

Qual a complexidade do seu algorítmo no pior caso? Ou seja, quantas vezes seu programa executa ações, relativo ao tamanho N do vetor de medições?
Quantas leituras serão realizadas para um número N de medições? Uma leitura é um acesso à uma posição do vetor.

Se as leituras só puderem ser acessadas sequencialmente e não em qualquer ordem, como você resolveria esse problema? (altere seu código para refletir essa realidade)
Para enteder o que é um acesso sequencial, considere que você não pode acessar diretamente o vetor de medições, porém terá disponível uma função que retorna a próxima medição.
*/
