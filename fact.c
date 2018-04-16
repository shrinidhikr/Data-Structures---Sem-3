#include <stdio.h>
void main()
{
int n,fact=1,m=0;
printf("Enter the no.\n");
scanf("%d",&n);
m=n;
while(n!=1)
{
fact=fact*n;
n=n-1;
}
printf("Factorial of %d is %d\n",m,fact);

}
