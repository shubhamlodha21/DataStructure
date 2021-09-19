//////////////////////////////////
/*Input:--
*Output:Enter the number 4
        Number is 4
Do you want to continue!!!!!  1
        Enter the number 3
        Number is 3
Do you want to continue!!!!!  1
       Enter the number 7
       Number is 7
Do you want to continue!!!!!  2
-----------------THANKYOU----------------------
*Description:Use of Malloc (Dynamic Memory Allocation )
*Date: 6-July-2021
*Author:Shruti Nahar*/
////////////////////////////////////
#include <iostream>
#include<stdlib.h>
using namespace std;
int main()
{
    int ch;
    int *p;
    do
    {
        p=(int*)malloc(sizeof(int));
        cout<<"Enter the number ";
        cin>>*p;
        cout<<"Number is "<<*p<<"\n";
        cout<<"Do you want to continue!!!!!  ";
        cin>>ch;
    }while(ch==1);
    cout<<"-----------------THANKYOU----------------------";
}
