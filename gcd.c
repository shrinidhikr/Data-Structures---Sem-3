#include<stdio.h>
#include<stdlib.h>

int gcd(int n,int m)
{
 int r;
 if(n%m==0)
 return(m);
 else
 {
 r=n%m;
 return(gcd(m,r));
 }
}

void main()
{
 int n,m,p;
 printf("Enter the nos.\n");
 scanf("%d%d",&n,&m);
 if(n==0 || m==0)
 {
 printf("Invalid\n");
 exit(0);
 }
 else
 p=gcd(n,m);
 printf("The gcd of %d and %d is %d\n",n,m,p);
}

