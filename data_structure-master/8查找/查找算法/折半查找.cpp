
#include<stdio.h>

int b_search(int array[], int low, int high, int target);

int main(void)
{	
	int a[] = {1,3,7,7,7, 9, 10, 10,13};
	int target = 0;
	int low = 0;
	int high = sizeof(a)/sizeof(int) - 1;
	int ret = 0; 

	while (1) {
		//get input
		printf("Please input a number: ");
		if (scanf("%d", &target) != 1) {
			printf("invalid input\n");
			return -1;
		}

		//search
		ret = b_search(a, low, high, target);
		if (ret < 0) {
			printf("not found\n");
		} else {
			printf("found match, index is %d\n", ret + 1);
			break;
		}
	}
	return 0;
}

int b_search(int array[], int low, int high, int target)
{
	int mid = 0;

	while(low <= high)
	{
		mid = (low+high)/2;
		if(array[mid] > target)
			high = mid - 1;
		else if(array[mid] < target)
			low = mid + 1;
		else
		return mid;
	}
	
	return -1;
}

