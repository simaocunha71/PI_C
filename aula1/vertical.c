#include <stdio.h>
// Triangulos vertical

/*
#
##
###
####
#####
####
###
##
#
*/

void print_f_half(int x)
{
    int i, j;
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < x; j++)
        {
            if (j <= i)
                printf("#");
        }
        printf("\n");
    }
}

void print_s_half(int x)
{
    int i, j;
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < x; j++)
        {
            if (j > i)
                printf("#");
        }
        printf("\n");
    }
}

void triangulo(int x)
{
    print_f_half(x);
    print_s_half(x);
}
