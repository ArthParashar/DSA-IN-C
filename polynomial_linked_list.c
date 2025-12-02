//4.3
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;   
    int pow;     
    struct Node *next;
};

struct Node* createNode(int coeff, int pow) 
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}
void insertNode(struct Node **head, int coeff, int pow) 
{
    struct Node *newNode = createNode(coeff, pow);
    if (*head == NULL) 
    {
        *head = newNode;
    } 
    else 
    {
        struct Node *temp = *head;
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display(struct Node *poly) 
{
    if (poly == NULL) 
    {
        printf("0");
        return;
    }
    while (poly != NULL) 
    {
        printf("%d", poly->coeff);
        if (poly->pow != 0) 
        {
            printf("x^%d", poly->pow);
        }
        if (poly->next != NULL && poly->next->coeff >= 0)
            printf(" + ");
        poly = poly->next;
    }
    printf("\n");
}

struct Node* addPolynomials(struct Node *poly1, struct Node *poly2) 
{
    struct Node *result = NULL;
    struct Node *p1 = poly1, *p2 = poly2;

    while (p1 != NULL && p2 != NULL) 
    {
        if (p1->pow == p2->pow) 
        {
            insertNode(&result, p1->coeff + p2->coeff, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->pow > p2->pow) 
        {
            insertNode(&result, p1->coeff, p1->pow);
            p1 = p1->next;
        } 
        else 
        {
            insertNode(&result, p2->coeff, p2->pow);
            p2 = p2->next;
        }
    }

    while (p1 != NULL) 
    {
        insertNode(&result, p1->coeff, p1->pow);
        p1 = p1->next;
    }
    while (p2 != NULL) 
    {
        insertNode(&result, p2->coeff, p2->pow);
        p2 = p2->next;
    }

    return result;
}

int main() 
{
    struct Node *poly1 = NULL, *poly2 = NULL, *sum = NULL;
    int deg, coeff, i;
    printf("Polynomial-1:\n");
    printf("Enter the Maximum power of x: ");
    scanf("%d", &deg);
    for (i = deg; i >= 0; i--) 
    {
        printf("Enter the coefficient of degree %d: ", i);
        scanf("%d", &coeff);
        insertNode(&poly1, coeff, i);
    }
    printf("\nPolynomial-2:\n");
    printf("Enter the Maximum power of x: ");
    scanf("%d", &deg);
    for (i = deg; i >= 0; i--) 
    {
        printf("Enter the coefficient of degree %d: ", i);
        scanf("%d", &coeff);
        insertNode(&poly2, coeff, i);
    }
    printf("\nPolynomial 1: ");
    display(poly1);
    printf("Polynomial 2: ");
    display(poly2);
    sum = addPolynomials(poly1, poly2);
    printf("\nSum of Polynomials: ");
    display(sum);

    return 0;
}
