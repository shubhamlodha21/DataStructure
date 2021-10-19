//Reverse the Array-List

#include<iostream>
using namespace std;

void Reverse(int Arr[])
{
    int iSize=sizeof(Arr);
    
    cout<<"Array After Reversing is:";
    for(int i=iSize+1;i>=0;i--)
    {
        cout<<Arr[i]<<"\t";
    }
}

int main()
{
    int arr[10]={20,0,88,99,4,55};
    Reverse(arr);
}