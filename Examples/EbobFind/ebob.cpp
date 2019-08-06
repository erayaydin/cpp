#include <stdio.h>

int main() {
    int sayi1;
    int sayi2;
    printf("Sayı1: ");
    scanf("%d", &sayi1);
    printf("Sayı2: ");
    scanf("%d", &sayi2);

    int start;
    if(sayi1>sayi2){
        start=sayi1;
    } else {
        start=sayi2;
    }

    int found=0;
    for(int i=start; i>=2; i--){
        if(sayi1%i==0 && sayi2%i==0){
            found=i;
            break;
        }
    }

    printf("Sonuç: %d", found);
}
