#include<stdio.h>
void towerofhanoi(int n,char from,char aux,char to)
{
 if(n==1)
 {
  printf("Move disk 1 from %c to %c\n",from,to);
 }
 else
 {
  towerofhanoi(n-1,from,to,aux);
  printf("Move disk %d from %c to %c\n",n,from,to);
  towerofhanoi(n-1,aux,from,to);
 }
}

void main()
{
 int n;
 printf("Enter the no. of disks\n");
 scanf("%d",&n);
 towerofhanoi(n,'A','B','C');
}
