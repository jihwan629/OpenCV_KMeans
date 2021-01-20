#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

int main()
{
    printf("OpenCV Version : %s\n\n", CV_VERSION);

	//Mat img = imread("Lenna.png", CV_LOAD_IMAGE_UNCHANGED);
	Mat img = imread("input.png", CV_LOAD_IMAGE_UNCHANGED);

	imshow("img", img);
	waitKey(0);

	return 0;
}
