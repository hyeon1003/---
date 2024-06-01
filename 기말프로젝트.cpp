// �⸻ ������Ʈ �ʱ�ü �����ν�
#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
void menu(Mat* img);
void Savefile(Mat& src);
void Roadfile(Mat& src);
void Clear(Mat& src);
void Run(Mat& src);
void Exit();
void on_mouse(int event, int x, int y, int flags, void* userdata);
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
	Mat dst = src(Rect(500, 0, 200, 500));//�޴���� �κ���� ����
	Size dstsize = dst.size();//dst ������
	for (int i = 0; i < 5; i++)//UI �ؽ�Ʈ �� �����ֱ� ���� �ݺ���
	{
		Size sizeText = getTextSize(massage[i], FONT_HERSHEY_TRIPLEX, 1.0, 1, 0);
		Point org((dstsize.width - sizeText.width) / 2, (dstsize.height / 5 + sizeText.height) / 2 + y);//�κ���� ����� ���� �����ʿ� �޴� UI �ؽ�Ʈ ��� 500 x 500�� �Է�â
		putText(dst, massage[i], org, FONT_HERSHEY_TRIPLEX, 1.0, 1);
		y += 100;
	}
}
void on_mouse(int event, int x, int y, int flags, void* userdata)
{
	Mat src = *(Mat*)userdata;
	String file;
	static Point ptPrev(-1, -1);
	switch (event)
	{
	case EVENT_LBUTTONDOWN:
	{
		ptPrev = Point(x, y);
		if (ptPrev.inside(Rect(500, 0, 200, 100)))
		{
			Savefile(src);
		}
		else if (ptPrev.inside(Rect(500, 100, 200, 100)))
		{
			Roadfile(src);
		}
		else if (ptPrev.inside(Rect(500, 200, 200, 100)))
		{
			Clear(src);
		}
		else if (ptPrev.inside(Rect(500, 300, 200, 100)))
		{
			Run(src);
		}
		else if (ptPrev.inside(Rect(500, 400, 200, 100)))
		{
			Exit();
		}
		break;
	}
	case EVENT_MOUSEMOVE:
	{
		if (flags & EVENT_FLAG_LBUTTON) {
			if (Rect(0,0,500,500).contains(ptPrev)&&Rect(0,0,500,500).contains(Point(x,y))){
				line(src, ptPrev, Point(x, y), Scalar::all(0), 5, LINE_AA, 0);
				ptPrev = Point(x, y);
			}
		}
		break;
	}
	}
}
void Savefile(Mat& src)
{
	String file;
	cout << "���ϸ� �Է�:";
	cin >> file;
	imwrite(file, src(Rect(0, 0, 500, 500)));
	cout << file << "������ �����" << endl;
}
void Roadfile(Mat& src)
{
	String file;
	cout << "���ϸ��� �Է�:";
	cin >> file;
	Mat dst = imread(file, IMREAD_COLOR);
	if (dst.empty()) { cerr << "������ ����ֽ��ϴ�." << endl; return; }
	dst.copyTo(src(Rect(0, 0, 500, 500)));
	cout << file << "������ �ҷ���" << endl;
}
void Clear(Mat& src)
{
	Mat dst = src(Rect(0, 0, 500, 500));
	dst = Scalar::all(255);
	cout << "�Է�â�� ������" << endl;
}
void Run(Mat& src)
{
	cout << "�νİ��" << endl;
}
void Exit()
{
	cout << "���α׷� ����" << endl;
	exit(1);
	return;
}
