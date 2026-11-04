/*
 * All-Pairs Shortest Path (APSP) using Floyd-Warshall Algorithm
 *
 * Description:
 * This program implements the Floyd-Warshall Algorithm to find the
 * shortest paths between all pairs of vertices in a weighted graph.
 * The graph is represented using a cost adjacency matrix.
 *
 * Features:
 * - Accepts the number of vertices and the cost adjacency matrix.
 * - Displays the intermediate matrix after each iteration (k = 1..n).
 * - Prints the final shortest path cost matrix.
 *
 * Algorithm Used: Floyd-Warshall Algorithm (Dynamic Programming)
 * Time Complexity: O(n^3)
 * Space Complexity: O(n^2)
 *
 * How to Compile & Run:
 *   Linux / macOS (terminal):
 *       gcc "All_pairs_shortest_path(Floyd_War_shall_algorithm).c" -o floyd
 *       ./floyd
 *   Windows (Command Prompt / PowerShell with MinGW gcc):
 *       gcc "All_pairs_shortest_path(Floyd_War_shall_algorithm).c" -o floyd.exe
 *       floyd.exe          (in PowerShell type: .\floyd.exe)
 *   (Keep the double quotes - the file name contains brackets.)
 *   You can also save the inputs in a text file and run:  ./floyd < input.txt
 *   Online: paste the code into any online C compiler (e.g. OnlineGDB) and
 *   type the inputs in the input/stdin box.
 *
 * Input Format (in this order):
 *   1. n             -> number of vertices (1 to 9)
 *   2. n x n matrix  -> cost adjacency matrix, row by row.
 *                       cost[i][j] = weight of edge i -> j (directed).
 *                       Enter 0 when there is no edge; the program changes
 *                       every off-diagonal 0 to 999 (infinity).
 *                       Diagonal entries should be 0.
 *
 * Sample Input:
 *   4
 *   0 0 3 0
 *   2 0 0 0
 *   0 7 0 1
 *   6 0 0 0
 *
 * Sample Output (final matrix, printed after the intermediate ones):
 *   The costs of shortest paths are
 *   0   10  3   4
 *   2   0   5   6
 *   7   7   0   1
 *   6   16  9   0
 *
 * Note:
 * - 999 in the output means there is no path between those vertices.
 * - Works with negative edge weights but does not detect negative cycles.
 */

#include<stdio.h>
int min(int,int);
void floyds(int p[10][10],int n)
{
	int i,j,k;
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(p[i][k]!=999 && p[k][j]!=999)
					p[i][j]=min(p[i][j],p[i][k]+p[k][j]);
			}
		}
		printf("\nthe costs of shortest paths are %d \n",k);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				printf("%d\t",p[i][j]);
			}
			printf("\n");
		}
	}
}
int min(int a,int b)
{
	if(a<b)
		return(a);
	else
		return(b);
}
void main()
{
	int cost[10][10],n,i,j;
	printf("\nEnter the number of vertices:");
	scanf("%d",&n);
	printf("Enter the cost adjacency matrix\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(i!=j && cost[i][j]==0)
				cost[i][j]=999;
		}
	}
	printf("matrix of input data \n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%d\t",cost[i][j]);
		printf("\n");
	}
	floyds(cost,n);
	printf("The costs of shortest paths are\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d\t",cost[i][j]);
		}
		printf("\n");
	}
}


