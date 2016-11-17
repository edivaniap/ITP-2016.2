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

/** problema das grutas resolvido com flood fill */

#include <stdio.h>
#define LIN 10
#define COL 10

/*char mat[LIN][COL] =
        {
            {1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 0, 0, 1, 0, 1, 1, 1},
            {1, 1, 0, 0, 0, 0, 1, 0, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 0, 0, 1, 1, 1, 0, 0, 1},
            {1, 0, 0, 0, 0, 1, 1, 0, 0, 1},
            {1, 0, 1, 0, 1, 1, 1, 1, 1, 1},
            {0, 0, 0, 0, 1, 0, 0, 1, 1, 0},
            {1, 1, 1, 0, 0, 1, 1, 1, 0, 0},
        }; */

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

/** o flood fill vai fazer o "reboco" nos buracos para que eles n㯠sejam contados novamente. */
void floodFill(int x, int y, int reboco, int buraco) {
  if(x >= 0 && x < LIN && y >= 0 && y < COL && mat[x][y] == buraco)
  {
    mat[x][y] = reboco; //reboca antes de come硲 recuss㯍

    floodFill(x + 1, y    , reboco, buraco);
    floodFill(x - 1, y    , reboco, buraco);
    floodFill(x    , y + 1, reboco, buraco);
    floodFill(x    , y - 1, reboco, buraco);
  }
}

int main(){
    char grutas = 0;
    int i, j;

    printf("\tCaverna:\n");
    /* imprime matriz (caverna) */
    for(i = 0; i < LIN; i++){
        for(j = 0; j < COL; j++){
            printf("%i  ", mat[i][j]);
        }
        printf("\n");
    }

    /* chamadas de floodfill */
    for(i = 0; i < LIN; i++){
        for(j = 0; j < COL; j++){
            if(mat[i][j] == 0){
                floodFill(i, j, grutas+2, 0);
                grutas++;
            }
        }
    }

    printf("\n");
    printf("  Caverna depois do reboco:\n");
    /* imprime matriz (caverna) ap󳠦lood fill */
    for(i = 0; i < LIN; i++){
        for(j = 0; j < COL; j++){
            printf("%i  ", mat[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    printf("Grutas: %i\n", grutas);

    system("pause");

    return 0;
}
