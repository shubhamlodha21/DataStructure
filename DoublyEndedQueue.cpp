
//Description:Implementation of DoublyEndedQueue is in STL
//Date: 20/09/2021
//Author: Shubham Lodha

#include<bits/stdc++.h>
using namespace std;

int main()
{

deque<int> d;//Creates Dequeue

    d.push_back(10);//Insert at last
    d.push_front(20);//Insert at First
    d.push_back(30);//Insert at last
    d.push_front(50);//Insert at First
    d.push_front(100);//Insert at First


    cout<<"Elements are:";
    for(int i:d)
    {
        cout<<i<<endl;
    }

    d.pop_back();//Delete at Last
    d.pop_front();//Delete at First

    cout<<"Elements After Popping are:";
    for(int i:d)
    {
        cout<<i<<endl;
    }
    
    cout<<"Number of Elements is in Dequeue are =>"<<d.size()<<endl;
    cout<<"Element at Indexed 2 is =>"<<d.at(1)<<endl;
    cout<<"Array is Empty or Not =>"<<d.empty()<<endl;
    cout<<"Element at First in Dequeue  is =>"<<d.front()<<endl;
    cout<<"Element at Last in  is=>"<<d.back()<<endl;

    d.clear();
    cout<<"Elemets After Clearing Data is =>";
    for(int i:d)
    {
        cout<<i<<endl;
    }
}
