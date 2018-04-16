#include <stdio.h>
void main()
{
int i,n,j;
printf("Enter the no. upto which primes need to be printed\n");
scanf("%d",&n);
for(i=2;i<=n;i++)
{
for(j=2;j<i;j++)
{
if(i%j==0)
{
printf("Not prime %d\n",i);
}
else
printf("Prime %d\n",i);
}

}
}
