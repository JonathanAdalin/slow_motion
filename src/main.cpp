#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include "sequence.h"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cout << "Enter the path to the video as an argument" << std::endl;
    return -1;
  }

  try {
    sequence::Sequence sequence = sequence::Sequence(argv[1]);
    sequence.DisplayVideo();
    sequence.WriteVideo("C:\\Users\\jadali\\Desktop");
  }
  catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}