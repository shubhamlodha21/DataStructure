//////////////////////////
/*Input:enter the no of block 5
enter the numbers
1
2
4
5
6
*Output:
        elements are    1    2    4    5    6
*Description:Implementation of calloc (dynamic memory allocation)
*Date:11-July-2021
*Author:Shruti Nahar*/
/////////////////////////////
#include<stdio.h>
#include<stdlib.h>
int main()
{
int n,*ptr;
int i;
printf("enter the no of block");
scanf("%d",&n);
ptr=(int*)calloc(n,sizeof(int));
printf("enter the numbers");
for(i=0;i<n;i++)
{
scanf("%d",(ptr+i));
}
printf("elements are");
for(i=0;i<n;i++)
{
printf("%5d",*(ptr+i));
}
}
