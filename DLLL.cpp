///////////////////////////////////////////////////////
//Function Name:main
//Input:--
//Output:--
//Description:Create a Doubly Linear Linked List in C++ to perform All functions.
//Date: 16/05/2021
//Author: Shubham Lodha
///////////////////////////////////////////////////////
//Doubly Linear LL
 #include<iostream>
 using namespace std;

typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
}NODE,*PNODE;

 class DoublyLL
 {
 private:
    PNODE Head;
    int iSize;
    
public:
    DoublyLL()      // Default constructor
    {
        Head = NULL;
        iSize = 0;
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

void DoublyLL::InsertFirst(int iNo)
{
	PNODE newn=NULL;
	newn=new NODE;
	newn->data=iNo;
	newn->next=NULL;
	newn->prev=NULL;

	if(Head==NULL)
	{
		Head=newn;
	}

	else
	{
		newn->next=Head;
		Head->prev=newn;
		Head=newn;
	}
	iSize++;
}

void DoublyLL::InsertLast(int iNo)
{
	PNODE newn=NULL;
	newn=new NODE;
	newn->data=iNo;
	newn->next=NULL;
	newn->prev=NULL;
	PNODE temp=Head;

	if(Head==NULL)
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
		newn->prev=temp;
	}	
	iSize++;
}

void DoublyLL::InsertatPos(int iNo,int iPos)
{
	if((iPos<1)||(iPos>iSize+1))
	{
		return;
	}

    if(iPos==1)
	{
		InsertFirst(iNo);
	}

	else if(iPos==iSize+1)
	{
		InsertLast(iNo);
	}

	else
	{
		PNODE newn=NULL;
		newn=new NODE;
		newn->data=iNo;
		newn->prev=NULL;
		newn->next=NULL;
		PNODE temp=Head;

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

void DoublyLL::DeleteFirst()
{

   if(iSize==0)
   {
   	return;
   }

   if(iSize==1)
   {
   	delete Head;
   }

   else
   {
   	Head=Head->next;
   	delete Head->prev;
   	Head->prev=NULL;
   }
   iSize--;
}

void DoublyLL::DeleteLast()
{
	PNODE temp=Head;

	if(Head==NULL)
	{
      return;
	}

	else if(Head->next==NULL)
	{
		delete Head;
		Head=NULL;
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

void DoublyLL::DeleteatPos(int iPos)
{
	if((iPos<1)||(iPos>iSize))
	{
		return;
	}

	if(iPos==1)
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
         delete(temp->next->prev);
	     temp->next->prev=temp;
	     iSize--;
	}
}

void DoublyLL::Display()
{
	PNODE temp=Head;
   while(temp!=NULL)
   {
   cout<<temp->data<<"\t";
   temp=temp->next;
   }
   cout<<"\n";
}

int DoublyLL::Count()
{
    return iSize;
}


 int main()
 {
  	int iOption=1,iPos=0,iNo=0,iRet=0;
    
    DoublyLL obj;
  	while(iOption!=0)
  	{

  		printf("\n______________________\n");
  		cout<<"Enter your choice:\n";
  		cout<<"1.Insert Node At First\n";
  		cout<<"2.Insert Node At Last\n";
  		cout<<"3.Insert Node At Position\n";
  		cout<<"4.Delete Node At First\n";
  		cout<<"5.Delete Node At Last\n";
  		cout<<"6.Delete Node At Position\n";
  		cout<<"7.Display Contents of all nodes\n";
  		cout<<"8.Count Numbers of Nodes\n";
  		cout<<"0.Exit the Application\n";
  		printf("\n______________________\n");

  		cin>>iOption;


  		switch(iOption)
  		{
           case 1:
           cout<<"Enter the Elements\n";
           cin>>iNo;
           obj.InsertFirst(iNo);
           break;

           case 2:
           cout<<"Enter the Elements\n";
           cin>>iNo;
           obj.InsertLast(iNo);
           break;

           case 3:
           cout<<"Enter the Elements\n";
           cin>>iNo;
           cout<<"Enter the Position\n";
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
           cout<<"Enter the Position\n";
           cin>>iPos;
           obj.DeleteatPos(iPos);
           break;

           case 7:
           obj.Display();
           break;

           case 8:
          iRet=obj.Count();
           cout<<"Number of Nodes Are:"<<iRet;
           break;

           case 0:
           cout<<"Thanks for Using the Application";
           break;

           default:
           cout<<"You Entered Incorrect Option:";
           break;
  		}
  	}
}