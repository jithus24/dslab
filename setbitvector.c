#include<stdio.h>
#define SIZE 100
int n,u[SIZE],a[SIZE],b[SIZE],bita[SIZE],bitb[SIZE],na,nb,i,j,k;
void display(int x[])
{
	printf("{");
	for(i=0;i<n;i++)
	{
		if(x[i])
			printf("%d ",u[i]);
	}
	printf("}");
}
void bunion(int a[],int b[])
{
	int c[SIZE];
	for(i=0;i<n;i++)
		c[i]=a[i]|b[i];
	printf("UNION:\n");
	display(c);
}
void bintersection(int a[],int b[])
{
        int c[SIZE];
        for(i=0;i<n;i++)
                c[i]=a[i]&b[i];
        printf("INTERSECTION:\n");
        display(c);
}
void bdiff(int a[],int b[])
{
        int c[SIZE];
        for(i=0;i<n;i++)
                c[i]=a[i]&(~b[i]);
        display(c);
}

int main()
{
	int un[SIZE],in[SIZE],di[SIZE],f;
	printf("Enter the size of universal set:");
	scanf("%d",&n);
	printf("Enter universal set:");
	for(i=0;i<n;i++)
		scanf("%d",&u[i]);
	printf("Enter the size of set A:");
        scanf("%d",&na);
        printf("Enter set A:");
        for(i=0;i<na;i++)
	{
		f=0;
                scanf("%d",&a[i]);
		for(j=0;j<n;j++)
		{
			if(a[i]==u[j])
				f=1;
		}
		if(f==0)
		{
			printf("%d is not in universal set\nEnter another value:",a[i]);
			i--;
		}
	}
	printf("Enter the size of set B:");
        scanf("%d",&nb);
        printf("Enter set B:");
        for(i=0;i<nb;i++)
	{
		f=0;
                scanf("%d",&b[i]);
		for(j=0;j<n;j++)
                {
                        if(b[i]==u[j])
                                f=1;
                }
		if(f==0)
		{
                	printf("%d is not in universal set\nEnter another value:",b[i]);
                	i--;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<na;j++)
		{
			bita[i]=0;
			if(a[j]==u[i])
			{
				bita[i]=1;
				break;
			}
		}
		for(k=0;k<nb;k++)
		{
			bitb[i]=0;
			if(b[k]==u[i])
			{
				bitb[i]=1;
				break;
			}
		}
	}
	printf("SET A:\n");
	display(bita);
	printf("\n");
	printf("SET B:\n");
	display(bitb);
	printf("\n");
	bunion(bita,bitb);
	printf("\n");
	bintersection(bita,bitb);
	printf("\n");
	printf("DIFFERENCE:\n");
	printf("A-B=");
	bdiff(bita,bitb);
	printf("\nB-A=");
	bdiff(bitb,bita);
	printf("\n");
}
