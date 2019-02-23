#include <sys/types.h>
#include <sys/stat.h>
#include "sequence.h"
#include "io.h"

namespace sequence {

Sequence::Sequence(std::string video_path) {
  LoadVideo(video_path);
  this->set_name("video");
}

void Sequence::LoadVideo(std::string video_path) {
  if (!this->is_empty()) {
    throw VideoLoadedException();
  }
  cv::VideoCapture video(video_path);
  if (!video.isOpened())
    throw slow_motion_io::LoadVideoFailException();
  bool is_first_frame = true;
  while (1) {
    cv::Mat current_frame;  // We need to create a new frame on each iteration.
    video >> current_frame;
    if (current_frame.empty())
      break;
    this->push_back(current_frame);
    if (is_first_frame) {  // Frames in a video are of equal dimension.
      is_first_frame = false;
      this->set_frame_width(current_frame.cols);
      this->set_frame_height(current_frame.rows);
    }
  }
  video.release();
  return;
}

void Sequence::WriteVideo(std::string video_path) {
  struct stat info;
  if (stat(video_path.c_str(), &info) != 0)
    throw slow_motion_io::WriteVideoFailException();
  else if (!info.st_mode & S_IFDIR)
    throw slow_motion_io::WriteVideoFailException();
  cv::String video_name = video_path.append("\\" + this->get_name() + "_out.avi");
  cv::VideoWriter video(video_name, CV_FOURCC('M', 'J', 'P', 'G'), 24,
                        cv::Size(this->get_frame_width(),
                                 this->get_frame_height()));
  while (!this->is_empty()) {
    video.write(this->get_frame(0));
    this->remove(0);
  }
  video.release();
  std::cout << "The video was written to: \n" + video_name << std::endl;
}

void Sequence::DisplayVideo() {
  for (cv::Mat frame : this->get_frames()) {
    cv::imshow("Frame", frame);
    char c = (char)cv::waitKey(25);  // Give some time to see the frame.
  }
  cv::destroyAllWindows();

}

}  // namespace flow