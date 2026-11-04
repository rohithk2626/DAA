/*
 * 0/1 Knapsack using Brute Force
 *
 * Description:
 * Solves the 0/1 knapsack problem (each item is either taken fully or not
 * at all) by trying every possible subset of items (2^n combinations) and
 * keeping the most profitable subset that fits in the knapsack.
 *
 * Algorithm Used: Brute force (exhaustive search of all subsets)
 * Time Complexity: O(n * 2^n)
 * Space Complexity: O(n)
 *
 * How to Compile & Run:
 *   Linux / macOS (terminal):
 *       gcc "0-1_Knapsack(Brute_Force).c" -o knapsack_brute -lm
 *       ./knapsack_brute
 *   Windows (Command Prompt / PowerShell with MinGW gcc):
 *       gcc "0-1_Knapsack(Brute_Force).c" -o knapsack_brute.exe -lm
 *       knapsack_brute.exe          (in PowerShell type: .\knapsack_brute.exe)
 *   (Keep the double quotes - the file name contains brackets.)
 *   You can also save the inputs in a text file and run:  ./knapsack_brute < input.txt
 *   Online: paste the code into any online C compiler (e.g. OnlineGDB) and
 *   type the inputs in the input/stdin box.
 *   (-lm is needed on Linux because the program uses pow() from math.h.)
 *
 * Input Format (in this order):
 *   1. n          -> number of objects (1 to 20)
 *   2. capacity   -> capacity of the knapsack
 *   3. weights    -> n weights separated by spaces
 *   4. profits    -> n profits separated by spaces (same order as weights)
 *
 * Sample Input:
 *   4
 *   5
 *   2 1 3 2
 *   12 10 20 15
 *
 * Sample Output:
 *   sloution vector:
 *   1101bestprofit:37.000000
 *
 * Note:
 * - The solution vector has one digit per item, in input order:
 *   1 = item taken, 0 = not taken (above: items 1, 2 and 4 are taken).
 */

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int knapsack(float p[] ,float w[],float Capacity,int n)
{
	 int A[20]={0},bestchoice[20]={0},i,k;	/* start with every item not taken */
	 float bestweight=0,bestvalue=0,tempweight,tempvalue;
	 for(i=1;i<pow(2,n);i++)
	 {
		 int j=n-1;
		 float tempweight=0,tempvalue=0;
		 while(A[j]!=0&&j>0)
		 {
			 A[j]=0;
			 j=j-1;
		 }
		 A[j]=1;
		 for(k=0;k<n;k++)
		 {
			 if(A[k]==1)
			 {
				 tempweight = tempweight + w[k];
				 tempvalue = tempvalue + p[k];
			 }
		 }
		 if((tempvalue>bestvalue)&&(tempweight<=Capacity))
		 {
			 bestvalue=tempvalue;
			 bestweight=tempweight;
			 for(k=0;k<n;k++)	/* remember this best subset */
				 bestchoice[k]=A[k];
		 }
	 }
	 printf("sloution vector:\n");
	 for(i=0;i<n;i++)
		 printf("%d",bestchoice[i]);
	 return bestvalue;
}


void main()
{
	float n,max,weight[25],profit[40],bestprofit;
	printf("no of objects:");
	scanf("%f",&n);
	printf("capacity of knapsack:");
	scanf("%f",&max);
	printf("weight of the objects are:");
	for(int i=0;i<n;i++)
		scanf("%f",&weight[i]);
	printf("profits of them respectively");
	for(int i=0;i<n;i++)
		scanf("%f",&profit[i]);
	bestprofit=knapsack(profit,weight,max,n);
	printf("bestprofit:%f",bestprofit);
}

