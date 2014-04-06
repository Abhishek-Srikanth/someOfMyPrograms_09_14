#include <iostream>

using namespace std;

void bubble(int a[], int &n)
{
    for(int i = 0; i < n-1; ++i)
    {
        for(int j = 0; j < n-i-1; ++j)
        {
            if(a[j]>a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void selection(int a[], int &n)
{
    int s,p;
    for(int i = 0; i < n; ++i)
    {
        s = a[i];
        p = i;
        for(int j = i; j < n; ++j)
        {
            if(a[j] < s)
            {
                s = a[j];
                p = j;
            }
        }
        a[p] = a[i];
        a[i] = s;
    }
}

int main()
{
    cout << "Enter array size: ";
    int n;
    cin >> n;
    int a[n];
    cout << "Enter your array : \n";
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    cout << endl;
    cout << "\n\tMENU : \n1.bubble_sort\n2.selection_sort\n3.exit\n\nEnter your choice : ";
    int ch;
    cin >> ch;
    switch(ch)
    {
        case 1:
                bubble(a,n);
                cout << "Your sorted array is : ";
                for(int i = 0; i < n; ++i)
                {
                    cout << a[i] << " ";
                }
                cout << endl;
                break;
        case 2:
                selection(a,n);
                cout << "Your sorted array is : ";
                for(int i = 0; i < n; ++i)
                {
                    cout << a[i] << " ";
                }
                cout << endl;
                break;
        case 3:
                cout << "bye.......";
    }
    return 0;
}
