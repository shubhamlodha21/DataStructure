#include<iostream>
using namespace std;

void MaxMin(int Arr[])
{
    int iMax=Arr[0];
    int iMin=Arr[0];

    int iSize=sizeof(Arr);
    
    for(int i=iSize+1;i>=0;i--)
    {
        if(Arr[i]>iMax)
        {
            iMax=Arr[i];
        }

        if(Arr[i]<iMin)
        {
            iMin=Arr[i];
        }
    }

    cout<<"Maximun Number is"<<iMax<<"\n";
    cout<<"Minimum Number is"<<iMin<<"\n";
}

int main()
{
    int arr[10]={20,0,88,99,4,55};
    MaxMin(arr);
}