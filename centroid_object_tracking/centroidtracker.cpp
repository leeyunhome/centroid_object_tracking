#include "centroidtracker.h"
#include <math.h>

// TODO: 러프하게 해보고 패턴을 발견한 후 오브젝트를 등록하는 코드를 함수로 빼낼 예정
//void register_Object(ObjectTracker* ot, int cX, int cY)
//{
//	int i;
//
//	for (i = 0; i < MAX_OBJECT; i++)
//	{
//		ot->objects[i].cX = 0;
//		ot->objects[i].cY = 0;
//	}
//}

double calcDistanceBetweenCentroids(const double x1, const double y1, const double x2, const double y2)
{
	double x = x1 - x2;
	double y = y1 - y2;
	double dist = sqrt((x * x) + (y * y));

	return dist;
}

void selection_sort(int arr[], int size)
{
	int r;
	int c;
	for (r = 0; r < size - 1; r++)
	{
		int smallest_idx = r;
		for (c = r + 1; c < size; c++)
		{
			if (arr[smallest_idx] < arr[c])
			{
				smallest_idx = c;
			}
		}
		my_swap(&(arr[smallest_idx]), &(arr[c]));
	}
}

void my_swap(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
