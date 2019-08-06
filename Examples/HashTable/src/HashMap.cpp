#include "HashMap.h"

HashMap::HashMap(unsigned long &total) {
    this->total = total;
    hashTable = new Employee*[total];
    for(int i=0; i < total; i++)
        hashTable[i] = nullptr;
}

Employee* HashMap::get(int key) {
    return hashTable[key];
}

void HashMap::print() {
    for(int i=0; i<total; i++) {
        cout << i << ")" << endl;
        Employee* employee = hashTable[i];
        if(employee != nullptr){
            cout << "\t" << employee->getNumber() << endl;

            Employee* next = employee->getNext();
            while(next != nullptr){
                cout << "\t" << next->getNumber() << endl;
                next = next->getNext();
            }
        }
    }
}

bool HashMap::remove(int number) {
    unsigned long index = number % this->total;
    Employee* employee = hashTable[index];
    if(employee != nullptr){
        if(employee->getNumber() == number){
            Employee* temp = employee->getNext();
            hashTable[index] = temp;
            delete employee;
            return true;
        } else {
            Employee* prev = employee;
            employee = employee->getNext();
            while(employee != nullptr){
                if(employee->getNumber() == number){
                    Employee* temp = employee->getNext();
                    prev->setNext(temp);
                    delete employee;
                    return true;
                }

                prev     = employee;
                employee = employee->getNext();
            }
        }
    }
    return false;
}

Employee* HashMap::search(int index, int number) {
    Employee* employee = hashTable[index];
    int totalStep = 0;
    if(employee != nullptr) {
        while(employee != nullptr){
            totalStep++;
            cout << "[HashMap] Search Step: " << endl;
            cout << "\t" << "Number: " << employee->getNumber() << " Name: " << employee->getName() << " Surname: " << employee->getSurname() << endl;
            if(employee->getNumber() == number)
                break;
            employee = employee->getNext();
        }
        cout << "[HashMap] Search Total Step: " << totalStep << endl;
        return employee;
    } else {
        return nullptr;
    }
}

unsigned int HashMap::getSearchStep(int index, int number) {
    Employee* employee = hashTable[index];
    unsigned int totalStep = 0;
    if(employee != NULL) {
        while(employee != NULL){
            totalStep++;
            if(employee->getNumber() == number)
                break;
            employee = employee->getNext();
        }
        return totalStep;
    } else {
        return 0;
    }
}

float HashMap::average() {
    unsigned int total = 0;
    for(int i=0; i < this->total; i++){
        Employee* employee = hashTable[i];
        if(employee != NULL){
            int hashIndex = employee->getNumber() % this->total;
            int step = this->getSearchStep(hashIndex, employee->getNumber());
            total += step;

            Employee* next = employee->getNext();
            while(next != NULL){
                step = this->getSearchStep(hashIndex, next->getNumber());
                total += step;
                next = next->getNext();
            }
        }
    }
    return (float) total / (float) this->total;
}

void HashMap::put(unsigned long key, Employee* employee) {
    if(hashTable[key] == nullptr) {
        hashTable[key] = employee;
    } else {
        Employee *targetEmployee = hashTable[key];
        if(targetEmployee->getNumber() > employee->getNumber()){
            employee->setNext(targetEmployee);
            hashTable[key] = employee;
        } else {
            while(targetEmployee != NULL){
                if(targetEmployee->getNext() != NULL){
                    if(targetEmployee->getNext()->getNumber() > employee->getNumber()){
                        break;
                    } else {
                        targetEmployee = targetEmployee->getNext();
                    }
                } else {
                    break;
                }
            }
            Employee *other = targetEmployee->getNext();
            employee->setNext(other);
            targetEmployee->setNext(employee);
        }
    }
    totalData++;
}

HashMap::~HashMap() {
    for(int i=0; i < this->total; i++) {
        if (hashTable[i] != nullptr) {
            Employee *prevEmployee = nullptr;
            Employee *employee = hashTable[i];
            while (employee != nullptr) {
                prevEmployee = employee;
                employee = employee->getNext();
                delete prevEmployee;
            }
        }
    }

    delete[] hashTable;
}