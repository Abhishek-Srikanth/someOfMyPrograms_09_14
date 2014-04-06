#include <iostream>
#include <string.h>

using namespace std;

void stradd(char *p, char *q, int lp, int lq)
{
    char *r = new char[lp + lq];
    for(int i = 0; i < lp; ++i)
    {
        *(r+i) = *(p+i);
    }
    for(int i = 0; i < lq; ++i)
    {
        *(r + lp + i) = *(q+i);
    }
    cout << r;
    delete r;
}

void search(int *a, int n, int num)
{
    for(int i = 0; i < n; ++i)
    {
        if(*(a+i) == num)
        {
            cout << "number is " << *(a+i) << " at position " << i+1 << endl;
            break;
        }
    }
}

int main()
{
    asd:
    cout << "\n\nMENU\n1.stradd\n2.search\n3.exit";
    cout << "Enter your choice : ";
    int ch;
    cin >> ch;
    switch(ch)
    {
        case 1:
        char w1[10], w2[10];
        cout << "Enter w1 : ";
        cin >> w1;
        cout << "Enter w2 : ";
        cin >> w2;
        stradd(w1,w2,strlen(w1), strlen(w2));
        goto asd;
        case 2:
        cout << "Enter array : ";
        int a[10];
        for(int i = 0; i < 10; ++i)
            cin >> a[i];
        cout << "Enter no to find : ";
        int num;
        cin >> num;
        search(a,10,num);
        goto asd;
        case 3:
        cout << "\nBye\n";
    }
    /*
    stradd("how ar" , "e you\n", 6,6);
    int a[10] = {1,2,3,4,5,6,7,8,9,0};
    search(a,10,6);*/
    return 0;
}
