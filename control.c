//
// Created by Pyromaniac on 10/16/2020.
//
#include <stdlib.h>
#include <stdio.h>
#include "control.h"
#include <string.h>

void clear_screen() {
    system("cls");
}

const char* get_option_text(enum options option) {
    char text[100];
    sprintf(text, "%d - ", option);
    switch (option) {

        case escape:
            strcat(text, "Exit.");
        case print_all:
            strcat(text, "Print all employees.");
        default:
            return text;
    }

}

void mainMenu() {
    printf("Welcome to the employee managment system"
           "Please chose one of the following");
//    iterates over all the options
    for (int i = print_all; i > escape; i++) {

    }

}
//Employee make(){
//    Employee  emp;
//    return &emp;
//}

