#ifndef SLOW_MOTION_IO_H_
#define SLOW_MOTION_IO_H_

#include <string>
#include "opencv2/opencv.hpp"
#include "sequence.h"

namespace slow_motion_io {

// Loads the video into a sequence of frames. Throws an exception if it load
// fails.
sequence::Sequence* LoadVideo(std::string video_path);

struct LoadMP4FailException : public std::exception {
   const char * what() const throw () {
     return "Could not load MP4.";
   }
};

}  // namespace slow_motion_io

#endif  // SLOW_MOTION_IO_H_