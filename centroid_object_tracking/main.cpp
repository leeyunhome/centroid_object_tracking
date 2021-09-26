//#include <stdio.h>
#include <iostream>
#include "centroidtracker.h"
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

int main()
{
	printf("####### Centroid Object Tracking ##########\n");

	// Create an Object Tracker
	ObjectTracker ot;

	VideoCapture cap(0);

	if (!cap.isOpened())
	{
		cout << "Cannot open camera";
	}

	String modelTxt = "model/deploy.prototxt";
	String modelBin = "model/res10_300x300_ssd_iter_140000.caffemodel";

	std::cout << "Loading ai model.." << endl;
	auto net = dnn::readNetFromCaffe(modelTxt, modelBin);

	std::cout << "Starting video stream" << std::endl;

	while (cap.isOpened())
	{
		Mat cameraFrame;
		cap.read(cameraFrame);

		resize(cameraFrame, cameraFrame, Size(400, 300));
		auto inputBlob = dnn::blobFromImage(cameraFrame, 1.0, Size(400, 300), Scalar(104.0, 177.0, 123.0));

		net.setInput(inputBlob);
		auto detection = net.forward("detection_out");
		Mat detectionMat(detection.size[2], detection.size[3], CV_32F, detection.ptr<float>());

		// vector는 RAII 개념을 구현하고 있음. {}(중괄호 영역)을 나가면 자동으로 메모리를 지워줌
		vector<vector<int>> boxes;

		float confidenceThreshold = 0.2;
		for (int i = 0; i < detectionMat.rows; i++)
		{
			float confidence = detectionMat.at<float>(i, 2);

			if (confidence > confidenceThreshold)
			{
				int xLeftTop = static_cast<int>(detectionMat.at<float>(i, 3) * cameraFrame.cols);
				int yLeftTop = static_cast<int>(detectionMat.at<float>(i, 4) * cameraFrame.rows);
				int xRightBottom = static_cast<int>(detectionMat.at<float>(i, 5) * cameraFrame.cols);
				int yRightBottom = static_cast<int>(detectionMat.at<float>(i, 6) * cameraFrame.rows);

				//calcCentroid(xLeftTop, yLeftTop, xRightBottom, yRightBottom, &centroid_x, &centroid_y);

				Rect object((int)xLeftTop, (int)yLeftTop, (int)(xRightBottom - xLeftTop),
					(int)(yRightBottom - yLeftTop));

				rectangle(cameraFrame, object, Scalar(255, 255, 0), 1);

				boxes.insert(boxes.end(), { xLeftTop, yLeftTop, xRightBottom, yRightBottom });
			}
		}

		imshow("Detection", cameraFrame);

		char c = (char)waitKey(15);
		if (c == 27)
			break;
	}

	return 0;
}


