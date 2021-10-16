/*input:-arr[]={10,16,4,3,9}
output:- After Quick sort 3 4 9 10 16 
description: Implementation of Quick Sort
date: 01-10-2021
Author name: Shruti Nahar*/
#include <iostream>
using namespace std;
void swap(int arr[],int i,int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
int parition(int arr[],int l,int r)
{
    int pivot=arr[r];
    int i=l-1;
    for(int j=l;j<r;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr,i+1,r);
    return i+1;
}
void quicksort(int arr[],int l,int r)
{
    if(l==r)
    {
        return ;
    }
    if(l<r)
    {
    int pi=parition(arr,l,r);
    quicksort(arr,l,pi-1);
    quicksort(arr,pi+1,r);
    }
}
int main()
{
    int arr[]={10,16,4,3,9};
    int r=sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,r-1);
    cout<<"After Quick Sort ";
    for(int i=0;i<r;i++)
    {
        cout<<arr[i]<<" ";
    }
}