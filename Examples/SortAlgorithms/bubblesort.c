#include <stdio.h>

int main()
{
    int array[100], total, x, y, temp;

    printf("Enter total number of elements in array: ");
    scanf("%d", &total);

    for(x=0; x<total; x++){
        printf("%d. Element: ", x+1);
        scanf("%d", &array[x]);
    }

    for(x=0; x < (total- 1); x++) {
        printf("x = %d\n", x);
        for(y=0; y < total - x - 1; y++) {
            printf("y = %d\n", y);
            printf("%d vs %d\n", array[y], array[y+1]);
            if(array[y] > array[y + 1]) {
                printf("changing...\n");
                temp = array[y];
                array[y] = array[y+1];
                array[y+1] = temp;
            }
        }
    }

    printf("Result\n");
    for(x=0; x<total; x++) {
        printf("%d\n", array[x]);
    }

    return 0;
}