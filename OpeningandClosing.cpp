#include <iostream>
#include "opencv2\highgui.hpp"
#include "opencv2\imgproc.hpp"

using namespace std;
using namespace cv;

int main() {

	//Opening 先侵蝕再膨脹
	Mat image;
	image = imread("../../data/images/opening.png", IMREAD_GRAYSCALE);
	imshow("image", image);

	//次數
	int iter = 3;
	int eroanddilaSize = 3;
	//建立structuring element
	Mat element_Opening = getStructuringElement(MORPH_OPEN,
		Size(2 * eroanddilaSize + 1, 2 * eroanddilaSize + 1),
		Point(eroanddilaSize, eroanddilaSize));

	Mat imageOpening;

	morphologyEx(image, imageOpening,MORPH_OPEN, element_Opening, Point(-1,-1), iter);

	imshow("Opening Image", imageOpening);

	Mat imageSubtraction = image - imageOpening;
	imshow("Subtraction", imageSubtraction);

	//Closing 先膨脹再侵蝕
	Mat image2 = imread("../../data/images/closing.png", IMREAD_GRAYSCALE);
	Mat imageClosing;

	int iter_C = 1;
	int ClosingSize = 10;

	Mat element_Closing = getStructuringElement(MORPH_ELLIPSE,
		Size(2 * ClosingSize + 1, 2 * ClosingSize + 1),
		Point(ClosingSize, ClosingSize));
	
	morphologyEx(image2, imageClosing, MORPH_CLOSE, element_Closing);
	
	imshow("image2", image2);
	imshow("Closing image", imageClosing);
	
	waitKey(0);

	return 0;
}