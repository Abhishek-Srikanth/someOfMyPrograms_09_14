#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>

using namespace std;

int main()
{
    ofstream ofile("Poem.txt");
    char q; // char that writes
    cout << "Enter poem, to stop enter @ \n";
    while(1)    // runs forever
    {
        q = getch();    // input character
        if(q == '\n' || q == '\r')
        {
            ofile << '~';
            cout << "\n";
            continue;         // skips all ahead
        }
        else if(q == ' ')
        {
            ofile << '_';
            cout << " ";
            continue;         // skips all ahead
        }
        if(q=='@')            // termination of input streak
            break;
        ofile << q;           // write to file
        cout << q;
    }
    ofile.close();      // close writing file

    cout << endl << endl << endl;

    ifstream ifile("Poem.txt");
    int nv = 0 , nl = 1;
    cout << "Enter word you wish to search for : ";
    char word[10];
    cin >> word;        // input word to be searched
    char w[10];
    int i = 0,c=0;
    while(!ifile.eof()) // loop until end of the file
    {
        char p;
        ifile >> p;
        if(p!='_' && p!='~' && p!='@')
        {
            w[i++] = p;     // saves characters of a word in Poem.txt into char w[10]
        }
        else if(p=='_' || p == '~')
        {                   // if word is over then :
            w[i] = '\0';
            i = 0;
            if(!strcmp(word,w)) // compare with given word
                c++;
            strcpy(w,"\0");     // reset w to '\0'
        }

        if(p == '~') nl++;  // if ENTER/RETURN key had been pressed, increment no of lines
        if (p=='a' || p == 'e' || p == 'i' || p == 'o' || p == 'u') nv++;
        if (p=='A' || p == 'E' || p == 'I' || p == 'O' || p == 'U') nv++;
        // above for all the vowels to be counted
    }

// below is the essential OUTPUT
    cout << endl << endl << "Poem has " <<  nv << " vowels and " <<  nl << " lines" << endl;
    cout << "Number of times " << word << " has repeated is : " << c << endl;
    cout << "size of file is " << sizeof(ifile) << " bytes";
    ifile.close();
// Journal questions 15,16,17,18 completed!
    return 0;
}
