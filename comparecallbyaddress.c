//1.1
#include<stdio.h>
int compare(int *x, int *y)
{
    if(*x>*y)
      printf("%d is greater than %d ", *x,*y );
    else if(*x<*y)
      printf("%d is greater than %d", *y,*x);
    else
      printf("Both numbers are same"); 
}
int main()
{
    int n1,n2;
    printf("enter two numbers");
    scanf("%d %d", &n1,&n2);
    compare(&n1,&n2);
    return 0;    
}