//
// Created by eray on 10/23/17.
//

#ifndef BASICLISTACTIONS_LIST_H
#define BASICLISTACTIONS_LIST_H

#include <stdio.h>
#include <malloc.h>
#include <math.h>

struct Node {
    int multiple;
    int base;
    int power;
    struct Node* next;
};

typedef struct Node Node;

Node* start;
Node* end;

int populateList(char* data);

void writeList();

void mergeList();

int getTotal();

void search(int query);

#endif //BASICLISTACTIONS_LIST_H
