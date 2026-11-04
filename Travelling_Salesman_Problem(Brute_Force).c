/*
 * Travelling Salesman Problem (TSP) using Brute Force
 *
 * Description:
 * Finds the cheapest tour that starts at city 1, visits every city exactly
 * once and returns to city 1. All 6 possible tours of a 4-city graph are
 * listed in temp[][] and the one with minimum cost is printed.
 *
 * Algorithm Used: Brute force (checks every permutation of cities)
 * Time Complexity: O(n!) in general (here fixed: 6 tours for 4 cities)
 * Space Complexity: O(n^2)
 *
 * How to Compile & Run:
 *   Linux / macOS (terminal):
 *       gcc "Travelling_Salesman_Problem(Brute_Force).c" -o tsp
 *       ./tsp
 *   Windows (Command Prompt / PowerShell with MinGW gcc):
 *       gcc "Travelling_Salesman_Problem(Brute_Force).c" -o tsp.exe
 *       tsp.exe          (in PowerShell type: .\tsp.exe)
 *   (Keep the double quotes - the file name contains brackets.)
 *   You can also save the inputs in a text file and run:  ./tsp < input.txt
 *   Online: paste the code into any online C compiler (e.g. OnlineGDB) and
 *   type the inputs in the input/stdin box.
 *
 * Input Format:
 *   1. 4 x 4 matrix -> cost adjacency matrix of exactly 4 cities, row by row.
 *                      cost[i][j] = cost of going from city i to city j.
 *                      0 = no road (that tour is skipped). Diagonal = 0.
 *   (The number of vertices is NOT asked - it is fixed at 4.)
 *
 * Sample Input:
 *   0 10 15 20
 *   10 0 35 25
 *   15 35 0 30
 *   20 25 30 0
 *
 * Sample Output:
 *   Minimum Cost Path: ->1->2->4->3->1
 *   Minimum Cost: 80
 */

#include<stdio.h>
int main()
{
	int a[5][5];
	printf("Enter cost adjacency matrix of a graph with 4 vertices:");
	for(int i=1;i<5;i++)
	{
		for(int j=1;j<5;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	int temp[6][5]={{1,2,3,4,1},{1,2,4,3,1},{1,3,2,4,1},{1,3,4,2,1},{1,4,3,2,1},{1,4,2,3,1}};
	int mincost=10000000;
	int minr=0;
	for(int i=0;i<6;i++)
	{
		int cost=0;
		int flag=1;
		for(int j=0;j<4;j++)
		{
			if(a[temp[i][j]][temp[i][j+1]]!=0)
			{
				cost=cost+a[temp[i][j]][temp[i][j+1]];
			}
			else
			{
				flag=0;
				break;
			}
		}
		if(flag)
		{
			if(mincost>cost)
			{
				mincost=cost;
				minr=i;
			}
		}
	}
	printf("\nMinimum Cost Path: ");
	for(int i=0;i<5;i++)
	{
		printf("->%d",temp[minr][i]);
	}
	printf("\nMinimum Cost: %d\n",mincost);
	return 0;
}
