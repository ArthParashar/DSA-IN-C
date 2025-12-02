//1.3
#include <stdio.h>
struct Employee 
{
    int emp_id;
    char name[50];
    char designation[50];
    float basic_salary;
    float hra_percent;
    float da_percent;
};
int main() 
{
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);
    struct Employee emp[n];
    for (int i = 0; i < n; i++) 
    {
        printf("\nEnter details for Employee %d:\n", i + 1);
        printf("Employee ID: ");
        scanf("%d", &emp[i].emp_id);
        printf("Name: ");
        scanf(" %[^\n]", emp[i].name);
        printf("Designation: ");
        scanf(" %[^\n]", emp[i].designation);
        printf("Basic Salary: ");
        scanf("%f", &emp[i].basic_salary);
        printf("HRA %%: ");
        scanf("%f", &emp[i].hra_percent);
        printf("DA %%: ");
        scanf("%f", &emp[i].da_percent);
    }
    printf("\nEmployee Details with Gross Salary:\n");
    printf("-----------------------------------------------------------\n");
    printf("ID\tName\t\tDesignation\tGross Salary\n");
    printf("-----------------------------------------------------------\n");
    for (int i = 0; i < n; i++) 
    {
        float hra = (emp[i].hra_percent / 100.0) * emp[i].basic_salary;
        float da = (emp[i].da_percent / 100.0) * emp[i].basic_salary;
        float gross_salary = emp[i].basic_salary + hra + da;
        printf("%d\t%-15s%-15s%.2f\n", emp[i].emp_id, emp[i].name, emp[i].designation, gross_salary);
    }
    return 0;
}