#include "io.h"

namespace slow_motion_io {

void LoadVideo(sequence::Sequence &sequence, std::string video_path) {
  cv::VideoCapture video(video_path);
  if (!video.isOpened())
    throw LoadVideoFailException();
  while (1) {
    cv::Mat current_frame;  // We need to create a new frame on each iteration.
    video >> current_frame;
    if (current_frame.empty())
      break;
    sequence.push_back(current_frame);
  }
  video.release();
  return;
}

void DisplayVideo(sequence::Sequence sequence) {
  for (cv::Mat frame : sequence.get_frames()) {
    cv::imshow("Frame", frame);
    char c = (char)cv::waitKey(25);  // Give some time to see the frame.
  }
  cv::destroyAllWindows();
}

}