#include <iostream>

using namespace std;

class cqueue
{
    int a[10];
    int top, bottom,size;
    public:
    cqueue()
    {
        top = 0;
        bottom = size = 0;
    }
    int add()
    {
        if(size == 10)
        {
            cout << "\nOverflow";
            return 0;
        }
        cout << "\nEnter number to add : ";
        int num;
        cin >> num;

        if(bottom == 10)
            bottom = 0;

        a[bottom++] = num;
        size++;
        return 1;
    }

    int del()
    {
        if(size==0)
        {
            cout << "\nUnderflow";
            return -1;
        }
        if(top==10)
            top=0;
        top++;
        size--;
    }
    int display()
    {
        cout << "\nThe queue is : ";
        if(size == 0)
        {
            cout << "empty!" << endl;
            return -2;
        }
        if(bottom > top)
        {
            for(int i = top; i < bottom; ++i)
                cout << a[i] << "  ";
        }
        else if(top > bottom)
        {
            for(int i = top; i < 10; ++i)
                cout << a[i] << "  ";
            for(int t = 0; t < bottom; ++t)
                cout << a[t] << "  ";
        }
    }
};

int main()
{
    cqueue a;
    a.add();
    a.display();
    a.add();
    a.add();
    a.add();
    a.add();
    a.add();
    a.display();
    a.add();
    a.add();
    a.add();
    a.add();
    a.add();
    a.display();
    a.del();
    a.del();
    a.display();
    a.add();
    a.display();
    a.del();
    a.del();
    a.del();
    a.del();
    a.del();
    a.display();
    a.del();
    a.del();
    a.display();
    a.del();
    a.del();
    a.del();
    a.display();
    return 0;
}
