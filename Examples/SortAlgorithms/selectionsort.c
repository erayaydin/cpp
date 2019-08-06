#include <stdio.h>

int main()
{
    int total, array[100], x, y, minimum;

    printf("Total: ");
    scanf("%d", &total);

    for(x=0; x<total; x++){
        printf("%d. Element: ", x+1);
        scanf("%d", &array[x]);
    }

    for(x=0; x<total; x++)
    {
        minimum = x;
        for(y=x; y<total; y++) {
            if(array[minimum]>array[y]){
                minimum = y;
            }
        }
        int temp = array[x];
        array[x] = array[minimum];
        array[minimum] = temp;
    }

    printf("RESULT\n");
    for(x=0;x<total;x++){
        printf("%d\n", array[x]);
    }
}