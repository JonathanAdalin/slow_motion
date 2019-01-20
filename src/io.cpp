#include "io.h"

namespace slow_motion_io {

sequence::Sequence* LoadVideo(std::string video_path) {
  cv::VideoCapture video(video_path);
  if (!video.isOpened())
    throw LoadVideoFailException();

  sequence::Sequence* sequence = new sequence::Sequence();
  
  while (1) {
    cv::Mat current_frame;
    video >> current_frame;
    if (current_frame.empty())
      break;

    // TODO replace with frame storing
    cv::imshow("Frame", current_frame);
    char c = (char) cv::waitKey(25);
    if (c == 27)
      break;
  }

  video.release();
  cv::destroyAllWindows();

  return NULL;
}

}