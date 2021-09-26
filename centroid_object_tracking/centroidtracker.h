#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <float.h>

#define MAX_OBJECT 5

// TODO : 구조체 사이즈에 영향을 미치는 패딩 고려
typedef struct _object
{
	// 음수 아이디는 없는 것을 전제로 함
	unsigned char		id;
	unsigned char  classid;
	//double x1;
	//double y1;
	//double x2;
	//double y2;

	// centroid x coord, centroid y coord
	double cX;
	double cY;

	// ...
} Object;

typedef struct _object_tracker
{
	Object objects[MAX_OBJECT];

	//int maxDisappeared;
	//int nextObjectID;
} ObjectTracker;

// ObjectTracker 연산
double calcDistanceBetweenCentroids(const double x1, const double y1, const double x2, const double y2);

// TODO : 오브젝트 등록하는 것을 메인함수에서 제거하고 register_Object함수로 빼내기
//void register_Object(ObjectTracker* ot, int cX, int cY);

void selection_sort(int arr[], int size);
void my_swap(int* num1, int* num2);