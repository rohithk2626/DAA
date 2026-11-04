/*
 * Single Source Shortest Path using Dijkstra's Algorithm
 *
 * Description:
 * This program implements Dijkstra's Algorithm to find the shortest path
 * from a given source vertex to all other vertices in a weighted graph.
 * The graph is represented using a cost adjacency matrix.
 *
 * Features:
 * - Accepts the number of nodes and cost matrix as input.
 * - Calculates the minimum distance from the source vertex to every other vertex.
 * - Displays the shortest path cost from the source to each destination node.
 *
 * Algorithm Used: Dijkstra's Greedy Algorithm
 * Time Complexity: O(n^2)
 * Space Complexity: O(n)
 *
 * How to Compile & Run:
 *   Linux / macOS (terminal):
 *       gcc "Single_Source_Shortest_Path(Dijkstra's algorithm).c" -o dijkstra
 *       ./dijkstra
 *   Windows (Command Prompt / PowerShell with MinGW gcc):
 *       gcc "Single_Source_Shortest_Path(Dijkstra's algorithm).c" -o dijkstra.exe
 *       dijkstra.exe          (in PowerShell type: .\dijkstra.exe)
 *   (Keep the double quotes - the file name contains brackets.)
 *   You can also save the inputs in a text file and run:  ./dijkstra < input.txt
 *   Online: paste the code into any online C compiler (e.g. OnlineGDB) and
 *   type the inputs in the input/stdin box.
 *
 * Input Format (in this order):
 *   1. n             -> number of nodes (1 to 9)
 *   2. n x n matrix  -> cost matrix, row by row.
 *                       cost[i][j] = weight of edge i -> j (directed).
 *                       Enter 0 when there is no edge (and on the diagonal);
 *                       the program treats 0 as infinity (999).
 *   3. v             -> source vertex (1 to n)
 *
 * Sample Input:
 *   5
 *   0 10 0 5 0
 *   0 0 1 2 0
 *   0 0 0 0 4
 *   0 3 9 0 2
 *   7 0 6 0 0
 *   1
 *
 * Sample Output:
 *   Shortest path:
 *   1->2, cost=8
 *   1->3, cost=9
 *   1->4, cost=5
 *   1->5, cost=7
 *
 * Note:
 * - The graph should not contain negative edge weights.
 * - A cost of 999 in the output means the vertex is unreachable.
 */

#include<stdio.h>
#define infinity 999
void dijkstra(int ,int ,int[10][10],int[10]);
void dijkstra(int n,int v,int cost[10][10],int dist[10])
{
	int i,u,count,w,flag[10],min;

	for(i=1;i<=n;i++)
	{
		flag[i]=0;
		dist[i]=cost[v][i];
	}
	dist[v]=0;
	count=2;
	while(count<=n)
	{
		min=infinity;
		for(w=1;w<=n;w++)
		{
			if(dist[w]<min && !flag[w])
			{
				min=dist[w];
				u=w;
			}
		}
		flag[u]=1;
		count++;
		for(w=1;w<=n;w++)
		{
			if((dist[u]+cost[u][w]<dist[w]) && !flag[w])
				dist[w]=dist[u]+cost[u][w];
		}
	}
}
void main()
{
        int n,v,i,j,cost[10][10],dist[10];
        printf("\n Enter the number of nodes:");
        scanf("%d",&n);
        printf("\n Enter the cost matrix:\n");
        for(i=1;i<=n;i++)
        {
                for(j=1;j<=n;j++)
                {
                        scanf("%d",&cost[i][j]);
                        if(cost[i][j]==0)
                                cost[i][j]=infinity;
                }
        }
        printf("\n Enter the source Vertex:");
        scanf("%d",&v);
        dijkstra(n,v,cost,dist);
        printf("\n Shortest path:\n");
        for(i=1;i<=n;i++)
                if(i!=v)
                        printf("%d->%d, cost=%d\n",v,i,dist[i]);
}

