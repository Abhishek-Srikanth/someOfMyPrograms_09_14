#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int qwebnm;
    int *ptr = &qwebnm;
    *ptr = 6087;
    cout << "&qwebnm = " << ptr << endl
         << "qwebnm = " << *ptr << endl;

    system("PAUSE");
    system("CLS");

    string movie;
    string *ptrtomovie;
    ptrtomovie = &movie;
    *ptrtomovie = "Good movie";
    cout << ptrtomovie << "\t" << movie << endl << endl;

    system("PAUSE");
    system("CLS");

    int *ptr2 = new int;
    *ptr2 = 10;
    cout << ptr2 << "   " << *ptr2 << endl;

    system("PAUSE");
    system("CLS");

    string  *stringptr = new string ("the salad is rotten ");
    cout << *stringptr << "\t\t" << stringptr << endl;

    system("PAUSE");
    system("CLS");

    cout << "QUICK STRING TESTS" << endl;
    cout << "the salad is rotten is a string" << endl;
    string newe = "Maybe i am wrong ";
    string combo = newe + *stringptr;
    cout << "string 2 is " << newe << endl << "and the sum of both strings is ... " << endl << combo << endl;

    system("PAUSE");
    system("CLS");

    string *asd = new string;
    *asd = "L.A.MURDERERS" ;
    for (int i=0; i<=asd->length(); i++)
    {
        cout << (*asd)[i] << " ";
    }
    delete asd;

    system("PAUSE");
    system("CLS");



}
