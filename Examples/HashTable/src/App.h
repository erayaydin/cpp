#ifndef MOODLEODEV_APP_H
#define MOODLEODEV_APP_H

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include "Employee.h"
#include "HashMap.h"

using namespace std;

class App {
    HashMap* hashMap;
    string dataFile;
    unsigned long getHash(int value, unsigned long total);
    vector<string> explode(string const &value, char delimeter);
    void error(string const &text);
    bool loadData();

    void clearScreen();
    char showMenu();
public:
    App();
    App(string dataFile);
    void setDataFile(string dataFile);
    string getDataFile();
    int run();
};

#endif //MOODLEODEV_APP_H