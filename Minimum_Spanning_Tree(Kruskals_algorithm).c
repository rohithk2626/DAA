/*
 * Minimum Cost Spanning Tree using Kruskal's Algorithm
 *
 * Description:
 * Finds the minimum cost spanning tree of a connected, undirected, weighted
 * graph. It repeatedly picks the cheapest remaining edge and adds it if it
 * does not form a cycle (checked with find/union on parent[]).
 *
 * Algorithm Used: Kruskal's Algorithm (Greedy + Union-Find)
 * Time Complexity: O(n^3) for this matrix-based version
 * Space Complexity: O(n^2)
 *
 * How to Compile & Run:
 *   Linux / macOS (terminal):
 *       gcc "Minimum_Spanning_Tree(Kruskals_algorithm).c" -o kruskal
 *       ./kruskal
 *   Windows (Command Prompt / PowerShell with MinGW gcc):
 *       gcc "Minimum_Spanning_Tree(Kruskals_algorithm).c" -o kruskal.exe
 *       kruskal.exe          (in PowerShell type: .\kruskal.exe)
 *   (Keep the double quotes - the file name contains brackets.)
 *   You can also save the inputs in a text file and run:  ./kruskal < input.txt
 *   Online: paste the code into any online C compiler (e.g. OnlineGDB) and
 *   type the inputs in the input/stdin box.
 *
 * Input Format (in this order):
 *   1. n             -> number of vertices (1 to 8)
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
 *   1 edge(1,2)=2
 *   2 edge(2,3)=3
 *   3 edge(1,4)=6
 *       Minimum Cost=11
 *
 * Note:
 * - Edge weights must be less than 999.
 */

#include<stdio.h>
#include<stdlib.h>
int i,j,k,a,b,u,v,n,ne=1;
int min,mincost=0,cost[9][9],parent[9];
int find(int);
int uni(int,int);
void main()
{
    printf("\n\nImplementation of Kruskal's a");
    printf("\nEnter the no. of vertices\n");
    scanf("%d",&n);
    printf("\nEnter the cost adjacency matrix\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=999;
        }
    }
    printf("\nThe edges of Minimum Cost Span");
    while(ne<n)
    {
        for(i=1,min=999;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(cost[i][j]<min)
                {
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
	u=find(u);
	v=find(v);
	if(uni(u,v))
	{
		printf("\n%d edge(%d,%d)=%d\n",ne++,a,b,min);
		mincost+=min;
	}
	cost[a][b]=cost[b][a]=999;
    }
    printf("\n\tMinimum Cost=%d\n",mincost);
}
int find(int i)
{
    while(parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j)
{
    if(i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}
