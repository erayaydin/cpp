/**
 * Project: Moodle Hash Table Example
 * Author: Eray AYDIN
 * Github: https://github.com/erayaydin
 * Blog: https://erayaydin.github.io
 */

#include "App.h"

App::App() = default;

/**
 * Initialize App with datafile
 *
 * @param dataFile data file path
 */
App::App(string dataFile) {
    this->setDataFile(dataFile);
}

/**
 * Set data file for initialized app
 *
 * @param dataFile data file path
 */
void App::setDataFile(string dataFile) {
    this->dataFile = dataFile;
}

/**
 * Get data file path from initialized app
 *
 * @return get current data file path in initialized app
 */
string App::getDataFile() {
    return this->dataFile;
}

/**
 * Get hash value for hash table.
 *
 * @param value value of data
 * @param total count of data
 * @return hash index
 */
unsigned long App::getHash(int value, unsigned long total) {
    return value % total;
}

/**
 * Explode string by delimeter.
 *
 * @param value value will be exploded
 * @param delimeter delimeter for explode
 * @return strings with exploded.
 */
vector<string> App::explode(string const &value, char delimeter) {
    vector<string> result;
    istringstream iss(value);

    for(string token; getline(iss, token, delimeter);) {
        result.push_back(move(token));
    }

    return result;
}

/**
 * Show error message in app.
 *
 * @param text error message
 */
void App::error(string const &text) {
    cerr << text << endl;
}

/**
 * Load data from data file.
 *
 * @return
 */
bool App::loadData() {

    ifstream file;
    file.open(this->dataFile);

    // If file can not be opened, show error.
    if(!file) {
        App::error("Unable to open " + this->dataFile);
        return false;
    }

    // Read line...
    string line;
    while(file.good()){
        getline(file, line);
    }

    // Explode line with '#' for get employees
    vector<string> employeesData = this->explode(line, '#');

    // Get total employee
    unsigned long total = employeesData.size();

    // Initialize hashMap with total employee size
    this->hashMap = new HashMap(total);

    // Create employees from data...
    for(string &employeeLine: employeesData){
        // Explode employee meta data from spaces.
        vector<string> employeeData = this->explode(employeeLine, ' ');

        // Get data of employee...
        int    number  = stoi(employeeData[0]); // String(From File Stream) to Int
        string name    = employeeData[1];
        string surname = employeeData[2];

        // Create employee data
        Employee *employee = new Employee(number, name, surname);

        // Get hash index with getHash() method.
        unsigned long hashIndex = this->getHash(number, total);

        // Insert employee to hashMap.
        this->hashMap->put(hashIndex, employee);
    }
}

void App::clearScreen() {
    cout << string( 100, '\n' );
}

char App::showMenu() {
    cout << "==== Hash Map Example ====" << endl;
    cout << "= p) Print Hash Map      =" << endl;
    cout << "= s) Search in Hash Map  =" << endl;
    cout << "= r) Remove an employee  =" << endl;
    cout << "= a) Average search step =" << endl;
    cout << "= e) Exit from app       =" << endl;
    cout << "==========================" << endl;

    cout << "--> Choice: ";
    char option;
    cin >> option;

    return option;
}

/**
 *
 * @return Application return code for system
 */
int App::run() {
    this->loadData();

    bool isClose = false;
    Employee* search = nullptr;
    while(!isClose){

        char selected = this->showMenu();
        switch(selected) {
            case 'p':
                this->hashMap->print();
                break;
            case 's':
                int searchNumber;
                cout << "Search Number: ";
                cin >> searchNumber;

                search = this->hashMap->search(this->getHash(searchNumber, this->hashMap->total), searchNumber);
                if(search == nullptr) {
                    cout << "Not found in hash map :(" << endl;
                }
                break;
            case 'r':
                int removeNumber;
                cout << "Remove Number: ";
                cin >> removeNumber;

                if(this->hashMap->remove(removeNumber)){
                    cout << removeNumber << " successfully deleted!" << endl;
                } else {
                    cout << removeNumber << " not found!" << endl;
                }
                break;
            case 'a':
                cout << "Average Search Step: " << this->hashMap->average() << endl;
                break;
            case 'e':
                isClose = true;
                cout << "Thank you for using application." << endl;
                break;
            default:
                cout << "Please select an option. " << selected << " is not in option list." << endl;
                break;
        }
    }
    return 0;
}