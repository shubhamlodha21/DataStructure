
#include<iostream>
using namespace std;
int inclusive_exc(int n,int a,int b)
{
    int c1=n/a;
    int c2=n/b;
    int c3=n/(a*b);
    return c1 + c2 - c3;
}
int main()
{
 cout<<"Check how many numbers are divisible by 5 & 7 by using inclusive_exclusive ";
 cout<<inclusive_exc(40,5,7);
}