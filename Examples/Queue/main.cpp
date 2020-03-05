#include "queue.cpp"
#include <iostream>

using namespace std;

int main()
{
    Queue y;
    cout << "Eleman Sayisi: " << y.totalData() << endl;

    y.push(3);
    cout << "Sayi atildi: 3" << endl;
    y.push(10);
    cout << "Sayi atildi: 10" << endl;
    y.push(5);
    cout << "Sayi atildi: 5" << endl;

    y.test();
    cout << "Sayi cekildi: " << y.pop() << endl;
    y.test();
    cout << "Sayi cekildi: " << y.pop() << endl;
    y.test();
    cout << "Sayi cekildi: " << y.pop() << endl;
    y.test();


    return 0;
}
