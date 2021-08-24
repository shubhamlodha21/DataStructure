//Singly Linear LinkedList


#include<iostream>
using namespace std;


typedef struct node
{
    int data;
    struct node *next;
}NODE,*PNODE;


class SLLL
{
    private:
    PNODE Head;
    int iSize;

    public:
    SLLL();
    ~SLLL();
    void InsertFirst(int);
    void InsertLast(int);
    void InsertAtPos(int,int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
    void Display();
    int Count();
    int FirstOcc(int);
    int LastOcc(int);
    int NumberofOcc(int);
    int Reverse();
};

    SLLL::SLLL() //Constructor 
    {
        Head=NULL;
        iSize=0;
    }

    SLLL::~SLLL()// Destructor
    {
        PNODE temp = NULL;

        for(int i = 1; i <= iSize; i++) 
        {
            temp = Head;
            temp=temp->next;
            delete temp;
        }
    }

    void SLLL::InsertFirst(int iValue)
    {
        PNODE newn=NULL;
        newn=new NODE;
        newn->data=iValue;
        newn->next=NULL;

        if(Head==NULL)//if LL is Empty
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

    void SLLL::InsertLast(int iValue)
    {
        PNODE newn=NULL;
        PNODE temp=Head;
        newn=new NODE;
        newn->data=iValue;
        newn->next=NULL;

        if(Head==NULL)//if LL is Empty

        {
            newn=Head;
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

    
    void SLLL::InsertAtPos(int iValue,int iPos)
    {
        PNODE newn;
        PNODE temp=Head;
        newn=new NODE;
        newn->data=iValue;
        newn->next=NULL;

        if((iPos<1)||(iPos>(iSize+1)))//if Position is Invalid
        {
            cout<<"Invalid Position..!";
            return;
        }
        else if(iPos==1)//if Position is 1
        {
            InsertFirst(iValue);
        }
        else if(iPos==iSize+1)//if Position is Last
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
            temp->next=newn;
            iSize++;
        }
    }

    void SLLL::DeleteFirst()
    {
        PNODE temp=Head;

        if(Head==NULL)//if LL is Empty
         
        {
            cout<<"LinkList is Already Empty..!";
            return;
        }
        else if(Head->next==NULL)
        {
            delete Head;
            Head=NULL;
            iSize--;
        }
        else
        {
            Head=Head->next;
            delete temp;
            iSize--;
        }
    }

    void SLLL::DeleteLast()
    {
        PNODE temp=Head;

        if(Head==NULL)//if  LL is Empty
        {
            cout<<"LinkList is Already Empty..!";
            return;
        }
        else if(Head->next==NULL)
        {
            delete Head;
            Head=NULL;
            iSize--;
        }
        else
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

    void SLLL::DeleteAtPos(int iPos)
    {
        PNODE temp=Head;
        PNODE target=NULL;

        if((iPos<0) ||(iPos>iSize))//if Position is invalid
        {
            cout<<"Invalid Position";
            return;
        }
        else if(iPos==1)//if position 1
        {
            DeleteFirst();
        }
        else if(iPos==iSize)//if position is last
        {
            DeleteLast();
        }
        else
        {
            for(int i=0;i<iPos-1;i++)
            {
                temp=temp->next;
            }
            target=temp->next;
            temp->next=target->next;
            delete target;
            iSize--;
        }
        
    }

    int SLLL::Count()
    {
        return iSize;
    }

    void SLLL::Display()
    {
        PNODE temp=Head;
        while(temp!=NULL)
        {
            cout<<"|" <<temp->data <<"|->"<<"\t";
            temp=temp->next;
        }
            cout<<"NULL"<<"\t";
        cout<<"\n";
    }
    
    int SLLL::FirstOcc(int iValue)
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

    int SLLL::LastOcc(int iValue)
    {
    int iCnt1=0,iCnt2=0;
    PNODE temp=Head;
    
        if(Head==NULL)//if LL is empty
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

    int SLLL::NumberofOcc(int iValue)
    {
    int iCnt=0;
    PNODE temp=Head;

    if(Head==NULL)//if LL is empty
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

    int SLLL::Reverse()
    {
       PNODE curr=Head;
       PNODE prev=NULL;
       PNODE nextX=NULL;

       if(curr==NULL)//if LL is Empty
       {
           return -1;
       }

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

int main()
{
    int iChoice = 1,iNo = 0,iPos=0,iRet=0;
    
    SLLL obj1;
    
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
        cout<<"12 : Reverse the Nodes\n";
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
                cout<<"Data Removed Succesfully..!";
                break;
            
            case 5:
                obj1.DeleteLast();
                cout<<"Data Removed Succesfully..!";
                break;
                
            case 6:
                cout<<"Enter a position\n";
                cin>>iPos;
                obj1.DeleteAtPos(iPos);
                cout<<"Data Removed Succesfully..!";
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
                cout<<"Linked-List is Empty..!";
                else
                cout<<"Linklist Reverse Successfully..!";
                break;
                
            case 0:
                cout<<"Thank you for using Singly Linear Linklist application\n";
                break;
                
            default:
                cout<<"Please enter proper option\n";
                break;
        }
    }
    return 0;
}
