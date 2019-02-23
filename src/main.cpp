#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include "sequence.h"
#include "flow.h"  // TODO remove

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cout << "Enter the path to the video as an argument" << std::endl;
    return -1;
  }
  try {
    sequence::Sequence sequence = sequence::Sequence(argv[1]);
    sequence.DisplayVideo();
    // flow::CalculateFlow(sequence.get_frame(0), sequence.get_frame(1));
    sequence.WriteVideo("C:\\Users\\jadali\\Code\\slow_motion\\out");
  }
  catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}