//Description:Implementation of Array is in STL
//Date: 20/09/2021
//Author: Shubham Lodha


#include<iostream>
#include<array>
using namespace std;

int main()
{

array<int,4> arr={19,21,39,41};//Creates Array 

    for(int i:arr)
    {
        cout<<i<<endl;
    }

cout<<"Element at Indexed 2 is=>"<<arr.at(1)<<endl;
cout<<"Array is Empty or Not=>"<<arr.empty()<<endl;
cout<<"Element at First in array is =>"<<arr.front()<<endl;
cout<<"Element at Last in array is=>"<<arr.back()<<endl;

}
