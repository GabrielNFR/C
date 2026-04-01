#include <stdio.h>

double calcSum(double M[][12], int line);
double calcAvg(double M[][12], int line);
 
int main() {
 
    double M[12][12];
    int line;
    char calc;
    
    scanf("%d", &line);
    scanf(" %c", &calc);

    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            scanf("%lf", &M[i][j]);
        }
    }
    
    if (calc == 'S')
    {
        double result = calcSum(M, line);
        printf("%.1lf\n", result);
    }
    else if (calc == 'M')
    {
        double result = calcAvg(M, line);
        printf("%.1lf\n", result);
    }
    else
    {
        printf("Invalid Character");
    }
    
    return 0;
}

double calcSum(double M[][12], int line)
{
    double sum = 0;
    
    for (int j = 0; j < 12; j++)
    {
        sum += M[line][j];
    }
    
    return sum;
}

double calcAvg(double M[][12], int line)
{
 double avg = 0;
 
 for (int j = 0; j < 12; j++)
    {
        avg += M[line][j] / 12;
    }
    
    return avg;
}