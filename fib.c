#include <stdio.h>
void main()
{
int a[100],i;
a[0]=0;
a[1]=1;
for(i=1;i<=20;i++)
{
a[i+1]=a[i]+a[i-1];
}
for(i=0;i<=20;i++)
{
printf("%d\t",a[i]);
}
printf("\n");
}


