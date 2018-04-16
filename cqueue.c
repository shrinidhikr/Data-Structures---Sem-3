#include<stdio.h>
#include<stdlib.h>
#define size 5
struct cqueue
{
 int front;
 int rear;
 int items[size];
};
typedef struct cqueue CQ;

int cqfull(CQ *cq)
{ 
  return((cq->rear+1)%size==cq->front);
}

int cqempty(CQ *cq)
{
 return(cq->front==cq->rear);
}

void cqinsert(CQ *cq,int ele)    
{
 if(cqfull(cq))
 {
  printf("Queue full\n");
  exit(0);
 }
 else
 {
  cq->rear=(cq->rear+1)%size;
  cq->items[cq->rear]=ele;
 }
}

void cqremove(CQ *cq,int *flag,int *ele)
{
 
 if(cqempty(cq))
 {
  printf("Queue empty\n");
  *flag=1;
  exit(0);
 }
 else
 {
  cq->front=(cq->front+1)%size;
  *ele=cq->items[cq->front];
 }

}       

void display(CQ *cq)
{ 
 int i=cq->front;
 while(i!=cq->rear)
 {
  i=(i+1)%size;
  printf("%d ",cq->items[i]);
 }
}

void main()
{
 CQ cq;
 int ele,ch,flag=0;
 cq.front=0;
 cq.rear=0;
 do
 {
  printf("\n1.Insert 2.Remove 3.Display 4.Exit\n");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:scanf("%d",&ele);
          cqinsert(&cq,ele);
          break;
   case 2:cqremove(&cq,&flag,&ele);
          if(flag==0)
          printf("Element removed is %d\n",ele);
          break;
   case 3:display(&cq);
          break;
   default: break;
  }
 }while(ch<4);
}                          
