#include <iostream>
#include <string.h>

using namespace std;

void func(char *a, char *b)
{
    // a is smaller //
    int i = 0;
    for(int j = 0; j < strlen(b) && i < strlen(a); ++j)
    {
        if(a[i]==b[j])
        {
            i++;
            continue;
        }
    }
    if(i==strlen(a))
        cout << "YES\n";
    else cout << "NO\n";

}

int main()
{
    int T;
    cin>> T;
    for(;T>0; --T)
    {
        char m[25001], w[25001];
        cin >> m;
        cin >> w;
        if(strlen(m)<strlen(w))
            func(m,w);
        else if(strlen(m)==strlen(w))
        {
            if(strcmp(m,w)==0)
                cout << "YES\n";
            else cout << "NO\n";
        }
        else
            func(w,m);
    }
    return 0;
}
