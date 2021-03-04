#include <stdio.h>
// Triangulos horizontais

/*  j
____|____
    #     |
   ###    |
  #####   |i
 #######  |
######### |
*/

void triangulo (int x)
{
    int i, j;
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < 2*x -1; j++)
        {

            if (j-i+1 > x || j+i+1 < x)
                printf(" ");
            else 
                printf("#");
                
        }
    printf("\n");
    }
}