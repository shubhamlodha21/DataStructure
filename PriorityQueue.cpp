//Description: Implementation of PriorityQueue is in STL
//Date : 21/09/2021
//Author : Shubham Lodha

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int iSize=0;
    priority_queue<float> p; //Max Heap
    priority_queue<int,vector<int>,greater<int>>min;//Min Heap

    p.push(11.1);
    p.push(99.9);
    p.push(01.11);


    cout<<"Number of Elements are:"<<p.size()<<endl;
    cout<<"Element at top of Queue is:"<<p.top()<<endl;
    p.pop();
    cout<<"After Popping on element Number of Elements are:"<<p.size()<<endl;
}