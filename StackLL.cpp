//Stack(Linked-List) LIFO(Last in First Out)

#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE,*PNODE;

class StackLL
{
private:
    int iSize;
    PNODE Head;

public:
    StackLL();
   ~StackLL();
    void Push(int);
    int Pop();
    int Peek();
    int Count();
    void Display();
    int FirstOcc(int);
    int LastOcc(int);
    int NumberofOcc(int);
    int Reverse();

};

StackLL::StackLL()//Constrcutor
{
    this->iSize=0;
    this->Head=NULL;
}

StackLL::~StackLL()//Destructor
{
    PNODE temp=Head;

    for(int i=1;i<=iSize;i++)
    {
        delete temp;
        temp=temp->next;
    }
}

void StackLL::Push(int iValue)//InsertLast
{
    PNODE newn=NULL;
    newn=new NODE;
    newn->data=iValue;
    newn->next=NULL;
    PNODE temp=Head;

    if(Head==NULL)//if LL is Empty
    {
        Head=newn;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
    }
    iSize++;
    
}

int StackLL::Pop()//DeleteFirst
{
    int iRet=-1;

    if(iSize==0)// If LL is Empty
    {
        cout<<"Stack is Empty..!";
        return iRet;
    }

    else
    {
        PNODE temp=Head;
        Head=Head->next;
        iRet=temp->data;
        delete temp;
        iSize--;
        return iRet;
    }
}

int StackLL::Peek()
{

	if(iSize==0)
	{
		cout<<"Stack is Empty...!";
		return -1;
	}
	else
	{
		return Head->data;
	}
}

int StackLL::Count()
{
    return this->iSize;
}

void StackLL::Display()
{
    PNODE temp=Head;

    while(temp!=NULL)
    {
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
}

int StackLL::FirstOcc(int iValue)
{
    int iCnt1=0,iCnt2=0;
    PNODE temp=Head;

    if(Head==NULL)
    {
        return -1;
    }
    else
    {
    for(int i=1;i<=iSize;i++)
    {
        iCnt1++;
        if(temp->data==iValue)
        {
            iCnt2=iCnt1;
            break;
        }
        temp=temp->next;
    }
     return iCnt2;
    }
}

int StackLL::LastOcc(int iValue)
{
    int iCnt1=0,iCnt2=0;
    PNODE temp=Head;
    
    if(Head==NULL)
    {
        return -1;
    }
    else
    {
    for(int i=1;i<=iSize;i++)
    {
        iCnt1++;
        if(temp->data==iValue)
        {
            iCnt2=iCnt1;
        }
        temp=temp->next;
    }
    return iCnt2;
    }
}

int StackLL::NumberofOcc(int iValue)
{
    int iCnt=0;
    PNODE temp=Head;

    if(Head==NULL)
    {
        return -1;
    }

    else
    {
    while(temp!=NULL)
    {
        if(temp->data==iValue)
        {
            iCnt++;
        }
        temp=temp->next;
    }
    return iCnt;
    }
}

int StackLL::Reverse()
{
    PNODE curr=Head;
    PNODE prev=NULL;
    PNODE nextX=NULL;

    if(Head==NULL)//if stack is Empty
    {
        return -1;
    }
    else // if stack contains more than one node
    {
        while(curr!=NULL)
        {
            nextX=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextX;
        }
        Head=prev;
        return 0;
    }

}

int main()
{
    int iChoice=1,iNo=0,iRet=0,iRet1=0;
    StackLL obj1;

    while (iChoice!=0)
    {
        printf("\n_________________________\n");
        cout<<"Enter Your Choice:"<<"\n";
        cout<<"1:Push the Element"<<"\n";
        cout<<"2:Pop the Element"<<"\n";
        cout<<"3:Peek the Element"<<"\n";
        cout<<"4.Count the Number of Elements"<<"\n";
        cout<<"5.Display the Elements"<<"\n";
        cout<<"6:First Occarance of Element"<<"\n";
        cout<<"7:Last Occarance of Element"<<"\n";
        cout<<"8:Count Occarance of Perticular Element\n";
        cout<<"9.Reverse the Linked List\n";
        cout<<"0: Exit the application "<<"\n";
        printf("\n____________________________\n");
        cin>>iChoice;
    

    switch(iChoice)
    {
        case 1: cout<<"Enter Element You Want Push:";
                cin>>iNo;
                obj1.Push(iNo);
                cout<<"Stack Updated Successfully..!";
                break;

        case 2: iRet=obj1.Pop();
                if(iRet==-1)
                cout<<"Stack is Empty";
                else
                cout<<"Pop Element is:"<<iRet<<"\n";
                break;

        case 3: iRet=obj1.Peek();
                cout<<"Peek Element is:"<<iRet<<"\n";
             
                break;

        case 4: iRet=obj1.Count();
                cout<<"Total Number of nodes are:"<<iRet;
                break;

        case 5:cout<<"Nodes are:\n";
                obj1.Display();
                break;

        case 6:
            cout<<"Enter Number Whose First Occurance You Want:";
            cin>>iNo;
            iRet=obj1.FirstOcc(iNo);
            if(iRet==0)
            {
                cout<<"Element Not Found..!";
            }
            else if(iRet==-1)
            {
                cout<<"Stack is Empty..!";
            }
            else
            {
            cout<<"First Occurance of "<<iNo<<" is at "<<iRet<<" Position "<<"\n";
            }
            break;

        case 7:
            cout<<"Enter Number Whose Last Occurance You Want:";
            cin>>iNo;
            iRet=obj1.LastOcc(iNo);
            if(iRet==0)
            {
                cout<<"Element Not Found..!";
            }
            else if(iRet==-1)
            {
                cout<<"Stack is Empty..!";
            }
            else
            {
            cout<< "Last Occurance of "<<iNo<<" is at "<<iRet<<" Position "<<"\n";
            }
            break;

        case 8:
            cout<<"Enter Number you want Count:";
            cin>>iNo;
            iRet=obj1.NumberofOcc(iNo);
            if(iRet==0)
            {
                cout<<"Element Not Found..!";
            }
            else if(iRet==-1)
            {
                cout<<"Stack is Empty..!";
            }
            else
            {
            cout<< iNo <<" is Present at "<< iRet <<" of times ";
            }
            break;

        case 9:
            iRet=obj1.Reverse();
            if(iRet==-1)
            {
                cout<<"Stack is Empty..!";
            }
            else
            {
                cout<<"Stack is Reverse Successfully..!";
            }
            break;

                
        case 0:
            cout<<"Thank you for using Stack(LL) application\n";
            break;
                
        default:
            cout<<"Please enter proper option\n";
            break;

        }
    }    
}