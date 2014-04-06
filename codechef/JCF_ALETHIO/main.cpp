#include <iostream>

using namespace std;

int main()
{
    char str[1000];
    long largest=0;
    cin >> str;

    int pos=0;
    int status = 2; // Will encounter character
    if(str[0]>='A' && str[0]<='Z')
        status = 1; // Starts on Character
        // 3 is character already encountered

    for(pos; !(str[pos]>='A' && str[pos]<='Z'); ++pos){}
    long num = 0;

    for(int i = 0; str[i]!='\0'; ++i)
    {
        if(status == 1)
        {
            num = 9;
            status=4;
            continue;
        }
        else if(status==4 && num==0)
        {   --i;
            status=3;
        }

        if(str[i]>='1' && str[i]<='9')  // if(  isnum()  )
        {
            num = num*10 + (int)(str[i]) - 48;
            if(largest<num)largest=num;
        }
        else if(str[i]>='A' && str[i]<='Z' && status != 2)
        {

            if(status==4)
            {
                pos++;
/**dsg*/        i = pos;
            }
            if(status==3)
                pos = i;
            if(num>largest){largest = num;}
            if(status!=4)status = 2;

            if(str[pos]>='A' && str[pos]<='Z') status=1;

            num=0;
        }
        else if(str[i]>='A' && str[i]<='Z' && status == 2)
        {
            num = num*10 + 9;
            if(num>largest){largest = num;}
            status = 3;
        }


    }
    cout << largest;

    return 0;
}



    /** TO FIND FIRST CHARACTER IN STRING
    //
    // unsigned int p_char = 0;
    // for(p_char; !(str[p_char]>='A' && str[p_char]<='Z'); ++p_char){} // to find position of 1st character //
    //
    */

