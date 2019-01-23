#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include "io.h"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cout << "Enter the path to the video as an argument" << std::endl;
    return -1;
  }

  sequence::Sequence sequence;
  try {
    slow_motion_io::LoadVideo(sequence, argv[1]);
    slow_motion_io::DisplayVideo(sequence);
    slow_motion_io::WriteVideo(sequence, "C:\\Users\\jadali\\Desktop");
  }
  catch (slow_motion_io::LoadVideoFailException e) {
    std::cout << e.what() << std::endl;
  }
  catch (slow_motion_io::WriteVideoFailException e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}