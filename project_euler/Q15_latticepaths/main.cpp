#include <iostream>

using namespace std;


// recursive function was too slow... -_-
int lattice(int n, int x, int y)
{
    if(x==n && y==0)
    {
        cout << "reached end\n";
        return 0;
    }
    if(y==0)
    {
        cout << "reached end\n";
        return 1;
    }
    if(x==n)
    {
        cout << "reached end\n";
        return 1;

    }

    cout << endl << x << ", " << y << endl;
    int a = lattice(n,x+1,y);
    int b = lattice(n,x,y-1);

    return a+b;
}

int main()
{
    int n = 20;
    long long grid[21][21] = {0};
    for(int i = 0; i <= n; ++i)
        grid[i][n] = 1;
    for(int i = 0; i <= n; ++i)
        grid[n][i] = 1;
    for(int i = n-1; i >= 0; --i)
    {
        for(int j = n-1; j >= 0; --j)
        {
            grid[i][j] = grid[i+1][j] + grid[i][j+1];
        }
    }
    cout << grid[0][0];
    return 0;
}
/**
    solved problem on EXCEL
    Ok, so this was a long question with a very simple solution. I first started solving it by going recursively
    repeating the solution function at every near point until end of grid. Unfortunately this took too long to solve.

    So i got another approach. I started by setting last row and column to value of 1. Then moving from bottom left of array (size 21x21)
    I added the value on bottom and right cell to get value of that cell given that cell did not have a value of 1. By moving so the value
    of array[0][0] had the number of moves available.
*/
