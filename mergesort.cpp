/*input:- arr[10]={8,5,1,3,4,2,6,7,9,10};
output:- After Merge sort 1 2 3 4 5 6 7 8 9 10 
description: Implementation of Merge Sort
date: 01-10-2021
Author name: Shruti Nahar*/
#include<iostream>
using namespace std;
void mergearr(int arr[],int l,int mid,int r)
{
    int n1=mid-l+1;
    int n2=r-mid;
    int a[n1];
    int b[n2];
    int i=0;
    int j=0;
    int k=l;
    for(int i=0;i<n1;i++)
    {
        a[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++)
    {
        b[i]=arr[mid+1+i];
    }
    while(i<n1 && j<n2)
    {
        if(a[i]<b[j])
        {
            arr[k]=a[i];
            k++;
            i++;
        }
        else
        {
            arr[k]=b[j];
            k++;
            j++;
        }
    }
    while(i<n1)
    {
        arr[k]=a[i];
        k++;
        i++; 
    }
    while(j<n2)
    {
        arr[k]=b[j];
        k++;
        j++; 
    }
}
void mergesort(int arr[],int l,int r)
{
    if(l>=r)
    {
        return;
    }
    if(l<r)
    {
        int mid=(l+r)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        mergearr(arr,l,mid,r);
    }

}

int main()
{
    int arr[10]={8,5,1,3,4,2,6,7,9,10};
    mergesort(arr,0,9);
    cout<<"After Merge sort ";
    for(int k=0;k<10;k++)
        {
            cout<<arr[k]<<" ";
        }
}