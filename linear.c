#include<stdio.h>
#include<stdlib.h>
#define size 10

struct queue
{
 int front;
 int rear;
 int items[size];
};
typedef struct queue Q;

int qempty(Q *q)
{
 return((q->front)>(q->rear));
}

int qfull(Q *q)
{
 return(q->rear==(size-1));
}

void qinsert(Q *q,int ele)
{
 if(qfull(q))
 {
  printf("Queue full\n");
  exit(0);
 }
 else
  q->items[++(q->rear)]=ele;
}

void qremove(Q *q,int *uflag,int *ele)
{
 
 if(qempty(q))
 {
  printf("Queue empty\n");
  *uflag=1;
  exit(0);
 }
 else
 {
  *ele=q->items[q->front++];
 }
  if((q->front)>(q->rear))
 {
  q->front=0;
  q->rear=-1;
 }
}

void display(Q *q)
{
 int i=0;
 for(i=q->front;i<=q->rear;i++)
 {
  printf("%d ",q->items[i]);
 }
}

void main()
{
 Q q;
 int ele,ch;
 int uflag=0;
 q.front=0;
 q.rear=-1;
 
 do
 {
  printf("\n1.Insert 2.Remove 3.Display 4.Exit\n");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:scanf("%d",&ele);
          qinsert(&q,ele);
          break;
   case 2:qremove(&q,&uflag,&ele);
          if(uflag==0)
          printf("Element removed is %d\n",ele);
          break;
   case 3:display(&q);
          break;
   default: break;
  }
 }while(ch<4);
}                     

