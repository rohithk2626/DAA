/*
 * Merge Sort using Divide and Conquer (with running-time measurement)
 *
 * Description:
 * Generates n random numbers, sorts them using Merge Sort, prints the
 * array before and after sorting, and prints the time taken to sort
 * (measured with clock()).
 *
 * Algorithm Used: Merge Sort (Divide and Conquer)
 * Time Complexity: O(n log n) in best, average and worst case
 * Space Complexity: O(n) (extra array b[])
 *
 * How to Compile & Run:
 *   Linux / macOS (terminal):
 *       gcc "Merge_Sort(Divide_and_Conquer).c" -o mergesort
 *       ./mergesort
 *   Windows (Command Prompt / PowerShell with MinGW gcc):
 *       gcc "Merge_Sort(Divide_and_Conquer).c" -o mergesort.exe
 *       mergesort.exe          (in PowerShell type: .\mergesort.exe)
 *   (Keep the double quotes - the file name contains brackets.)
 *   You can also save the inputs in a text file and run:  ./mergesort < input.txt
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
 *   Time spent for 10 elements is 0.000002
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
int *a,*b,n;
void merge(int low,int mid,int high);
void mergesort(int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		mergesort(low,mid);
		mergesort(mid+1,high);
		merge(low,mid,high);
	}
}
void merge(int low,int mid,int high)
{
	int i=low,h=low,j=mid+1;
	int k;
	while((h<=mid) && (j<=high))
	{
		if(a[h]<=a[j])
		{
			b[i]=a[h];
			h=h+1;
		}
		else
		{
			b[i]=a[j];
			j=j+1;
		}
		i=i+1;
	}
	if(h>mid)
	{
		for(k=j;k<=high;k++)
		{
			b[i]=a[k];
			i=i+1;
		}
	}
	else
	{
		for(k=h;k<=mid;k++)
		{
			b[i]=a[k];
			i=i+1;
		}
	}
	for(k=low;k<=high;k++)
	{
		a[k]=b[k];
	}
}
void main()
{
	int i,j;
	double st,et,tts;
	printf("Enter number of elements:");
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	b=(int *)malloc(n*sizeof(int));
	//for(i=0;i<n;i++)
		// a[i]=i;
	//Worst Case
	//for(i=n,j=0;i>=0;i--,j++)
		//a[j]=i;
	//Average Case
	for(i=0;i<n;i++)
		a[i]=rand()%n;
	printf("\nRandom numbers:");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	st=clock();
	mergesort(0,n-1);
	et=clock();
	tts=(double)(et-st)/CLOCKS_PER_SEC;
	printf("\nAfter sorting elements are:");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\nTime spent for %d elements is %lf",n,tts);
}




