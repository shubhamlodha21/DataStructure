//Description:Implementation of Vector is in STL
//Date: 20/09/2021
//Author: Shubham Lodha

#include<bits/stdc++.h>
using namespace std;

int main()
{

vector<int> v;//Creates Vector

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(50);

    cout<<"Elements are:";
    for(int i:v)
    {
        cout<<i<<endl;
    }

    v.pop_back();
    cout<<"Elements After Popping are:";
    for(int i:v)
    {
        cout<<i<<endl;
    }
    
cout<<"capacity/Memory  of Vector is:"<<v.capacity()<<endl;
cout<<"Number of Elements is in  Vectors are:"<<v.size()<<endl;
cout<<"Element at Indexed 2 is =>"<<v.at(1)<<endl;
cout<<"Array is Empty or Not =>"<<v.empty()<<endl;
cout<<"Element at First in Vector  is =>"<<v.front()<<endl;
cout<<"Element at Last in Vector is=>"<<v.back()<<endl;

    v.clear();
    cout<<"Elemets After Clearing Data is =>";
    for(int i:v)
    {
        cout<<i<<endl;
    }


}
