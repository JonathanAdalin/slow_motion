#ifndef SLOW_MOTION_IO_H_
#define SLOW_MOTION_IO_H_

#include <string>
#include "opencv2/opencv.hpp"
#include "sequence.h"

namespace slow_motion_io {

// Loads the video from <video_path> into a sequence of frames, <sequence>.
// Throws a LoadVideoFailException exception if the load fails.
void LoadVideo(sequence::Sequence &sequence, std::string video_path);

// Writes <sequence> as an .MP4 to <video_path>.
// Throws a WriteVideoException exception if the write fails.
void WriteVideo(sequence::Sequence sequence, std::string video_path);

// Displays the video to the user.
void DisplayVideo(sequence::Sequence sequence);

struct LoadVideoFailException : public std::exception {
   const char * what() const throw () {
     return "Could not load target video.";
   }
};

struct WriteVideoFailException : public std::exception {
  const char * what() const throw () {
    return "Could not write video. Target path not accessible or does not \
            \nexist.";
  }
};

}  // namespace slow_motion_io

#endif  // SLOW_MOTION_IO_H_