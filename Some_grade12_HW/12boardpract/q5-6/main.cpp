#include <iostream>

using namespace std;

struct node
{
    int val;
    node *link;
};

class llist
{
    node *top, *end;
    public:
    llist()
    {
        top = end = NULL;
    }
    ~llist();
    void create();
    void add_to_pos();
    void append();
    void remove_first();
    void remove_pos();
    void display();

};

void llist::add_to_pos()
{
    cout << "Enter position to add : ";
    int pos;
    cin >> pos;
    pos--;
    node *p1 = top;
    for(int i = 1; i < pos; ++i)
    {
        p1 = p1->link;
    }
    node *n = new node;
    cout << "Enter value of new node : ";
    cin >> n->val;
    n->link = p1->link;
    p1->link = n;
}

void llist::display()
{
    node *n = top;
    while(n!=NULL)
    {
        cout << n->val << "  ";
        n = n->link;
    }
}

void llist::append()
{
    node *n = new node;
    cout << "Enter value : ";
    cin >> n->val;
    n->link = NULL;
    end->link = n;
    end = n;
}

void llist::create()
{
    node *n = new node;
    cout << "Enter value : ";
    cin >> n->val;
    n->link = NULL;
    top = end = n;
    char ch = 'y';
    cout << "Add more (y/n) ? ";
    cin >> ch;
    while(ch == 'y' || ch == 'Y')
    {
        append();
        cout << "Add more (y/n) ? ";
        cin >> ch;
    }
}

void llist::remove_first()
{
    if(top!=NULL)
    {
        node *n= top;
        top = top->link;
        delete n;
    }
}

void llist::remove_pos()
{
    aboc:
    cout << "Enter position you want to remove : ";
    int pos;
    cin >> pos;
    if(pos<2)
        goto aboc;
    --pos;
    node *p1 = top;
    for(int i = 1; i < pos; ++i)
    {
        p1 = p1->link;
    }
    node *p2 = p1->link;
    p1->link = p2->link;
    delete p2;
}

llist::~llist()
{
    cout << endl;
    while(top!=NULL)
    {
        cout << top->val << " ";
        remove_first();
    }
    cout << endl;
}

int main()
{
    llist a;
    cout << endl << endl;
    a.create();
    cout << "\n\ncreation : \n";
    a.display();
    a.append();
    cout << "\n\npost append : \n";
    a.display();
    a.add_to_pos();
    cout << "\n\npost add2pos : \n";
    a.display();
    a.remove_pos();
    cout << "\n\npost rem_pos : \n";
    a.display();
    a.remove_first();
    cout << "\n\npost rem 1st : \n";
    a.display();
    cout << endl << endl << "DESTRUCTOR " << endl;
    return 0;
}
