//�⸻ ������Ʈ �ʱ�ü �����ν�
#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
void menu(Mat* img);
void on_mouse(int x, int y, int flags, void* userdata);
int main(void)
{
	Mat src(500, 700, CV_8UC3, Scalar(255, 255, 255));
	menu(&src);
	Mat Write = src(Rect(Point(0, 0), Size(500, 500)));//�ʱ�ü ���� �Է�â
	Mat Save = src(Rect(Point(500, 0), Size(200, 100)));//���� ��ư
	Mat Load = src(Rect(Point(500, 100), Size(200, 100)));//�ҷ����� ��ư
	Mat Clear = src(Rect(Point(500, 200), Size(200, 100)));//���� ��ư
	Mat Run = src(Rect(Point(500, 300), Size(200, 100)));//�ν� ��ư
	Mat Exit = src(Rect(Point(500, 400), Size(200, 100)));//���� ��ư
	imshow("src", src);
	waitKey();
	return 0;
}
void menu(Mat* img)
{
	Mat src = *img;
	line(src, Point(0, 0), Point(0, 499), Scalar(0, 0, 0), 3);
	line(src, Point(0, 0), Point(699, 0), Scalar(0, 0, 0), 3);
	line(src, Point(699, 0), Point(699, 499), Scalar(0, 0, 0), 3);
	line(src, Point(0, 499), Point(699, 499), Scalar(0, 0, 0), 3);
	line(src, Point(500, 0), Point(500, src.rows - 1), Scalar(0, 0, 0), 3);
	line(src, Point(500, 100), Point(src.cols - 1, 100), Scalar(0, 0, 0), 3);
	line(src, Point(500, 200), Point(src.cols - 1, 200), Scalar(0, 0, 0), 3);
	line(src, Point(500, 300), Point(src.cols - 1, 300), Scalar(0, 0, 0), 3);
	line(src, Point(500, 400), Point(src.cols - 1, 400), Scalar(0, 0, 0), 3);
	String massage[] = { "Save","Load","Clear","Run","Exit" };
	int y = 0;
	for (int i = 0; i < 5; i++)
	{
		Size sizeText = getTextSize(massage[i], FONT_HERSHEY_TRIPLEX, 1.0, 1, 0);
		Point org((1200 - sizeText.width) / 2, (100 + sizeText.height) / 2 + y);//Mat �迭�� �κ� �����Ͽ� �ϰ� ���� 1200�̶�� ���ڰ� ��� ������ ��
		putText(src, massage[i], org, FONT_HERSHEY_TRIPLEX, 1.0, 1);
		y += 100;
	}
}
void on_mouse(int x, int y, int flags, void* userdata)
{
	Mat src =
}