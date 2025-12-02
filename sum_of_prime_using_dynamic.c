//1.2
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int isPrime(int num) 
{
    if (num <= 1) 
    return 0;
    if (num == 2) 
    return 1;
    if (num % 2 == 0) 
    return 0;
    for (int i = 3; i <= sqrt(num); i += 2) 
    {
        if (num % i == 0) return 0;
    }
    return 1;
}
int sumOfPrimes(int *arr, int n) 
{
    int sum = 0;
    for (int i = 0; i < n; i++) 
    {
        if (isPrime(arr[i])) 
        {
            sum += arr[i];
        }
    }
    return sum;
}
int main() 
{
    int *arr, n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) 
    {
        printf("Memory allocation failed!\n");
        return 1;
    }
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    int sum = sumOfPrimes(arr, n);
    printf("Sum of prime elements: %d\n", sum);
    free(arr);
    return 0;
}