#ifndef SLOW_MOTION_SEQUENCE_H_
#define SLOW_MOTION_SEQUENCE_H_

#include <list>
#include <string>
#include "opencv2/opencv.hpp"

namespace sequence {

class Sequence {
 public:
  Sequence(std::string video_path);

  // Accessors and mutators
  const std::list<cv::Mat> get_frames() { return this->frames; }
  void set_frames(std::list<cv::Mat> frames) { this->frames = frames; }

 private:
  // Frame interpolation requires multiple inserts, which are O(1) for lists.
  std::list<cv::Mat> frames;
};

}  // namespace sequence

#endif  // SLOW_MOTION_SEQUENCE_H_