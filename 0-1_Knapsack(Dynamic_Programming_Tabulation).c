/*
 * 0/1 Knapsack using Dynamic Programming (Tabulation / Bottom-up)
 *
 * Description:
 * Solves the 0/1 knapsack problem by filling a table knap[i][j] = maximum
 * profit using the first i items with capacity j. It then traces back
 * through the table to find which items were selected.
 *
 * Algorithm Used: Dynamic Programming (tabulation)
 * Time Complexity: O(n * capacity)
 * Space Complexity: O(n * capacity)
 *
 * How to Compile & Run:
 *   Linux / macOS (terminal):
 *       gcc "0-1_Knapsack(Dynamic_Programming_Tabulation).c" -o knapsack_dp
 *       ./knapsack_dp
 *   Windows (Command Prompt / PowerShell with MinGW gcc):
 *       gcc "0-1_Knapsack(Dynamic_Programming_Tabulation).c" -o knapsack_dp.exe
 *       knapsack_dp.exe          (in PowerShell type: .\knapsack_dp.exe)
 *   (Keep the double quotes - the file name contains brackets.)
 *   You can also save the inputs in a text file and run:  ./knapsack_dp < input.txt
 *   Online: paste the code into any online C compiler (e.g. OnlineGDB) and
 *   type the inputs in the input/stdin box.
 *
 * Input Format (in this order):
 *   1. n                 -> number of items (1 to 9)
 *   2. for each item     -> "profit weight" (two integers: PROFIT FIRST,
 *                           then weight), one item per line
 *   3. capacity          -> capacity of the knapsack (integer)
 *
 * Sample Input:
 *   4
 *   12 2
 *   10 1
 *   20 3
 *   15 2
 *   5
 *
 * Sample Output:
 *   solution is:1   1   0   1
 *   items no included are
 *   item no weight  profit
 *   1       2       12
 *   2       1       10
 *   4       2       15
 *   total profit=37
 *
 * Note:
 * - Only integer profits, weights and capacity are supported.
 */

#include<stdio.h>
int w[10],p[10],n,i,j,cap,x[10]={0};
int max(int i,int j)
{
	return ((i>j)?i:j);
}
int main()
{
	int profit,count=0,value;
	printf("\nenter no.of elements:");
	scanf("%d",&n);
	printf("enter the profit and weights of the elements:\n");
	for(i=1;i<=n;i++)
	{
		printf("for item no %d\n",i);
		scanf("%d%d",&p[i],&w[i]);
	}
	printf("\nenter the capacity:\n");
	scanf("%d",&cap);
	int knap[n+1][cap+1];
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=cap;j++)
		{
			if((i==0)||(j==0))
				knap[i][j]=0;
			else
			{
				if(j<w[i])
					value=knap[i-1][j];
				else
					value=max(knap[i-1][j],p[i]+knap[i-1][j-w[i]]);
				knap[i][j]=value;
			}
		}
	}
	profit=knap[n][cap];
	i=n;
	j=cap;
	while(j!=0 && i!=0)
	{
		if(knap[i][j]!=knap[i-1][j])
		{
			x[i]=1;
			j=j-w[i];
			i--;
		}
		else
			i--;
	}
	printf("solution is:");
	for(i=1;i<=n;i++)
		printf("%d\t",x[i]);

	printf("\nitems no included are\n");
	printf("item no\tweight\tprofit\n");
	for(i=1;i<=n;i++)
		if(x[i])
			printf("%d\t%d\t%d\n",i,w[i],p[i]);
	printf("total profit=%d\n",profit);
}

