#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
 int info;
 struct node *next;
};
typedef struct node * NODE;

NODE getnode()
{
 return((NODE)malloc(sizeof(struct node)));
}

void infront(NODE *clist,int ele)
{
 NODE newnode;
 newnode=getnode();
 newnode->info=ele;
 newnode->next=NULL;  
 if(*clist==NULL)
 {
  (*clist)=newnode;
   newnode->next=(*clist);
 }
 else
 {
  newnode->next=(*clist)->next;
  (*clist)->next=newnode;
 }
}

void delfront(NODE *clist)
{
 NODE temp;
 if(*clist==NULL)
 {
  printf("List does not exist\n");
 }
 else
 { 
  if((*clist)->next!=*clist)
  {
  temp=(*clist)->next;
  (*clist)->next=temp->next;
  printf("Element deleted is %d",temp->info);
  free(temp);
  }
  else
  {
  printf("Element deleted is %d",(*clist)->info);
  *clist=NULL;
  }
 }
}
  

void insend(NODE *clist,int ele)
{
 NODE curr,newnode;
 newnode=getnode();
 newnode->info=ele;
 newnode->next=NULL;
 curr=*clist; 
 
 if(*clist==NULL)
 {
  *clist=newnode;
  newnode->next=*clist;
 }
 else
 {
  newnode->next=(*clist)->next;
  (*clist)->next=newnode;
  *clist=newnode;
 }
}

void delend(NODE *clist)
{
 NODE curr,prev;
 
 if(*clist==NULL)
 {
  printf("List does not exist\n");
  
 }
else
{
 curr=(*clist)->next;
 prev=NULL;
 while(curr!=*clist)
 {
   prev=curr;
   curr=curr->next;
 }
 if(prev==NULL)
 {
  
  printf("Element deleted is %d",(*clist)->info);
  *clist=NULL;
 }
 else
 {
  prev->next=(*clist)->next;
  *clist=prev;
  printf("Element deleted is %d",curr->info);
  free(curr);    
 }
}
}


/*void delend(NODE *clist)
{ 
 NODE curr,temp;
 if(*clist==NULL)
 printf("Empty\n");
 else
 {
  curr=(*clist)->next;
  while(curr->next!=*clist)
   curr=curr->next;
  if(curr==*clist)
  {
   printf("Deleted element is %d",curr->info);
   *clist=NULL;
  }
  else
  {
   temp=*clist;
   curr->next=(*clist)->next;
   *clist=curr; 
   printf("Deleted element is %d",temp->info);
   free(temp);
  }
 }
} 
*/

void delnth(NODE *clist,int n)
{
NODE prev=NULL,curr;
int c=1;
if((*clist)==NULL)
printf("List empty\n");
else
{
 curr=(*clist)->next;
 while(curr!=*clist && c!=n)
 {
  c++;
  prev=curr;
  curr=curr->next;
 }
 if(c!=n)
 {
  printf("Not possible\n");
 }
 else
{
 if(prev!=NULL)
 {
  if(curr!=*clist)
  {
  prev->next=curr->next;
  printf("Element deleted is %d",curr->info);
  free(curr);
  }
  else
  {
   prev->next=(*clist)->next;
   *clist=prev;
   printf("Element deleted is %d",curr->info);
   free(curr);
  }
 }
 else
 {
  if(curr!=*clist)
  {
  (*clist)->next=curr->next;
  printf("Element deleted is %d",curr->info);
  free(curr);
  }
  else
  {
  printf("Element deleted is %d",curr->info);
  *clist=NULL;
  }
 }
}
}
}

void insnth(NODE *clist,int ele,int n)
{
 NODE curr,prev,newnode;
 int i=1;
 newnode=getnode();
 newnode->info=ele;
 newnode->next=NULL;
 curr=*clist;
 prev=NULL;
 if(*clist==NULL)
 {
  if(n==1)
  {
  *clist=newnode;
  newnode->next=*clist;
  }
  else
  printf("Invalid\n");
 }
 else
 {
  curr=(*clist)->next;
  while(curr!=*clist && i!=n)
  {
   prev=curr;
   curr=curr->next;
   i++;
  }
  if((i+1)<n)
  printf("Invalid\n");
  else
 {
  if(curr==*clist && (i+1)==n)
  {
   newnode->next=curr->next;
   (*clist)->next=newnode;
   *clist=newnode;
  }
  else if(prev==NULL)
  {
   newnode->next=(*clist)->next;
   (*clist)->next=newnode;
  }
  else
  {
   prev->next=newnode;
   newnode->next=curr;
  }
 }
}
}
 

void display(NODE *clist)
{
 NODE curr;
 curr=(*clist);
 if(*clist==NULL)
 {
 printf("List empty\n");
 }
 else
 {
 do
 {
  curr=curr->next;
  printf("%d ",curr->info);
  
 }while(curr!=*clist);
 }
} 


void main()
{
 NODE clist=NULL;
 int ch,ele,n;
 do
 {
   printf("\n1.Infront 2.Delfront 3.Insend 4.Delend 5.Display 6.Delnth 7.Insnth 8.Exit\n");
   scanf("%d",&ch);
   switch(ch)
   {
    case 1:scanf("%d",&ele);
           infront(&clist,ele);
           break;
    case 2:delfront(&clist);
           break;
    case 3:scanf("%d",&ele);
           insend(&clist,ele);
           break;   
    case 4:delend(&clist);
           break; 
    case 5:display(&clist);
           break;
    case 6:printf("Enter value of n\n");
           scanf("%d",&n);
           delnth(&clist,n);
           break; 
    case 7:scanf("%d",&ele);
           printf("Enter the value of n\n");
           scanf("%d",&n);
           insnth(&clist,ele,n);
           break; 
 
    default: break;
   }
 }while(ch<8);
}     

        
