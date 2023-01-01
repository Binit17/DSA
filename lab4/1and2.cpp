#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node * next;

    node(){data=0;next=NULL;} //default constructor
    node(int data)  //parameterized constructor
    {
        this->data = data;
        this->next = NULL;
    }
};
class linkedlist
{
    node* head;
    public:
    linkedlist():head(NULL){};
    void insertAtEnd(int data);
    void insertAtBeg(int data);
    void insertBefore(int data,int num);
    void insertAfter(int data,int num);

    void printlist();

    void deleteAtEnd();
    void deleteAtBeg();
    void deleteAtPos(int pos);
};
void linkedlist::insertAtEnd(int data)
{
    node *newnode, *temp;
    //newnode to create and store the address of newly created dynamic node.
    //temp is to traverse through the node.
    temp=head;
    newnode = new node(data);

    if(head==NULL)
    {
        head=newnode;
        return;
    }

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
}
void linkedlist::insertAtBeg(int data)
{
    node *newnode;
    //newnode to create and store the address of newly created dynamic node.
    newnode = new node(data);

    newnode->next=head;
    head = newnode;
}
void linkedlist::insertAfter(int data,int num)
{
    node *newnode, *temp;
    temp=head;
    newnode = new node(data);

    while (temp->data!=num)
    {
        temp=temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}
void linkedlist::insertBefore(int data,int num)
{
    node *newnode, *temp1, *temp2;
    temp1=head;
    newnode = new node(data);

    while (temp1->data!=num)
    {
        temp2=temp1;
        temp1=temp1->next;
    }
    newnode->next = temp2->next;
    temp2->next = newnode;
}
void linkedlist::printlist()
{
    node *temp;
    temp = head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"\t\t";
        temp=temp->next;
    }
}
void linkedlist::deleteAtEnd()
{
    node *temp2, *temp1;
    temp1=head;

    while(temp1->next!=NULL)
    {
        temp2=temp1;
        temp1=temp1->next;
    }
    temp2->next = NULL;
    free(temp1);
}
void linkedlist::deleteAtBeg()
{
    node *temp;
    temp=head;
    head= temp->next;
    free(temp);
}
void linkedlist::deleteAtPos(int pos)
{
    node *temp1, *temp2;
    temp1=head;
    int i=1;
    while(i<pos)
    {
        temp2=temp1;
        temp1=temp1->next;
    }
    temp2->next = temp1->next;
    free(temp1);
}
int main()
{
    linkedlist list;
    int data,pos,num;
    int choice;
    do
    {
        cout<<"\nenter your choice: ";
        cout<<"\n1.insert at end.";
        cout<<"\n2.insert at beginning.";
        cout<<"\n3.insert after.";
        cout<<"\n4.insert before.";
        cout<<"\n5.delete at end.";
        cout<<"\n6.delete at beginning.";
        cout<<"\n7.delete at pos.";
        cout<<"\n8.print list\n";
        cin>>choice;

        switch (choice)
        {
        case 1:
            cout<<"enter data to insert: ";
            cin>>data;
            list.insertAtEnd(data);
            break;
        case 2:
            // int data;
            cout<<"enter data to insert: ";
            cin>>data;
            list.insertAtBeg(data);
            break;
        case 3:
            // int data,num;
            cout<<"the datas are: "<<endl;
            list.printlist();
            cout<<"enter data to insert: ";
            cin>>data;
            cout<<"enter the number : ";
            cin>>num;
            list.insertAfter(data,num);
            break;
        case 4:
            // int data,num;
            cout<<"the datas are: "<<endl;
            list.printlist();
            cout<<"enter data to insert: ";
            cin>>data;
            cout<<"enter the number : ";
            cin>>num;
            list.insertBefore(data,num);
            break;
        case 5:
            list.deleteAtEnd();break;
        case 6:
            list.deleteAtBeg();break;
        case 7:
            // int pos;
            cout<<"enter the position: ";
            cin>>pos;
            list.deleteAtPos(pos);break;
        
        case 8:
            list.printlist();
            break;
        default:
            break;
        }

    } while (choice!=9);
    return 0;
}