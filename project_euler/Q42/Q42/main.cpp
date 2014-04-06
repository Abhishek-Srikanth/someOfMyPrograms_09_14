#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int a[] = {1 , 3 , 6 , 10 , 15 , 21 , 28 , 36 , 45 , 55 , 66 , 78 , 91 , 105 , 120 , 136 , 153 , 171 , 190 , 210 , 231 , 253 , 276 , 300 , 325 , 351 , 378 , 406};
    char str[15];
    int c = 0;
    int val = 0;
    ifstream i("file.txt", ios::in);
    while(!i.eof())
    {
        val = 0;
        i >> str;
        cout << str << "\t";
        for(int j = 0; str[j] != '\0'; ++j)
        {
            val += ((int)(str[j])-64);
        }
        cout << val << endl;
        for(int j = 0; a[j] < 407; ++j)
        {

            if(val==a[j])
            {
                ++c;
                break;
            }
        }
    }
    cout << "\nValues of c is " << c << endl;
    i.close();
    return 0;
}
