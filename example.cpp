// Martin Kersner, m.kersner@gmail.com
// 2016/12/18

#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>

#include "utils.hpp"
#include "nms.hpp"


int main()
{

  // initialization
  cv::Mat imgBefore(cv::Size(500, 500), cv::DataType<float>::type);
  cv::Mat imgAfter = imgBefore.clone();
  float threshold	= 0.5;
  std::vector<std::vector<float> > rectangles =
  {
    {300, 300, 400, 400},
    {320, 290, 500, 390},
    {320, 320, 420, 420},
    {295, 259, 415, 415},
    {100, 100, 150, 150},
    {90,  90,  180, 180},
    {112, 112, 170, 170},
    {100, 122, 200, 180}
  };

  // before
  DrawRectangles(imgBefore, rectangles);

  cv::imshow("Before", imgBefore);
  //

  /*
  std::vector<float> tvect(10);

  tvect = {21,3,5,1,0,11,53,12, 2 , 13};
  std::vector<int> idx(tvect.size());
  std::iota(idx.begin(), idx.end(), 0);
  
  // sort indexes based on comparing values in v
  sort(idx.begin(), idx.end(), [&tvect](int i1, int i2) {return tvect[i1] < tvect[i2];}); // c++ tricky sort function

  for (int i=0; i< tvect.size(); i++){
     std::cout<< "idx " << idx[i] << ",  vect val: " << tvect[idx[i]] << std::endl;
    //  std::cout<< idx[i] << std::endl;
  }
 */

  // after
  std::vector<std::vector<float>> reducedRectangle = nms(rectangles, threshold); // nms with scores and thresholds

  for (int i=0; i< reducedRectangle.size(); i++){
  std::cout<< "1: " << reducedRectangle[i][0]<< ", 2: " << reducedRectangle[i][1]<< ", 3: " << reducedRectangle[i][2]<< ", 4: " << reducedRectangle[i][3]<< std::endl;
  }

  DrawRectangles(imgAfter, reducedRectangle);
  cv::imshow("After", imgAfter);
  
  cv::waitKey(0);
}

