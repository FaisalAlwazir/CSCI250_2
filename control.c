#include <stdlib.h>
#include <stdio.h>
#include "control.h"


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

void show_all(int number, Employee *employees) {
    for (int i = 0; i < number; i++) {
        print_employee(*employees);
        employees++;
    }
}

void show_retired(int number, Employee *employees) {
    for (int i = 0; i < number; i++) {
        if (employees->Status == retired) {
            print_employee(*employees);
        }
        employees++;
    }

}

void show_working(int number, Employee *employees) {
    for (int i = 0; i < number; i++) {
        if (employees->Status != retired) {
            print_employee(*employees);
        }
        employees++;
    }
}

void show_annual(int number, Employee *employees) {
    for (int i = 0; i < number; i++) {
        printf("%s's anual salaray after deduction and tax is %f", employees->name,
               employees->salary_after_tax - employees->deduction);
        employees++;
    }
}

void start_menu() {
    clear_screen();
    printf("\nWelcome!\nPlease enter the number of employees you want to create:\n");
    int number;
    scanf("%d", &number);
    Employee employees[number];


    for (int i = 0; i < number; i++) {
        clear_screen();
        printf("Employee numer %d\n", i + 1);
        employees[i] = new_employee();
        employees[i].id = i + 1;
    }

    const Employee *employees_cpy = &employees[0];
    int flag = 0;
    while (flag == 0) {
        flag = mainMenu(employees_cpy, number);
    }
    clear_screen();
    printf("Bye!");
}

int mainMenu(const Employee *emps, int number) {

        printf("Welcome to the employee management system.\n"
        );

        int c = main_options();
        clear_screen();

        switch (c) {
            case 3:
                show_annual(number, emps);
                break;
            case 4:
                show_retired(number, emps);
                break;
            case 5:
                show_working(number, emps);
                break;
            case 6:
                show_all(number, emps);
                break;
            case 7:
                return 1;

        }
        printf("Press Enter to ontinue");
        int wait;
        scanf("%d", &wait);
        return 0;



}

void testing() {
//  p);
}
