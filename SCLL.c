///////////////////////////////////////////////////////
//Function Name:main
//Input:--
//Output:--
//Description:Create a Singly CircularLinked List in C to perform All functions.
//Date: 15/05/2021
//Author: Shubham Lodha
///////////////////////////////////////////////////////
 //Singly Circular LinkList

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
int iSize=0,i=0;


void InsertFirst(PPNODE Head,PPNODE Tail,int iNo)
{

    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn -> data = iNo;
    newn -> next = NULL;
    
    if((*Head == NULL)&&(*Tail==NULL))
    {
        *Head = newn;
        *Tail = newn;
        (*Tail)->next=*Head;
    }
    else
    {
        newn->next = *Head;
        *Head = newn;
        (*Tail)->next=newn;
    } 
    iSize++;
}

void InsertLast(PPNODE Head,PPNODE Tail,int iNo)
{

    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn -> data = iNo;
    newn -> next = NULL;
    
    if((*Head == NULL)&&(*Tail==NULL))
    {
        *Head = newn;
        *Tail=newn;
    }
    else
    {
    	(*Tail)->next=newn;
    	*Tail=newn;
    }
    (*Tail)->next=*Head; 
     iSize++;
}

void InsertatPos(PPNODE Head,PPNODE Tail,int iNo,int iPos)
{
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
		PNODE temp=*Head;
		PNODE newn=NULL;
		newn=(PNODE)malloc(sizeof(NODE));
		newn->data=iNo;
		newn->next=NULL;

		for(i=1;i<iPos-1;i++)
		{
			temp=temp->next;
		}

		newn->next=temp->next;
		temp->next=newn;
		iSize++;
	}
}

void DeleteFirst(PPNODE Head,PPNODE Tail)
{
	PNODE temp=*Head;

	if(iSize==0)
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
    free(Head);
    (*Tail)->next=*Head;
    iSize--;
    }
}

void DeleteLast(PPNODE Head,PPNODE Tail)
{
	PNODE temp=NULL;

	if(iSize==0)
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
            PNODE temp = *Head;
            
            for(i = 1; i < iSize-1; i++)
            {
                temp = temp -> next;
            }
            free(Tail);
            *Tail = temp;
            (*Tail)->next=*Head;
            iSize--;
            
     }
}

void DeleteatPos(PPNODE Head,PPNODE Tail,int iPos)
{
	if((iPos<1)&&(iPos>iSize))
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
		PNODE temp=*Head;
		PNODE Target=NULL;
		for(i=1;i<iPos-1;i++)
		{
			temp=temp->next;
		}
		
        Target=temp->next;
        temp->next=Target->next;
        free(Target);
		iSize--;
	}
}


void Display(PNODE Head,PNODE Tail)
{ 
  int i=0;
    for(i=1;i<=iSize;i++)
    {
     printf("|%d|=>",Head->data);
      Head=Head->next;
    }
}

int Count(PNODE Head,PNODE Tail)
{
    return iSize;
}

int main()
{
	PNODE First=NULL;
	PNODE Last=NULL;
    int iOption=1,iNo=0,iRet=0,iPos=0;
    
    while(iOption!=0)
    {
    printf("\n__________________________________\n");
    printf("1.Insert Node At First\n");
    printf("2.Insert Node At Last\n");
    printf("3.Insert Node At Position\n");
    printf("4.Delete Node At First\n");
    printf("5.Delete Node At Last\n");
    printf("6.Delete Node At Position\n");
    printf("7.Display The Nodes\n");
    printf("8.Count The number of Nodes\n");
    printf("0.Exit the Applications\n");
    printf("\n___________________________________\n");
    scanf("%d",&iOption);
    
     switch(iOption)    
    {
    	case 1:
    	printf("Enter the number\n");
    	scanf("%d",&iNo);
    	InsertFirst(&First,&Last,iNo);
    	break;

    	case 2:
    	printf("Enter the number\n");
    	scanf("%d",&iNo);
    	InsertLast(&First,&Last,iNo);
    	break;


        case 3:
    	printf("Enter the number\n");
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
    	printf("Contents of Nodes are:\n");
    	Display(First,Last);
    	break;
        
        case 8:
        iRet=Count(First,Last);
    	printf("Number of Nodes Are :%d",iRet);
    	break;
        
        case 0:
    	printf("Thanks for Using Singly Circular Linklist Applications\n");
    	break;

    	default:
    	printf("You Entered Wrong Option");
    	break;
        
    }
  }
  return 0;
}