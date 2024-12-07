#include<stdio.h>
#include<stdlib.h>
struct Node
{
        int data;
        struct Node *next,*prev;
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
{        int item;
        struct Node *newnode=createNode();
        printf("\nEnter value to insert:");
        scanf("%d",&item);
        newnode->data=item;
	newnode->prev=NULL;
        newnode->next=head;
	if(head!=NULL)
	head->prev=newnode;
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
	{
		newnode->prev=NULL;
                head=newnode;
	}
        else
        {
                temp=head;
                while(temp->next!=NULL)
                        temp=temp->next;
                temp->next=newnode;
		newnode->prev=temp;
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
                temp=head;
                for(int i=0;i<pos;i++)
                {
                        if(temp==NULL)
                        {
                                printf("Position is out of bounds");
                                return;
                        }
                        else
                                temp=temp->next;
                }
		if(temp==NULL)
		{
			insertAtEnd();
			return;
		}
		printf("Enter the value:");
                scanf("%d",&item);
                newnode->data=item;
                newnode->next=temp;
		newnode->prev=temp->prev;
		//if(temp->prev!=NULL)
		temp->prev->next=newnode;
                //temp->next=newnode;
		temp->prev=newnode;
        }
}
void deleteOnlyNode()
{
	temp=head;
	head=NULL;
	printf("value deleted:%d",temp->data);
	free(temp);
}
void deleteFromBeginning()
{
        isEmpty();
	if(head->next==NULL)
		deleteOnlyNode();
        else if(head!=NULL)
        {
                temp=head;
                printf("value deleted:%d",temp->data);
                head=head->next;
		head->prev=NULL;
                free(temp);
        }
}
void deleteFromEnd()
{
        isEmpty();
	if(head->next==NULL)
		deleteOnlyNode();
        else if(head!=NULL)
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
                        for(int i=0;i<pos;i++)
                        {
                                if(temp->next==NULL)
				{
                                        printf("Position is out of bounds");
					return;
				}
                                temp=temp->next;
                        }
			if(temp->next==NULL)
			{
				deleteFromEnd();
				return;
			}
                        ptr=temp;
                        temp->next->prev=temp->prev;
			temp->prev->next=temp->next;
			printf("value deleted:%d",ptr->data);
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
        printf("SELECT ONE:\n1. INSERT at beginning\n2. INSERT at end\n3. INSERT at any position\n4. DELETE from beginning\n5. DELETE from end\n6. DELETE from any position\n7. SEARCH\n8. DISPLAY\n9. EXIT");
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
			case 9:printf("\nThank you !!");
				break;
			default:printf("\nWrong Input !");
		}
        }while(o!=9);
}
