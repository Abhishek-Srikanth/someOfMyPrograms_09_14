#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int T;
    scanf("%d\n",&T);
    while(T-->0)
    {

        int parent[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        char ch;
        for(;;)
        {
            cin.get(ch);
            if(ch=='\n' || ch=='\r')
                break;
            if(ch!=' ')
            {
                ++parent[ch-97];
            }
        }
        //cout << "OK>>>>>>>>>>>NOW<<<<<<<<<<NUMBER\n";
        int n = 0;
        scanf("%d\n",&n);
        for(int i = 0; i < n;)
        {
            cin.get(ch);
            if(ch=='\n' || ch=='\r')
            {
                ++i;
                continue;
            }
            parent[ch-97]-=1;
        }
        bool flag=1;
        //1 means true
        //0 means no
        for(n=0; n<26; ++n)
        {
            if(parent[n]<0)
            {
                flag = 0; // NO
            }
        }
        if(flag)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
