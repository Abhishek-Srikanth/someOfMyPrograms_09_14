#include <iostream>

using namespace std;

struct node // structure defined as specified
{
    long Mno;
    char Mname[20];
    node *link;
    void add();
    void del();
    void display();
}*start=NULL, *end=NULL;

void node::add()    // addition to queue
{
    node *n = new node;
    cout << "Enter Mno : ";
    cin >> n->Mno;
    cout << "Enter Mname : ";
    cin >> n->Mname;
    n->link = NULL;
    if(start == NULL)
    {
        start = n;
        end = n;
    }
    else
    {
        end->link = n;
        end = n;
    }
}

void node::del()
{
    if(start==NULL) // underflow situation if asked to remove when no value is present
        cout << "UNDERFLOW...\n";
    else
    {
        node *n = start;
        start = start->link;
        delete n;
    }
}

void node::display()    // display function that traverses through queue
{
    node *n = start;
    while(n!=NULL)
    {
        cout << n->Mno << "  " << n->Mname << endl;
        n = n->link;
    }
}


int main()
{
    node q;
    q.del();
    // simply to check for nderflow condition
    q.add();
    q.add();
    q.add();
    q.display();
    cout << "del\n";
    q.del();
    q.display();
    cout << "del\n";
    q.del();
    q.display();
    return 0;
}
