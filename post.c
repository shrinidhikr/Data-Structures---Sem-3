#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define size 50
struct stack
{
 int top;
 char items[size];
};
typedef struct stack STACK;

int empty(STACK *s)
{
 return(s->top==-1);
}

void push(STACK *s,char ele)
{
  if(s->top==(size-1))
  {
   printf("STACKFULL\n");
   exit(0);
  }
  else
  s->items[++(s->top)]=ele;
}

char pop(STACK *s)
{
  return(s->items[(s->top)--]);
}

int priority(char op)
{
  switch(op)
  {
   case '(':return(0);
   case '+':return(1);
   case '-':return(1);
   case '*':return(2);
   case '/':return(2);
   case '^':return(3);
   case '$':return(3);
   default : printf("Invalid\n");
             exit(0);
  }
}

int prcd(char op1,char op2)
{
  if(op1=='^'|| op1=='$')
  return(1);
  return(priority(op1)>priority(op2));
}

void infixpostfix(char infix[],char postfix[])
{
 STACK s;
 int j=0,i=0;
 s.top=-1;
 char symb,topsymb;
 
 while((symb=infix[i++])!='\0')
 {
  if(symb=='(')
  push(&s,symb);
  else if(isalpha(symb))
  postfix[j++]=symb;
  else if(symb==')')
  {
   if(empty(&s))
   {
    printf("Invalid\n");
    exit(0);
   }
    topsymb=pop(&s);
   while(topsymb!='(')
    {
     postfix[j++]=topsymb;
     if(empty(&s))
     {
      printf("Invalid\n");
      exit(0);
     }
     topsymb=pop(&s);
    }
  }
  else
  {
   while(!empty(&s) && !prcd(symb,s.items[s.top]))
   {
    postfix[j++]=pop(&s);
   }
   push(&s,symb);
  }
 }
 while(!empty(&s))
 {
  if(s.items[s.top]!='(')
  postfix[j++]=pop(&s);
  else
  {
   printf("Invalid\n");
   exit(0);
  }
 }
  postfix[j]='\0';
}

void main()
{
 char infix[20],postfix[20];
 printf("Enter infix expr\n");
 gets(infix);
 infixpostfix(infix,postfix);
 printf("Postfix expr is\n");
 puts(postfix);
}
