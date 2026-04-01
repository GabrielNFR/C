#include <stdio.h>
 
int main() {
 
    int N[10];
    int num;
    
    scanf("%d", &num);
    
    N[0] = num;
    
    for (int i = 1; i < 10; i++)
    {
        N[i] = N[i - 1] * 2;
        printf("N[%d] == %d\n", i, N[i]);
    }

 
    return 0;
}