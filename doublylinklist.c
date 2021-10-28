#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>
struct linklist // self ref. structure
{
	int num;
	struct linklist *prev;
	struct linklist *next;
};
struct linklist *start;

void insert();
void display();
void del();
void edit();
void count();
void sort();
void reverse();
void exit();
void atbeg();
void atbeg1();
void atend();
void atend1();
void before();
void before1();
void after();
void after1();
void atpos();
void atpos1();

int main()
{
	int ch1;
	char choice1 = 'y';
	start = NULL;
	system("cls"); // clrscr();

	do
	{
		printf("\n 1. INSERT     ");
		printf("\n 2. DISPLAY     ");
		printf("\n 3. DELETE      ");
		printf("\n 4. EDIT        ");
		printf("\n 5. COUNT NODES ");
		printf("\n 6. SORTING      ");
		printf("\n 7. REVERSE     ");
		printf("\n 8. EXIT        ");

		printf("\n\n Enter Your Choice = ");
		scanf("%d", &ch1);

		switch (ch1)
		{
		case 1:
			insert();
			break;

		case 2:
			display();
			break;
		case 3:
			 del ( );
			break;
		case 4:
			 edit ( );
			break;
		case 5:
			 count ( );
			break;
		case 6:
		 sort();
			break;
		case 7:
			 reverse ( );
			break;
		case 8:
			choice1 = 'n';
			break;
		default:
			printf("\ninvalid choice");
		}
	} while (choice1 == 'y');
	return 0;
} // end of main //

void insert()
{
	int ch2;
	char choice2;

	do
	{
		printf("\n 1. ATBEG ");
		printf("\n 2. ATEND");
		printf("\n 3. BEFORE");
		printf("\n 4. AFTER ");
		printf("\n 5. ATPOSI");
		printf("\n 6. EXIT      ");

		printf("\n\n Enter Your Choice = ");
		scanf("%d", &ch2);

		switch (ch2)
		{
		case 1:
			atbeg();
			break;
		case 2:
			atend();
			break;
		case 3:
			 before ( );
			break;
		case 4:
			 after ( );
			break;
		case 5:
			 atpos ( );
			break;
		case 6:
			choice2 = 'n';
			break;
		default:
			printf("\nINVALID CHOICE");
		}
	} while (choice2 == 'y');
}

// to display//
void display()
{
	struct linklist *temp;
	temp=start;
	
	while(temp != NULL)
	{
		printf("<--%d-->",temp->num);
		temp = temp->next;
	}
	 
}

// atbeg //
void atbeg()
{
	struct linklist *temp,*node;
	node = (struct linklist*)malloc(sizeof(struct linklist));
	printf("\n\nEnter the data in doubly linklist :");
	scanf("%d",&node->num);
	
	node->next=NULL;
	node->prev=NULL;
	
	if(start==NULL)
	{
		start=node;
		return;
	}
	
	else
	{
		temp=start;
		start=node;
		node->next=temp;
		temp->prev=node;
	}
}

// atend //
void atend()
{
	struct linklist *temp,*node;
	node = (struct linklist*)malloc(sizeof(struct linklist));
	printf("\n\nEnter the data in doubly linklist : ");
	scanf("%d",&node->num);
	
	node->next=NULL;
	node->prev=NULL;
	
	if(start==NULL)
	{
		start=node;
		return;
	}
	temp=start;
	
	while(temp->next != NULL)
	{
		temp = temp->next;// temp is last node//
	}
	temp->next=node;
	node->prev=temp;
}

// at before //
void before( )
{
	int val;
	struct linklist *temp,*temp1,*node;

	printf("\n before which node u want to insert = ");
	scanf("%d",&val);

	node=(struct linklist*)malloc(sizeof(struct linklist));
	printf("enter the data of node = ");
	scanf("%d",&node->num);
	node->next = NULL;
	node->prev = NULL;

	temp=start;
	while(temp->num != val) // val = 50
	{
		temp1 = temp;
		temp = temp->next;
	}
	temp1->next=node;
	node->next=temp;
	node->prev=temp1;
}

void after()
{
	int val;
	struct linklist *temp,*node;
	printf("\n after which node u want to insert = ");
	scanf("%d",&val);

	node=(struct linklist*)malloc(sizeof(struct linklist));
	printf("enter the data of node :");
	scanf("%d",&node->num);
	node->next =NULL;

	temp=start;
	while(temp->num != val )
	{
		temp=temp->next;
	}
	node->next=temp->next;
	temp->next=node;
	node->prev=temp;
}

// to count //
void count()
{
	int count=0;
	struct linklist *temp;
	temp=start;
	
	while(temp!=NULL)
	{
		count=count+1;
		temp=temp->next;
	}
	printf("/n/n the total nodes = %d",count);
}
// for position//

void atpos()
{
	int n,i=1,c=0;
	printf("Where you want to add the node = ");
	scanf("%d",&n);
	
	struct linklist *temp,*temp1,*node;
	
	node=(struct linklist*)malloc(sizeof(struct linklist));
	printf("\n\n enter the data of node : ");
	scanf("%d",&node->num);
	node->next = NULL;
	node->prev = NULL;
	
	temp=start;
	
	while(temp!=NULL)
	{
		c=c+1;
		temp=temp->next;
	}
	
	if(n>c)
	{
		printf("Invalid entry");
		return;
	}
	temp=start;

	while(i<n)
	{
		i = i+1;
		temp1=temp;
		temp=temp->next;
	}
	temp1->next=node;
	node->next=temp;
	node->prev=temp1;
}

// to delete//
void del( )
{
	int ch3;
	char choice3;

	do
	{
		printf("\n 1. ATBEG 	");
		printf("\n 2. ATEND 	");
		printf("\n 3. BEFORE 	");
		printf("\n 4. AFTER      ");
		printf("\n 5. ATPOST   ");
		printf("\n 6. EXIT         ");

		printf("\n\n Enter Your Choice = ");
		scanf("%d",&ch3);

		switch(ch3)
		{
			case 1:
				atbeg1( );
				break;
			case 2:
				atend1( );
				break;
			case 3:
				before1( );
				break;
			case 4:
			    after1( );
				break;
			case 5:
				atpos1( );
				break;
			case 6:
				choice3='n';
				break;
			default:
				printf("\n\n INVALID CHOICE ");
			}
		}while(choice3=='y');
}
void atbeg1( )
{
	struct linklist *temp;
	temp=start;
	start=start->next;// start is the first node
	temp->next = NULL;// to delete the last node to previous node like 5 from 6
	temp->prev = NULL;
	free(temp);
}
void atend1( )

	{
		struct linklist *temp,*temp1;
		temp = start;
		while(temp->next!=NULL)
			{
				temp1=temp;
				temp=temp->next; //temp is last node
			}
			temp1->next=NULL;// to delete the last node to previous node like 5 from 6
			temp1->prev=NULL;
			free(temp);
	}
	
void before1( )
{
	int n;
	struct linklist *temp,*temp1,*temp2;
	printf("\n Before which node u want to delete = ");
	scanf("%d",&n);
	temp=start;
	temp1=temp->next;
	temp2=temp1->next;

	while(temp2->num != n)
	{
		temp=temp->next;
		temp1=temp->next;
		temp2=temp1->next;
	}
	temp->next=temp2;
	temp1->next=NULL;
	temp1->prev=NULL;
	free(temp1);
}
	
void after1( )
{
	int n;
	struct linklist *temp,*temp1,*temp2;
	printf("\n after which node u want to delete = ");
	scanf("%d",&n);
	temp=start;
	temp1=temp->next;
	temp2=temp1->next;

	while(temp->num != n) // only one change in this Line
	{
		temp=temp->next;
		temp1=temp->next;
		temp2=temp1->next;
	}
	temp->next=temp2;
	temp1->next=NULL;
	temp1->prev=NULL;
	free(temp1);
}	

void atpos1( )
{
	int i=1,c=0,n;
	struct linklist *temp,*temp1;
	printf("enter the position no =");
	scanf("%d",&n);
	temp=start;

	while(temp!=NULL)
	{
		c=c+1;
		temp=temp->next;
	}
	if (n>c)
	{
		printf("Not valid ");
		return;
	}
	temp=start;

	while(i<n)
	{
		i = i +1;
		temp1=temp;
		temp=temp->next;

	}
	temp1->next=temp->next;
	temp->next=NULL;
	temp->prev=NULL;
	free(temp);
}

void edit ( )
{
	int i=1,count=0,pos,num1;
	struct linklist *temp;
	printf("\n enter the position of node for edit =");
	scanf("%d",&pos);

	printf("\n\n enter the data of new node :");
	scanf("%d",&num1);

	temp=start;

	while(temp!=NULL)
	{
		count=count+1;
		temp=temp->next;
	}

	if(pos>count)
	{
		printf("\n Not valid");
		return;
	}

	temp=start;

	while(i<pos)
	{
		i=i+1;
		temp=temp->next;
	}
	temp->num=num1;
	num1->prev=temp;
	temp = NULL ;
	
	free(temp) ;
}

void reverse( )
{
	struct linklist *ptr,*temp,*old;
	temp=start;
	ptr=NULL;
	while(temp!=NULL)
	{
		old       = ptr;
		ptr       = temp;
		temp      = temp->next;
		ptr->next = old;
	}
	start=ptr;
}

void sort( )
{
	int n;
	struct linklist *temp,*temp1;
	temp=start;
	while(temp==start)
	while(temp!=NULL)
	{
		temp1=temp->next;
		while(temp1!=NULL)
		{
			if(temp->num>temp1->num)
			{
				n=temp->num;
				temp->num=temp1->num;
				temp1->num=n;
			}
			temp1=temp1->next;
		}
		temp=temp->next;
	}
}


