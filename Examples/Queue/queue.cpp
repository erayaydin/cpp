#include <iostream>

using namespace std;

class Queue {
    static const int CAPACITY = 100;
    int data[CAPACITY];
    int count = 0;

    public:
        bool push(int item)
        {
            if(count == CAPACITY)
                return false;
            data[count++]=item;
            return true;
        }

        int pop()
        {
            if(count == 0)
                return -1;

            int item = data[0];
            for(int i=0; i<totalData()-1; i++)
                data[i] = data[i+1];
            count--;
            return item;
        }

        void test()
        {
            for(int i=0; i<3; i++){
                cout << i << ". " << data[i] << endl;
            }
        }

        int totalData()
        {
            return count;
        }
};

