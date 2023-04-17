//N#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "function.h"

int main(int argc, char *argv[]) {
    Patient p1;

    p1 = SetPatient(&p1);
    system("cls");

    PrintPatient(p1);

    return 0;
}