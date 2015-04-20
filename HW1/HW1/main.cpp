#include <cv.h>
#include <highgui.h>
#include "opencv2/imgproc/imgproc.hpp"
using namespace std;
using namespace cv;

int main()
{
	Mat src = imread("D:\\8.jpg", CV_LOAD_IMAGE_COLOR);
	namedWindow("Source", CV_WINDOW_AUTOSIZE);
	imshow("Source", src);

	Mat img;
	cvtColor(src, img, CV_RGB2GRAY);
	GaussianBlur(img, img, Size(5, 5), 0, 0);
	Canny(img, img, 200, 200, 3);
	namedWindow("Canny", CV_WINDOW_AUTOSIZE);
	imshow("Canny", img);

	/*
	vector<Vec4i> lines;
	HoughLinesP(img, lines, 1, CV_PI / 180, 200, 20, 0);
	for (size_t i = 0; i < lines.size(); i++)
	{
		Vec4i l = lines[i];
		line(img, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 2);
	}

	namedWindow("Hough", CV_WINDOW_AUTOSIZE);
	imshow("Hough", img);
	*/

	Mat img2 = img;
	vector<KeyPoint> keypoints;
	FastFeatureDetector fast(40, true);
	fast.detect(img, keypoints);
	drawKeypoints(img, keypoints, img2, Scalar::all(255), DrawMatchesFlags::DRAW_OVER_OUTIMG);
	imshow("角点检测后的二值效果图", img2);
	
	vector<Point> points;
	


	waitKey();
	return 0;
}