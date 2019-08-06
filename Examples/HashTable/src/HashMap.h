#ifndef MOODLEODEV_HASHMAP_H
#define MOODLEODEV_HASHMAP_H

#include "Employee.h"

class HashMap {
private:
    Employee **hashTable;
    unsigned int totalData;
public:
    HashMap(unsigned long &total);
    Employee* get(int key);
    void put(unsigned long key, Employee* employee);
    Employee* search(int index, int number);
    unsigned int getSearchStep(int index, int number);
    bool remove(int number);
    void print();
    float average();
    ~HashMap();
    unsigned long total;
};


#endif //MOODLEODEV_HASHMAP_H