/*
 * N-Queens Problem using Backtracking
 *
 * Description:
 * Places N queens on an N x N chessboard so that no two queens attack each
 * other (same row, column or diagonal). Prints every solution as a board
 * (Q marks a queen) and the total number of solutions.
 *
 * Algorithm Used: Backtracking
 * Time Complexity: O(n!)
 * Space Complexity: O(n)
 *
 * How to Compile & Run:
 *   Linux / macOS (terminal):
 *       gcc "N_Queens_Problem(Backtracking).c" -o nqueens
 *       ./nqueens
 *   Windows (Command Prompt / PowerShell with MinGW gcc):
 *       gcc "N_Queens_Problem(Backtracking).c" -o nqueens.exe
 *       nqueens.exe          (in PowerShell type: .\nqueens.exe)
 *   (Keep the double quotes - the file name contains brackets.)
 *   You can also save the inputs in a text file and run:  ./nqueens < input.txt
 *   Online: paste the code into any online C compiler (e.g. OnlineGDB) and
 *   type the inputs in the input/stdin box.
 *
 * Input Format:
 *   1. n  -> number of queens / size of the board (1 to 29;
 *            values above ~12 take a long time and print many boards)
 *
 * Sample Input:
 *   4
 *
 * Sample Output:
 *   Solution =1
 *       Q
 *               Q
 *   Q
 *           Q
 *
 *   Solution =2
 *           Q
 *   Q
 *               Q
 *       Q
 *
 *   Total solution=2
 *
 * Note:
 * - n = 2 and n = 3 have no solutions (Total solution=0).
 */

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int x[30],count=0;
int place(int k,int i)
{
	int j;
	for(j=1;j<=k-1;j++)
	{
		if((x[j]==i) || ((abs(x[j]-i)==abs(j-k))))
			return 0;
	}
	return 1;
}
void print_sol(int n)
{
	int i,j;
	count++;
	printf("\n\nSolution =%d \n",count);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(x[i]==j)
				printf("Q\t");
			else
				printf("\t");
		}
		printf("\n");
	}
}
void queen(int k,int n)
{
	int i,val;
	for(i=1;i<=n;i++)
	{
		if(place(k,i))
		{
			x[k]=i;
			if(k==n)
				print_sol(n);
			else
				queen(k+1,n);
		}
	}
}
void main()
{
	int i,n;
	printf("Enter the number of queens\n");
	scanf("%d",&n);
	queen(1,n);
	printf("\nTotal solution=%d",count);
	printf("\n");
}

