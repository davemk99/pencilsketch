#include <opencv2/opencv.hpp>

void PencilSketch(cv::Mat InputImage,cv::Mat &dst)
{
	cv::Mat gray;

	cv::cvtColor(InputImage, gray, CV_BGR2GRAY);
	cv::Mat invert;
	cv::Mat tmp;
	cv::Mat gaus;
	cv::GaussianBlur(gray, gaus, cv::Size(25, 25), 0,0);
	
	cv::divide(gray, gaus,dst, 256);
	
	cv::cvtColor(dst, dst, CV_GRAY2BGR);

		
	
	

	
}
int main(int argc,char** argv)
{
	cv::Mat frame=cv::imread(argv[1]);
	cv::Mat Pencil;
	PencilSketch(frame, Pencil);
	
	cv::imwrite("PencilSketch.jpg", Pencil);
	
	
	
}
