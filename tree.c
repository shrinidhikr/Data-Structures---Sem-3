#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>
#define null 0

struct node
{
int info;
struct node *left,*right;
};
 typedef struct node *nodeptr;

nodeptr getnode()
{
return((nodeptr)malloc(sizeof(struct node)));
}

void freenode(nodeptr p)
{
 free(p);
}

nodeptr maketree(int ele)
{
nodeptr new=getnode();
new->info=ele;
new->left=new->right=NULL;
return(new);
}

int isleft(nodeptr p)
{
return(p->left!=null);
}


int isright(nodeptr p)
{
return(p->right!=null);
}

void setleft(nodeptr p,int ele)
{
nodeptr new;
if(isleft(p))
printf("left son exists");
else
{
new=getnode();
new->info=ele;
new->left=new->right=NULL;
p->left=new;
}
}

void setright(nodeptr p,int ele)
{
nodeptr new;
if(isright(p))
printf("right son exists");
else
{
new=getnode();
new->info=ele;
new->left=new->right=NULL;
p->right=new;
}
}

//Binary search tree construction

nodeptr createbst()
{
nodeptr root,father,son;
int ele;
printf("Enter first element\n");
scanf("%d",&ele);
root=maketree(ele);
printf("Enter tree elements, enter 11111 to terminate\n");
while(ele!=11111)
{
scanf("%d",&ele);
if(ele!=11111)
{
father=son=root;
while(son!=null)
{
father=son;
if(ele<father->info)
{
son=father->left;
}
else
son=father->right;
}
if(ele<father->info)
setleft(father,ele);
else
setright(father,ele);
}
}
return(root);
}

//Binary Tree construction

nodeptr createbt()
{
nodeptr new;
int ele;
printf("Enter the data and if there is no son enter, enter -1\n");
scanf("%d",&ele);
if(ele==-1)
return NULL;
new=getnode();
new->info=ele;
printf("For the left son of %d\n",ele);
new->left=createbt();
printf("For the right son of %d\n",ele);
new->right=createbt();
return(new);
}

//RECURSIVE TRAVERSALS

void inorder(nodeptr tree)
{
 if(tree!=null)
 {
  inorder(tree->left);
  printf("%d ",tree->info);
  inorder(tree->right);
 }
}
void preorder(nodeptr tree)
{
 if(tree!=null)
 {
  if(tree->right!=NULL)
  printf("%d ",(tree->right)->info);
  preorder(tree->left);
  preorder(tree->right); 
 }
}

void postorder(nodeptr tree)
{
 if(tree!=null)
 {
  postorder(tree->left);
  postorder(tree->right); 
  printf("%d ",tree->info);
 } 
}

//TREE OPERATIONS

int find(nodeptr tree)
{
 if(tree==null)
 return(0);
 else
 return(find(tree->left)+find(tree->right)+1);
}

int max(int a,int b)
{
 if(a>b)
 return(a);
 else
 return(b);
}

int height(nodeptr tree)
{
 if(tree==null)
 return(0);
 else
 return(max(height(tree->left),height(tree->right))+1);
}
 
int sum(nodeptr tree)
{
 if(tree==null)
 return(0);
 else
 return(sum(tree->left)+sum(tree->right)+tree->info);
}

int search(nodeptr tree,int ele)
{
 if(tree==NULL)
 return(0);
 if(tree->info==ele)
 return(1);
 else
 {
 if(ele<tree->info)
 return(search(tree->left,ele));
 else
 return(search(tree->right,ele));
 }
}

//NON RECURSIVE TRAVERSALS

void pretrav(nodeptr tree)
{
 struct stack
 {
  int top;
  nodeptr items[20];
 }s;
 nodeptr curr;
 s.top=-1;
 curr=tree;
 do
 {
  while(curr!=null)
  {
   if(curr->left!=NULL)
   printf("%d ",(curr->left)->info);
   s.items[++s.top]=curr;
   curr=curr->left;
  }
  if(s.top!=-1)
  {
   curr=s.items[s.top--];
   curr=curr->right;
  }
 }while((s.top!=-1)||(curr!=null));
}
  
void intrav(nodeptr tree)
{
 struct stack
 {
  int top;
  nodeptr items[20];
 }s;
 nodeptr curr;
 s.top=-1;
 curr=tree;
 do
 {
  while(curr!=null)
  {
   s.items[++s.top]=curr;
   curr=curr->left;
  }
  if(s.top!=-1)
  {
   curr=s.items[s.top--];
   printf("%d ",curr->info);
   curr=curr->right;
  }
 }while((s.top!=-1)||(curr!=null));
}
 
void posttrav(nodeptr tree)
{
struct stack
{
nodeptr a[50];
int top;
}s1,s2;

nodeptr curr=tree;
s1.top=s2.top=-1;
s1.a[++s1.top]=tree;
while(s1.top!=-1)
{
curr=s1.a[s1.top--];
s2.a[++s2.top]=curr;
if(curr->left!=null) s1.a[++s1.top]=curr->left;
if(curr->right!=null) s1.a[++s1.top]=curr->right;
}
while(s2.top!=-1)
{
curr=s2.a[s2.top--];
printf("%d ",curr->info);
}
}

//DELETE A NODE

nodeptr delBST(nodeptr tree,int ele)
{
nodeptr father,curr,rep,f,leftson;
if(tree==NULL)
{
printf("Void deletion\n");
return(tree);
}
curr=tree;
father=NULL;
while(curr!=NULL&&curr->info!=ele)
{
father=curr;
curr=(ele<curr->info)?father->left:father->right;
}
if(curr==NULL)
{
printf("Node not found\n");
return(tree);
}
if(curr->left==NULL)
rep=curr->right;
else if(curr->right==NULL)
rep=curr->left;
else
{
f=curr;
rep=curr->right;
leftson=rep->left;
while(leftson!=NULL)
{
f=rep;
rep=leftson;
leftson=leftson->left;
}
if(f!=curr)
{
f->left=rep->right;
rep->right=curr->right;
}
rep->left=curr->left;
}
if(father==NULL)
tree=rep;
else
{
if(curr==father->left)
father->left=rep;
else
father->right=rep;
}
freenode(curr);
return(tree);
}

void main()
{ 
 nodeptr tree1,tree2;
 int f,s,ch,i,ele,c=0,h;
 printf("1.BST 2.BT\n");
 scanf("%d",&ch);
 if(ch==1)
 {
 tree1=createbst();
 printf("Inorder traversal\n");
 inorder(tree1);
 printf("\n");
 intrav(tree1);
 printf("\n");
 printf("Preorder traversal\n");
 preorder(tree1);
 printf("\n");
 pretrav(tree1);
 printf("\n");
 printf("Postorder traversal\n");
 postorder(tree1);
 printf("\n");
 posttrav(tree1);
 printf("\n");
 f=find(tree1);
 s=sum(tree1);
 h=height(tree1);
 printf("No. of nodes is %d, height is %d and sum of all elements is %d\n",f,h,s);
 printf("Enter element to be searched\n");
 scanf("%d",&ele);
 i=search(tree1,ele);
 if(i==1)
 printf("Element found\n");
 else
 printf("Element not found\n");
 printf("Enter element to be deleted, enter 11111 to terminate\n");
 while(c!=11111)
 {
 scanf("%d",&c);
 if(c!=11111)
 {
 tree1=delBST(tree1,c);
 }
 }
 inorder(tree1);
 printf("\n");
 }
 else if(ch==2)
 {
 tree2=createbt();
 printf("Inorder traversal\n");
 inorder(tree2);
 printf("\n");
 intrav(tree2);
 printf("\n");
 printf("Preorder traversal\n");
 preorder(tree2);
 printf("\n");
 pretrav(tree2);
 printf("\n");
 printf("Postorder traversal\n");
 postorder(tree2);
 printf("\n");
 posttrav(tree2);
 printf("\n");
 f=find(tree2);
 s=sum(tree2);
 h=height(tree2);
 printf("No. of nodes is %d, height is %d and sum of all elements is %d\n",f,h,s);
 }
 else
 printf("Invalid\n");
}

