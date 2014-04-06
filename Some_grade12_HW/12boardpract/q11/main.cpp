#include <iostream>

using namespace std;

void sortndisp(int a[], int &n)
{
    for(int i = 1; i < n; ++i)
    {
        for(int j = i; j > 0; --j)
        {
            if(a[j] < a[j-1])
                swap(a[j],a[j-1]);
        }
    }
    for(int i = 0; i < n; ++i)
        cout << a[i] << "  ";
    cout << endl;
}

int linear(int a[], int n, int num)
{
    for(int i = 0; i < n; ++i)
    {
        if(a[i] == num)
            return i+1;
    }
    return 0;
}

int binary(int a[], int bot, int num)
{
    int top = 0,mid;
    while(top <= bot)
    {
        mid = (top + bot) / 2;
        if(a[mid] == num)   return mid+1;
        else if(a[mid] > num) bot = mid-1;
        else top = top+1;
    }
    return 0;
}

int main()
{
    int n;
    cout << "Enter number of integers : ";
    cin >> n;
    int a[n];
    cout << "Time to insert all values : \n";
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    cout << "Your array has the numbers : ";
    sortndisp(a,n);
    menu:
    int ch;
    cout << "Enter the choice as per menu : \n1.linear_search\n2.binary_search\n3.exit\n\nso...";
    cin >> ch;
    int num = 0;
    if(ch==1 || ch==2)
    {
        cout << "Enter number to find : ";
        cin >> num;
    }
    switch(ch)
    {
        case 1:
            cout << "position of number is " << linear(a,n,num) << "\n\t\t(0 means number non-existant)\n\n";
            goto menu;
        case 2:
            cout << "position of number is " << binary(a,n,num) << "\n\t\t(0 means number non-existant)\n\n";
            goto menu;
        case 3:
            cout << "\n\nbye bye";
    }

    delete []a;
    return 0;
}
