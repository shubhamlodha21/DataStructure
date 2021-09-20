//Description: Implementations of Queue is in STL
//Author: Shubham Lodha
//Date : 21/09/2021

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i=0,iSize=0;
    queue<string>q;

    q.push("Shubham");
    q.push("Rajkumar");
    q.push("Lodha");

    cout<<"Size of Queue is:"<<q.size()<<endl;
    cout<<"Queue is empty or not:"<<q.empty()<<endl;
    cout<<"Element at Front in Queue is:"<<q.front()<<endl;
    cout<<"Element at Back in Queue is:"<<q.back()<<endl;

    q.pop();//Pop Element at Top
    cout<<"After Popping size of Queue is:"<<q.size();

}