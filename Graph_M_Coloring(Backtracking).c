/*
 * Graph (M) Coloring using Backtracking
 *
 * Description:
 * Finds every way to color the vertices of a graph using at most m colors
 * so that no two adjacent vertices get the same color. Each solution is
 * printed as a list of colors, one per vertex, e.g. (123) means
 * vertex 1 -> color 1, vertex 2 -> color 2, vertex 3 -> color 3.
 *
 * Algorithm Used: Backtracking
 * Time Complexity: O(n * m^n)
 * Space Complexity: O(n)
 *
 * How to Compile & Run:
 *   Linux / macOS (terminal):
 *       gcc "Graph_M_Coloring(Backtracking).c" -o mcoloring
 *       ./mcoloring
 *   Windows (Command Prompt / PowerShell with MinGW gcc):
 *       gcc "Graph_M_Coloring(Backtracking).c" -o mcoloring.exe
 *       mcoloring.exe          (in PowerShell type: .\mcoloring.exe)
 *   (Keep the double quotes - the file name contains brackets.)
 *   You can also save the inputs in a text file and run:  ./mcoloring < input.txt
 *   Online: paste the code into any online C compiler (e.g. OnlineGDB) and
 *   type the inputs in the input/stdin box.
 *
 * Input Format (in this order):
 *   1. n             -> number of vertices (1 to 9)
 *   2. n x n matrix  -> adjacency matrix, 1 = edge, 0 = no edge
 *                       (enter row by row, numbers separated by spaces)
 *   3. m             -> number of colors available
 *
 * Sample Input (triangle graph, 3 colors):
 *   3
 *   0 1 1
 *   1 0 1
 *   1 1 0
 *   3
 *
 * Sample Output:
 *   possible colours to colour(123)
 *   possible colours to colour(132)
 *   possible colours to colour(213)
 *   possible colours to colour(231)
 *   possible colours to colour(312)
 *   possible colours to colour(321)
 *
 * Note:
 * - If the graph cannot be colored with m colors, the program prints
 *   "not possible" (e.g. the triangle above with m = 2).
 */

#include<stdio.h>
int n,m,x[10]={0},a[20][20];
int found=0;	/* becomes 1 once at least one valid colouring is printed */
void Nextvalue(int k)
{
	int j;
	do
	{
		x[k]=(x[k]+1)%(m+1);
		if(x[k]==0)
			return;
		for(j=1;j<=n;j++)
		{//if j is adjacent to k and the colors of j and k both are same
			if((a[k][j]!=0 && x[k]==x[j]) || (a[j][k]!=0 && x[k]==x[j]))
				break;
		}
		//adjacent vertices of k have different colors from k
		//a new color found
		if(j==n+1)
			return;
	}
	while(1);//infinite loop
}
void mcoloring(int k)
{	int i;
	do
	{
		Nextvalue(k);
		if(x[k]==0)
			return;
		if(k==n)
		{
			found=1;
			printf("\npossible colours to colour");
			printf("(");
			for(i=1;i<=n;i++)
				printf("%d",x[i]);
			printf(")\n");
		}
		else
			mcoloring(k+1);
	}
	while(1);
}
int main()
{
	int v;
	printf("\nEnter the number of vertices");
	scanf("%d",&n);
	printf("\nEnter graph data in matrix form\n");
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	printf("Enter the number of colors;");
	scanf("%d",&m);
	mcoloring(1);
	if(!found)	/* x[] is reset while backtracking, so use the flag instead */
		printf("\nnot possible");
	printf("\n");
}


