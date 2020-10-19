#include "employee.h"
#include <stdio.h>
#include <string.h>

Employee new_employee(){
    Employee result;

    /// for fgets to work properly
    fflush(stdin);

    printf("Name: ");
    fgets(result.name, 50, stdin);
    /// this removes the linefeed
    result.name[strcspn(result.name,"\n")] = 0;

    printf("Age: ");
    scanf("%d", &result.age);

    printf("Salary: ");
    scanf("%f", &result.salary);

    if (result.age >= 60){
        result.Status = retired;
        result.salary_after_tax = result.salary * .95;
    } else {
        result.Status = working;
        result.salary_after_tax = result.salary * .92;
    }
    return result;

}

void print_employee(Employee emp){
    printf("ID %d | ", emp.id);
    printf("Name: %s ", emp.name);
    printf("age: %d ", emp.age);
    printf("salary: $%f ", emp.salary);
    printf("salary after tax reduction: $%f ", emp.salary_after_tax);
    if(emp.Status == working){
        printf("status: working.\n");
    } else {
        printf(" status: retired.\n");
    }
}