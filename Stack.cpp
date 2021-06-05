///////////////////////////////////////////////////////
//Function Name:main
//Input:--
//Output:--
//Description:Implementation of Stack
//Date: 05/06/2021
//Author: Shubham Lodha
///////////////////////////////////////////////////////

#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE, * PNODE;

class Stack
{
private:
    PNODE Head;
    int iSize;
    
public:
    Stack();                // Constructor
    ~Stack();              // Destructor
    void Push(int);     //  void InsertFirst(int)
    int Pop();              // void DeleteFirst();
    int Peek();             // Just return the value without removing the node
    void Display();
    int Count();
};

Stack::Stack()  // Constructor
{
    cout<<"Inside Constructor\n";
    this->Head = NULL;  // Head = NULL;
    this->iSize = 0;
}

Stack::~Stack()
{
    cout<<"Inside Destructor\n";
    PNODE temp = NULL;
    
    while(Head != NULL)
    {
        temp = Head;
        Head = Head -> next;
        delete temp;
    }
}

void Stack::Push(int iNo)   // IsnertFirst
{
    PNODE newn = new NODE;
    newn->data = iNo;
    newn->next = NULL;
    
    newn->next = Head;
    Head = newn;
    iSize++;
}

int Stack::Pop()    // DeleteFirst
{
    int iRet = -1;
    
    if(iSize == 0)
    {
        cout<<"Stack is empty\n";
    }
    else
    {
        PNODE temp = Head;
        Head = Head -> next;
        iRet = temp->data;
        delete temp;
        iSize--;
    }
    return iRet;
}

int Stack :: Peek()
{
        if(iSize == 0)
        {
            cout<<"Stack is empty";
            return -1;
        }
        else
        {
            return Head->data;
        }
}

void Stack:: Display()
{
    PNODE temp = Head;
    
    while(temp != NULL)
    {
        cout<<temp->data<<"\t";
        temp = temp -> next;
    }
    cout<<"\n";
}

int Stack::Count()
{
    return this->iSize;
}

int main()
{
    Stack *sobj = new Stack;  //Stack sobj;         It implicitelly calls the constrctor
    int iOption =1, iRet = 0, iNo = 0;
    
    while(iOption != 0)
    {
        cout<<"Please select the option\n";
        cout<<"1 : Push the element\n";
        cout<<"2 : Pop the element\n";
        cout<<"3 : Display the elements\n";
        cout<<"4 : Count number of elements\n";
        cout<<"5 : Peek the emenet\n";
        cout<<"0 : Exit the aplication\n";
        cin>>iOption;
        
        switch(iOption)
        {
            case 1:
                cout<<"Enter the element to push\n";
                cin>>iNo;
                sobj->Push(iNo);
                break;
                
            case 2 :
                iRet = sobj->Pop();
                cout<<"Poped element is : "<<iRet<<"\n";
                break;
                
            case 3:
                cout<<"Elements of stack are\n";
                sobj->Display();
                break;
                
            case 4:
                iRet = sobj->Count();
                cout<<"Number of elements in stack are : "<<iRet<<"\n";
                break;
                
            case 5 :
                iRet = sobj->Peek();
                cout<<"Value of top element is : "<<iRet<<"\n";
                break;
                
            case 0:
                cout<<"Thank you for using the applicatoion\n";
                delete sobj;        // It implecitelly calls the destructor
                break;
                
            default:
                cout<<"Please enter the proper option\n";
                break;
        }// End of switch
    } // End of while
    return 0;
}   // End of main

// Stack *arr = new Stack[iNo];
// arr[0].Push(11);
