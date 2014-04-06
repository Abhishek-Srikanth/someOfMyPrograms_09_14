#include <iostream>

using namespace std;

class lstack
{   // class definition
    int data;
    lstack *link;
    public:
    void push();
    void pop();
    void display();

}*top=NULL;

void lstack::push()
{   // push function to add value
    lstack *n = new lstack;
    cout << "Enter value : ";
    cin >> n->data;
    if(top==NULL)
    {
        top = n;
        top->link = NULL;
    }
    else
    {
        n->link = top;
        top = n;
    }

    /**** NOTE . NO NEED FOR OVERFLOW AS IT IS LINKED, NOT LINEAR ****/
}

void lstack::pop()
{
    if(top == NULL)     // condition for underflow situation
        cout << "Underflow, cannot POP any value...\n";
    else
    {
        lstack *n = top;
        top = top->link;
        delete n;
    }
}

void lstack::display()
{                       // function displaying all values in stack
    lstack *n = top;
    while(n!=NULL)
    {
        cout << n->data << "  ";
        n=n->link;
    }
    if(top == NULL) // if the stack is empty
    cout << "Empty Stack, nothing to display...";
    cout << endl;
}

int main()
{
    lstack A;

    A.display();    // give empty message
    A.pop();        // give underflow scenario

    A.push(); A.push(); A.push(); A.push(); A.push(); A.push();
    A.display();    // display all 6 input values

    A.pop();  A.pop();
    A.display();    // displays first 4 input values

    A.pop();  A.pop();
    A.display();    // displays first 2 input values

    A.pop();  A.pop();
    A.display();    // gives empty message

    return 0;
}
