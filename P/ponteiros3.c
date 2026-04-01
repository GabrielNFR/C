#include <stdio.h>

void transpor3x3(int *m)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            int temp = *(m + i * 3 + j);
            *(m + i * 3 + j) = *(m + j * 3 + i);
            *(m + j * 3 + i) = temp;
        }
    }
}

int main(void)
{
    int m[3][3];
    int *p = &m[0][0];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", p + (i * 3 + j));
        }
    }

    transpor3x3(*m);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d", *(p + (i * 3 + j)));
        }
        printf("\n");
    }

    return 0;
}