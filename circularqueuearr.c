/*Circular QUEUE OPERATIONS USING ARRAY*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int front=-1,rear=-1;
int cqueue[MAX];
void push();
void pop();
void traverse();
int main()
{
 
 int ch;
 
 printf("Circular QUEUE APPLICATION:USING ARRAY:");
 do
 {
  printf("\n1.PUSH\n");
  printf("2.POP\n");
  printf("3.TRAVERSE\n");
  printf("4.EXIT\n");
  printf("enter your choice:");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:push();break;
   case 2:pop();break;
   case 3:traverse();break;
   case 4:printf("END OF Circular QUEUE APPLICATION:");break;
   default:printf("YOU HAVE ENTERED WRONG CHOICE:");
  }
 }while(ch!=4);
	return 0;
}

void push()
{
 int item;
 if((front == (rear+1) % MAX))
 {
  printf("Circular QUEUE OVERFLOW");
  return ;
 }
 printf("enter no for insertion:");
 scanf("%d",&item);
  if( front == -1)
  {
  		front++;
  		rear++;
  }
  else
  {
  		rear = (rear+1) % MAX ;
  }
  cqueue[rear]=item;
 
  
 }

void pop()
{
 int item=0;
 if(front == -1)
 {
  printf("Circular QUEUE IS EMPTY: Underflow !!");
  return ;
 }
 if(front==rear)
  {
   item=cqueue[front];
   cqueue[front] = 0;
   front=-1;
   rear=-1;
   printf("%d is deleted:",item);
   return ;
  }
   item=cqueue[front];
   cqueue[front] = 0;
   front = (front+1) % MAX ;
   printf("%d is deleted:",item);

}


/* void traverse()
{
	int temp;
	if(front==-1)
	{
		printf("Queue is Empty.");
		return;
	}
	temp=front;
	if(temp>rear)
	{
		while(temp>=(rear+1)%MAX)
		{
		printf("| %d |",cqueue[temp]);
	
		temp=(temp+1)%MAX;	
		}
		if(temp<=rear)
		{
			while(temp<=rear)
			{
				printf("| %d |",cqueue[temp]);
				temp=temp+1;
			}
		}
	}
	if(temp<=rear)
	{
		while(temp<=rear)
		{
			printf("| %d |",cqueue[temp]);
			temp=temp+1;
		}
	}
} */

void traverse()
{
	int temp;
	if(front==-1)
	{
		printf("Queue is Empty.");
		return;
	}
	temp=front;
	if(temp>rear)
	{
		while(temp>=(rear+1)%MAX)
		{
		printf("| %d |",cqueue[temp]);
	
		temp=(temp+1)%MAX;	
		}
		
	}
	if(temp<=rear)
	{
		while(temp<=rear)
		{
			printf("| %d |",cqueue[temp]);
			temp=temp+1;
		}
	}
}
