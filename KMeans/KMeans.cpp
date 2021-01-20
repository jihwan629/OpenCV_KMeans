#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

//클러스터링한 결과값을 표시하기 위해 미리 설정한 색상값
Scalar colorTab[] =
{
	Scalar(105, 210, 231),
	Scalar(167, 219, 216),
	Scalar(224, 228, 204),
	Scalar(243, 134, 48),
	Scalar(250, 105, 0),
	Scalar(255, 255, 255),
	Scalar(203, 232, 107),
	Scalar(243, 233, 225),
	Scalar(28, 20, 13),
	Scalar(64, 59, 51),
	//.... 좀 더 추가 할 수 있음...
};

Mat img, res, points, labels, centers;
int Width, Height, Pixels, K;

int main()
{
    printf("OpenCV Version : %s\n\n", CV_VERSION);

	img = imread("input.png", CV_LOAD_IMAGE_UNCHANGED);

	if (!img.data)
	{
		printf("Image load fail....\n\n");
		return -1;
	}
	
	Width = img.cols;				//이미지 너비 설정
	Height = img.rows;				//이미지 높이 설정
	Pixels = Width * Height;		//이미지의 전체 pixel값 설정
	K = 3;							//클러스터링 개수

	points.create(Pixels, 1, CV_32FC3);
	res.create(Height, Width, img.type());
	centers.create(K, 1, CV_32FC3);

	// 채널 값 변경
	for (int y = 0, n = 0; y < Height; y++) {
		for (int x = 0; x < Width; x++, n++) {
			if (img.at<Vec4b>(y, x)[3] != 0)
			{
				points.at<Vec3f>(n)[0] = img.at<Vec4b>(y, x)[0];
				points.at<Vec3f>(n)[1] = img.at<Vec4b>(y, x)[1];
				points.at<Vec3f>(n)[2] = img.at<Vec4b>(y, x)[2];
			}
		}
	}

	// kmeans
	kmeans(points, K, labels, 
		TermCriteria(CV_TERMCRIT_EPS + CV_TERMCRIT_ITER, 10, 1.9),
		3, KMEANS_RANDOM_CENTERS, centers);

	for (int y = 0, n = 0; y < Height; y++) {
		for (int x = 0; x < Width; x++, n++) {
			//현재 픽셀의 label값을 받아온다.
			int cIndex = labels.at<int>(n);
			//받아온 label값에 대응되는 색상을 입힌다.
			res.at<Vec4b>(y, x)[0] = colorTab[cIndex][0];
			res.at<Vec4b>(y, x)[1] = colorTab[cIndex][1];
			res.at<Vec4b>(y, x)[2] = colorTab[cIndex][2];
		}
	}

	namedWindow("Input", WINDOW_AUTOSIZE);
	namedWindow("Result");

	imshow("Input", img);
	imshow("Result", res);

	waitKey(0);

	return 0;
}
