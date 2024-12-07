#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 100
void bfs(int graph[MAX_VERTICES][MAX_VERTICES],int vertices,int start)
{
	int visited[MAX_VERTICES]={0};
	int queue[MAX_VERTICES],front=-1,rear=-1;
	int i;
	visited[start]=1;
	queue[++rear]=start;
	printf("BFS starting from vertex %d: ",start);
	while(front!=rear)
	{
		front++;
		int node=queue[front];
		printf("%d\t",node);
		for(i=0;i<vertices;i++)
		{
			if(graph[node][i]==1&&!visited[i])
			{
				visited[i]=1;
	                	queue[++rear]=i;
            		}
        	}
    	}
    	printf("\n");
}
void dfs(int graph[MAX_VERTICES][MAX_VERTICES],int vertices,int visited[MAX_VERTICES],int node)
{
    	printf("%d\t",node);
    	visited[node]=1;
    	for(int i=0;i<vertices;i++)
	{
        	if(graph[node][i]==1 && !visited[i])
            		dfs(graph,vertices,visited,i);
    	}
}
void dfs_topo(int graph[MAX_VERTICES][MAX_VERTICES],int vertices,int visited[MAX_VERTICES],int node,int stack[MAX_VERTICES],int *top)
{
    	visited[node]=1;
    	for(int i=0;i<vertices;i++)
	{
        	if(graph[node][i]==1 && !visited[i])
            		dfs_topo(graph,vertices,visited,i,stack,top);
    	}
    	stack[++(*top)]=node;
}
void topologicalSort(int graph[MAX_VERTICES][MAX_VERTICES],int vertices)
{
    	int visited[MAX_VERTICES]={0};
    	int stack[MAX_VERTICES],top=-1;
    	for(int i=0;i<vertices;i++)
	{
        	if(!visited[i])
            		dfs_topo(graph, vertices, visited, i, stack, &top);
    	}
 	printf("\nTopological Sort: ");
    	for(int i=top;i>=0;i--)
        	printf("%d\t",stack[i]);
    	printf("\n");
}
int main()
{
   	int graph[MAX_VERTICES][MAX_VERTICES]={0};
    	int vertices,u,v,c;
    	printf("Enter the number of vertices: ");
    	scanf("%d",&vertices);
    	char labels[vertices][50];
    	printf("Enter the labels for the vertices:\n");
    	for(int i=0;i<vertices;i++)
	{
        	printf("Enter label for vertex %d: ",i);
        	scanf("%s",labels[i]);
   	}
	for(int i=0;i<vertices;i++)
	{
        	printf("\nFor vertex %s , choose vertices to connect to:\n", labels[i]);
        	while(1)
		{
            		printf("Enter vertex index to connect (or -1 to stop): ");
            		scanf("%d",&v);
            		if(v==-1)
				break;
            		if(v>=0 && v<vertices)
			{
                		graph[i][v]=1;
                		printf("Edge added from %s to %s.\n",labels[i],labels[v]);
			}
			else
				printf("Invalid vertex index! Please enter a valid index.\n");
		}
	}
	printf("\nAdjacency Matrix:\n");
	for(int i=0;i<vertices;i++)
	{
		for(int j=0;j<vertices;j++)
			printf("%d\t",graph[i][j]);
		printf("\n");
    	}
	printf("SELECT ONE:\n1.BFS\n2.DFS\n3.Topological Sort\n");
	do
	{
		printf("Your option:");
		scanf("%d",&c);
		switch(c)
		{
			case 1:printf("\nEnter the starting vertex index for BFS:");
				scanf("%d",&u);
				bfs(graph,vertices,u);
				int visited[MAX_VERTICES]={0};
				break;
			case 2:printf("\nEnter the starting vertex index for DFS: ");
				scanf("%d",&u);
				printf("DFS starting from vertex %d: ",u);
				dfs(graph,vertices,visited,u);
				printf("\n");
				break;
			case 3:topologicalSort(graph,vertices);
				break;
			case 4:printf("Thank you\n");
				break;
			default:printf("Wrong input!");
		}
	}while(c!=4);
	return 0;
}
