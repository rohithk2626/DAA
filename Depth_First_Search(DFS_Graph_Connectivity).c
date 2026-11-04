/*
 * Depth First Search (DFS) - Checking Graph Connectivity
 *
 * Description:
 * Performs a recursive Depth First Search starting from vertex 1, prints
 * every tree edge it follows (u->v), and then reports whether the graph is
 * connected (all vertices were reached) or not.
 *
 * Algorithm Used: Depth First Search (recursion)
 * Time Complexity: O(n^2) (adjacency matrix)
 * Space Complexity: O(n)
 *
 * How to Compile & Run:
 *   Linux / macOS (terminal):
 *       gcc "Depth_First_Search(DFS_Graph_Connectivity).c" -o dfs
 *       ./dfs
 *   Windows (Command Prompt / PowerShell with MinGW gcc):
 *       gcc "Depth_First_Search(DFS_Graph_Connectivity).c" -o dfs.exe
 *       dfs.exe          (in PowerShell type: .\dfs.exe)
 *   (Keep the double quotes - the file name contains brackets.)
 *   You can also save the inputs in a text file and run:  ./dfs < input.txt
 *   Online: paste the code into any online C compiler (e.g. OnlineGDB) and
 *   type the inputs in the input/stdin box.
 *
 * Input Format (in this order):
 *   1. n             -> number of vertices (1 to 19)
 *   2. n x n matrix  -> adjacency matrix, 1 = edge, 0 = no edge
 *                       (enter row by row, numbers separated by spaces)
 *
 * Sample Input:
 *   4
 *   0 1 1 0
 *   1 0 0 1
 *   1 0 0 1
 *   0 1 1 0
 *
 * Sample Output:
 *   1->2
 *   2->4
 *   4->3
 *   Graph is connected
 *
 * Note:
 * - DFS always starts from vertex 1.
 */

#include<stdio.h>
int a[20][20],reach[20],n,count;
void dfs(int v)
{
	int i;
	reach[v]=1;
	for(i=1;i<=n;i++)
	{
		if(a[v][i]==1 && reach[i]==0)
		{
			printf("\n%d->%d",v,i);
			count++;
			dfs(i);
		}
	}
}
void main()
{
	int i,j;
	count=1;
	printf("\nEnter no of vertices:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		reach[i]=0;
		for(j=1;j<=n;j++)
		a[i][j]=0;
	}
	printf("\nEnter adjacency matrix:");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	dfs(1);
	printf("\n");
	if(count==n)
	{
		printf("\nGraph is connected");
	}
	else
	{
		printf("\nGraph is not connected");
	}
}

