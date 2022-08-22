#include "detection.cpp"



int main(int argc, char *argv[])
{

    cv::Mat img = cv::imread("456.jpeg");
    if(img.empty())
        return EXIT_FAILURE;
    Detection *obj = new Detection(img);
    obj->findContours();
    obj->compareObjects();
    cv::imshow("img",img);
    cv::waitKey(0);
    cv::destroyAllWindows();
    
    return 0;
}
