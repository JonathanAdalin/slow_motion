#ifndef SLOW_MOTION_IO_H_
#define SLOW_MOTION_IO_H_

#include <string>

namespace slow_motion_io {

struct LoadVideoFailException : public std::exception {
   const char * what() const throw () {
     return " Could not load target video.";
   }
};

struct WriteVideoFailException : public std::exception {
  const char * what() const throw () {
    return " Could not write video. Target path not accessible or does not \
            \n exist.";
  }
};

}  // namespace slow_motion_io

#endif  // SLOW_MOTION_IO_H_