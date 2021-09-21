//Description: Implementation Map is in STL
//Date : 21/09/2021
//Author : Shubham Lodha


#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<int,string>m;//Creating map

    m[1]="Shubham";
    m[5]="Rajkumar";
    m[11]="Lodha";
    m.insert({21,"Shaila"});

    cout<<"Check whether 5th key is present or not=>"<<m.count(5)<<endl;
    cout<<"Delete Key with key value 5=>"<<m.erase(5)<<endl;
}