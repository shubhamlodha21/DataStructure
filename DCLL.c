///////////////////////////////////////////////////////
//Function Name:main
//Input:--
//Output:--
//Description:Create a Doubly Circular Linked List in C to perform All functions.
//Date: 15/05/2021
//Author: Shubham Lodha
///////////////////////////////////////////////////////
//Doubly Circular LinkList

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;
int iSize=0,i=0;

void InsertFirst(PPNODE Head,PPNODE Tail,int iNo)
{
	PNODE newn=NULL;
	newn=(PNODE)malloc(sizeof(NODE));
	newn->data=iNo;
	newn->next=NULL;
	newn->prev=NULL;

	if((*Head==NULL)&&(*Tail==NULL))
	{
		*Head=newn;
		*Tail=newn;
	}
   
    else
    {
    	newn->next=*Head;
    	(*Head)->prev=newn;
    	*Head=newn;
    }
       (*Head)->prev=*Tail;
       (*Tail)->next=*Head;
       iSize++;
}

void InsertLast(PPNODE Head,PPNODE Tail,int iNo)
{
	PNODE newn=NULL;
	newn=(PNODE)malloc(sizeof(NODE));
	newn->data=iNo;
	newn->next=NULL;
	newn->prev=NULL;

	if((*Head==NULL)&&(*Tail==NULL))
	{
		*Head=newn;
		*Tail=newn;
	}
   
    else
    {
    	(*Tail)->next=newn;
    	newn->prev=(*Tail);
    	*Tail=newn;
    }
       (*Head)->prev=*Tail;
       (*Tail)->next=*Head;
       iSize++;
}

void InsertatPos(PPNODE Head,PPNODE Tail,int iNo,int iPos)
{
	PNODE newn=NULL;
	newn=(PNODE)malloc(sizeof(NODE));
	newn->data=iNo;
	newn->next=NULL;
	newn->prev=NULL;
	PNODE temp=*Head;

	if((iPos<1)||(iPos>iSize+1))
	{
		return;
	}

	else if(iPos==1)
	{
		InsertFirst(Head,Tail,iNo);
	}

	else if(iPos==iSize+1)
	{
		InsertLast(Head,Tail,iNo);
	}

	else
	{
		for(i=1;i<iPos-1;i++)
		{
			temp=temp->next;
		}

		newn->next=temp->next;
		temp->next->prev=newn;
		newn->prev=temp;
		temp->next=newn;
		iSize++;
	}
}

void DeleteFirst(PPNODE Head,PPNODE Tail)
{
	if((*Head==NULL)||(*Tail==NULL))
	{
		return;
	}

	else if(iSize==1)
	{
		free(Head);
		*Head=NULL;
		*Tail=NULL;
		 iSize--;
	}

	else
	{
		*Head=(*Head)->next;
		free((*Head)->prev);
	    (*Head)->prev=*Tail;
        (*Tail)->next=*Head;
        iSize--;
    }
}

void DeleteLast(PPNODE Head,PPNODE Tail)
{
	if((*Head==NULL)||(*Tail==NULL))
	{
		return;
	}

	else if(iSize==1)
	{
		free(Head);
		*Head=NULL;
		*Tail=NULL;
		iSize--;
	}

	else
	{
		*Tail=(*Tail)->prev;
		free((*Tail)->next);
	
	 (*Head)->prev=*Tail;
     (*Tail)->next=*Head;
     iSize--;
    }
}

void DeleteatPos(PPNODE Head,PPNODE Tail,int iPos)
{
	
	PNODE temp=*Head;
	PNODE Target=NULL;
	
	if((iPos<1)||(iPos>iSize))
	{
		return;
	}

	else if(iPos==1)
	{
		DeleteFirst(Head,Tail);
	}

	else if(iPos==iSize)
	{
		DeleteLast(Head,Tail);
	}

	else
	{
		for(i=1;i<iPos-1;i++)
		{
			temp=temp->next;
		}
		Target=temp->next;
		temp->next=Target->next;
		free(Target);
		temp->next->prev=temp;
		iSize--;
	}
}


void Display(PNODE Head,PNODE Tail)
{
	for(i=1;i<=iSize;i++)
	{
		printf("|  %d  |",Head->data);
		Head=Head->next;
	}
}

int Count()
{
	return iSize;
}

int main()
{
	int iOption=1,iRet=0,iPos=0,iNo=0;
	PNODE First=NULL;
	PNODE Last=NULL;

	while(iOption!=0)
	{
		printf("\n_________________________________________\n");
		printf("Enter Your Choice:\n");
		printf("1.Insert Node at First\n");
		printf("2.Insert Node at Last\n");
		printf("3.Insert Node at Positon\n");
		printf("4.Delete Node at First\n");
		printf("5.Delete Node at Last\n");
		printf("6.Delete Node at position\n");
		printf("7.Display the Nodes\n");
		printf("8.Count Numbers of Nodes\n");
		printf("0.Exit The Application\n");
		scanf("%d",&iOption);
		printf("\n_________________________________________\n");


		switch(iOption)
		{
			case 1:
			printf("Enter the Number\n");
			scanf("%d",&iNo);
		    InsertFirst(&First,&Last,iNo);
			break;

			case 2:
			printf("Enter the Number\n");
			scanf("%d",&iNo);
	        InsertLast(&First,&Last,iNo);
			break;

			case 3:
			printf("Enter the Number");
			scanf("%d",&iNo);
			printf("Enter the Position\n");
			scanf("%d",&iPos);
			InsertatPos(&First,&Last,iNo,iPos);
			break;

			case 4:
			DeleteFirst(&First,&Last);
			break;

			case 5:
			DeleteLast(&First,&Last);
			break;

			case 6:
			printf("Enter the Position\n");
			scanf("%d",&iPos);
			DeleteatPos(&First,&Last,iPos);
			break;

			case 7:
			Display(First,Last);
			break;

			case 8:
			iRet=Count();
			printf("Number of Nodes Are:%d\n",iRet);
			break;

			case 0:
			printf("Thanks for Using Doubly Circular LinkList Application\n");
			break;
		}		
	}
	return 0;
}
