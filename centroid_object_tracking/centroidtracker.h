#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <float.h>

#define MAX_OBJECT 5

// TODO : ����ü ����� ������ ��ġ�� �е� ���
typedef struct _object
{
	// ���� ���̵�� ���� ���� ������ ��
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

// ObjectTracker ����
double calcDistanceBetweenCentroids(const double x1, const double y1, const double x2, const double y2);

// TODO : ������Ʈ ����ϴ� ���� �����Լ����� �����ϰ� register_Object�Լ��� ������
//void register_Object(ObjectTracker* ot, int cX, int cY);

void selection_sort(int arr[], int size);
void my_swap(int* num1, int* num2);