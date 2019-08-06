#include "Employee.h"

Employee::Employee(int number, string name, string surname) {
    this->number = number;
    this->name   = name;
    this->surname = surname;
}

void Employee::setNext(Employee *employee) {
    this->next = employee;
}

Employee* Employee::getNext() {
    return this->next;
}

int Employee::getNumber() {
    return this->number;
}

string Employee::getName() {
    return this->name;
}

string Employee::getSurname() {
    return this->surname;
}