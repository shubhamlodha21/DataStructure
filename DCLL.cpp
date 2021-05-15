///////////////////////////////////////////////////////
//Function Name:main
//Input:--
//Output:--
//Description:Create a Doubly Circular Linked List in C++ to perform All functions.
//Date: 16/05/2021
//Author: Shubham Lodha
///////////////////////////////////////////////////////
//Doubly Circular LL


#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
}NODE,*PNODE;

class DoublyCL
{
private:
	PNODE Head;
	PNODE Tail;
	int iSize;

public:
	DoublyCL()
	{
		Head=NULL;
		Tail=NULL;
		iSize=0;
	}
	void InsertFirst(int);
	void InsertLast(int);
	void InsertatPos(int,int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteatPos(int);
	void Display();
	int Count();
};

void DoublyCL::InsertFirst(int iNo)
{
	PNODE newn=new NODE;
	newn->next=NULL;
	newn->prev=NULL;
	newn->data=iNo;

  if((Head==NULL)&&(Tail==NULL)) //iSize==0
  {
  	Head=newn;
  	Tail=newn;
  }
  else
  {
  	newn->next=Head;
  	Head->prev=newn;
  	Head=newn;
  }
  Tail->next=Head;
  Head->prev=Tail;
  iSize++;

}
void DoublyCL::InsertLast(int iNo)
{
    PNODE newn=new NODE;
	newn->next=NULL;
	newn->prev=NULL;
	newn->data=iNo;

  if((Head==NULL)&&(Tail==NULL)) //iSize==0
  {
  	Head=newn;
  	Tail=newn;
  }
  else
  {
  	Tail->next=newn;
  	newn->prev=Tail;
  	Tail=newn;
  }
  Tail->next=Head;
  Head->prev=Tail;
  iSize++;

}
void DoublyCL::InsertatPos(int iNo,int iPos)
{
   if((iPos<1)||(iPos>iSize+1))
      {
      	return;
      }

    else if(iPos==1)
    {
    	InsertFirst(iNo);
    }  
    else if(iPos==iSize+1)
    {
    	InsertLast(iNo);
    }
    else
    {
    	PNODE newn=new NODE;
    	newn->data=iNo;
    	newn->next=NULL;
    	newn->prev=NULL;
    	PNODE temp=Head;

    	for(int i=1;i<iPos-1;i++)
    	{
    		temp=temp->next;
    	}
    		newn->next=temp->prev;
    		temp->next->prev=newn;
    		newn->prev=temp;
    		temp->next=newn;
    		iSize++;
    	
    }
}
void DoublyCL::DeleteFirst()
{
  if(iSize==0)
  {
  	return;
  }
  if(iSize==1)
  {
  	delete Head;
  	Head=NULL;
  	Tail=NULL;
  	iSize=0;
  }
  else
  {
  	Head=Head->next;
  	free(Tail->next);//delete(Head->prev);
  	Head->prev=Tail;
  	Tail->next=Head;
  	iSize--;
  }

}
void DoublyCL::DeleteLast()
{
if(iSize==0)
  {
  	return;
  }
  if(iSize==1)
  {
  	delete Head;
  	Head=NULL;
  	Tail=NULL;
  	iSize=0;
  }
  else
  {
  	Tail=Tail->prev;
  	delete(Tail->next);//delete(Head->prev)
  	Head->prev=Tail;
  	Tail->next=Head;
  	iSize--;
  }

}
void DoublyCL::DeleteatPos(int iPos)
{
 if((iPos<1)||(iPos>iSize))
      {
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
    	PNODE temp=Head;

    	for(int i=1;i<iPos-1;i++)
    	{
    		temp=temp->next;
    	}
    	temp->next=temp->next->next;
    	free(temp->next->prev);
    	temp->next->prev=temp;
    	iSize--;
    }

}
void DoublyCL::Display()
{
 PNODE temp=Head;
 for(int i=1;i<=iSize;i++)
 {
     cout<<temp->data<<"\t";
     temp=temp->next;
 }
  cout<<"\n";
}

int DoublyCL::Count()
{
return iSize;
}


int main()
{
	int iChoice=1,iNo=0,iRet=0,iPos=0;

	DoublyCL obj;

	while(iChoice!=0)
	{
		printf("\n___________________\n");
		cout<<"Enter your Choice:\n";
		cout<<"1.Insert Node at First\n";
		cout<<"2.Insert Node at Last\n";
		cout<<"3.Insert Node at Position\n";
		cout<<"4.Delete Node at First\n";
		cout<<"5.Delete Node at Last\n";
		cout<<"6.Delete Node at Position\n";
		cout<<"7.Display the Nodes\n";
		cout<<"8.Count the Nodes\n";
		cout<<"0.Exit The Applications";
        printf("\n___________________\n");
		cin>>iChoice;


		switch(iChoice)
		{
			case 1:
			cout<<"Enter a Number\n";
			cin>>iNo;
			obj.InsertFirst(iNo);
			break;

			case 2:
			cout<<"Enter a Number\n";
			cin>>iNo;
			obj.InsertLast(iNo);
			break;

			case 3:
			cout<<"Enter a Number\n";
			cin>>iNo;
			cout<<"Enter a Position\n";
			cin>>iPos;
			obj.InsertatPos(iNo,iPos);
			break;

			case 4:
			obj.DeleteFirst();
			break;

			case 5:
			obj.DeleteLast();
			break;

			case 6:
			cout<<"Enter a Position\n";
			cin>>iPos;
			obj.DeleteatPos(iPos);
			break;

			case 7:
			cout<<"Elements of LL Are:\n";
			obj.Display();
			break;

			case 8:
			iRet=obj.Count();
			cout<<"Number of Nodes Are:"<<iRet;
			break;

			case 0:
			cout<<"Thanks You for using Applications\n";
			break;

			default:
			cout<<"Enter Wrong Options\n";
			break;
		}

	}

}