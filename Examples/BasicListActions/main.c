#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "menu.h"
#include "types.h"
#include "list.h"

/**
 * Main function
 *
 * Description:
 * - Short Action List
 *   - Do Action
 *
 * @author Eray Aydın <eray@labkod.com>
 * @return Program's execute status
 */
int main() {

    int pop = populateList("data.txt");
    if(!pop) {
        printf("Data file not exists or not readable. Check data.txt");
        return -1;
    }

    // Is user want to exit? (Default: no)
    usint isExit = 0;

    while(!isExit){ // If user not want to exit, then show the menu again...

        // Show the menu and get the choice of user
        int total, query;
        int answer = menu("ACTION", "-", 1, 3, 5, "Write Current List", "Merge", "Search in List", "Get Total", "Exit");
        switch(answer) {
            case 1:
                writeList();
                break;

            case 2:
                mergeList();
                break;

            case 3:

                printf("Search: ");
                scanf("%d", &query);
                search(query);
                printf("Redirecting to actions menu in 3 seconds...\n");
                sleep(3);
                break;

            case 4:
                total = getTotal();
                printf("Total: %d\n", total);
                printf("Redirecting to actions menu in 3 seconds...\n");
                sleep(3);
                break;
            default:
                isExit = 1;
                break;
        }
    }

    // User decided to exit.
    return 0;
}