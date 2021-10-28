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
		//	 del ( );
			break;
		case 4:
		//	 edit ( );
			break;
		case 5:
		//	 count ( );
			break;
		case 6:
		//	 sort();
			break;
		case 7:
		//	 reverse ( );
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
		//	 before ( );
			break;
		case 4:
		//	 after ( );
			break;
		case 5:
		//	 atpos ( );
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

// at
