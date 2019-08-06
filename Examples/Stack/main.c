#include <stdio.h>
#include <malloc.h>

/**
 * Bağlı listenin yapısını tanımlıyoruz
 */
struct Node {
    char character;
    struct Node* next;
} typedef Node;

// Bağlı listenin başlangıç noktasını tutuyoruz
Node* start = NULL;
// Dosya işlemleri için FILE oluşturuyoruz.
FILE* file;

int isExists(char character, Node* iter) {
    int isExists = 0;
    while(iter != NULL){
        if(character == iter->character) {
            isExists = 1;
            break;
        }
        iter = iter->next;
    }
    return isExists;
}

int main() {

    char str[100];
    file = fopen("data.txt", "r");
    if(file) {
        while(fscanf(file, "%s", str) != EOF){

            if(isExists(str[0], start))
                break;

            if(start == NULL){
                printf("bas bos, basa ekleniyor...\n");
                Node* first = (Node*)malloc(sizeof(Node));
                first->character = str[0];
                first->next = NULL;
                start = first;
            } else {
                printf("bas dolu, tum elemanlar kontrol ediliyor...\n");
                Node* iter = start;

                Node* new = (Node*)malloc(sizeof(Node));
                new->character = str[0];
                if((int) iter->character > (int) str[0]){
                    printf("bastaki %c karakteri yeni gelecek %c den kucuk, %c basa ekleniyor...\n", iter->character, str[0], str[0]);
                    new->next = start;
                    start = new;
                }

                while(iter != NULL){
                    if(iter->next != NULL){
                        if((int) iter->next->character > (int) str[0]){
                            printf("onceden eklenmis %c karakteri %c karakterinden buyuk, %c den sonraya ekleniyor...\n", iter->next->character, str[0], iter->character);
                            new->next = iter->next;
                            iter->next = new;
                            break;
                        }
                        if(iter->next == NULL){
                            printf("%c sona ekleniyor. (%c den sonra)\n", str[0], iter->character);
                            new->next = NULL;
                            iter->next = new;
                            break;
                        }
                    } else {
                        printf("%c sona ekleniyor. (%c den sonra)\n", str[0], iter->character);
                        new->next = NULL;
                        iter->next = new;
                        break;
                    }
                    iter = iter->next;
                }
            }
        }
        fclose(file);
    }

    Node* iterr = start;
    while(iterr != NULL){
        printf("%c\n", iterr->character);
        iterr = iterr->next;
    }

    int maxCount = 0;
    char max[100];
    char seq[100];

    Node* iter = start;
    while(iter != NULL){
        Node* check = iter;
        int x = 0;
        while(check != NULL){
            seq[x] = check->character;
            if(check->next != NULL){
                if((int)check->character+1 == (int)check->next->character){
                    x++;
                } else {
                    if(maxCount < x+1){
                        maxCount = x+1;

                        int i;
                        for(i=0; i<=100; i++){
                            max[i] = seq[i];
                        }
                    }
                    break;
                }
            } else {
                if(maxCount < x+1){
                    maxCount = x+1;

                    int i;
                    for(i=0; i<=100; i++){
                        max[i] = seq[i];
                    }
                }
                break;
            }
            check = check->next;
        }
        iter = iter->next;
    }

    printf("%d\n", maxCount);
    int y;
    for(y=0;y<maxCount;y++){
        printf("%c", max[y]);
    }

    return 0;
}