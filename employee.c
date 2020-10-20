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
void print_employee_deduction(Employee emp){
    printf("ID %d | ", emp.id);
    printf("Name: %s ", emp.name);
    printf("salary before deduction: $%f ", emp.salary);
    printf("salary after deduction: $%f ", emp.salary- emp.deduction);
    printf("salary after tax reduction: $%f ", emp.salary_after_tax);
    if(emp.Status == working){
        printf("status: working.\n");
    } else {
        printf(" status: retired.\n");
    }
}
Employee *get_by_id(int number, int id, Employee *employees){
    Employee *employees_cpy = employees;
    for (int i = 0; i < number; i++){
        if (employees->id == id){
            return employees;
        }
        employees ++;
    }
    printf("Wrong id..\nTry again\n ");
    return get_by_id(number, id, employees_cpy);
}