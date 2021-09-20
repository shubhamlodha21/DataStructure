//Description: Implementations of List isin STL
//Author: Shubham Lodha
//Date : 21/09/2021

#include<bits/stdc++.h>
using namespace std;

int main()
{

list<int> l;//Creates Lists

    l.push_back(10);//Insert at last
    l.push_front(20);//Insert at First
    l.push_back(30);//Insert at last
    l.push_front(50);//Insert at First
    l.push_front(100);//Insert at First


    cout<<"Elements are:";
    for(auto i:l)
    {
        cout<<i<<endl;
    }

    l.pop_back();//Delete at Last
    l.pop_front();//Delete at First

    cout<<"Elements After Popping are:";
    for(int i:l)
    {
        cout<<i<<endl;
    }
    
    cout<<"Number of Elements is in List are =>"<<l.size()<<endl;
    cout<<"List is Empty or Not =>"<<l.empty()<<endl;
    cout<<"Element at First in list  is =>"<<l.front()<<endl;
    cout<<"Element at Last in list is =>"<<l.back()<<endl;

    l.clear();
    cout<<"Elemets After Clearing Data is =>";
    for(int i:l)
    {
        cout<<i<<endl;
    }
}
