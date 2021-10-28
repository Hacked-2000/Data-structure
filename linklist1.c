void before( )
{
	int val;
	struct linklist *temp,*temp1,*node;

	printf("\n before which node u want to insert = ");
	scanf("%d",&val);

	node=(struct linklist*)malloc(sizeof(struct linklist));
	printf("enter the data of node");
	scanf("%d",&node->num);
	node->next = NULL;

	temp=start;
	while(temp->num != val) // val = 50
	{
		temp1 = temp;
		temp = temp->next;
	}

