// QUEUE OPRATION USING ARRAY //

#include<stdio.h>
#include<stdlib.h>
#define MAX 5

void push();
void pop();
void traverse();

int front=-1,rear=-1;
int queue[MAX];

int main()
{
   int ch;
   
   printf("QUEUE APPLICATION: USING ARREY : ");
   do
   {
       printf("\n1.PUSH\n");
       printf("2.POP\n");
       printf("3.TRAVERSE\n");
       printf("4.EXIT\n");
       printf("Enter your choise : ");
       scanf("%d",&ch);
       switch(ch)
       {
           case 1:push();break;
           case 2:pop();break;
           case 3:traverse();break;
           case 4:printf("END OF QUEUE APPLICATION :");break;
           default:printf("YOU HAVE ENTER A WRONG CHOISE:");
       }
   }
   while(ch!=4);
   return 0;
}

void push()
{
    int item;
    if(rear>=MAX-1)
    {
        printf("\nQUEUE OVERFLOW !!");
        return;
    }
    printf("\n       Enter the number to push : ");
    scanf("%d",&item);

    if(front==-1)  // if this is first number
    {
        front += 1;
        rear += 1;
    }
    else
    {
        rear += 1;
    }

    queue[rear]=item;
}

void pop()
{
    int item=0;
    if(front<0)
    {
        printf("\nQUEUE IS EMPTY !!");
        return;
    }
    if(front==rear)
    {
        item=queue[front] ;   // for only one element in queue
        queue[front] = NULL;
        front  = -1;
        rear = -1;
        printf("\n       %d is deleted",item);
        return;
    }

    item=queue[front];      // for many element of queue.
    queue[front] = NULL;
    front = front+1;
    printf("\n       %d is deleted",item);
}

void traverse()
{
    int temp;
    if(front<0)
    {
        printf("\nQUEUE IS EMPTY !!");
        return;
    }
    temp=front;
    printf("\n       element of queue : ");
    while(temp<=rear)
    {
        printf("%d->",queue[temp]);
        temp=temp+1;
    }
}