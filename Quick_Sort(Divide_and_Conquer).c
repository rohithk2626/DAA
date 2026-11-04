/*
 * Quick Sort using Divide and Conquer (with running-time measurement)
 *
 * Description:
 * Generates n random numbers, sorts them using Quick Sort (first element
 * as pivot), prints the array before and after sorting, and prints the
 * time taken to sort (measured with clock()).
 *
 * Algorithm Used: Quick Sort (Divide and Conquer)
 * Time Complexity: O(n log n) average, O(n^2) worst case (sorted input)
 * Space Complexity: O(log n) recursion stack on average
 *
 * How to Compile & Run:
 *   Linux / macOS (terminal):
 *       gcc "Quick_Sort(Divide_and_Conquer).c" -o quicksort
 *       ./quicksort
 *   Windows (Command Prompt / PowerShell with MinGW gcc):
 *       gcc "Quick_Sort(Divide_and_Conquer).c" -o quicksort.exe
 *       quicksort.exe          (in PowerShell type: .\quicksort.exe)
 *   (Keep the double quotes - the file name contains brackets.)
 *   You can also save the inputs in a text file and run:  ./quicksort < input.txt
 *   Online: paste the code into any online C compiler (e.g. OnlineGDB) and
 *   type the inputs in the input/stdin box.
 *
 * Input Format:
 *   1. n  -> number of elements to sort
 *   The elements are NOT typed in: the program fills the array with random
 *   numbers between 0 and n-1 using rand().
 *
 * Sample Input:
 *   10
 *
 * Sample Output (random numbers may differ on your system):
 *   Random numbers:3  6  7  5  3  5  6  2  9  1
 *   After sorting elements are:1  2  3  3  5  5  6  6  7  9
 *   Time spent for 10 elements is 0.000001
 *
 * Note:
 * - For a time analysis, run it with large n (e.g. 1000, 5000, 10000) and
 *   record the time printed for each n.
 * - Best / worst case inputs: uncomment the commented loops in main()
 *   (sorted or reverse-sorted array) and comment out the rand() loop.
 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int *a,n;
int partition(int m,int p);
void quicksort(int p,int q)
{
	int j;
	if(p<q)
	{
		j=partition(p,q);
		quicksort(p,j-1);
		quicksort(j+1,q);
	}
}
int partition(int m,int p)
{
	int v=a[m],i=m,j=p;
	while(i<=j)
	{
		while(a[i]<=v && i<=p)
		i++;
		while(a[j]>v && j>=0)
		j--;
		if(i<j)
		{
			int t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}
	a[m]=a[j];
	a[j]=v;
	return j;
}
void main()
{
	int i,j;
	double st,et,tts;
	printf("Enter number of elements:");
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	//for(i=0;i<n;i++)
		//a[i]=i;
	//for(i=n,j=0;i>=0;i--,j++)
		//a[j]=i;
	for(i=0;i<n;i++)
		a[i]=rand()%n;
	printf("\nRandom numbers:");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	st=clock();
	quicksort(0,n-1);
	et=clock();
	tts=(double)(et-st)/CLOCKS_PER_SEC;
	printf("\nAfter sorting elements are:");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\nTime spent for %d elements is %lf",n,tts);
}


