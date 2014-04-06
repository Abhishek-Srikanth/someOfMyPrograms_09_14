#include <iostream>

int main(){
std::cout << "Never mind, did it with brute force!\n\n";
return 0;
}
/**
#include <iostream>

using namespace std;

int main()
{
    for(long int i = 100000000;; ++i)
    {
        bool flag = 1;
        for(long int j = 2; j <21; ++j)
        {
            if(i%j!=0)
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            cout << i;
            break;
        }
        cout << ".";
        if(i%10000==0)
            cout << i << endl;
    }
    return 0;
}
*/
