#include<stdio.h>

int binary(int a[],int low,int high,int key)
{
 int mid=0;
 if(low>high)
 return(-1);
 mid=(low+high)/2;
 if(key==a[mid])
 return(mid);
 else if(key<a[mid])
 return(binary(a,low,mid-1,key));
 else
 return(binary(a,mid+1,high,key));
}

void main()
{
 int a[50],n,i,pos,k;
 printf("Enter the size of array\n");
 scanf("%d",&n);
 printf("Enter the array elements\n");
 for (i=0;i<n;i++)
 scanf("%d",&a[i]);
 printf("Enter the key\n");
 scanf("%d",&k);
 pos=binary(a,0,n-1,k);
 if(pos==-1)
 printf("ELEMENT NOT FOUND\n");
 else
 printf("Element found at %d\n",pos+1);
}
 
