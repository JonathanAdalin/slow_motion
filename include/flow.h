#ifndef SLOW_MOTION_FLOW_H_
#define SLOW_MOTION_FLOW_H_

#include "opencv2/opencv.hpp"

namespace flow {

// Calculates the optical flow between two frames <frame_1> and <frame_2>
cv::Mat calculate_flow(cv::Mat frame_1, cv::Mat frame_2);

}  // namespace flow

#endif  // SLOW_MOTION_FLOW_H_