#include "detection.h"



Detection::Detection(const cv::Mat img)
{
    image = img;
}


void Detection::findContours()
{
    /* Find contours and extract objects by checking area of contours
       objects are extracted from original image and stored in an array*/
     cv::Mat out;
     int x = 0;
     cv::Rect r;
     std::vector<cv::Mat> objimgs;
     std::vector<cv::Vec4i> hiearchy;
     std::vector<cv::Point> approxCurve;
     std::vector<std::vector<cv::Point>> contours;
     cv::Mat drawing = cv::Mat::zeros(image.rows, image.cols, image.type());
     cv::Canny(image, out, 100, 200);
     cv::findContours(out, contours, hiearchy, cv::RETR_CCOMP, cv::CHAIN_APPROX_SIMPLE);

     for(size_t i=0; i<contours.size();i++)
     {
         cv::approxPolyDP(contours[i], approxCurve, 0.1*cv::arcLength(contours[i], true), true);
         r = cv::boundingRect(contours[i]);

         if(r.area() > 10450 &&(std::abs(r.x-x)>40))
         {
             objimgs.push_back(image(r));
             x = r.x;
         }
         cv::drawContours(drawing, contours, int(i), cv::Scalar(0,0,255), 1, cv::LINE_8, cv::Mat());
     }
     detectedImages = objimgs;

}


void Detection::compareObjects()
{
    /* Stored object images are compared based on their histogram calculations 
       All methods are applied on image pairs while comparing histograms*/
    cv::Mat hsv1, hsv2;
    cv::Mat hist_hsv1, hist_hsv2;
    int histSize[] = {50, 50};
    float h_ranges[] = {0, 180};
    float s_ranges[] = {0, 256};
    const float* ranges[] = {h_ranges, s_ranges};
    int channels[] = {0, 1};

    for(size_t i=0;i<detectedImages.size();i++)
    {
        cv::cvtColor(detectedImages[i], hsv1, cv::COLOR_BGR2HSV);
        cv::calcHist(&hsv1, 1, channels, cv::Mat(), hist_hsv1, 2, histSize, ranges, true, false);
        cv::normalize(hist_hsv1, hist_hsv1, 0, 1, cv::NORM_MINMAX, -1, cv::Mat());
        for(size_t j=0;j<detectedImages.size();j++)
        {
            if(j==i)
                continue;
            cv::cvtColor(detectedImages[j], hsv2, cv::COLOR_BGR2HSV);
            cv::calcHist(&hsv2, 1, channels, cv::Mat(), hist_hsv2, 2, histSize, ranges, true, false);
            cv::normalize(hist_hsv2, hist_hsv2, 0, 1, cv::NORM_MINMAX, -1, cv::Mat());
            double comparison = cv::compareHist(hist_hsv1, hist_hsv2, 0);
            double comparison1 = cv::compareHist(hist_hsv1, hist_hsv2, 1);
            double comparison2 = cv::compareHist(hist_hsv1, hist_hsv2, 2);
            double comparison3 = cv::compareHist(hist_hsv1, hist_hsv2, 3);
            std::cout <<"comp1: " << comparison <<" comp2: " <<comparison1 << " comp3: "<<comparison2<<" comp4: " <<comparison3<< std::endl;
            cv::imshow("img1", detectedImages[i]);
            cv::imshow("img2", detectedImages[j]);
            cv::waitKey(0);
            cv::destroyAllWindows();
        }
    }

}





