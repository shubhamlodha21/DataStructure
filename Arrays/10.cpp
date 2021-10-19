//Move all negative numbers on left side of array


#include<bits/stdc++.h>
using namespace std;

void Move(int *Arr,int iNo)
{   
    int j=0;
    for(int i=0;i<iNo;i++)
    {
        if(Arr[i] < 0)
        {
           swap(Arr[i],Arr[j]);
            j++;
        }
       
    }

    cout<<"After Moving elements are:";
    for(int i=0;i<iNo;i++)
    {
        cout<<Arr[i]<<"\n";
    }
}

int main()
{
    int iNo=0;
    int *Arr=new int;

    cout<<"Enter number of Elements:";
    cin>>iNo;

    cout<<"Enter Elements";
    for(int i=0;i<iNo;i++)
    {
        cin>>Arr[i];
    }

    Move(Arr,iNo);

    return 0;
}