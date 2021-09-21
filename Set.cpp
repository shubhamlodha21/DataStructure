//Description: Implementation of Set is in STL
//Date : 21/09/2021
//Author : Shubham Lodha

#include<bits/stdc++.h>
using namespace std;

int main()
{
    set<float>s;//Creating set

    s.insert(5);
    s.insert(12);
    s.insert(01);
    s.insert(65);
    s.insert(99);
    s.insert(99);//Duplication NA

    cout<<"Elemets are:";
    for(auto i:s)//Display elements in ascending order
    {
        cout<<i<<endl;
    }

    cout<<"Element 99 present or  not in set:"<<s.count(99);
    
    s.erase(s.begin());

    cout<<"Elements after Erasing First element:";
    for(auto i:s)//Display elements in ascending order
    {
        cout<<i<<endl;
    }

}   

