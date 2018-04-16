#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int det(int A[100][100],int n)
{
    int minor[100][100];
    int i,j,k,a,b;
    int d;

    if(n==1)
   {
    return(A[1][1]); 
   }

    else
   {
     d = 0;
     for(k=1;k<=n;k++)
    {
      a=1;
      b=1;
      for(i=1;i<=n;i++)
     {
       for(j=1;j<=n;j++)
      {
        if(i!=1 && j!=k)
       {
         minor[a][b] = A[i][j];
         if(b<(n-1))
        {
         b++;
        }
         else
        {
         a++;
         b=1;
        }
       }
      }
     }
      d = d+pow(-1,(1+k))*(A[1][k]*det(minor,n-1));
    }
   }
    return(d);
}

void main()
{
    int A[100][100];
    int i,j,n,res;
    printf("Enter the order of the matrix: \n");
    scanf("%d",&n);
    if(n<=0)
   {
    printf("Invalid matrix\n");
    exit(0);
   }
    else
   {
    printf("\nEnter the elements of the matrix: \n");
    for(i=1;i<=n;i++)
   {
     for(j=1;j<=n;j++)
    {
     scanf("%d",&A[i][j]);
    }
   }
   printf("Entered matrix A is: \n");
    for(i =1;i<=n;i++)
   {
     for(j =1;j<=n;j++)
    {
     printf("A[%d][%d]=%d\t",i,j,A[i][j]);
    }
     printf("\n");
   }
    res = det(A,n);
    printf("Determinant of matrix is %d\n",res);
   }
}



