#ifndef SLOW_MOTION_SEQUENCE_H_
#define SLOW_MOTION_SEQUENCE_H_

#include <list>
#include <string>
#include "opencv2/opencv.hpp"

namespace sequence {

class Sequence {
 public:

  // Calls LoadVideo to load the video from <video_path> into a sequence.
  // Throws a LoadVideoFailException exception if the load fails.
  Sequence(std::string video_path);

  // Accessors and mutators
  const std::vector<cv::Mat> get_frames() { return this->frames; }
  void push_back(cv::Mat frame) { this->frames.push_back(frame); }
  const cv::Mat get_frame(int i) { return this->frames[i]; }
  void remove(int i) { this->frames.erase(frames.begin() + i); }
  bool is_empty() { return this->frames.empty(); }
  const std::string get_name() { return this->name; }
  void set_name(std::string name) { this->name = name; }
  void set_frame_width(int width) { this->frame_width = width; }
  void set_frame_height(int height) { this->frame_height = height; }
  int get_frame_width() { return this->frame_width; }
  int get_frame_height() { return this->frame_height; }

  // Loads the video from <video_path> into a sequence of frames.
  // Throws a LoadVideoFailException exception if the load fails.
  // Throws a VideoLoadedException exception if the sequence is already
  // populated.
  void LoadVideo(std::string video_path);

  // Writes the frame sequence as an .MP4 to <video_path>.
  // Throws a WriteVideoException exception if the write fails.
  void WriteVideo(std::string video_path);

  // Displays the video to the user.
  void DisplayVideo();

  struct VideoLoadedException : public std::exception {
    const char * what() const throw () {
      return " Could not load target video to Sequence because the sequence \
              \n already contains frames.";
    }
  };

 private:
  // We need to access frames often and vectors have O(1) access.
  std::vector<cv::Mat> frames;
  std::string name;
  int frame_width;
  int frame_height;
};

}  // namespace sequence

#endif  // SLOW_MOTION_SEQUENCE_H_