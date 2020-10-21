#ifndef CSCI250_2_CONTROL_H
#define CSCI250_2_CONTROL_H
#include "employee.h"
enum options {op_after_tax,op_after_deduction, op_annual, op_ret, op_all_emp, escape };
void testing();

int mainMenu();
void clear_screen();
void start_menu();
int main_options();

#endif //CSCI250_2_CONTROL_H
