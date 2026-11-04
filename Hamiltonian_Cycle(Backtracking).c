/*
 * Hamiltonian Cycle using Backtracking
 *
 * Description:
 * Finds and prints ALL Hamiltonian cycles of an undirected graph. A Hamiltonian
 * cycle visits every vertex exactly once and returns to the starting vertex.
 * The graph is given as an adjacency matrix.
 *
 * Algorithm Used: Backtracking
 * Time Complexity: O(n!) in the worst case
 * Space Complexity: O(n)
 *
 * How to Compile & Run:
 *   Linux / macOS (terminal):
 *       gcc "Hamiltonian_Cycle(Backtracking).c" -o hamiltonian
 *       ./hamiltonian
 *   Windows (Command Prompt / PowerShell with MinGW gcc):
 *       gcc "Hamiltonian_Cycle(Backtracking).c" -o hamiltonian.exe
 *       hamiltonian.exe          (in PowerShell type: .\hamiltonian.exe)
 *   (Keep the double quotes - the file name contains brackets.)
 *   You can also save the inputs in a text file and run:  ./hamiltonian < input.txt
 *   Online: paste the code into any online C compiler (e.g. OnlineGDB) and
 *   type the inputs in the input/stdin box.
 *
 * Input Format (in this order):
 *   1. n                 -> number of vertices (1 to 9)
 *   2. n x n matrix      -> adjacency matrix, 1 = edge, 0 = no edge
 *                           (enter row by row, numbers separated by spaces)
 *   3. s                 -> starting vertex (1 to n)
 *
 * Sample Input:
 *   4
 *   0 1 1 1
 *   1 0 1 1
 *   1 1 0 1
 *   1 1 1 0
 *   1
 *
 * Sample Output:
 *   1-2-3-4-1
 *   1-2-4-3-1
 *   1-3-2-4-1
 *   1-3-4-2-1
 *   1-4-2-3-1
 *   1-4-3-2-1
 *
 * Note:
 * - Vertices are numbered from 1 to n.
 * - If nothing is printed after the inputs, the graph has no Hamiltonian cycle.
 */

#include<stdio.h>
int a[10][10],n,i,j,s,x[10],count=0;
void nextvalue(int k)
{
	do
	{
		x[k]=(x[k]+1)%(n+1);
		if(x[k]==0)
			return;
		if(a[x[k-1]][x[k]]!=0)
		{
			for(j=1;j<k;j++)
				if(x[j]==x[k])
					break;
			        if(j==k)
					if((k<n)||(k==n)&& a[x[n]][x[1]]!=0)
						return;
		}
	}while(1);
}
void hamiltonian(int k)
{
	do
	{
		nextvalue(k);
		if(x[k]==0)
			return;
		if(k==n)
		{
			count++;
			for(i=1;i<=n;i++)
				printf("%d-",x[i]);
			        printf("%d",s);
				printf("\n");
		}
		else
			hamiltonian(k+1);
	}while(1);
}
int main()
{
	int i,j;
	printf("enter no of vertices:");
	scanf("%d",&n);
	printf("\nenter adjacency matrix of graph:");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	}
	printf("enter starting vertex");
	scanf("%d",&s);
	x[1]=s;
	hamiltonian(2);
}



