#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100
int s=0;
struct Item;
struct Node
{
	int val;
	struct Node *next;
	struct Item *itemPtr;
};
struct Item
{
	struct Node *hd, *tl;
};
struct ListSet
{
	struct Node* nodeAddress[SIZE];
};
void makeset(struct ListSet* set, int a);
struct Item* find(struct ListSet* set, int key);
void Union(struct ListSet* set, struct Item* set1, struct Item* set2);
void printItem(struct Item* item);
void makeset(struct ListSet* set, int a)
{
	struct Item *newSet = (struct Item*)malloc(sizeof(struct Item));
	newSet->hd = (struct Node*)malloc(sizeof(struct Node));
	newSet->tl = newSet->hd;
	set->nodeAddress[a] = newSet->hd;
	newSet->hd->val = a;
	newSet->hd->itemPtr = newSet;
	newSet->hd->next = NULL;
	//s++;
}
struct Item* find(struct ListSet* set, int key)
{
	struct Node *ptr = set->nodeAddress[key];
	if(ptr==NULL)
		return NULL;
    	return ptr->itemPtr;
}
void Union(struct ListSet* set, struct Item* set1, struct Item* set2)
{
    	struct Node *cur = set2->hd;
   	while (cur != NULL)
    	{
        	cur->itemPtr = set1;
        	cur = cur->next;
    	}
	set1->tl->next = set2->hd;
    	set1->tl = set2->tl;
	free(set2);
	//s--;
}
void printItem(struct Item* item)
{
    	struct Node* cur = item->hd;
    	while (cur != NULL)
    	{
        	printf("%d ", cur->val);
        	cur = cur->next;
    	}
    	printf("\n");
}
void display()
{
	struct ListSet* set;
	for(int i=0;i<SIZE;i++)
	{
		printItem(set->nodeAddress[i]->itemPtr);
	}
}
int main()
{
	int o,k,l;
	struct Item* ptr;
	struct ListSet a;
	memset(&a, 0, sizeof(struct ListSet));
	printf("SELECT ONE:\n1.Make Set\n2.Union\n3.Display Set\n4.Find\n5.Exit");
	do{
		printf("\nYour Option:");
		scanf("%d",&o);
		switch(o)
		{
			case 1:printf("\nEnter an element:");
				scanf("%d",&k);
				if(find(&a,k)==NULL)
					makeset(&a,k);
				else
					printf("Element already exists:");
				break;
			case 2:printf("\nEnter any two set elements:");
				scanf("%d%d",&k,&l);
				if(find(&a,k)!=NULL && find(&a,l)!=NULL)
					Union(&a,find(&a,k),find(&a,l));
				else
					printf("Element not found");
				break;
			case 3:printf("\nEnter any set element:");
				scanf("%d",&k);
				if(find(&a,k)!=NULL)
					printItem(find(&a,k));
				else
                                        printf("Element not found");
				break;
			case 4:printf("\nEnter element to search:");
				scanf("%d",&k);
				if(find(&a,k)!=NULL)
					printf("Item found\nRepresentative Element:%d",find(&a,k)->hd->val);
				else
					printf("Item not found");
				break;
			case 6:display();
				break;
			case 5:printf("Thank you!\n");
				break;
			default:printf("\nWrong Input");
		}
	}while(o!=5);
    	return 0;
}
