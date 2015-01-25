
#include <stdio.h>
#include <stdlib.h>

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
		int high = n;
		int low = 0;

		while (low < high)
		{
			if (A[low] == elem)
			{
				A[low] = A[--high];
			}
			else
			{
				++low;
			}
		}
        
		return low;
    }
};

int main(int argc, char * argv[])
{
	int a[1000];
	int n;

	Solution sl;
}
