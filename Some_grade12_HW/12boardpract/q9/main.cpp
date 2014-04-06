#include <cstdio>

using namespace std;

void swap(int &x, int &y)
{
    int t = x;
    x = y;
    y = t;
}

void bubble(int a[], int &n)
{
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n-i; ++j)
        {
            if(a[j]>a[j+1])
                swap(a[j],a[j+1]);
        }
    }
}

void insertion(int a[], int &n)
{
    for(int i =0; i < n; ++i)
    {
        for(int j = i; j > 0; --j)
        {
            if(a[j]<a[j-1])
                swap(a[j],a[j-1]);
        }
    }
}

int main()
{
    int n;
    printf("Enter number of integers : ");
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    printf("MENU\n1.bubble\n2.insertion\n3.exit\nso...");
    int ch;
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            bubble(a,n);
            break;
        case 2:
            insertion(a,n);
            break;
        case 3:
            printf("bye");
    }
    for(int i = 0; i <  n; ++i)
        printf(" %d ", a[i]);
    return 0;
}
