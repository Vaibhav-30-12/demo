#include <iostream>

using namespace std;

class ChainNode {
  friend class Chain;
  public:
        ChainNode (int element=0, ChainNode *next=0) // constructor
        {       data = element; link = next;    }
  private:
        int data;
        ChainNode *link;
};

class Chain {
  private:
        ChainNode *first;
  public:
        Chain() { first = NULL; } // constructor
        void insertbegin(int);
        void insertend(int);
        void remove(int);
        void printchain();
        void countNodes();
        void insertAfter(int,int); // inserts a node after finding the specified data
        ~Chain() {              // destructor
                        ChainNode *tmp;
                        while (first) {
                                tmp = first->link;
                                delete first;
                                first = tmp;
                                }
                 }

};

int main()
{
  Chain c;
  short int choice;
  int data, item;
  do
  {
    cout << endl << "   Insert at: 1. Beginning 2. End  3. After an item 4. Stop " << endl;
        cout << "   Enter your choice (1/2/3/4): ";
    cin >> choice;
    switch (choice)
    {
        case 1: cout << "Data to be inserted at beginning: ";
                cin >> data;
                c.insertbegin(data);
                break;
        case 2: cout << "Data to be inserted at end: ";
                cin >> data;
                c.insertend(data);
                break;
        case 3: cout << "Data to be inserted: ";
                cin >> data;
                cout << "Item after which data is to be inserted: ";
                cin >> item;
                c.insertAfter(data,item);
                break;
    }
  } while (choice != 4);
  c.printchain();
  cout << "Enter node to be removed : ";
  cin >> data;
  c.remove(data);
  c.printchain();
  return 0;
}

void Chain::printchain()
{
    if (first==NULL)return;
    ChainNode* temp=first;
    while(temp->link!= nullptr){
        cout<< temp->data<<" ->";
        temp= temp->link;
    }




}

void Chain::insertbegin(int x)
{
  if (first) // list already exists
  {
    ChainNode * temp=new ChainNode(x);
    temp->link=first;
    first=temp;
  }
  else
        first = new ChainNode(x,0);
}

void Chain::insertend(int x)
{
  if (first)  // list already exists
  {
    ChainNode* temp= first;
    while(temp->link!=nullptr){
        temp=temp->link;
    }
    ChainNode* temp1=new ChainNode(x);
    temp->link=temp1;

    ChainNode * temp=first;
    while(temp->link!=nullptr){
        temp= temp->link;
    }
    temp->link= new ChainNode(x,nullptr);

    
  }
  else // empty list; creating the first node of the list
        first = new ChainNode(x,0);
}