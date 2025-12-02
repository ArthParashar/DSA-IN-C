//3.3
#include <stdio.h>

int main() 
{
    int deg1, deg2, maxDeg;
    printf("Enter degree of first polynomial: ");
    scanf("%d", &deg1);
    int poly1[deg1 + 1];
    printf("Enter coefficients of Polynomial-1 from lowest to highest degree: ");
    for (int i = 0; i <= deg1; i++) 
    {
        scanf("%d", &poly1[i]);
    }
    printf("Enter degree of second polynomial: ");
    scanf("%d", &deg2);
    int poly2[deg2 + 1];
    printf("Enter coefficients of Polynomial-2 from lowest to highest degree: ");
    for (int i = 0; i <= deg2; i++) 
    {
        scanf("%d", &poly2[i]);
    }
    maxDeg = (deg1 > deg2) ? deg1 : deg2;
    int result[maxDeg + 1];
    for (int i = 0; i <= maxDeg; i++) 
    {
        result[i] = 0;
    }
    for (int i = 0; i <= deg1; i++) 
    {
        result[i] += poly1[i];
    }
    for (int i = 0; i <= deg2; i++) 
    {
        result[i] += poly2[i];
    }
    printf("Resultant Polynomial: ");
    for (int i = maxDeg; i >= 0; i--) 
    {
        if (result[i] != 0) 
        {
            printf("%dx^%d", result[i], i);
            if (i != 0) 
            {
                printf("+");
            }
        }
    }
    printf("\n");
    return 0;
}