#include <iostream>

using namespace std;

int main()
{
    double a,b,c,d,e,f,g,h,i,j;
    for ( a=b=c=d=e=f=g=h=i=j=0; a<=10, b<=20, c<=30, d<=40, e<=50, f<=60, g<=70, h<=80, i<=90, j<=100; a++,b+=2, c+=3, d+=4, e+=5, f+=6, g+=7, h+=8, i+=9, j+=10 )
    {
        cout << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << f << "\t" << g << "\t" << h << "\t" << i << "\t" << j << endl;
    }
    return 0;
}
