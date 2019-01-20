#ifndef SLOW_MOTION_IO_H_
#define SLOW_MOTION_IO_H_

#include <string>
#include "opencv2/opencv.hpp"
#include "sequence.h"

namespace slow_motion_io {

// Loads the video from <video_path> into a sequence of frames, sequence.
// Throws an exception if it load fails.
void LoadVideo(sequence::Sequence &sequence, std::string video_path);

// Displays the video to the user.
void DisplayVideo(sequence::Sequence sequence);

struct LoadVideoFailException : public std::exception {
   const char * what() const throw () {
     return "Could not load target video.";
   }
};

}  // namespace slow_motion_io

#endif  // SLOW_MOTION_IO_H_