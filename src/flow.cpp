#include "flow.h"
#include "io.h"

namespace flow {

cv::Mat CalculateFlow(cv::Mat frame_1, cv::Mat frame_2) {
  // Optical flow can't handle colored images.
  cv::Mat gray_frame_1, gray_frame_2;
  cv::cvtColor(frame_1, gray_frame_1, cv::COLOR_BGR2GRAY);
  cv::cvtColor(frame_2, gray_frame_2, cv::COLOR_BGR2GRAY);

  cv::Mat prev_pts = cv::Mat(gray_frame_1.size(), CV_8U, 1);
  cv::Mat next_pts = cv::Mat(gray_frame_1.size(), CV_8U);

  slow_motion_io::DisplayFrame(gray_frame_1);
  slow_motion_io::DisplayFrame(gray_frame_2);

  // cv::calcOpticalFlowPyrLK(gray_frame_1, gray_frame_2, prev_pts, next_pts,

  return frame_1;
}

}  // namespace flow