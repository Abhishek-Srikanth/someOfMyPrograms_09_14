#include <iostream>
#define nl cout << endl
using namespace std;

class llist
    {   // class definition
        int data;   // value of class
        llist *link;    // link object points to
        public:
        void create();
        void add2start();
        void add2end();
        void del1st();
        void delLAST();
        void del2pos();
        void add2pos();
        void display();


    }*start=NULL,*end=NULL;


    void llist::create()
    {
        // creates list
        char ch = 'Y';
        while(ch=='Y' || ch=='y')
        {
            llist *n = new llist;
            cout << "Enter data : ";
            cin >> n->data;
            n->link=NULL;
            if(start==NULL)
            {
                start = n;
                end = n;
            }
            else
            {
                end->link = n;
                end = n;
            }
            cout << "Do you wish to add any more?\n->";
            cin >> ch;
        }
    }

    void llist::add2start()
    {   // adds 1 value to the start of the list
        llist *n = new llist;
        cout << "Enter data : ";
        cin >> n->data;
        n->link = start;
        start = n;
    }
    void llist::add2end()
    {   // adds to end of the list
        llist *n = new llist;
        cout << "Enter data : ";
        cin >> n->data;
        n->link = NULL;
        end->link = n;
        end = n;
    }
    void llist::del1st()
    {   // deletes 1st value of list
        llist *n = start;
        start = start->link;
        delete n;
    }

    void llist::delLAST()
    {   // deletes last value in list
        llist *n = start;
        while(n->link!=end)
        {
            n=n->link;
        }
        n->link=NULL;
        delete end;
        end = n;
    }

    void llist::del2pos()
    {   // deletes a specific location of list
        cout << "Enter position to delete : ";
        int pos;
        cin >> pos;
        pos--;
        llist *n1 = start;
        llist *n2 = start;
        for(int i = 1; i < pos; ++i)
        {
            n1=n1->link;
            n2=n2->link;
        }
        n1=n1->link;

        n2=n1->link;
        delete n1;
    }

    void llist::add2pos()
    {   // adds to a specific position
        cout << "Enter position to add : ";
        int pos;
        cin >> pos;
        pos--;
        llist *n1 = start;
        llist *n2 = start;
        if(pos>=2)  // must be greater than 2
        {
            for(int i = 1; i < pos; ++i)
            {
                n1=n1->link;
                n2=n2->link;
            }
            n1=n1->link;
            llist *n = new llist;
            cout << "Enter data : ";
            cin >> n->data;
            n->link = n1;
            n2->link = n;
        }
    }
    void llist::display()
    {   // display function
        llist *n = start;
        while(n!=NULL)
        {
            cout << n->data << "  ";
            n = n->link;
        }
    }

int main()
{
    llist a;
    cout << "The operations carried out are : \n";
    cout << "0. create list\n";
    a.create();nl;
    cout << "1. insert at start\n";
    a.add2start();nl;
    cout << "2. insert at specific position\n";
    a.add2pos();nl;
    cout << "3. insert at end\n";
    a.add2end();nl;nl;
    a.display();nl;nl;
    cout << "4. delete 1st value\n";
    a.del1st();nl;
    cout << "5. delete at given position\n";
    a.del2pos();nl;nl;
    a.display();nl;nl;
    cout << "6. delete last value\n";
    a.delLAST();nl;nl;
    a.display();


    return 0;
}
