#include <iostream>

using namespace std;

int add(int a[10], int &bottom)
{
   if(bottom==10)
    {
        cout << "OVer flow";
        return -2;
    }
    cout << "Enter value to add : ";
    cin >> a[bottom];
    ++bottom;
    return 1;
}

int del(int a[10], int &top, int &bottom)
{
    if(top<bottom)
    top++;
    else
    {
        cout << "Under flow";
        return -1;
    }
    return 1;
}

void display(int a[10], int t, int &b)
{
    for(; t < b; ++t)
    {
        cout << a[t] << "  ";
    }
    cout << endl;
}

int main()
{
    int a[10];
    int top=0, bottom = 0;
    add(a,bottom);
    add(a,bottom);
    display(a,top,bottom);
    del(a,top,bottom);
    display(a,top,bottom);
    del(a,top,bottom);
    del(a,top,bottom);
    display(a,top,bottom);

    return 0;
}
