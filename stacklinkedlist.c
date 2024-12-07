#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
struct Node *top;
void push()
{
	int item;
	struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
	printf("\nEnter value to push:");
	scanf("%d",&item);
	newnode->data=item;
	newnode->next=top;
	top=newnode;
}
void pop()
{
	int data;
	struct Node *temp;
	temp=top;
	if(temp==NULL)
		printf("\nStack is empty");
	else
	{
		data=top->data;
		printf("Value popped:%d",data);
		top=temp->next;
		free(temp);
	}
}
void search()
{
	struct Node *temp;
	int key;
	temp=top;
	printf("\nEnter key:");
	scanf("%d",&key);
	while(temp!=NULL)
	{
		if(temp->data==key)
		{
			printf("Element found!!");
			break;
		}
		temp=temp->next;
	}
	if(temp==NULL)
		printf("\nElement not found");
}
void display()
{
	struct Node *temp;
	temp=top;
	printf("\nStack:\t");
	if(top==NULL)
		printf("\nStack is empty");
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
}
int main()
{
	int o;
	do
	{
		printf("\nSELECT ONE\n1. PUSH\n2. POP\n3. SEARCH\n4. DISPLAY\n5. EXIT\nYour option:");
		scanf("%d",&o);
		switch(o)
		{
			case 1:push();
				break;
			case 2:pop();
				break;
			case 3:search();
				break;
			case 4:display();
				break;
			case 5:printf("Thank you!(o_o)\n");
				break;
			default:printf("Wrong option");
		};
	}while(o!=5);
	return 0;
}
