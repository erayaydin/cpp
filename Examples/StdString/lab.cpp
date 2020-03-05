#include <iostream>

using namespace std;

int main() {
    string str1("ilk string");
    cout << "str1=" << str1 << endl;

    //string str3("#####");
    string str3(5, '#');
    cout << "str3=" << str3 << endl;

    string str4(str1, 4, 6);
    cout << "str4=" << str4 << endl;

    string str5(str1.begin(), str1.begin()+5);
    cout << "str5=" << str5 << endl;

    //string str2(str1.begin(), str1.end());
    string str2(str1);
    cout << "str2=" << str2 << endl;

    str5.clear();
    cout << "str5=" << str5 << endl;

    int uzunluk = str1.length();
    cout << "uzunluk=" << uzunluk << endl;

    int boyut = str1.size();
    cout << "boyut=" << boyut  << endl;

    char ch = str1.at(2);
    cout << "ch=" << ch << endl;

    char ch2 = str1[2];
    cout << "ch2=" << ch2 << endl;

    //char ch_f = str1[0];
    char ch_f = str1.front();
    //char ch_b = str1[str1.length()-1];
    char ch_b = str1.back();

    cout << "ch_f=" << ch_f << endl;
    cout << "ch_b=" << ch_b << endl;

    //str1 += " denemesi";
    str1.append(" denemesi");
    cout << "str1=" << str1 << endl;

    str1.erase(7, 4);
    cout << "str1=" << str1 << endl;
}
