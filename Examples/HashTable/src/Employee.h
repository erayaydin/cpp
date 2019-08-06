#ifndef MOODLEODEV_EMPLOYEE_H
#define MOODLEODEV_EMPLOYEE_H

#include <iostream>

using namespace std;

class Employee {
private:
    int number;
    string name;
    string surname;
    Employee *next = NULL;
public:
    Employee(int number, string name, string surname);
    void setNext(Employee *employee);
    Employee* getNext();
    int getNumber();
    string getName();
    string getSurname();
};


#endif //MOODLEODEV_EMPLOYEE_H