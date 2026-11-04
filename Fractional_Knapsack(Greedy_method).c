/*
 * Fractional Knapsack using the Greedy Method
 *
 * Description:
 * Fills a knapsack of given capacity to get the maximum profit, where items
 * may be taken partly (fractions allowed). Items are sorted by
 * profit/weight ratio and picked greedily in that order.
 *
 * Algorithm Used: Greedy method (sort by profit/weight ratio)
 * Time Complexity: O(n^2) (bubble sort used for sorting) + O(n)
 * Space Complexity: O(n)
 *
 * How to Compile & Run:
 *   Linux / macOS (terminal):
 *       gcc "Fractional_Knapsack(Greedy_method).c" -o fractional_knapsack
 *       ./fractional_knapsack
 *   Windows (Command Prompt / PowerShell with MinGW gcc):
 *       gcc "Fractional_Knapsack(Greedy_method).c" -o fractional_knapsack.exe
 *       fractional_knapsack.exe          (in PowerShell type: .\fractional_knapsack.exe)
 *   (Keep the double quotes - the file name contains brackets.)
 *   You can also save the inputs in a text file and run:  ./fractional_knapsack < input.txt
 *   Online: paste the code into any online C compiler (e.g. OnlineGDB) and
 *   type the inputs in the input/stdin box.
 *
 * Input Format (in this order):
 *   1. n          -> number of objects (1 to 20)
 *   2. weights    -> n weights separated by spaces
 *   3. profits    -> n profits separated by spaces (same order as weights)
 *   4. capacity   -> capacity of the knapsack
 *   (Decimal values are allowed.)
 *
 * Sample Input:
 *   3
 *   18 15 10
 *   25 24 15
 *   20
 *
 * Sample Output:
 *   Fractions of items taken:
 *   x[0] = 1.00
 *   x[1] = 0.50
 *   x[2] = 0.00
 *
 *   Maximum profit = 31.50
 *
 * Note:
 * - x[] is printed in the SORTED order (highest profit/weight first),
 *   not in the order the items were entered.
 */

#include<stdio.h>
void knapsack(int n,float weight[],float profit[],float capacityu)
{
	float x[20],tp=0;
	int i,j;
	float u;
	u=capacityu;
	for(i=0;i<n;i++)
	x[i]=0.0;
	for(i=0;i<n;i++)
	{
		if(weight[i] <= u)
		{
            		x[i] = 1.0;         
            		tp = tp + profit[i];
            		u = u - weight[i];
       		}
        	else
        	{
			x[i] = u / weight[i];   
			tp = tp + x[i] * profit[i];
			break;		
        	}
	}
    printf("\nFractions of items taken:\n");
    for(i = 0; i < n; i++)
        printf("x[%d] = %.2f\n", i, x[i]);
    printf("\nMaximum profit = %.2f", tp);
}

int main()
{
	float weight[20],profit[20],capacity;
	int num,i,j;
	float ratio[20],temp;
	printf("\nEnter the no of objects:");
	scanf("%d",&num);
	printf("\nEnter the weights of %d objects",num);
	for(i=0;i<num;i++)
		scanf("%f",&weight[i]);
	printf("\nEnter the profits of %d objects: ",num);
	for(i=0;i<num;i++)
		scanf("%f",&profit[i]);
	printf("\nEnter the capacity of knapsack:");
	scanf("%f",&capacity);
	for(i=0;i<num;i++)
		ratio[i]=profit[i]/weight[i];
	for(i=0;i<num;i++)
	{
		for(j=0;j<num-i-1;j++)
		{
			if(ratio[j]<ratio[j+1])
			{
				temp=ratio[j];
				ratio[j]=ratio[j+1];
				ratio[j+1]=temp;

				temp=weight[j];
				weight[j]=weight[j+1];
				weight[j+1]=temp;

				temp=profit[j];
				profit[j]=profit[j+1];
				profit[j+1]=temp;
			}
		}
	}
	knapsack(num,weight,profit,capacity);
	printf("\n");
	return 0;
}


