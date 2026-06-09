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
