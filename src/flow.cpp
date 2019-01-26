#include "flow.h"
#include "io.h"

namespace flow {

cv::Mat CalculateFlow(cv::Mat frame_1, cv::Mat frame_2) {
  cv::Mat gray_frame_1, gray_frame_2;
  cv::cvtColor(frame_1, gray_frame_1, cv::COLOR_BGR2GRAY);
  slow_motion_io::DisplayFrame(gray_frame_1);
  return frame_1;
}

}  // namespace flow