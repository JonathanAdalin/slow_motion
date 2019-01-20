#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include "io.h"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cout << "Enter the path to the video as an argument" << std::endl;
    return -1;
  }

  slow_motion_io::LoadVideo(argv[1]);

  return 0;
}