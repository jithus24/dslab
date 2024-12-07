#include<stdio.h>
#define SIZE 100
int front=0,rear=-1,q[SIZE],s;
int isEmpty()
{
	if(rear==-1)
	{
		printf("Queue is empty!");
		return(1);
	}
	else
		return(0);
}
int isFull()
{
	if((rear+2)%(s+1)==front)
	{
		printf("Queue is full!");
		return(1);
	}
	else
		return(0);
}
void enqueue()
{
	int value;
	if(!isFull())
	{
		printf("Enter the value to insert:");
		scanf("%d",&value);
		(rear++)%s;
		q[rear]=value;
	}
}
void dequeue()
{
	if(!isEmpty())
	{
		printf("Deleted value:%d",q[front]);
		if(front==rear)
		{
			front=0;
			rear=-1;
		}
		else
			(front++)%s;
	}
}
void display()
{
	int i=front;
	while(!isEmpty())
	{
		printf("%d\t",q[i]);
		if(i==rear)
			break;
		(i++)%s;
	}
}
void search()
{
	int key,i=front;
	printf("Enter value to search:");
	scanf("%d",&key);
	while(!isEmpty())
        {
                if(key==q[i])
		{
			printf("Value found!");
			break;
		}
                if(i==rear)
		{
			printf("Value not found!");
                        break;
		}
                (i++)%s;
        }
}
int main()
{
	printf("Enter size of queue:");
	scanf("%d",&s);
	int c;
	printf("SELECT ONE:\n1. ENQUEUE\n2. DEQUEUE\n3. DISPLAY\n4. SEARCH\n5. EXIT");
	do
	{
		printf("\nYour option:");
		scanf("%d",&c);
		switch(c)
		{
			case 1:enqueue();
				break;
			case 2:dequeue();
				break;
			case 3:display();
				break;
			case 4:search();
				break;
			case 5:printf("Thank you!\n");
				break;
			default:printf("Wrong input!");
		}
	}while(c!=5);
	return 0;
}
