#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
struct Node *head,*temp,*ptr;
struct Node* createNode()
{
	struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
	return(newnode);
}
void isEmpty()
{
	if(head==NULL)
		printf("List is empty");
}
void insertAtBeginning()
{
	int item;
	struct Node *newnode=createNode();
	printf("\nEnter value to insert:");
        scanf("%d",&item);
        newnode->data=item;
        newnode->next=head;
        head=newnode;
}
void insertAtEnd()
{
	int item;
	struct Node *newnode=createNode();
	printf("\nEnter value to insert:");
        scanf("%d",&item);
	newnode->data=item;
	newnode->next=NULL;
	if(head==NULL)
		head=newnode;
	else
	{
		temp=head;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=newnode;
	}
}
void insertAtPosition()
{
	int item,pos;
	struct Node *newnode=createNode();
	printf("Enter position:");
	scanf("%d",&pos);
	if(pos==0)
		insertAtBeginning();
	else
	{
		printf("Enter the value:");
		scanf("%d",&item);
		newnode->data=item;
		temp=head;
		for(int i=1;i<pos;i++)
		{
			if(temp->next==NULL)
			{
				printf("Position is out of bounds");
				return;
			}
			else
				temp=temp->next;
		}
		newnode->next=temp->next;
		temp->next=newnode;
	}
}
void deleteFromBeginning()
{
	isEmpty();
	if(head!=NULL)
	{
		temp=head;
		printf("value deleted:%d",temp->data);
		head=head->next;
		free(temp);
	}
}
void deleteFromEnd()
{
	isEmpty();
	if(head!=NULL)
	{
		if(head->next==NULL)
			deleteFromBeginning();
		else
		{
			temp=head;
			while(temp->next!=NULL)
			{
				ptr=temp;
				temp=temp->next;
			}
			ptr->next=NULL;
			printf("value deleted:%d",temp->data);
			free(temp);
		}
	}
}
void deleteFromPosition()
{
	int pos;
	isEmpty();
	if(head!=NULL)
	{
		printf("Enter position:");
		scanf("%d",&pos);
		if(pos==0)
			deleteFromBeginning();
		else
		{
			temp=head;
			for(int i=1;i<pos;i++)
			{
				if(temp==NULL || temp->next==NULL)
					printf("Position is out of bounds");
				temp=temp->next;
			}
			ptr=temp->next;
			temp->next=temp->next->next;
			free(ptr);
		}
	}
}
void search()
{
	int value;
	isEmpty();
	if(head!=NULL)
	{
		printf("Enter value to search:");
		scanf("%d",&value);
		temp=head;
		while(temp!=NULL)
		{
			if(temp->data==value)
			{
				printf("Found");
				return;
			}
			temp=temp->next;
		}
		printf("Not found");
	}
}
void display()
{
	isEmpty();
	if(head!=NULL)
	{
		temp=head;
		while(temp!=NULL)
		{
			printf("%d\t",temp->data);
			temp=temp->next;
		}
	}
}
int main()
{
	int o;
	printf("SELECT ONE:\n1. INSERT at beginning\n2. INSERT at end\n3. INSERT at any position\n4. DELETE from beginning\n5. DELETE from end\n6. DELETE from any position\n7. SEARCH\n8. DISPLAY\n9. EXIT\n");
	do
	{
		printf("\nYour option:");
		scanf("%d",&o);
		switch(o)
		{
			case 1:insertAtBeginning();
				break;
			case 2:insertAtEnd();
				break;
			case 3:insertAtPosition();
				break;
			case 4:deleteFromBeginning();
				break;
			case 5:deleteFromEnd();
				break;
			case 6:deleteFromPosition();
				break;
			case 7:search();
				break;
			case 8:display();
				break;
			case 9:printf("thank you!!\n");
				break;
			default:printf("Wrong input");
		}
	}while(o!=9);
	return 0;
}
