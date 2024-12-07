#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *parent,*left,*right;
};
struct Node *root,*temp,*parent;
int isEmpty()
{
	if(root==NULL)
	{
		printf("Tree is empty");
		return(1);
	}
	return(0);
}
struct Node* createNode()
{
        struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
	newnode->left=newnode->right=newnode->parent=NULL;
        return(newnode);
}
void insertion()
{
	int value;
	struct Node *newnode=createNode();
	printf("Enter value:");
	scanf("%d",&value);
	newnode->data=value;
	if(root==NULL)
	{
		root=newnode;
		return;
	}
	temp=root;
	while(temp!=NULL)
	{
		parent=temp;
		if(value<temp->data)
			temp=temp->left;
		else
			temp=temp->right;
	}
	if(value<parent->data)
		parent->left=newnode;
	else
		parent->right=newnode;
	newnode->parent=parent;
}
void valueDeleted(struct Node* temp)
{
	printf("Value deleted:%d",temp->data);
	free(temp);
}
struct Node* successor(struct Node *node)
{
	while(node->left!=NULL)
		node=node->left;
	return(node);
}
void deletion()
{
	struct Node *suc,*sparent;
	int value,lc=0;
	if(!isEmpty())
	{
		printf("Enter value to be deleted:");
		scanf("%d",&value);
		temp=root;
		parent=NULL;
		while(temp!=NULL && temp->data!=value)
		{
			parent=temp;
			if(value<temp->data)
			{
				temp=temp->left;
				lc=1;
			}
			else
			{
				temp=temp->right;
				lc=0;
			}
		}
		if(temp==NULL)
		{
			printf("Value not found!");
			return;
		}
		if(temp->left==NULL && temp->right==NULL)
		{
			if(temp==root)
			{
				valueDeleted(temp);
				root=NULL;
				return;
			}
			if(lc)
				parent->left=NULL;
			else
				parent->right=NULL;
			valueDeleted(temp);
		}
		else if(temp->left==NULL)
		{
			if(temp==root)
			{
				root=temp->right;
				valueDeleted(temp);
				return;
			}
			else if(lc)
			{
				parent->left=temp->right;
			}
			else
			{
				parent->right=temp->right;
			}
			temp->right->parent=parent;
			valueDeleted(temp);
		}
		else if(temp->right==NULL)
                {
                        if(temp==root)
                        {
                                root=temp->left;
                                valueDeleted(temp);
                                return;
                        }
                        else if(lc)
                        {
                                parent->left=temp->left;
                        }
                        else
                        {
                                parent->right=temp->left;
                        }
                        temp->left->parent=parent;
                        valueDeleted(temp);
                }
		else
		{
			suc=successor(temp->right);
			if(suc!=temp->right)
			{
				sparent=suc->parent;
				sparent->left=suc->right;
				if(suc->right!=NULL)
					suc->right->parent=sparent;
				suc->right=temp->right;
				temp->right->parent=suc;
			}
			suc->left=temp->left;
			temp->left->parent=suc;
			if(temp=root)
			{
				root=suc;
				valueDeleted(temp);
				return;
			}
			else if(lc)
				parent->left=suc;
			else
				parent->right=suc;
			suc->parent=parent;
			valueDeleted(temp);
		}
	}
}
void inorder(struct Node* node)
{
	isEmpty();
	if(node!=NULL)
	{
		inorder(node->left);
		printf("%d\t",node->data);
		inorder(node->right);
	}
}
void preorder(struct Node* node)
{
	isEmpty();
	if(node!=NULL)
	{
		printf("%d\t",node->data);
		preorder(node->left);
		preorder(node->right);
	}
}
void postorder(struct Node* node)
{
	isEmpty();
	if(node!=NULL)
	{
		postorder(node->left);
		postorder(node->right);
		printf("%d\t",node->data);
	}
}
void search(struct Node* node,int key)
{
	if(!isEmpty())
	{
		if(node==NULL)
		{
			printf("Value not found");
			return;
		}
		if(key==node->data)
			printf("Value found");
		else if(key<node->data)
			search(node->left,key);
		else
			search(node->right,key);
	}
}
int main()
{
	int o,key;
        printf("SELECT ONE:\n1. INSERT\n2. DELETE \n3. INORDER TRAVERSAL\n4. PREORDER TRAVERSAL\n5. POSTORDER TRAVERSAL\n6. SEARCH\n7. EXIT");
        do
        {
                printf("\nYour option:");
                scanf("%d",&o);
                switch(o)
                {
                        case 1:insertion();
                                break;
                        case 2:deletion();
                                break;
                        case 3:inorder(root);
                                break;
                        case 4:preorder(root);
                                break;
                        case 5:postorder(root);
                                break;
                        case 6:printf("Enter value to search:");
				scanf("%d",&key);
				search(root,key);
                                break;
                        case 7:printf("thank you!!\n");
                                break;
                        default:printf("Wrong input");
                }
        }while(o!=7);
        return 0;
	return 0;
}
