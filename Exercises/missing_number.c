// Warm-up Exercise: Finding a Missing Number

// You are given a list of n-1 integers and these integers are in the range of 1 to n.
// There are no duplicates in the list. One of the integers is missing in the list. 
// Write an efficient code to find the missing integer.

#include <stdio.h>

/* getMissingNo takes array and size of array as arguments*/
int getMissingNo(int a[], int n)
{
	// Write your code here
}

/*program to test above function */
int main()
{
	int a[] = { 1, 2, 4, 5, 6 };
	int miss = getMissingNo(a, 5);
	printf("%d", miss);
	getchar();
}

// Test with these inputs
// A = {1, 3, 4, 5, 6, 7, 8}, Output = 2
// A = {1, 3, 2, 4, 6, 8, 7}, Output = 5
// A = {6, 7, 5, 4, 3, 2}, Output = 1
