#include <stdio.h>

void printArray(int array[], int total){
    int x;
    printf("= ARRAY =\n");
    for(x=0;x<total;x++) {
        printf("%d) %d\n", x+1, array[x]);
    }
}

void merge(int array[], int left, int middle, int right)
{
    printf("[MERGE] Left: %d\tMiddle: %d\tRight: %d\n", left, middle, right);
    int x, y, z;
    int array1 = middle - left + 1;
    printf("[MERGE] Left Array Length: %d\n", array1);
    int array2 = right - middle;
    printf("[MERGE] Right Array Length: %d\n", array2);

    int leftArray[array1], rightArray[array2];

    for(x=0; x < array1; x++) {
        printf("[MERGE] Add %d to leftArray's %d. element\n", array[left+x], x);
        leftArray[x] = array[left + x];
    }
    for(y=0; y < array2; y++) {
        printf("[MERGE] Add %d to rightArray's %d. element\n", array[middle+1+y], y);
        rightArray[y] = array[middle + 1 + y];
    }

    x=0;
    y=0;
    z=left;
    while(x < array1 && y < array2) {
        printf("[MERGE] %d < leftArray's length and %d < rightArray's length\n", x, y);
        if(leftArray[x] <= rightArray[y]){
            printf("[MERGE] %d <= %d\n", leftArray[x], rightArray[y]);
            array[z] = leftArray[x];
            printf("[MERGE] set %d. element of array is %d\n", z, leftArray[x]);
            x++;
        } else {
            printf("[MERGE] %d > %d\n", leftArray[x], rightArray[y]);
            array[z] = rightArray[y];
            printf("[MERGE] set %d. element of array is %d\n", z, rightArray[y]);
            y++;
        }
        z++;
        printf("[MERGE] now testing x=%d\ty=%d\n",x,y);
    }

    printf("[MERGE] Testing;  %d < leftArray's length\n", x);
    while(x < array1) {
        printf("[MERGE] SET %d. element of array is %d\n", z, leftArray[x]);
        array[z] = leftArray[x];
        x++;
        z++;
        printf("[MERGE] Testing;  %d < leftArray's length\n", x);
    }

    printf("[MERGE] Testing;  %d < rightArray's length\n", y);
    while(y < array2) {
        printf("[MERGE] SET %d. element of array is %d\n", z, rightArray[y]);
        array[z] = rightArray[y];
        y++;
        z++;
        printf("[MERGE] Testing;  %d < rightArray's length\n", y);
    }
}

void mergeSort(int array[], int left, int right)
{
    printf("[MERGESORT] Left: %d\tRight: %d\n", left, right);
    if(left < right) {
        printf("[MERGESORT] left(%d) < right(%d)\n", left, right);
        int middle = left + (right - left) / 2;
        printf("[MERGESORT] Middle: %d\n", middle);

        printf("[MERGESORT] Go and merge sort left: %d\tright(middle): %d\n", left, middle);
        mergeSort(array, left, middle);
        printf("[MERGESORT] Go and merge sort left: %d\tright: %d\n", middle+1, right);
        mergeSort(array, middle+1, right);

        printf("[MERGESORT] MERGE --> Left: %d\tMiddle: %d\tRight: %d\n", left, middle, right);
        merge(array, left, middle, right);
    }
}

int main()
{
    int total;
    printf("Total Elements: ");
    scanf("%d", &total);

    int array[total], x;
    for(x=0;x<total;x++) {
        printf("%d. Element: ", x+1);
        scanf("%d", &array[x]);
    }

    printArray(array, total);

    mergeSort(array, 0, total-1);

    printArray(array, total);
    return 0;
}