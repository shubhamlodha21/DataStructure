//Stack with Array


#include<iostream>
#include<stdlib.h>
using namespace std;

class StackArray
{
    private:
    int *Arr;
    int iTop;
    int iSize;

    public:
    void Size(int);
    StackArray();
    ~StackArray();
    void Push(int);
    int Pop();
    int Peek();
    int Display();
    int FirstOcc(int);
    int LastOcc(int);
    int NumberofOcc(int);
};

void StackArray::Size(int iNo)
{
    Arr=new int[iNo];
    iSize=iNo;
}

StackArray::StackArray()
{
    iTop=-1;
}

StackArray::~StackArray()
{
    delete []Arr;
    iTop=-1;
}

void StackArray::Push(int iNo)
{
    if(iTop==iSize-1)
    {
        cout<<"Sorry...Stack is Full...!"<<"\n";
        return;
    }
    else
    {
        iTop++;
        Arr[iTop]=iNo;
    }
}

int StackArray::Pop()
{
    if(iTop==-1)
    {
        cout<<"Stack is Empty..!";
        return -1;
    }
    else
    {
        int iNo=Arr[iTop];
        iTop--;
        return iNo;
    }
}

int StackArray::Peek()
{
    int iNo=0;
    if(iTop==-1)
    {
        cout<<"Stack is Empty..!";
        return 0;

    }
    else
    {
        iNo=Arr[iTop];
    }
    return iNo;
}

int StackArray::Display()
{
    if(iTop==-1)
    {
        return -1;
    }
    else
    {
        for(int i=0;i<=iTop;i++)
        {
            cout<<Arr[i]<<"\t";
        }
        cout<<"\n";
    }
    return 0;
}

int StackArray::FirstOcc(int iNo)
{
    int iCnt=0;

    if(iTop==-1)
    {
        return -1;
    }
    else
    {
        for(int i=0;i<=iTop;i++)
        {
            if(Arr[i]==iNo)
            {
                iCnt=i+1;
                break;
            }
        }
    }
    return iCnt;
}

int StackArray::LastOcc(int iNo)
{
    int iCnt=0;

    if(iTop==-1)
    {
        return -1;
    }
    else
    {
        for(int i=0;i<=iTop;i++)
        {
            
            if(Arr[i]==iNo)
            {
                iCnt=i+1;
            }
        }
    }
    return iCnt;
}

int StackArray::NumberofOcc(int iNo)
{
    int iCnt=0;

    if(iTop==-1)
    {
        return -1;
    }
    else
    {
        for(int i=0;i<=iTop;i++)
        {
            
            if(Arr[i]==iNo)
            {
                iCnt++;
            }
        }
    }
    return iCnt;
}

int main()
{

    int iValue=0,iNo=0,iRet=0,iChoice=1;

    cout<<"Enter Size of Array:";
    cin>>iValue;
    StackArray obj1;

    obj1.Size(iValue);
    while (iChoice!=0)
    {
        printf("\n_________________________\n");
        cout<<"Enter Your Choice:"<<"\n";
        cout<<"1:Push the Element"<<"\n";
        cout<<"2:Pop the Element"<<"\n";
        cout<<"3:Peek the Element"<<"\n";
        cout<<"4.Display the Elements"<<"\n";
        cout<<"5:First Occarance of Element"<<"\n";
        cout<<"6:Last Occarance of Element"<<"\n";
        cout<<"7:Count Occarance of Perticular Element\n";
        cout<<"0: Exit the application "<<"\n";
        printf("\n____________________________\n");
        cin>>iChoice;
    

    switch(iChoice)
    {
        case 1: cout<<"Enter Element You Want Push:";
                cin>>iNo;
                obj1.Push(iNo);
                break;

        case 2: iRet=obj1.Pop();
                if(iRet==-1)
                cout<<"Stack is Empty";
                else
                cout<<"Pop Element is:"<<iRet<<"\n";
                break;

        case 3: iRet=obj1.Peek();
                cout<<"Peek Element is:"<<iRet<<"\n";
                break;

        case 4:cout<<"Nodes are:\n";
                obj1.Display();
                break;

        case 5:
            cout<<"Enter Number Whose First Occurance You Want:";
            cin>>iNo;
            iRet=obj1.FirstOcc(iNo);
            if(iRet==0)
            {
                cout<<"Element Not Found..!";
            }
            else if(iRet==-1)
            {
                cout<<"Stack is Empty..!";
            }
            else
            {
            cout<<"First Occurance of "<<iNo<<" is at "<<iRet<<" Position "<<"\n";
            }
            break;

        case 6:
            cout<<"Enter Number Whose Last Occurance You Want:";
            cin>>iNo;
            iRet=obj1.LastOcc(iNo);
            if(iRet==0)
            {
                cout<<"Element Not Found..!";
            }
            else if(iRet==-1)
            {
                cout<<"Stack is Empty..!";
            }
            else
            {
            cout<< "Last Occurance of "<<iNo<<" is at "<<iRet<<" Position "<<"\n";
            }
            break;

        case 7:
            cout<<"Enter Number you want Count:";
            cin>>iNo;
            iRet=obj1.NumberofOcc(iNo);
            if(iRet==0)
            {
                cout<<"Element Not Found..!";
            }
            else if(iRet==-1)
            {
                cout<<"Stack is Empty..!";
            }
            else
            {
            cout<< iNo <<" is Present at "<< iRet <<" of times ";
            }
            break;
                
        case 0:
            cout<<"Thank you for using Stack(Array) Application\n";
            break;
                
        default:
            cout<<"Please enter proper option\n";
            break;

        }
    }    
}