/**
 * Project: Moodle Hash Table Example
 * Author: Eray AYDIN
 * Github: https://github.com/erayaydin
 * Blog: https://erayaydin.github.io
 */

#include <iostream>
#include "App.h"

/**
 * Check file exists in filepath.
 *
 * @param filepath search in path
 * @return is exists?
 */
bool checkFileExists(string filepath) {
    ifstream infile(filepath);

    return infile.good();
}

/**
 * get data file path from console or file.
 *
 * @return data file path
 */
string getDataFile() {

    ifstream infile("path.dat");
    if(infile.good()){
        string line;
        getline(infile, line);

        if(!checkFileExists(line)){
            remove("path.dat");
            return getDataFile();
        }
        return line;
    } else {
        string dataFile;
        bool exists = false;
        while(!exists){
            cout << "Data File: ";
            cin >> dataFile;

            exists = checkFileExists(dataFile);
        }

        ofstream outfile("path.dat");
        outfile << dataFile;
        outfile.close();
        cout << "path.dat file created!" << endl;

        return dataFile;
    }
}

int main() {

    // Get data file path
    string dataFile = getDataFile();

    // Initialize app with data file path.
    auto *app = new App(dataFile);
    return app->run();
}