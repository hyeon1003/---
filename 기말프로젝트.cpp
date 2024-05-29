// 기말 프로젝트 필기체 인식
//기말 프로젝트 필기체 숫자인식
#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
void menu(Mat* img);
void on_mouse(int event,int x, int y, int flags, void* userdata);
int main(void)
{
	Mat src(500, 700, CV_8UC3, Scalar(255, 255, 255));
	menu(&src);
	namedWindow("src");
	setMouseCallback("src", on_mouse, &src);
	while (true)
	{
		imshow("src", src);
		waitKey(1);
	}
	return 0;
}
void menu(Mat* img)
{
	Mat src = *img;
	rectangle(src, Rect(0, 0, 700, 500), Scalar(0, 0, 0), 3);
	line(src, Point(500, 0), Point(500, 500), Scalar(0, 0, 0), 3);
	for (int i = 1; i <= 4; ++i) {
		line(src, Point(500, i * 100), Point(700, i * 100), Scalar(0, 0, 0), 3);
	}
	String massage[] = { "Save","Load","Clear","Run","Exit" };
	int y = 0;
	Mat dst = src(Rect(500, 0, 200, 500));//메뉴기능 부분행렬 추출
	Size dstsize = dst.size();//dst 사이즈
	for (int i = 0; i < 5; i++)//UI 텍스트 를 보여주기 위한 반복문
	{
		Size sizeText = getTextSize(massage[i], FONT_HERSHEY_TRIPLEX, 1.0, 1, 0);
		Point org((dstsize.width - sizeText.width) / 2, (dstsize.height / 5 + sizeText.height) / 2 + y);//부분행렬 추출로 원본 오른쪽에 메뉴 UI 텍스트 출력 500 x 500은 입력창
		putText(dst, massage[i], org, FONT_HERSHEY_TRIPLEX, 1.0, 1);
		y += 100;
	}
}
void on_mouse(int event,int x, int y, int flags, void* userdata)
{
	Mat src = *(Mat*)userdata;
	static Point ptPrev(-1, -1);
	switch (event)
	{
	case EVENT_LBUTTONDOWN:
	{
		ptPrev = Point(x, y);
		break;
	}
	case EVENT_MOUSEMOVE:
	{
		if (flags & EVENT_FLAG_LBUTTON) {
			line(src, ptPrev, Point(x, y), Scalar::all(0), 5, LINE_AA, 0);
			ptPrev = Point(x, y);
		}
		break;
	}
	}
}