#include <stdio.h>
#include "control.h"
#include "employee.h"
int main() {
    clear_screen();

    printf("Welcome!\nPlease enter the number of employees you want to create: ");
    int number =2;
    mainMenu();
    scanf("%d", &number);
    Employee employees[10];
    for (int i = 0; i <= number ; i++){
        clear_screen();
        printf("Employee numer %d\n", i+1);
        employees[i] = new_employee();
        employees[i].id = i+1;
        print_employee(employees[i]);
    }


    return 0;
}
