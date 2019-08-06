//
// Created by eray on 10/23/17.
//

#include "list.h"

Node* start = NULL;

int populateList(char* data){
    int multiple, base, power;
    FILE* file;
    file = fopen(data, "r");

    if(file == NULL)
        return 0;

    char line[7]; // x x x\n --> 5 + 2(\n) = 7 bytes

    while(fgets(line, sizeof(line), file) != NULL){
        sscanf(line, "%d %d %d", &multiple, &base, &power);

        Node* node     = (Node*)malloc(sizeof(Node));
        node->multiple = multiple;
        node->base     = base;
        node->power    = power;
        node->next     = NULL;

        if (start == NULL){
            start = node;
        } else if(node->base < start->base || (node->base == start->base && node->power < start->power)) {
            node->next = start;
            start      = node;
        } else {
            Node* iter = start;
            while(iter != NULL){
                if(iter->next->base > node->base || (iter->next->base == node->base && iter->next->power >= node->power)) {
                    break;
                }
                iter = iter->next;
            }
            node->next = iter->next;
            iter->next = node;
        }
    }

    return 1;
}

void writeList(){
    Node* iter = start;
    while(iter != NULL) {
        printf("%dx%d^%d\n", iter->multiple, iter->base, iter->power);
        iter = iter->next;
    }
}

void mergeList(){
    Node* iter = start;
    while(iter != NULL) {
        Node* iter2 = iter->next;

        int newMultiple = iter->multiple;
        while(iter2 != NULL && iter2->base == iter->base && iter2->power == iter->power) {
            newMultiple += iter2->multiple;
            iter2 = iter2->next;
        }

        if(newMultiple != iter->multiple) {
            iter->multiple = newMultiple;
            iter->next = iter2;
        }

        iter = iter->next;
    }
}

int getTotal(){
    int total = 0;
    Node* iter = start;
    while (iter != NULL) {
        total += iter->multiple * pow(iter->base, iter->power);
        iter = iter->next;
    }

    return total;
}

void search(int query){
    Node* iter = start;
    while(iter != NULL) {
        double calculate = iter->multiple * pow(iter->base, iter->power);

        if (calculate == query) {
            printf("[ > ] %dx%d^%d\n", iter->multiple, iter->base, iter->power);
        }

        iter = iter->next;
    }
}