#include <iostream>

using namespace std;

int main() {
    string str6("ilk string denemesi");

    //str6.erase(5, str6.length()-(5+3));
    str6.erase(str6.begin()+5, str6.end()-3);
    cout << str6 << endl;
}
