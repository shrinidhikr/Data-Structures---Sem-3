#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#define size 10
struct str
{
int top;
float a[size];
};
typedef struct str Stack;

void push(Stack *s,float ele)
{
if(s->top==(size-1))
printf("Stack is full\n");
else 
s->a[++(s->top)]=ele;
}

int empty(Stack *s)
{
return(s->top==-1);
}

float pop(Stack *s)
{
return(s->a[(s->top)--]);
}

float evaluate(Stack *s,float op1,float op2,char ch)
{
float result;
switch(ch)
	{
	case '+':result=op1+op2;break;
	case '-':result=op1-op2;break;
	case '*':result=op1*op2;break;
	case '/':if(op2!=0)
                 result=op1/op2;
                 else
                 exit(0); 
                 break;
	case '^':result=pow(op1,op2);break;
	default:printf("The equation is not valid\n");break;
	}
return(result);
}

void main()
{
Stack s;
int i=0;
float op1,op2,result;
char a[30],symb;
s.top=-1;
printf("Enter the postfix equation\n");
gets(a);
while(a[i]!='\0')
	{
	if (isdigit(a[i]))
        {
        push(&s,a[i]-'0');
	}
        else
		{
                  if(empty(&s))
			{
                         printf("The equation is invalid\n");
                         exit(0);
                        }
		  else op2=pop(&s);
		  if(empty(&s))
			{
                          printf("The equation is invalid\n");
                          exit(0);
                        }
		  else op1=pop(&s);
		  result=evaluate(&s,op1,op2,a[i]);
                  push(&s,result);
		}
        i=i+1;
	}
result=pop(&s);
if(empty(&s))
printf("The solution is %f\n",result);
else 
printf("The equation is invalid\n");
}
