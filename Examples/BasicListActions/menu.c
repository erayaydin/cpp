//
// Created by eray on 10/23/17.
//

#include "menu.h"

int menu(
        char* name,        // Menu's name (eg: Choice your math function)
        char* prefix,      // Menu's prefix (eg: [X],[O],[|]
        usint orientation, // Orientation of menu (0=Horizontal, 1=Vertical)
        usint pad,         // Items padding (eg: 3,4,5)
        usint count,       // Number of items
        ...                // Item list (char*)
){
    va_list args;
    usint temp = 1;
    int pos;

    int choice;
    int correct = 1;
    do {
        #ifdef WINDOWS
                system("cls");
        #else
                system("clear");
        #endif
        printf("%s %s:", prefix, name);
        // Build menu...
        va_start(args, count);
        for (temp=1; temp <= count; temp++){
            (orientation) ? printf("\n") : 0;
            pos = pad;
            while ((pos--) > 0)
                printf(" ");
            printf("%d) ", temp);
            printf("%s", va_arg(args, char*));
        }
        va_end(args); // End of argument management

        printf("\nYour Choice: ");
        scanf("%d", &choice);

    } while(choice < 1 || choice > count); // Show menu again if its not 0

    return choice;
}