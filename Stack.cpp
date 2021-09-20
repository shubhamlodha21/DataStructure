//Description: Implementations of Stack is in STL
//Author: Shubham Lodha
//Date : 21/09/2021

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i=0,iSize=0;
    stack<string>str;

    str.push("Shubham");
    str.push("Rajkumar");
    str.push("Lodha");

    cout<<"Data at Top in Stack is:"<<str.top()<<endl;
    cout<<"Size of Stack is:"<<str.size()<<endl;
    cout<<"Stack is empty or not:"<<str.empty()<<endl;

    str.pop();//Pop Element at Top
    cout<<"After  Popping Elements at Top is:"<<str.top();

}