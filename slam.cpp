// slam.cpp
#include "slam.hpp"

#include <iostream>
using namespace std;

void process_frame(cv::Mat *frame) {
    // Display the resulting frame
    cv::imshow( "Frame", *frame);
}

int main() {
    cv::VideoCapture cap("../videos/test_countryroad.mp4");

    
    if (!cap.isOpened()) {
        cout << "Error opening video stream or file" << endl;
        return -1;
    }

    cv::Mat frame;
    while(true){
        // Capture frame-by-frame
        cap.read(frame);
        if (!frame.empty()) {
            process_frame(&frame);
        } else {
            break;
        }

        // If the frame is empty, break immediately
        if (frame.empty())
            break;
  
        // Press  ESC on keyboard to exit
        char c=(char) cv::waitKey(25);
        if(c==27)
            break;
    }

    // When everything done, release the video capture object
    cap.release();

    // Closes all the frames
    cv::destroyAllWindows();

    return 0;
}