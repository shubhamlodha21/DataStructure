//Sort the array which contains only 0 , 1 , 2 without using any sorting alogorithms.

#include<bits/stdc++.h>
using namespace std;


void Sort012(int *Arr,int iNo)
{
    sort(Arr,Arr+iNo);//Sort-Element

    cout<<"Sorted list is:";
    for(int i=0;i<iNo;i++)
    {
        cout<<Arr[i]<<"\t";
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

    Sort012(Arr,iNo);

    return 0;
}