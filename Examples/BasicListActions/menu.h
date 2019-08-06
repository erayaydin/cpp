//
// Created by eray on 10/23/17.
//

#ifndef BASICLISTACTIONS_MENU_H
#define BASICLISTACTIONS_MENU_H

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "types.h"

// menu function's prototype
int menu(char* name, char* prefix, usint orientation, usint pad, usint count, ...);

#endif //BASICLISTACTIONS_MENU_H
