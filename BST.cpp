////////////////////////////////////////////////////////
//Function Name:BST
//Input:--
//Output:--
//Description: Implementation of Binary Search Tree
//Date: 04/09/2021
//Author: Shubham Lodha
///////////////////////////////////////////////////////



#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
}NODE,*PNODE,**PPNODE;

class BST
{
    private:
    PNODE Head;
    int iSize;

    public:
    BST();
    void InsertNode(PPNODE,int);
    void Inorder(PNODE);
    void PreOrder(PNODE);
    void PostOrder(PNODE);
    int Count();
    void CountParent(PNODE,int *);
    void CountLeaf(PNODE,int *);
    bool SearchNode(PNODE,int);
};


BST::BST()//Constructor
{
    Head=NULL;
    iSize=0;
}

void BST::InsertNode(PPNODE root,int iNo)
{
    PNODE temp=Head;
    PNODE newn=NULL;
    newn=new NODE;
    newn->data=iNo;
    newn->lchild=NULL;
    newn->rchild=NULL;

    if(Head==NULL)//If EMpty node contains 
    {
        Head=newn;
        *root=Head;
        iSize++;
    }
    else
    {
        while(1)
        {
            if(iNo > temp->data)//if Data is less than current root
            {
                if(temp->rchild==NULL)
                {
                temp->rchild=newn;
                iSize++;
                break;
                }
                temp=temp->rchild;
            }
            else if(iNo < temp->data)//if Data is greater than current root
            {
                if(temp->lchild==NULL)
                {
                    temp->lchild=newn;
                    iSize++;
                    break;
                }
                temp=temp->lchild;
            }
            else //if Data is already  
            {
                cout<<"Duplicate Data Not Allowed..!";
                delete newn;
                break;
            }

        }      
    }
}

void BST::Inorder(PNODE temp)
{
    if(temp!=NULL)
    {
        Inorder(temp->lchild);    // L
        cout<<temp->data<<"\t";  // D
        Inorder(temp->rchild);  // R
    }
}

void BST::PreOrder(PNODE temp)
{
    if(temp!=NULL)
    {
        cout<<temp->data<<"\t";//D
        PreOrder(temp->lchild);//L
        PreOrder(temp->rchild);//R
    }
}

void BST::PostOrder(PNODE temp)
{
    if(temp!=NULL)
    {
        PostOrder(temp->lchild);//L
        PostOrder(temp->rchild);//R
        cout<<temp->data<<"\t";//D
    }
}

int BST::Count()
{
    return iSize;
}

void BST::CountLeaf(PNODE temp,int *i)
{
    if(temp!=NULL)
    {
        if((temp->lchild==NULL)&&(temp->rchild==NULL))
        {
            (*i)++;
        }
        CountLeaf(temp->lchild,i);
        CountLeaf(temp->rchild,i);
    }
}

void BST::CountParent(PNODE temp,int *i)
{
    if(temp!=NULL)
    {
        if((temp->lchild!=NULL)||(temp->rchild!=NULL))
        {
            (*i)++;
        }
        CountLeaf(temp->lchild,i);
        CountLeaf(temp->rchild,i);
    }
}

bool BST::SearchNode(PNODE temp,int iNo)
{
    if(temp)
    {
        if(iNo > temp->data)
        {
            return SearchNode(temp->rchild,iNo);
        }
        else if(iNo < temp->data)
        {
            return SearchNode(temp->lchild,iNo);
        }
        else if(iNo== temp->data)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}



int main()
{
    int iNo=0,iRet=0,iChoice=1,i=0;
    bool bRet=false;
    PNODE root=NULL;
    BST obj;

    while(iChoice!=0)
    {
    printf("\n_______________________________\n");
    cout<<"Enter Your Choice:"<<"\n";
    cout<<"1.Insert Node"<<"\n";
    cout<<"2.Display Inorder"<<"\n";
    cout<<"3.Display Preorder"<<"\n";
    cout<<"4.Display Postorder"<<"\n";
    cout<<"5.Count Total Nodes"<<"\n";
    cout<<"6.Count Parent Nodes"<<"\n";
    cout<<"7.Count Leaf Nodes"<<"\n";
    cout<<"8.Search Node"<<"\n";
    cout<<"0.Exit the Application"<<"\n";
    printf("\n____________________________________\n");
    cin>>iChoice;

    switch(iChoice)
    {
        case 1:
        cout<<"Enter Node You Want Add:"<<"\n";
        cin>>iNo;
        obj.InsertNode(&root,iNo);
        break;

        case 2:
        cout<<"Nodes in Inorder sequence are:"<<"\n";
        obj.Inorder(root);
        break;

        case 3:
        cout<<"Nodes in Preorder Sequence are:"<<"\n";
        obj.PreOrder(root);
        break;

        case 4:
        cout<<"Nodes in Postorder Sequence are:"<<"\n";
        obj.PostOrder(root);
        break;

        case 5:
        iRet=obj.Count();
        cout<<"Total Number of Nodes are:"<<iRet;
        break;

        case 6:
        i=0;
        obj.CountParent(root,&i);
        cout<<"Total Number of Parent Nodes are:"<<i;
        break;

        case 7:
        i=0;
        obj.CountLeaf(root,&i);
        cout<<"Total Number of Leaf Nodes are:"<<i;
        break;

        case 8:
        cout<<"Enter Node You Want Search:";
        cin>>iNo;
        bRet=obj.SearchNode(root,iNo);
        if(bRet==true)
        {
            cout<<iNo<<"Node is Present";
        }
        else
        {
            cout<<iNo<<"Node is not Present";
        }
        break;

        case 0:
        cout<<"Thanks for using Binary Search Tree(BST) Application"<<"\n";
        break;

        default:
        cout<<"Please Select Correct option..!";
        break;
        }
    }
}
