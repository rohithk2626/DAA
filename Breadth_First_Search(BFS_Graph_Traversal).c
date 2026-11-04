/*
 * Breadth First Search (BFS) Graph Traversal
 *
 * Description:
 * Traverses an undirected graph level by level, starting from a given
 * vertex, using a queue. The graph is entered as a list of edges and the
 * program prints the vertices in the order they are visited.
 *
 * Algorithm Used: Breadth First Search (queue based)
 * Time Complexity: O(n^2) (adjacency matrix)
 * Space Complexity: O(n^2)
 *
 * How to Compile & Run:
 *   Linux / macOS (terminal):
 *       gcc "Breadth_First_Search(BFS_Graph_Traversal).c" -o bfs
 *       ./bfs
 *   Windows (Command Prompt / PowerShell with MinGW gcc):
 *       gcc "Breadth_First_Search(BFS_Graph_Traversal).c" -o bfs.exe
 *       bfs.exe          (in PowerShell type: .\bfs.exe)
 *   (Keep the double quotes - the file name contains brackets.)
 *   You can also save the inputs in a text file and run:  ./bfs < input.txt
 *   Online: paste the code into any online C compiler (e.g. OnlineGDB) and
 *   type the inputs in the input/stdin box.
 *
 * Input Format (in this order):
 *   1. n        -> number of vertices (1 to 19)
 *   2. m        -> number of edges
 *   3. edges    -> m lines, each edge as two vertex numbers "u v"
 *                  (undirected)
 *   4. v        -> starting vertex (1 to n)
 *
 * Sample Input:
 *   5
 *   5
 *   1 2
 *   1 3
 *   2 4
 *   3 4
 *   4 5
 *   1
 *
 * Sample Output:
 *   Visited vertices:1   2   3   4   5
 *
 * Note:
 * - Vertices are numbered from 1 to n.
 * - The graph should be connected, otherwise the output is not meaningful.
 */

#include<stdio.h>
#include<stdlib.h>
void bfsearch();
int cost[20][20],explored[20],visited[20];
int qu[20];
int f=0,r=0;
int i,j,k,n,v,m;
int main()
{
	printf("Enter no of vertices:");
	scanf("%d",&n);
	printf("\nEnter no edges:");
	scanf("%d",&m);
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	cost[i][j]=0;
	for(i=1;i<=n;i++)	/* initialise every vertex (was looping to m) */
	{
		visited[i]=0;
		explored[i]=0;
	}
	printf("\nEdges:");
	for(k=1;k<=m;k++)	/* read exactly m edges (was looping n times) */
	{
		scanf("%d%d",&i,&j);
		cost[i][j]=cost[j][i]=1;
	}
	printf("\nEnter starting vertex:");
	scanf("%d",&v);
	printf("\nVisited vertices:");
	printf("%d\t",v);
	visited[v]=1;
	bfsearch();
	return 0;
}
void bfsearch()
{
	k=1;
	while(k<n)
	{
		for(j=1;j<=n;j++)
		{
			if(cost[v][j]!=0 && visited[j]!=1 && explored[j]!=1)
			{
				explored[j]=1;
				qu[r++]=j;
			}
		}
		v=qu[f++];
		printf("%d\t",v);
		k++;
		explored[v]=0;
		visited[v]=1;
	}
}
