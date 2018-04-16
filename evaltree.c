#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

struct node
{
 struct node *left, *right;
 char info;
};
typedef struct node *NODE;

NODE getnode()
{
 return((NODE)malloc(sizeof(struct node)));
}

float oper(float a,char symb,float b)
{
 switch(symb)
 {
  case '+':return(a+b);
  case '-':return(a-b);
  case '*':return(a*b);
  case '/':if(b!=0)return(a/b);
           else{
                printf("Not possible\n");
                exit(0);
               }
  case '^':return(pow(a,b));
  case '$':return(pow(a,b));
 }
}

float evalbintree(NODE tree)
{
 float opnd1, opnd2;
 char symb;
 if(isdigit(tree->info))
 return((float)(tree->info)-'0');
 else
 {
  opnd1=evalbintree(tree->left);
  opnd2=evalbintree(tree->right);
  symb=tree->info;
  return(oper(opnd1,symb,opnd2));
 }
}

NODE create(char postfix[])
{
 struct stack
 {
  int top;
  NODE items[50];
 }s;
 s.top=-1;
 NODE new;
 char symb;
 int i=0;
 while((symb=postfix[i++])!='\0')
 {
  if(isdigit(symb))
  {
   new=getnode();
   new->info=symb;
   new->right=NULL;
   new->left=NULL;
   s.items[++s.top]=new;
  }
  else
  {
   new=getnode();
   new->info=symb;
   new->right=s.items[s.top--];
   new->left=s.items[s.top--];
   s.items[++s.top]=new;
  }
 }
  if(s.top==0)
  return(s.items[s.top--]);
  else
  printf("Invalid\n");
}

void main()
{
 NODE tree=NULL,curr;
 char postfix[20];
 float f=0;
 printf("Enter expr\n");
 gets(postfix);
 curr=create(postfix);
 f=evalbintree(curr);
 printf("Solution of expr is %f\n",f);
}
