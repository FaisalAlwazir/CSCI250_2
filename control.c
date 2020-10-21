#include <stdlib.h>
#include <stdio.h>
#include "control.h"
#include <string.h>

int number;
Employee employees[10];

void clear_screen() {
    system("cls");
}

int main_options() {

    printf("Please chose one of the following\n"
           "\n"
           "1 Calculate salary after tax\n"
           "2 Calculate salary after detuction\n"
           "3 Calculate annual salary\n"
           "4 Print retired employee details\n"
           "5 Print working employee details\n"
           "6 Print all employee details\n"
           "7 Exit \n");
    int choice;
    scanf("%d", &choice);
    return choice;


}

void show_all() {
    for (int i = 0; i < number; i++) {
        print_employee(employees[i]);
    }
}

void after_tax() {
    for (int i = 0; i < number; i++) {

    }
}

int choose_emp() {
    printf("\nEnter the name of one of these employees:");
    for (int i = 0; i < number; i++) {
        printf("\n%d - %s\n", employees[i].id, employees[i].name);
    }
    char choice[50];

    fflush(stdin);
    fgets(choice, 50, stdin);

    choice[strcspn(choice, "\n")] = 0;

    clear_screen();
    for (int i = 0; i < number; i++) {
        if (strcmp(employees[i].name, choice) == 0) {
            return i;
        }
    }
    printf("Wrong name! Try again:\n");
    return choose_emp();

}

void show_retired() {
    for (int i = 0; i < number; i++) {
        if (employees[i].Status == retired) {
            print_employee(employees[i]);
        }
    }
}

void show_working() {
    for (int i = 0; i < number; i++) {
        if (employees[i].Status != retired) {
            print_employee(employees[i]);
        }
    }
}

void tax(){
    int emp = choose_emp();
    print_employee(employees[emp]);
}
void deduct() {
    int emp = choose_emp();
    printf("\nEnter amount to deduct off %s's salary \n", employees[emp].name);
    scanf("%f", &employees[emp].deduction);
    if (employees[emp].Status == retired) {
        employees[emp].salary_after_tax = (float) ((employees[emp].salary - employees[emp].deduction) * .95);
    }
    if (employees[emp].Status == working) {
        employees[emp].salary_after_tax = (float) ((employees[emp].salary - employees[emp].deduction) * .92);
    }
    print_employee(employees[emp]);


}

void show_annual() {
    for (int i = 0; i < number; i++) {
        printf("\n%s's anual salaray after deduction and tax is %f\n", employees[i].name,
               employees[i].salary_after_tax - employees[i].deduction);
    }
}

void start_menu() {

    clear_screen();
    printf("\nWelcome!"
           "\nPlease enter the number of employees you want to create:\n");
    scanf("%d", &number);
//    number -=1;

    for (int i = 0; i < number; i++) {
        clear_screen();
        printf("Employee numer %d\n", i + 1);
        employees[i] = new_employee();
        employees[i].id = i + 1;
    }

    int flag = 0;
    while (flag == 0) {
        flag = mainMenu();
    }
    clear_screen();
    printf("Bye!");
}

int mainMenu() {

    printf("Welcome to the employee management system.\n"
    );

    int c = main_options();
    clear_screen();

    switch (c) {
        case 1:
            tax();
            break;
        case 2:
            deduct();
            break;
        case 3:
            show_annual();
            break;
        case 4:
            show_retired();
            break;
        case 5:
            show_working();
            break;
        case 6:
            show_all();

            break;
        case 7:
            return 1;

    }
    printf("Press Enter to continue");
    int wait;
    scanf("%d", &wait);
    return 0;


}

void testing() {
//  p);
}
