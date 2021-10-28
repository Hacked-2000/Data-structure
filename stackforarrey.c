/*STACK OPERATIONS USING ARRAY*/
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5  	
		
int stack[MAX_SIZE];
int top=-1; // stack is empty

void push();
 void pop();
 void peep();
 void traverse();
 
int main()
{
 int ch;
 printf("Stack Application Menu :");
 do
 {
 printf("\n\n1.PUSH\n");
 printf("2.POP\n");
 printf("3.PEEP \n");
 printf("4.TRAVERSE\n");
 printf("5.EXIT\n");
 printf("enter your choice(1 to 5) : ");
 scanf("%d",&ch);
 switch(ch)
 {
  case 1:push();break;
  case 2:pop();break;
  case 3:peep();break;
  case 4:traverse();break;
  case 5:printf("end of stack application:");break;
  default:printf("you have entered wrong choice:");
 }
 }while(ch!=5);
 
}

// for push //
void push()
{
	int item;
	if(top>=MAX_SIZE-1)
	{
		printf("\nStack overflow");
	}
	else
	{
		printf("\nEnter the value : ");
		scanf("%d",&item);
		top++;
		stack[top]=item;
	}
}

// for pop //
void pop()
{
 int item;
 if(top < 0)
  printf("\nEMPTY / UNDERFLOW !!"); 
 else
 {
  item=stack[top];
  printf("\n%d is popped out:",item);
  stack[top] = NULL;
  top--;
 }
}


// for travers to display //
void traverse()
{
	int i=0,temp;
	if(top<0)
	{
		printf("\nEMPTY/UNDERFLOW");
	}
	
	temp=top;
	printf("\nStack element is : ");
	 while(temp >=0)
  {
  	printf(" %d",stack[temp]);
  	temp = temp - 1 ;
  }
}

// for peep //
void peep()
{
	int pos;
	printf("Enter the position num of peep : ");
	scanf("%d",&pos);
	
	if((top-pos+1)<0)
	{
		printf("\nsorry !! not possible\n");
		return;
	}
	printf("\n%d is peep out at locaton %d\n",stack[top-pos+1],pos);
	
 } 
