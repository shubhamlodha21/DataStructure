//Queue Linked-List(FIFO)

#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE,*PNODE;


class QueueLL
{
    private:
    int iSize;
    PNODE Head;

    public:
    QueueLL();
    ~QueueLL();
    void EnQueue(int);
    int DeQueue();
    int Count();
    void Display();
    int FirstOcc(int);
    int LastOcc(int);
    int NumberofOcc(int);
    int Reverse();
};

QueueLL::QueueLL()//Constructor
{
    iSize=0;
    Head=NULL;
}

QueueLL::~QueueLL()//Destructor
{
    PNODE temp=Head;

    while(temp!=NULL)
    {
        delete temp;
        temp=temp->next;
    }
}

void QueueLL::EnQueue(int iValue)//InsertFirst
{
    PNODE temp=Head;
    PNODE newn=NULL;
    newn=new NODE;
    newn->data=iValue;
    newn->next=NULL;

    if(Head==NULL)
    {
        Head=newn;
    }
    else
    {
        newn->next=Head;
        Head=newn;
    }
    iSize++;
}

int QueueLL::DeQueue() //DeleteFirst
{
    PNODE temp=Head;
    int iRet=-1;

    if(Head==NULL)
    {
        cout<<"Queue is  Empty..!";
        return -1;
    }
    else
    {
        Head=Head->next;
        iRet=temp->data;
        delete temp;
        iSize--;
        return iRet;
    }
}

int QueueLL::Count()
{
   return iSize;
}

void QueueLL::Display()
{
    PNODE temp=Head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
}

int QueueLL::FirstOcc(int iValue)
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


int QueueLL::LastOcc(int iValue)
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

int QueueLL::NumberofOcc(int iValue)
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


int QueueLL::Reverse()
{
    PNODE curr=Head;
    PNODE prev=NULL;
    PNODE nextX=NULL;

    if(curr==NULL)//if Queue is Empty
    {
        return -1;
    }
    else
    {
        for(int i=1;i<=iSize;i++)
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
    int iChoice=1,iNo=0,iRet=0;
    QueueLL obj1;

    while(iChoice!=0)
    {
        printf("\n____________________________\n");
        cout<<"Enter the Choice:"<<"\n";
        cout<<"1:EnQueue the Element"<<"\n";
        cout<<"2:DeQueue the Element"<<"\n";
        cout<<"3:Count the Elements"<<"\n";
        cout<<"4:Display the Elements"<<"\n";
        cout<<"5:First Occarance of Element"<<"\n";
        cout<<"6:Last Occarance of Element"<<"\n";
        cout<<"7:Count Occrance of Perticlar Element"<<"\n";
        cout<<"8:Reverse the Elements"<<"\n";
        cout<<"0.Exit the Application";
        printf("\n_____________________________\n");
        cin>>iChoice;
        
    switch(iChoice)
    {   
        case 1: cout<<"Enter Element You Want Enqueue:";
                cin>>iNo;
                obj1.EnQueue(iNo);
                cout<<"Queue Updated Successfully..!";
                break;

        case 2: iRet=obj1.DeQueue();
                if(iRet==-1)
                cout<<"Queue is Empty";
                else
                cout<<"DeQueue Element is:"<<iRet<<"\n";
                break;

        case 3: iRet=obj1.Count();
                cout<<"Total Number of Elements are:"<<iRet;
                break;

        case 4:cout<<"Nodes are:";
                obj1.Display();
                break;

        case 5:
            cout<<"Enter Number Whose First Occurance You Want:";
            cin>>iNo;
            iRet=obj1.FirstOcc(iNo);
            if(iRet==0)
            {
                cout<<"Element Not Found..!";
            }
            else if(iRet==-1)
            {
                cout<<"Queue is Empty..!";
            }
            else
            {
            cout<<"First Occurance of "<<iNo<<" is at "<<iRet<<" Position "<<"\n";
            }
            break;

        case 6:
            cout<<"Enter Number Whose Last Occurance You Want:";
            cin>>iNo;
            iRet=obj1.LastOcc(iNo);
            if(iRet==0)
            {
                cout<<"Element Not Found..!";
            }
            else if(iRet==-1)
            {
                cout<<"Queue is Empty..!";
            }
            else
            {
            cout<< "Last Occurance of "<<iNo<<" is at "<<iRet<<" Position "<<"\n";
            }
            break;

        case 7:
            cout<<"Enter Number you want Count:";
            cin>>iNo;
            iRet=obj1.NumberofOcc(iNo);
            if(iRet==0)
            {
                cout<<"Element Not Found..!";
            }
            else if(iRet==-1)
            {
                cout<<"Queue is Empty..!";
            }
            else
            {
            cout<< iNo <<" is Present at "<< iRet <<" of times ";
            }
            break;

        case 8:
            iRet=obj1.Reverse();
            if(iRet==-1)
            {
                cout<<"Queue is Empty..!\n";
            }
            else
            {
                cout<<"Queue is Reversed Successfully..!\n";
            }
            break;

                
        case 0:
            cout<<"Thank you for using Queue(LL) application\n";
            break;
                
        default:
            cout<<"Please enter proper option\n";
            break;
    
         }   

    }
}
