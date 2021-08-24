#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *next;
}NODE,*PNODE;

class SCLL
{
	private:	
		PNODE Head;
		PNODE Tail;
		int iSize;

	public:
		SCLL();
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
		int Reverse();
};


 	SCLL::SCLL()
 	{
 		Head=NULL;
 		Tail=NULL;
 		iSize=0;
 	}

 	void SCLL::InsertFirst(int iValue)
 	{
 		PNODE newn=NULL;
 		newn=new NODE;
 		newn->data=iValue;
 		newn->next=NULL;

 		if((Head==NULL)&&(Tail==NULL))
 		{
 			Head=newn;
            Tail=newn;
 		}
 		else
 		{
 			newn->next=Head;
 			Head=newn;
 		}
 		iSize++;
 		Tail->next=Head;
 	}

 	void SCLL::InsertLast(int iValue)
 	{
 		PNODE newn=NULL;
 		newn=new NODE;
 		newn->data=iValue;
 		newn->next=NULL;

 		if((Head==NULL)&&(Tail==NULL))
 		{
 			Head=newn;
 		}
 		else
 		{

 			Tail->next=newn;
 			Tail=newn;
 		}
 		iSize++;
 		Tail->next=Head;
 	}

 	void SCLL::InsertAtPos(int iValue,int iPos)
 	{
 		PNODE newn=NULL;
 		newn=new NODE;
 		newn->data=iValue;
 		newn->next=NULL;
 		PNODE temp=Head;

 		if((iPos<1)&&(iPos>iSize+1))
 		{
 			cout<<"Invalid position";
 			return;
 		}

 		else if (iPos==1)
 		{
 			InsertFirst(iValue);
 		}

 		else if(iPos==iSize+1)
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


 	void SCLL::DeleteFirst()
 	{
 		if((Head==NULL)&&(Tail==NULL))
 		{
 			cout<<"Linked-List is Already Empty..!";
 			return;
 		}

 		else if(iSize==1)
 		{
 			delete Head;
 			Head=NULL;
 			Tail=NULL;
 			iSize--;

 		}

 		else
 		{
 			Head=Head->next;
 			delete (Tail->next);
 			Tail->next=Head;
 			iSize--;
 		}
 	}

 	void SCLL::DeleteLast()
 	{
 		PNODE temp=Head;
 		if(iSize==0)
 		{
 			cout<<"Linked-List is Already Empty..!";
 			return;
 		}

 		else if(iSize==1)
 		{
 			delete Head;
 			Head=NULL;
 			Tail=NULL;
 			iSize--;
 		}

 		else
 		{
 			for(int i=1;i<iSize-1;i++)
 			{
 				temp=temp->next;
 			}
 			delete Tail;
 			Tail=temp;
 			Tail->next=Head;
 			iSize--;
 		}
 	}

 	void SCLL::DeleteAtPos(int iPos)
 	{
 		PNODE temp=Head;
 		PNODE target=NULL;

 		if((iPos<1)||(iPos>iSize))
 		{
 			cout<<"Invalid position";
 			return;
 		}

 		else if(iPos==1)
 		{
 			DeleteFirst();
 		}

 		else if(iPos==iSize)
 		{
 			DeleteLast();
 		}

 		else
 		{
 			for(int i=1;i<iPos-1;i++)
 			{
 				temp=temp->next;
 			}
 			target=temp->next;
 			temp->next=target->next;
 			delete target;
 			iSize--;
 			Tail->next=Head;
 		}
 	}

 	int SCLL::Count()
 	{
 		return iSize;
 	}

 	void SCLL::Display()
 	{
 		PNODE temp=Head;
 		for(int i=1;i<=iSize;i++)
 		{
 			cout<<"|"<<temp->data<<"|"<<"->";
 			temp=temp->next;
 		}
 	}

 	int SCLL::FirstOcc(int iValue)
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

    int SCLL::LastOcc(int iValue)
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

    int SCLL::NumberofOcc(int iValue)
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

	int SCLL::Reverse()
	{
		PNODE curr=Head;
		PNODE prev=NULL;
		PNODE nextX=NULL;

		if(Head==NULL)//if LL is Empty
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
    
    SCLL obj1;
    
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
					cout<<"Linked List is Empty..!";
				}
				else
				{
					cout<<"Linked List Reverse Successfully..!";
				}
				break;
                
            case 0:
                cout<<"Thank you for using Singly Circular Linklist application\n";
                break;
                
            default:
                cout<<"Please enter proper option\n";
                break;
        }
    }
    return 0;
}


