#include <iostream>

using namespace std;

void add_to_pos(int a[50], int &n, int pos = 1)
{
    --pos;
    if(pos>=n)
        goto ending;
    for(int i = n; i > pos; --i)
    {
        swap(a[i],a[i-1]);
    }
    cout << "Enter new value to be added : ";
    cin >> a[pos];
    ++n;
    ending:;
}

void add_to_end(int a[50], int &n)
{
    if(n<50)
    {
        cout << "Enter value to add : ";
        cin >> a[n++];
    }

}

void display(int a[50], int &n)
{
    for(int i = 0; i < n; ++i)
        cout << a[i] << "  ";
    cout << endl;
}

int main()
{
    int a[50];
    for(int i = 0; i < 50; ++i)
        a[i] = 0;
    cout << "How many integers do you wish to enter at first : ";
    int n;
    int pos = 0;
    cin >> n;
    cout << "Enter your array below : " << endl;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
menu:
    cout << "\n\nEnter your choice : \n1. add to start\n2. add to pos \n3. add to end\n 4.bye \nso... ";
    int ch;
    cin >> ch;

    switch(ch)
    {
case 1:
    add_to_pos(a,n);
    display(a,n);
    goto menu;
case 2:
    cout << "Enter pos to add : ";
    cin >> pos;
    add_to_pos(a,n,pos);
    display(a,n);
    goto menu;
case 3:
    add_to_end(a,n);
    display(a,n);
    goto menu;
        case 4:
        cout << "BYE BYE";
    }
    return 0;
}
