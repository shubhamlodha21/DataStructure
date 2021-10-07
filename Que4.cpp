/*input:-s="ABC" 
output:-  ABC
          ACB
          BAC
          BCA
          CBA
          CAB
description:The task is to display all the permutation of the string
date: 07-10-2021
Author name: Shubham Lodha*/
#include<iostream>
using namespace std;
void permutae(string a,int l,int r)
{
    if(l==r)
    {
        cout<<a<<"\n";
    }
    else
    {
        for(int i=l;i<=r;i++)
        {
            swap(a[l],a[i]);
            permutae(a,l+1,r);
            swap(a[l],a[i]);
        }
    }
}
int main()
{
  string s="ABC";
  int l=0;
  int r=s.size();
  permutae(s,l,r-1);
}
