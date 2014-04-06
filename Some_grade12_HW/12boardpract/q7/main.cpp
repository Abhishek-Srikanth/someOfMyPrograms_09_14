#include <iostream>

using namespace std;

void sum_dia(int a[4][4])
{
    cout << "sum of values of main diagonal is  : " << a[0][0] + a[1][1] + a[2][2] + a[3][3] << endl;
    cout << "sum of values of other diagonal is : " << a[0][3] + a[1][2] + a[2][1] + a[3][0] << endl;
}

void sum_row(int a[4][4])
{
    a:
    cout << "Enter row number : ";
    int r;
    cin >> r;
    if(r>4)
        goto a;
    cout << "sum of values of row "<< r << " is : " << a[r-1][0] + a[r-1][1] + a[r-1][2] + a[r-1][3] << endl;
}

void sum_col(int a[4][4])
{
    b:
    cout << "Enter column number : ";
    int c;
    cin >> c;
    if(c>4)
        goto b;
    c--;
    cout << "sum of values of row "<< c+1 << " is : " << a[0][c] + a[1][c] + a[2][c] + a[3][c] << endl;
}

int main()
{
    int a[4][4];
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            cout << "Enter " << i+1 << "." << j+1 << "here : ";
            cin >> a[i][j];
        }
        cout << endl;
    }

    cout << "Your array is : \n";
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
            cout << a[i][j] << "  ";
        cout << endl;
    }

    topa:
    cout << "\n\tMENU\n1.Sum_diagonals\n2.Sum_specified_row\n3.Sum_indiv_col\n4.exit\n\nenter your choice : ";
    int ch;
    cin >> ch;
    switch(ch)
    {
        case 1:
            sum_dia(a);
            goto topa;
        case 2:
            sum_row(a);
            goto topa;
        case 3:
            sum_col(a);
            goto topa;
        case 4:
            cout << "\n\nBye\n\n";
    }

    return 0;
}
