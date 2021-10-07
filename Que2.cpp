#include<iostream>
using namespace std;
void reversedigit(int num)
{
    int rem;
    while(num!=0)
    {
        rem=num%10;
        cout<<rem;
        num=num/10;
    }
}
int main()
{
    reversedigit(123);
}
