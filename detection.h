#include <opencv4/opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "opencv2/calib3d.hpp"
#include <opencv2/features2d.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <iostream>

class Detection{
    private:
        cv::Mat image;
        std::vector<cv::Mat> detectedImages;
    public:
        Detection(const cv::Mat img);
        void findContours();
        void compareObjects();
};
