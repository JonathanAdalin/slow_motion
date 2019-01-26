#ifndef SLOW_MOTION_IO_H_
#define SLOW_MOTION_IO_H_

#include <string>

namespace slow_motion_io {

// Display <frame> to the user who can use keystroke to close the window.
// The displayed window has name <window_name>, which will default to "Frame".
inline void DisplayFrame(cv::Mat frame, std::string window_name = "Frame") {
  cv::namedWindow(window_name, cv::WINDOW_AUTOSIZE);
  cv::imshow(window_name, frame);
  cv::waitKey(0);
  cv::destroyAllWindows();
}

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