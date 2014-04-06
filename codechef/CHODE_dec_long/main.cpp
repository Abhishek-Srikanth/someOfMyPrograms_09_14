#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct o26
{
    char alpha;
    int freq;
    char code;
};

void swap(o26 &a, o26 &b)
{
    o26 c;
    c.alpha = a.alpha;
    c.freq = a.freq;

    a.alpha = b.alpha;
    a.freq = b.freq;

    b.alpha = c.alpha;
    b.freq = c.freq;

}

int fn()
{
    char freq[26];
    char code[150000] = {0};
    o26 a[26];
    for(int i = 0; i < 26; ++i)
    {
        a[i].alpha = 'a' + i;
        a[i].freq = 0;
    }
    gets(freq);
    gets(code);


    for(int i = 0; i < 150000 && code[i]!='\0'; ++i)
    {
        switch(code[i])
        {
            case 'A':
            case 'a':
                a[0].freq+=1;
                break;
            case 'B':
            case 'b':
                a[1].freq+=1;
                break;
            case 'C':
            case 'c':
                a[2].freq+=1;
                break;
            case 'D':
            case 'd':
                a[3].freq+=1;
                break;
            case 'E':
            case 'e':
                a[4].freq+=1;
                break;
            case 'F':
            case 'f':
                a[5].freq+=1;
                break;
            case 'G':
            case 'g':
                a[6].freq+=1;
                break;
            case 'H':
            case 'h':
                a[7].freq+=1;
                break;
            case 'I':
            case 'i':
                a[8].freq+=1;
                break;
            case 'J':
            case 'j':
                a[9].freq+=1;
                break;
            case 'K':
            case 'k':
                a[10].freq+=1;
                break;
            case 'L':
            case 'l':
                a[11].freq+=1;
                break;
            case 'M':
            case 'm':
                a[12].freq+=1;
                break;
            case 'N':
            case 'n':
                a[13].freq+=1;
                break;
            case 'O':
            case 'o':
                a[14].freq+=1;
                break;
            case 'P':
            case 'p':
                a[15].freq+=1;
                break;
            case 'Q':
            case 'q':
                a[16].freq+=1;
                break;
            case 'R':
            case 'r':
                a[17].freq+=1;
                break;
            case 'S':
            case 's':
                a[18].freq+=1;
                break;
            case 'T':
            case 't':
                a[19].freq+=1;
                break;
            case 'U':
            case 'u':
                a[20].freq+=1;
                break;
            case 'V':
            case 'v':
                a[21].freq+=1;
                break;
            case 'W':
            case 'w':
                a[22].freq+=1;
                break;
            case 'X':
            case 'x':
                a[23].freq+=1;
                break;
            case 'Y':
            case 'y':
                a[24].freq+=1;
                break;
            case 'Z':
            case 'z':
                a[25].freq+=1;
                break;
        }

    }
    // to sort o26 ascending order of freq
    for(int i = 0; i < 26; ++i)
    {
        for(int j = 0; j < 25; ++j)
        {
            if(a[j].freq>a[j+1].freq)
                swap(a[j], a[j+1]);
            else if(a[j].freq==a[j+1].freq && a[j].alpha > a[j+1].alpha)
                swap(a[j], a[j+1]);
        }
    }
    // end of sorting algorithm


    for(int i = 0; i < 26; ++i)
        a[i].code = freq[i];

// alpha Oda match pannittu atha code Ode maathanum

    for(int i = 0; i < 150000 && code[i]!='\0'; ++i)
    {
        if(isalpha(code[i]))
        {
            for(int j = 0; j < 26; ++j)
            {
                if(tolower(code[i])==a[j].alpha)
                {
                    if(isupper(code[i]))
                    {
                        code[i] = a[j].code - 32;
                    }
                    else
                        code[i] = a[j].code;
                    break;
                }
            }
        }
    }

    cout << code << endl;
    return 0;
}
int main()
{
    char t[4];
    t[0] = '0';
    t[1] = '0';
    t[2] = '0';
    t[3] = '0';
    gets(t);
    int T = atoi(t);

    while(T-- > 0)
        fn();
    return 0;
}
