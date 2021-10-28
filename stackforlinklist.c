// Stack by linklist //
/*STACK OPERATIONS USING LINKED LIST(POINTER)*/
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct stack
{
  int item;
  struct stack *next;
};
typedef struct stack st;
st *top = NULL,*start = NULL;
int main()
{
 int ch;
 void push();
 void pop();
 void traverse();

 printf("STACK APPLICATION USING POINTER:\n");
 do
 {
 printf("\n\n1.PUSH\n");
 printf("2.POP\n");
 printf("3.TRAVERSE\n");
 printf("4.PEEP\n");
 printf("5.EXIT\n");
 printf("enter your choice(1 to 5):");
 scanf("%d",&ch);
 
switch(ch)
 {
  case 1:push();break;
  case 2:pop();break;
  case 3:traverse();break;
  case 4:peep();break;
  case 5:printf("\nEnd of stack application:");break;
  default:printf("\nyou have entered wrong choice:");
 }
 }while(ch!=5);

}

void push()
{
 st *node,*temp;
 int data;
 printf("enter any data to PUSH into stack:");
 scanf("%d",&data);
 node =(st*)malloc(sizeof(st));
 node ->item = data;
 node ->next = NULL;
 if(top==NULL)
 {
  top = start = node;
  return;
 }
 temp=start;
 while(temp->next!=NULL)
	{
		temp=temp->next; //temp is last node
	}
	temp->next=node;
	top = node ;
}

void pop()
{
 int data;
 st *temp,*temp1;
 if(top==NULL)
 {
  printf("\nstack is already empty:\n");
  return;
 }
 if(top == start)       // for single value
 {
 	data = top->item;
 	printf("\n%d is POP out",data);
 	free(top);
 	top = NULL;
 	start = NULL;
 	return ;
 }
  temp = start;    // for multilpe value
 while(temp->next!=NULL)
 {
		temp1=temp;
		temp=temp->next; //temp is last node
 }
	data = top->item;
	printf("\n%d is POP out",data);
	free(temp);
	top = temp1;
	top->next = NULL;
}

void traverse()
{
 st *temp;
 if(start==NULL)
  {
  	printf("\nstack is empty !!");
  	return ;
  }
   temp = start;
while(temp!=NULL)
  {
   printf("\n-------------->%d ",temp->item);
   temp=temp->next;
  }
}

void peep()
{
int pos,i=1,count=0;
printf("Enter the position number to PEEP : ");
scanf("%d",&pos);
st *temp;
temp=start;

while(temp!=NULL)
{
    count+=1;
    temp=temp->next;
}
if(!count)
{
printf("The stack is empty.");
return;
}
else
{
    temp=start;
    if(pos>count)
    {
        printf("Entered position exceeds stack size.");
        return;
    }
    else
        {
        while(i<pos)
        {
            i+=1;
            temp=temp->next;
        }
        printf("\n%d is peeped out at location %d\n",temp->item,pos);
        }
}
free(temp);
}

      //printf("\n%d is peeped out at location %d\n",temp->item,pos);



