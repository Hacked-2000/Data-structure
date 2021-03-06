#include<stdio.h>
#include<stdlib.h>
struct rec
{
	int num;
	struct rec *left;
	struct rec *right;	
};

struct rec *tree = NULL;

struct rec *insert(struct rec *,int);
void search(struct rec *tree,int num);

void preorder(struct rec *tree);
void inorder(struct rec *tree);
void postorder(struct rec *tree);

int main()
{
	int choice;
	int digit;
	do
	{
		choice = select();
		switch(choice)
		{
			case 1:
				puts("Enter integer : To quit enter 0 ");
				scanf("%d",&digit);
				while(digit != 0)
				{
					tree = insert(tree,digit);
					scanf("%d",&digit);
				}continue;
			case 2: puts ("Enter the number to be search ");
					scanf("%d",&digit);
					search(tree,digit);
					continue;
			case 3:
				puts("\n Preorder Traversing Tree :");
				preorder(tree);continue;
			case 4:
				puts("\n Inorder Traversing Tree :");
				inorder(tree);continue;
			case 5:
				puts("\n Postorder Traversing Tree :");
				postorder(tree);continue;
			case 6:
				puts("********************END*******************");
				exit(0);
		}
	}while(choice != 7);
return 0;
}
int select()
	{
		int selection;
		do
		{
			puts("\nEnter 1 : Insert a node in the BST ");
			puts("Enter 2 : Search a node in the BST");
			puts("Enter 3 : Display (preorder) the BST");
			puts("Enter 4 : Display (inorder) the BST");
			puts("Enter 5 : Display (postorder) the BST");
			puts("Enter 6 : END ");
			puts("Enter your choice ");
			scanf("%d",&selection);
			if((selection < 1) || (selection > 7))
			{
				puts("wrong choice : try again");
				getch();
			}
		}while((selection < 1) || (selection >7));
		return selection;
	}
	
	struct rec *insert(struct rec *tree,int digit)
	{
		if(tree == NULL)
		{
			tree = (struct rec *) malloc (sizeof(struct rec));
			tree->left = tree->right = NULL;
			tree->num = digit;
			
		}
		else if ( digit < tree -> num )
			tree->left = insert(tree->left,digit);
		else if ( digit > tree-> num)
		   tree->right = insert(tree->right,digit);
		else if(digit == tree->num)
		{
			puts("Duplicate node : program exited ");
			exit(0);
		}
		return(tree);
	}
//	void search(struct
 void search(struct rec *tree , int digit)
	{
		if(tree==NULL)
		puts("The number does not exits \n ");
		else if(digit == tree -> num )
		printf("Number = %d Exists \n",digit);
		else if(digit < tree->num)
		search(tree->left,digit); // recursive Call
		else
		search(tree->right,digit); // recursive call
	}
	void preorder(struct rec *tree)  // N L R
	{
		if(tree != NULL)
		{
			printf("\n%d ",tree->num );  
			preorder(tree->left);
			preorder(tree->right);
		}
	}
	void inorder(struct rec *tree)  // L N R
	{
		if(tree != NULL)
		{
			inorder(tree->left);
			printf("\n%d ",tree->num );
			inorder(tree->right);
		}
	}
	void postorder(struct rec *tree)  // L R N
	{
		if(tree != NULL)
		{
			postorder(tree->left);
			postorder(tree->right);
			printf("\n%d ",tree->num );
		}
	}

