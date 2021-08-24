#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}NODE,*PNODE;

class DCLL
{
    private:
    int iSize;
    PNODE Head;
    PNODE Tail;

    public:
    DCLL();
    ~DCLL();
	void InsertFirst(int no);
    void InsertLast(int no);
    void InsertAtPos(int no,int ipos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int pos);
    void Display();
    int Count();
    int FirstOcc(int no);
    int LastOcc(int no);
    int NumberofOcc(int no);
    int  Reverse();
};


    DCLL::DCLL() //Constructor calls
    {
        iSize=0;
        Head=NULL;
        Tail=NULL;
    }

    DCLL::~DCLL()// Destructors Calls
    {
        PNODE temp=Head;

        for(int i=0;i<iSize;i++)
        {
            temp=temp->next;
            delete temp;
        }
    }

    void DCLL::InsertFirst(int iValue)
    {
        PNODE newn=NULL;
        newn=new NODE;
        newn->data=iValue;
        newn->prev=NULL;
        newn->next=NULL;

        if(Head==NULL)// if LL is empty
        {
            Head=newn;
            Tail=newn;
        }

        else //if LL conatins more than one node
        {
            Head->prev=newn;
            newn->next=Head;
            Head=newn;
        } 
        Head->prev=Tail;
        Tail->next=Head;
        iSize++;
    }

      void DCLL::InsertLast(int iValue)
    {
        PNODE newn=NULL;
        newn=new NODE;
        newn->data=iValue;
        newn->prev=NULL;
        newn->next=NULL;

        if(Head==NULL)// if LL is empty
        {
            Head=newn;
            Tail=newn;
        }

        else //if LL conatins more than one node
        {
            Tail->next=newn;
            newn->prev=Tail;
            Tail=newn;
        } 
        Head->prev=Tail;
        Tail->next=Head;
        iSize++;
    }

    void DCLL::InsertAtPos(int iValue,int iPos)
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

      void DCLL::DeleteFirst()
    {
        if(Head==NULL)//if LL is Empty
        {
            cout<<"Link-List is Already Empty";
            return;
        }

        else if(iSize==1)// if LL contains only one node
        {
            delete Head;
            Head=NULL;
        }

        else // if LL contains more than one node
        {
           Head=Head->next;
           delete Head->prev;
        }
        Head->prev=Tail;
        Tail->next=Head;
        iSize--;
    }

    void DCLL::DeleteLast()
    {
        PNODE temp=Head;

          if(Head==NULL)//if LL is Empty
        {
            cout<<"Link-List is Already Empty";
            return;
        }

        else if(iSize==1)// if LL contains only one node
        {
            delete Head;
            Head=NULL;
        }

        else // if LL contains more than one node
        {
            Tail=Tail->prev;
            delete(Tail->next);
        }
        Head->prev=Tail;
        Tail->next=Head;
        iSize--;
    }

    void DCLL::DeleteAtPos(int iPos)
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
            delete (temp->next->prev);
            temp->next->prev=temp;
            iSize--;
        }

    }

    int DCLL::Count()
    {
        return iSize;
    }

    void DCLL::Display()
    {
        PNODE temp=Head;
        for(int i=0;i<iSize;i++)
        {
            cout<<temp->data<<"\t";
            temp=temp->next;
        }
    
    }

    int DCLL::FirstOcc(int iValue)
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
    }
     return iCnt2;
    }
    }

    int DCLL::LastOcc(int iValue)
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
    }
    return iCnt2;
    }
}

    int DCLL::NumberofOcc(int iValue)
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


    int DCLL::Reverse()
    {
        PNODE curr=Head;
        PNODE prev=NULL;
        PNODE nextX=NULL;

        if(curr==NULL)//if LL is Empty
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
    
    int iChoice = 1,iNo = 0,iPos=0,iRet=0;
    
    DCLL obj1;
    
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
        cout<<"12 : Reverse the Linkedlist\n";
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
                        cout<<"Linked list is Empty..!\n";
                    }
                    else
                    {
                        cout<<"Linked list Reverse Successfully..!\n";
                    }
                    break;

                
            case 0:
                cout<<"Thank you for using Doubly Circular Linklist application\n";
                break;
                
            default:
                cout<<"Please enter proper option\n";
                break;
        }
    }
    return 0;
}
