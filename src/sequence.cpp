#include <sys/types.h>
#include <sys/stat.h>
#include "sequence.h"
#include "io.h"

namespace sequence {

Sequence::Sequence(std::string video_path) {
  LoadVideo(video_path);
}

void Sequence::LoadVideo(std::string video_path) {
  if (!this->is_empty()) {
    throw VideoLoadedException();
  }
  cv::VideoCapture video(video_path);
  if (!video.isOpened())
    throw slow_motion_io::LoadVideoFailException();
  while (1) {
    cv::Mat current_frame;  // We need to create a new frame on each iteration.
    video >> current_frame;
    if (current_frame.empty())
      break;
    this->push_back(current_frame);
  }
  video.release();
  return;
}

void Sequence::WriteVideo(std::string video_path) {
  struct stat info;
  if (stat(video_path.c_str(), &info) != 0)
    throw slow_motion_io::WriteVideoFailException();
  else if (info.st_mode & S_IFDIR)
    return;
  else
    throw slow_motion_io::WriteVideoFailException();
  return;
}

void Sequence::DisplayVideo() {
  for (cv::Mat frame : this->get_frames()) {
    cv::imshow("Frame", frame);
    char c = (char)cv::waitKey(25);  // Give some time to see the frame.
  }
  cv::destroyAllWindows();

}

}