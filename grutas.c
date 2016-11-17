/* 
	Faça um program que encontre buracos em uma caverna 2D.
	Caverna: matriz 10x10
	Rocha: valor 1
	Espaço: valor 0
	Grutas: sequência contínua de espaços (1 ou mais, não diagonais)
	Exemplo:
	Entrada =>
	{ {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	  {1, 1, 0, 0, 1, 1, 0, 1, 1, 1},
	  {1, 1, 0, 0, 1, 1, 1, 0, 1, 1},
	  {1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
	  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	  {1, 1, 0, 0, 1, 1, 1, 1, 1, 1},
	  {1, 1, 0, 0, 0, 1, 1, 1, 1, 1},
	  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	  {1, 1, 1, 1, 1, 0, 0, 1, 1, 1},
	  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1} }
	 Saída => 6 grutas
*/

/** Problema das grutas SEM usar flood fill */
/* com tratamento de bordas */
#include <stdio.h>
#define LIN 10
#define COL 10
#define FALSE 0
#define TRUE 1

char mat[LIN][COL] =
        {
            {1, 1, 1, 0, 1, 1, 1, 1, 1, 0},
            {1, 1, 1, 0, 0, 1, 0, 0, 0, 0},
            {1, 0, 0, 0, 0, 1, 1, 0, 1, 0},
            {0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
            {0, 0, 1, 1, 1, 0, 1, 1, 1, 0},
            {1, 1, 0, 0, 1, 1, 1, 0, 0, 0},
            {1, 1, 0, 0, 0, 1, 1, 0, 0, 0},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {0, 1, 1, 1, 1, 0, 0, 0, 1, 0},
            {0, 0, 1, 1, 1, 0, 1, 1, 0, 0},
        };

int main(){
    char grutas = 0;
    char dentro = FALSE; //vai me dizer se ja estou dentro de uma gruta (caso ja esteja, n㯠a conto)
    char contei = FALSE; //vai me dizer se ja contei tal gruta na linha anterior  (caso ja contei, subtraio 1)
    int i, j;

    /* imprime matriz (caverna) */
    printf("\tCaverna:\n");
    for(i = 0; i < LIN; i++){
        for(j = 0; j < COL; j++){
            printf("%i  ", mat[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    /* m᧩ca aqui */
    for(i = 0; i < LIN; i++){
        for(j = 0; j < COL; j++){
            if(mat[i][j] == 0){
                    if(dentro == FALSE){
                       grutas++;
                       dentro = TRUE;
                    }
                    if(i != 0 && mat[i-1][j] == 0){
                        contei = TRUE;
                    }
                    if(j == COL-1 && contei == TRUE){
                        grutas--;
                    }
            } else if(mat[i][j] == 1 && dentro == TRUE){
                if(contei == TRUE){
                    grutas--;
                }
                dentro = FALSE;
                contei = FALSE;
            }
        }
        dentro = FALSE;
        contei = FALSE;
    }

    printf("Grutas: %i\n", grutas);

    system("pause");

    return 0;
}
