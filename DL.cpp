//Doubly Linear Link-List.

#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}NODE,*PNODE;

class DLLL
{
    private:
    int iSize;
    PNODE Head;

    public:
    DLLL();
    ~DLLL();
    void InsertFirst(int);
    void InsertLast(int );
    void InsertAtPos(int,int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
    void Display();
    int Count();
    int FirstOcc(int);
    int LastOcc(int );
    int NumberofOcc(int);
    int Reverse();
};


    DLLL::DLLL()
    {
        iSize=0;
        Head=NULL;
    }

    DLLL::~DLLL()
    {
        PNODE temp=Head;

        for(int i=0;i<iSize;i++)
        {
            temp=temp->next;
            delete temp;
        }
    }

    void DLLL::InsertFirst(int iValue)
    {
        PNODE newn=NULL;
        newn=new NODE;
        newn->data=iValue;
        newn->next=NULL;
        newn->prev=NULL;

        if(Head==NULL)//IF conatins empty LL
        {
            Head=newn;
        }

        else //if LL contains Atleast one node
        {
            newn->next=Head;
            Head->prev=newn;
            Head=newn;
        }

        iSize++;
    }

    void DLLL::InsertLast(int iValue)
    {
        PNODE newn=NULL;
        newn=new NODE;
        newn->data=iValue;
        newn->next=NULL;
        newn->prev=NULL;
        PNODE temp=Head;

        if(Head==NULL)//if Contains Empty LL
        {
            Head=newn;
        }
        else //if LL Contains atleast one node
        {
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newn;
            newn->prev=temp;
        }
        iSize++;
    }

    void DLLL::InsertAtPos(int iValue,int iPos)
    {
        PNODE temp=Head;
        PNODE newn=NULL;
        newn=new NODE;
        newn->data=iValue;
        newn->prev=NULL;
        newn->next=NULL;

        if((iPos<0)||(iPos>iSize+1)) // If position is invalid
        {
            cout<<"InValid Position..!";
            return ;
        }

        else if(iPos==1)  // If position is 1st 
        {
            InsertFirst(iValue);
        }

        else if(iPos==iSize+1) //If Position is Last
        {
            InsertLast(iValue);
        }

        else
        {
            for(int i=1;i<iPos-1;i++)
            {
                temp=temp->next;
            }

            newn->next=temp->next;
            temp->next->prev=newn;
            temp->next=newn;
            newn->prev=temp;
            iSize++;
        }
    }

    void DLLL::DeleteFirst()
    {
        if(Head==NULL)//if LL is Empty
        {
            cout<<"Link-List is Already Empty";
            return;
        }

        else if(Head->next==NULL)// if LL contains only one node
        {
            delete Head;
            Head=NULL;
        }

        else // if LL contains more than one node
        {
            Head=Head->next;
            delete Head->prev;
            Head->prev=NULL;
        }
        iSize--;
    }

    void DLLL::DeleteLast()
    {
        PNODE temp=Head;

          if(Head==NULL)//if LL is Empty
        {
            cout<<"Link-List is Already Empty";
            return;
        }

        else if(Head->next==NULL)// if LL contains only one node
        {
            delete Head;
            Head=NULL;
        }

        else // if LL contains more than one node
        {
            while(temp->next->next!=NULL)
            {
                temp=temp->next;
            }
            delete temp->next;
            temp->next=NULL;
            iSize--;
        }
    }

    void DLLL::DeleteAtPos(int iPos)
    {
        if((iPos<1)||(iPos>iSize))// if position is not valid
        {
            cout<<"Invalid Position..!";
            return;
        }

        else if(iPos==1) // if LL wants delete first position
        {
            DeleteFirst();
        }

        else if(iPos==iSize) // if LL wants delete last position
        {
            DeleteLast();
        }

        else // if wants delete at specific position
        {
            PNODE temp=Head;

            for(int i=1;i<iPos-1;i++)
            {
                temp=temp->next;
            }
            temp->next=temp->next->next;
            delete(temp->next->prev);
            temp->next->prev=temp;
            iSize--;
        }
    }

    int DLLL::Count()
    {
        return iSize;
    }

    void DLLL::Display()
    {
        PNODE temp=Head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"\t";
            temp=temp->next;
        }
        cout<<"NULL"<<"\n";
    }

    int DLLL::FirstOcc(int iValue)
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

    int DLLL::LastOcc(int iValue)
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

    int DLLL::NumberofOcc(int iValue)
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

    int DLLL::Reverse()
    {
        PNODE curr=Head;
        PNODE nextX=NULL;
        PNODE prev=NULL;

        if(Head==NULL)
        {
            return -1; //If LL is Empty
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
    
    int iChoice = 1,iNo = 0,iPos=0,iRet=0;
    
    DLLL obj1;
    
    while(iChoice != 0)
    {
        printf("\n_______________________\n");
        cout<<"Enter your choice :"<<"\n";
        cout<<"1  : Insert at first position "<<"\n";
        cout<<"2  : Insert at last position "<<"\n";
        cout<<"3  : Insert at given position "<<"\n";
        cout<<"4  : Delete first node "<<"\n";
        cout<<"5  : Delete last node "<<"\n";
        cout<<"6  : Delete node at give position "<<"\n";
        cout<<"7  : Display the contents "<<"\n";
        cout<<"8  : Count number of nodes "<<"\n";
        cout<<"9  : Count First Occarance of Node\n";
        cout<<"10 : Count Last Occarance of Node\n";
        cout<<"11 : Count Number of Times Node Occuares\n";
        cout<<"12 : Reverse the Linklist\n";
        cout<<"0  : Exit the application "<<"\n";
        printf("\n_________________________\n");
        cin>>iChoice;
        
        switch(iChoice)
        {
            case 1:
                cout<<"Enter number\n";
                cin>>iNo;
                obj1.InsertFirst(iNo);
                break;
                
            case 2:
                cout<<"Enter number\n";
                cin>>iNo;
                obj1.InsertLast(iNo);
                break;
            
            case 3:
                cout<<"Enter a Number\n";
                cin>>iNo;
                cout<<"Enter a position\n";
                cin>>iPos;
                obj1.InsertAtPos(iNo,iPos);
                break;
            
            case 4:
                obj1.DeleteFirst();
                break;
            
            case 5:
                obj1.DeleteLast();
                break;
                
            case 6:
                cout<<"Enter a position\n";
                cin>>iPos;
                obj1.DeleteAtPos(iPos);
                break;
            
            case 7:
                obj1.Display();
                break;
            
            case 8:
                iNo = obj1.Count();
                cout<<"Number of Nodes are : "<<iNo<<"\n";
                break;

            case 9:
                cout<<"Enter Number Whose First Occurance You Want:";
                cin>>iNo;
                iRet=obj1.FirstOcc(iNo);

                if(iRet==0)
                {
                cout<<"Element Not Found..!"<<"\n";
                }
               else if(iRet==-1)
                {
                cout<<"Linked-List is Empty..!";
                }
                else
                {
                 cout<<"First Occurance of "<<iNo<<" is at "<<iRet<<" Position "<<"\n";
                }
                break;


            case 10:
                cout<<"Enter Number Whose Last Occurance You Want:";
                cin>>iNo;
                iRet=obj1.LastOcc(iNo);

                if(iRet==0)
                {
                cout<<"Element Not Found..!"<<"\n";
                }
               else if(iRet==-1)
                {
                cout<<"Linked-List is Empty..!";
                }
                else
                {
                 cout<<"Last Occurance of "<<iNo<<" is at "<<iRet<<" Position "<<"\n";
                }
                break;


            case 11:
                cout<<"Enter Number you want Count:";
                cin>>iNo;
                iRet=obj1.NumberofOcc(iNo);
               
                if(iRet==0)
                {
                    cout<<"Element Not Found..!";
                }
                else if(iRet==-1)
                {
                    cout<<"Linked-List is Empty..!";
                }
                else
                {
                cout<< iNo <<" is Present at "<< iRet <<" of times ";
                }
                break;

            case 12:
                iRet=obj1.Reverse();
                if(iRet==-1)
                {
                    cout<<"Linklist is  Empty..!";
                }
                else
                {
                    cout<<"Linked List Reverse Successfully..!";
                }
                break;

                
            case 0:
                cout<<"Thank you for using Doubly Linear Linklist application\n";
                break;
                
            default:
                cout<<"Please enter proper option\n";
                break;
        }
    }
    return 0;
}
