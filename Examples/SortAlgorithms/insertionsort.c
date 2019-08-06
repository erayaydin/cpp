#include <stdio.h>

int main()
{
    int total, x, y, temp, array[100];

    printf("Total: ");
    scanf("%d", &total);

    for(x=0;x<total;x++) {
        printf("%d. Element: ", x+1);
        scanf("%d", &array[x]);
    }

    for(x=1; x <= total -1; x++) {
        y = x;

        while(y > 0 && array[y] < array[y-1]){
            temp = array[y];
            array[y] = array[y-1];
            array[y-1] = temp;

            y--;
        }
    }

    printf("RESULT\n");

    for(x=0;x<total;x++) {
        printf("%d\n", array[x]);
    }

    return 0;
}