#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node
{
 int info;
 struct node *right,*left;
};
typedef struct node *NODE;

NODE getnode()
{
 return((NODE)malloc(sizeof(struct node)));
}

void insfront(NODE *dlist,int ele)
{
 NODE curr,new=getnode();
 new->info=ele;
 new->right=NULL;
 new->left=NULL;
 if(*dlist==NULL)
 {
  *dlist=new;
 }
 else
 {
  new->right=*dlist;
  *dlist=new;
 }
}

void delfront(NODE *dlist)
{
 NODE curr,temp;
 if(*dlist==NULL)
 {
  printf("List empty\n");
 }
 else
 {
  temp=*dlist;
  curr=(*dlist)->right;
  if((*dlist)->right==NULL)
  {
   printf("Deleted element is %d",temp->info);
   *dlist=NULL;
  }
  else
  {
   *dlist=curr;
   (*dlist)->left=NULL;
   printf("Deleted element is %d",temp->info);
   free(temp);
  }
 }
}

void insend(NODE *dlist,int ele)
{
 NODE curr,new=getnode();
 new->info=ele;
 new->right=NULL;
 new->left=NULL;
 if(*dlist==NULL)
 {
  *dlist=new;
 }
 else
 { 
  curr=*dlist;
  while(curr->right!=NULL)
  {
   curr=curr->right;
  }
   curr->right=new;
   new->left=curr;
 }
} 
  
void delend(NODE *dlist)
{
 NODE curr,prev=NULL;
 if(*dlist==NULL)
 {
  printf("List empty\n");
 }
 else
 {
  curr=*dlist;
  while(curr->right!=NULL)
  {
   prev=curr;
   curr=curr->right;
  }
  if(prev==NULL)
  {
   printf("Deleted element is %d",curr->info);
   *dlist=NULL;
  }
  else
  {
  prev->right=NULL;
  printf("Deleted element is %d",curr->info);
  free(curr);
  }
}
}

void display(NODE *dlist)
{
 NODE curr;
 if(*dlist==NULL)
 printf("List empty\n");
 else
 {
 curr=*dlist;
 while(curr!=NULL)
 {
  printf("%d",curr->info);
  curr=curr->right;
 } 
 }
}

/*void insnth(NODE *dlist,int ele,int n)
{
 NODE curr,prev=NULL,new=getnode();
 int c=0;
 new->info=ele;
 new->right=NULL;
 new->left=NULL;
 if(*dlist==NULL)
 {
  *dlist=new;
 }
 else
 {
  curr=*dlist;
  while(curr!=NULL)
  { c++;
   if(c!=n)
   {
   prev=curr;
   curr=curr->right;
   }
   else
   {
    if(prev!=NULL)
    {
     prev->right=new;
     new->left=prev;
     new->right=curr;
     curr->left=new;
    }
    else
    {
     *dlist=new;
     new->right=curr;
     curr->left=new;
    }
   }
  }
 }
}*/

void insnth(NODE *dlist,int ele,int n)
{
 NODE curr,prev=NULL,new=getnode();
 int c=1;
 new->info=ele;
 new->right=NULL;
 new->left=NULL;
 if(*dlist==NULL)
 {
  *dlist=new;
 }
 else
 {
  curr=*dlist;
  while(curr!=NULL && c!=n)
  { 
   c++;
   prev=curr;
   curr=curr->right;
  }
  if(curr==NULL && c==n) 
  {
   prev->right=new;
   new->left=prev;
   new->right=NULL;
  }
 else
 { 
   if(c!=n)
   {
    printf("Not posible\n");
   }
  else
  {
   if(prev!=NULL)
    {
     prev->right=new;
     new->left=prev;
     new->right=curr;
     curr->left=new;
    }
    else
    {
     *dlist=new;
     new->right=curr;
     curr->left=new;
    }
   }
  }
 }
}


void delnth(NODE *dlist,int n)
{
 NODE curr,prev=NULL;
 int c=0;
 if(*dlist==NULL)
 printf("List empty\n");
 else
 { 
  curr=*dlist;
  while(curr!=NULL)
  { 
   c++;
   if(c!=n)
   {
    prev=curr;
    curr=curr->right;
   }
   else
   { 
    if(prev==NULL)
    {
     if(curr->right!=NULL)
     {
     *dlist=curr->right;
     (*dlist)->left=NULL;
     printf("Deleted element is %d",curr->info);
     free(curr);
     }
     else
     {
     printf("Deleted element is %d",(*dlist)->info);
     *dlist=NULL;
     }
    }
    else
    { 
     if(curr->right!=NULL)
     {
     prev->right=curr->right; 
     (curr->right)->left=prev;
     printf("Deleted element is %d",curr->info);
     free(curr);
     }
     else
     {
     prev->right=NULL;
     printf("Deleted element is %d",curr->info);
     free(curr);
     }
    }
   }
 }
}
}

void order(NODE *dlist,int ele)
{
 NODE curr,prev=NULL,new;
 new=getnode();
 new->info=ele;
 new->right=NULL;;
 new->left=NULL;
 if(*dlist==NULL)
 {
  *dlist=new;
 }
 else
 {
  curr=*dlist;
  while((curr!=NULL)&& (ele>curr->info))
  {
   prev=curr;
   curr=curr->right;
  }
  if(prev==NULL)
  {
   new->right=curr;
   curr->left=new;
   *dlist=new;
  }
  else if(curr==NULL)
  {
   prev->right=new;
   new->left=prev;
  }
  else
  {
   prev->right=new;
   new->right=curr;
   curr->left=new;
   new->left=prev;
  }
 }
}
void main()
{
 NODE dlist=NULL;
 int ch,ele,n;
 do
 {
   printf("\n1.Insfront 2.Delfront 3.Insend 4.Delend 5.Display 6.Delnth 7.Insnth 8.Order 9.Exit\n");
   scanf("%d",&ch);
   switch(ch)
   {
    case 1:scanf("%d",&ele);
           insfront(&dlist,ele);
           break;
    case 2:delfront(&dlist);
           break;
    case 3:scanf("%d",&ele);
           insend(&dlist,ele);
           break;   
    case 4:delend(&dlist);
           break;
    case 5:display(&dlist);
           break;
    case 6:printf("Enter value of n\n");
           scanf("%d",&n);
           delnth(&dlist,n);
           break; 
    case 7:scanf("%d",&ele);
           printf("Enter the value of n\n");
           scanf("%d",&n);
           insnth(&dlist,ele,n);
           break;
    case 8:scanf("%d",&ele);
           order(&dlist,ele);
           break; 
    
    default: break;
   }
 }while(ch<9);
}                                    

