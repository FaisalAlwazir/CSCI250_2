//
// Created by Pyromaniac on 10/16/2020.
//

#ifndef CSCI250_2_EMPLOYEE_H
#define CSCI250_2_EMPLOYEE_H
typedef enum status {working, retired} status;
typedef struct Employee {
    char name[50];
    int id;
    int age;
    float salary;
    status Status;
}Employee;

/// method to get status

Employee new_employee();
void print_employee(Employee emp);
#endif //CSCI250_2_EMPLOYEE_H