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
 * Algorithm Used:
 * Dijkstra's Greedy Algorithm
 *
 * Time Complexity: O(n²)
 * Space Complexity: O(n)
 *
 * Note:
 * - The graph should not contain negative edge weights.
 * - A cost of 0 is treated as no direct edge between vertices.
 */

#include<stdio.h>
#define infinity 999
void dijkstra(int n,int v, int cost[10][10],int dist[10]){
	int i,u,count,w,flag[10],min;
	for(i=1;i<=n;i++){
		flag[i]=0;
		dist[i]=cost[v][i];
	}
	count=2;
	while(count<=n){
		min=infinity;
		for(w=1;w<=n;w++){
			if(dist[w]<min&&!flag[w]){
				min=dist[w];
				u=w;
			}
		}
		flag[u]=1;
		count++;
		for(w=1;w<=n;w++){
			if((dist[u]+cost[u][w]<dist[w])&&!flag[w])
				dist[w]=dist[u]+cost[u][w];
		}
	}
}
void main(){
	int n,v,i,j,cost[10][10],dist[10];
	printf("\nenter no of nodes: ");
	scanf("%d",&n);
	printf("\nenter cost matrix:\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=infinity;
	}
	printf("\nenter source vertex: ");
	scanf("%d",&v);
	dijkstra(n,v,cost,dist);
	printf("\nShortest path:\n");
	for(i=1;i<=n;i++)
		if(i!=v)
			printf("%d->%d, cost=%d\n",v,i,dist[i]);
}
