#include <iostream>

using namespace std;

void sortit(int a[], int la)
{
    for(int i = 0; i < la; ++i)
    {
        for(int j = 0; j < la-i; ++j)
        {
            if(a[j]>a[j+1])
                swap(a[j],a[j+1]);
        }
    }
    for(int i = 0; i < la; ++i)
        cout << a[i] << " ";
    cout << endl << endl;
}

void merge(int a[], int b[], int la, int lb)
{
    int i,j,k;
    i=j=k=0;
    int c[la+lb];
    while(i<la && j < lb)
    {
        if(a[i]< b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }
    while(i<la)
        c[k++] = a[i++];
    while(j<lb)
        c[k++] = b[j++];

    cout << "The new array is : ";
    for(i = 0; i < k; ++i)
    {
        cout << c[i] << "  ";
    }
    cout << endl;
}

int main()
{
    cout << "Enter length of array 1 : ";
    int la,lb;
    cin >> la;
    cout << "Enter length of array 2 : ";
    cin >> lb;
    int a[la], b[lb];
    cout << "Enter array 1 : \n";
    for(int i = 0; i < la; ++i)
        cin >> a[i];
    cout << "Enter array 2 : \n";
    for(int i = 0; i < lb; ++i)
        cin >> b[i];
    sortit(a,la);
    sortit(b,lb);
    merge(a,b,la,lb);
    return 0;
}
