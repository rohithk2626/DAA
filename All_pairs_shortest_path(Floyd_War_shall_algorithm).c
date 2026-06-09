/*
 * All-Pairs Shortest Path (APSP) using Floyd-Warshall Algorithm
 *
 * Description:
 * This program implements the Floyd-Warshall Algorithm to find the
 * shortest paths between all pairs of vertices in a weighted graph.
 * The graph is represented using an adjacency cost matrix.
 *
 * Features:
 * - Accepts the number of vertices and the cost adjacency matrix.
 * - Computes the shortest distance between every pair of vertices.
 * - Displays intermediate matrices after each iteration.
 * - Prints the final shortest path cost matrix.
 *
 * Algorithm Used:
 * Floyd-Warshall Algorithm (Dynamic Programming)
 *
 * Time Complexity: O(n³)
 * Space Complexity: O(n²)
 *
 * Note:
 * - '999' is used to represent infinity (no direct edge).
 * - Supports positive and negative edge weights,
 *   but does not detect negative cycles.
 */

#include<stdio.h>
int min(int,int);
void floyds(int p[10][10],int n){
	int i,j,k;
	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(p[i][k]!=999 && p[k][j]!=999)
					p[i][j]=min(p[i][j],p[i][k]+p[k][j]);
			}
		}
		printf("\nThe costs of shortest paths are A-%d:\n",k);
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				printf("%d\t",p[i][j]);
			}
			printf("\n");
		}
	}
}
int min(int a,int b){
	if(a<b)
		return(a);
	else
		return(b);
}
void main(){
	int cost[10][10],n,i,j;
	printf("\nEnter the number of vertices: ");
	scanf("%d",&n);
	printf("Enter the cost adjacency matrix\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&cost[i][j]);
			if(i!=j && cost [i][j]==0)
				cost[i][j]=999;
		}
	}
	printf("Matrix of input data:\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
			printf("%d\t",cost[i][j]);
		printf("\n");
	}
	floyds(cost,n);
	printf("The costs of the shortest paths are:\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d\t",cost[i][j]);
		}
		printf("\n");
	}
}
