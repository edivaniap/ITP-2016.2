/* Escreva um programa em C que gere a série de Fibonacci até o vigésimo termo.
   Utilize apenas a estrutura de repetição do-while */
#include <stdio.h>

int main(void) {
	int contador = 3;
	int fibonacci;
	int anterior1 = 0;
    	int anterior2 = 1;

    printf("1°: %i \n", anterior1); //primeiro numero
    printf("2°: %i \n", anterior2); //segundo numero

	do {
		fibonacci = anterior1 + anterior2;
		anterior1 = anterior2;
		anterior2 = fibonacci;
		printf("%i°: %i \n", contador, fibonacci);
		contador++;
	} while(contador <= 20);

	return 1;
}
