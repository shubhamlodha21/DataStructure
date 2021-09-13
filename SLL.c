//////////////////////////////////////////////////////////
//Function Name:main//
//Input:--
//Output:--
//Description:Create a Singly Linear Linked List in C to perform All functions.
//Date: 07/05/2021
//Author: Shubham Lodha
///////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;


void InsertFirst(PPNODE Head,int No)
{
	PNODE newn=NULL;
	newn=(PNODE)malloc(sizeof(NODE));
	newn->data=No;
	newn->next=NULL;

	if(*Head==NULL)
	{
		*Head = newn;
	}
	else
	{
	  newn->next=*Head;
	  *Head=newn;
	}
}

void InsertLast(PPNODE Head,int No)
{
	PNODE newn=NULL;
	PNODE temp=*Head;
	newn=(PNODE)malloc(sizeof(NODE));
	newn->data=No;
	newn->next=NULL;

	if(*Head==NULL)
	{
		*Head=newn;
	}
	else
	{
       while(temp->next!=NULL)
       {
       	temp=temp->next;
       }
       temp->next=newn;
	}
}

void Display(PNODE Head)
{
	while(Head!=NULL)
	{
		printf("|%d|->",Head->data);
		Head=Head->next;
	}
	printf("NULL\n");
}

int Count(PNODE Head)
{
	int iCnt=0;
	while(Head!=NULL)
	{
		iCnt++;
		Head=Head->next;
	}
	return iCnt;
}

void DeleteFirst
{
	PNODE temp=*Head;
	
}

int main()
{
	PNODE first =NULL;
	int iRet=0,iOption=1,iValue;

	while(iOption!=0)
	{   
		printf("\n_______________________________\n");
		printf("Enter Your Action on Linked List:\n");
		printf("1.Insert Node at first position\n");
		printf("2.Insert Node at Last position\n");
		printf("3.Insert Node at Given position\n");
		printf("4.Delete Node at first position\n");
		printf("5.Delete Node at Last position\n");
		printf("6.Delete Node at Given position\n");
		printf("7.Display the Content\n");
		printf("8.Count Node of Linked List\n");
		printf("0.Exit Applications");
		printf("\n_______________________________\n");

		scanf("%d",&iOption);

		switch(iOption)
		{
			case 1:
			printf("Enter data to insert:\n");
			scanf("%d",&iValue);
			InsertFirst(&first,iValue);
			break;

			case 2:
			printf("Enter data to insert:\n");
			scanf("%d",&iValue);
			InsertLast(&first,iValue);
			break;

			case 7:
			printf("Nodes of Linked List Are: %d\n",iRet);
			Display(first);
		    break;

		    case 8:
		    iRet = Count(First);
		    printf("Number of Nodes Are: %d".iRet);
		    break;

		    case 0:
		    printf("Exit Your Applications\n");
		    break;

		    default:
		    printf("Enter Valid Option\n");
		    break;
	   }//End Of Switch
    }//End of While

	return 0;
}//End of main
