/*
 * Minimum Cost Spanning Tree using Prim's Algorithm
 *
 * Description:
 * Finds the minimum cost spanning tree of a connected, undirected, weighted
 * graph. Starting from vertex 1, it repeatedly adds the cheapest edge that
 * connects a visited vertex to an unvisited vertex.
 *
 * Algorithm Used: Prim's Algorithm (Greedy)
 * Time Complexity: O(n^3) for this matrix-based version
 * Space Complexity: O(n^2)
 *
 * How to Compile & Run:
 *   Linux / macOS (terminal):
 *       gcc "Minimum_Spanning_Tree(Prims_algorithm).c" -o prims
 *       ./prims
 *   Windows (Command Prompt / PowerShell with MinGW gcc):
 *       gcc "Minimum_Spanning_Tree(Prims_algorithm).c" -o prims.exe
 *       prims.exe          (in PowerShell type: .\prims.exe)
 *   (Keep the double quotes - the file name contains brackets.)
 *   You can also save the inputs in a text file and run:  ./prims < input.txt
 *   Online: paste the code into any online C compiler (e.g. OnlineGDB) and
 *   type the inputs in the input/stdin box.
 *
 * Input Format (in this order):
 *   1. n             -> number of nodes (1 to 9)
 *   2. n x n matrix  -> cost adjacency matrix, row by row (symmetric,
 *                       because the graph is undirected).
 *                       Enter 0 when there is no edge (and on the diagonal);
 *                       the program treats 0 as infinity (999).
 *
 * Sample Input:
 *   4
 *   0 2 0 6
 *   2 0 3 8
 *   0 3 0 0
 *   6 8 0 0
 *
 * Sample Output:
 *   Edge 1: (1 2) cost:2
 *   Edge 2: (2 3) cost:3
 *   Edge 3: (1 4) cost:6
 *   Minimun cost=11
 *
 * Note:
 * - The tree is always grown from vertex 1.
 * - Edge weights must be less than 999.
 */

#include<stdio.h>
int a,b,u,v,n,i,j,ne=1;
int visited[10]={0},min,mincost=0,cost[10][10];
void main()
{
	printf("\n Enter the number of nodes:");
	scanf("%d",&n);
	printf("\n Enter the adjacency matrix:\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=999;
		}
	visited[1]=1;
	printf("\n");
	while(ne<n)
	{
		for(i=1,min=999;i<=n;i++)
			for(j=1;j<=n;j++)
				if(cost[i][j]<min)
					if(visited[i]!=0)
					{
						min=cost[i][j];
						a=u=i;
						b=v=j;
					}
		if(visited[u]==0 || visited[v]==0)
		{
			printf("\n Edge %d: (%d %d) cost:%d", ne++,a,b,min);
			mincost+=min;
			visited[b]=1;
		}
		cost[a][b]=cost[b][a]=999;
	}
	printf("\n Minimun cost=%d", mincost);
}
