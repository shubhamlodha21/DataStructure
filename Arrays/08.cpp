//Find kth Maximum-Minimum Element of array

#include<bits/stdc++.h>
using namespace std;

void MaxMin(int *Arr,int iNo,int max,int min)
{

    sort(Arr,Arr+iNo);

    for(int i=0;i<iNo;i++)
    {
        if(i==min-1)
        {
            cout<<"Element at minimum position is:"<<Arr[i]<<endl;
            continue;
        }

        else if(i==(iNo-(max)))
        {
            cout<<"Element at maximum position is:"<<Arr[i]<<endl;
        }
    }

}

int main()
{
    int iNo=0,iMin=0,iMax=0;
    int *Arr=new int;

    cout<<"Enter number of Elements:";
    cin>>iNo;

    cout<<"Enter Elements";
    for(int i=0;i<iNo;i++)
    {
        cin>>Arr[i];
    }

    cout<<"Enter position for maximum number:";
    cin>>iMax;

    cout<<"Enter position for minimum number";
    cin>>iMin;

    MaxMin(Arr,iNo,iMax,iMin);

    return 0;
}