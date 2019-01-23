#ifndef SLOW_MOTION_SEQUENCE_H_
#define SLOW_MOTION_SEQUENCE_H_

#include <list>
#include <string>
#include "opencv2/opencv.hpp"

namespace sequence {

class Sequence {
 public:

  Sequence();

  // Accessors and mutators
  const std::list<cv::Mat> get_frames() { return this->frames; }
  void set_frames(std::list<cv::Mat> frames) { this->frames = frames; }
  void push_back(cv::Mat frame) { this->frames.push_back(frame); }

  // Loads the video from <video_path> into a sequence of frames.
  // Throws a LoadVideoFailException exception if the load fails.
  void LoadVideo(std::string video_path);

  // Writes the frame sequence as an .MP4 to <video_path>.
  // Throws a WriteVideoException exception if the write fails.
  void WriteVideo(std::string video_path);

  // Displays the video to the user.
  void DisplayVideo();

 private:
  // Frame interpolation requires multiple inserts, which are O(1) for lists.
  std::list<cv::Mat> frames;
};

}  // namespace sequence

#endif  // SLOW_MOTION_SEQUENCE_H_