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

void infront(NODE *list,int ele)
{
 NODE newnode;
 newnode=getnode();
 newnode->info=ele;
 newnode->next=NULL;  
 
 newnode->next=*list;
 *list=newnode;
}

void delfront(NODE *list)
{
 NODE temp;
 if(*list==NULL)
 {
  printf("List does not exist\n");
  exit(0);
 }
 else
 { 
 temp=*list;
 *list=temp->next;
 printf("Element deleted is %d",temp->info);
 free(temp);
 }
}
  
void insend(NODE *list,int ele)
{
 NODE curr,newnode;
 newnode=getnode();
 newnode->info=ele;
 newnode->next=NULL;
 curr=*list; 
 
 if(curr==NULL)
 *list=newnode;
 
 else
 {
  while(curr->next!=NULL)
  {
   curr=curr->next;
  }
  if(curr!=NULL)
  curr->next=newnode;
  else
  *list=newnode;
 }
}

void delend(NODE *list)
{
 NODE curr,prev;
 curr=*list;
 prev=NULL;
 if(*list==NULL)
 {
  printf("List does not exist\n");
  exit(0);
 }
 while(curr->next!=NULL)
 {
   prev=curr;
   curr=curr->next;
 }
 if(prev!=NULL)
 {
  prev->next=NULL;
  printf("Element deleted is %d",curr->info);
  free(curr);
 }
 else
 {
 *list=NULL;
 printf("Element deleted is %d",curr->info);
 free(curr);     
 }
} 

void delnth(NODE *list,int n)
{
 NODE curr,prev;
 int c=0;
 curr=*list;
 prev=NULL;
 if(*list==NULL)
 {
  printf("List does not exist\n");
  exit(0);
 }
 while(curr!=NULL)
 { 
  c++;
  if(c!=n)
  {
   prev=curr;
   curr=curr->next;
  } 
  else
  {
   if(prev!=NULL)
   {
   prev->next=curr->next;
   printf("Element deleted is %d\n",curr->info);
   free(curr);
   }
   else
   {
    *list=curr->next;
    printf("Element deleted is %d\n",curr->info);
    free(curr);
   }
  } 
 }
} 

void insnth(NODE *list,int ele,int n)
{
 NODE curr,prev,newnode;
 int i=0;
 newnode=getnode();
 newnode->info=ele;
 newnode->next=NULL;
 curr=*list;
 prev=NULL;
 if(curr==NULL)
 *list=newnode;
 else
{
 while(curr!=NULL)
 {
  i++;
  if(i!=n)
  {
   prev=curr;
   curr=curr->next;
  }
  else
  {
   if(prev!=NULL)
   {
   prev->next=newnode;
   newnode->next=curr;
   }
   else
   {
   *list=newnode;
   newnode->next=curr;
   }
  }
 }
}
}  

void display(NODE *list)
{
 NODE curr;
 curr=*list;
 if(curr==NULL)
 {
 printf("List empty\n");
 exit(0);
 }
 while(curr!=NULL)
 {
  printf("%d ",curr->info);
  if(curr->next!=NULL)
  printf("->");
  curr=curr->next;
 }
} 

void delall(NODE *list,int ele)
{
 NODE curr,temp,prev;
 prev=NULL;
 curr=*list;
 if(*list==NULL)
 {
 printf("List does not exist\n");
 exit(0);
 }
  while(curr!=NULL)
 {
  
  if(curr->info==ele)
  { 
    temp=curr;
    curr=temp->next;
    if(prev==NULL)
    *list=curr;
    else
    prev->next=curr;
  free(temp);
  }
  else
 {
  prev=curr;
  curr=curr->next;
 }
 }
}

void place(NODE *list,int ele)
{
 NODE curr,new,prev;
 new=getnode();
 new->info=ele;
 new->next=NULL;
 curr=*list;
 prev=NULL;
 while(curr!=NULL && curr->info<ele)
 {
  prev=curr;
  curr=curr->next;
 }
 if(prev!=NULL)
  prev->next=new;
 else
  *list=new;
 new->next=curr;
}
 

void main()
{
 NODE list=NULL;
 int ch,ele,n;
 do
 {
   printf("\n1.Infront 2.Delfront 3.Insend 4.Delend 5.Display 6.Delnth 7.Insnth 8.DelAll 9.Place 10.Exit\n");
   scanf("%d",&ch);
   switch(ch)
   {
    case 1:scanf("%d",&ele);
           infront(&list,ele);
           break;
    case 2:delfront(&list);
           break;
    case 3:scanf("%d",&ele);
           insend(&list,ele);
           break;   
    case 4:delend(&list);
           break;
    case 5:display(&list);
           break;
    case 6:printf("Enter value of n\n");
           scanf("%d",&n);
           delnth(&list,n);
           break;
    case 7:scanf("%d",&ele);
           printf("Enter the value of n\n");
           scanf("%d",&n);
           insnth(&list,ele,n);
           break; 
    case 8:printf("Enter the element to be removed\n");
           scanf("%d",&ele);
           delall(&list,ele);
           break;   
    case 9:scanf("%d",&ele);
           place(&list,ele);
           break;    
    default: break;
   }
 }while(ch<10);
}                                    
