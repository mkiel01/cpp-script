#include <opencv2/opencv.hpp>
#include <iostream>
#include <CoreGraphics/CoreGraphics.h>
#include <ApplicationServices/ApplicationServices.h>
#include <thread>
#include <chrono>
using namespace std;


int main() {

    int centerX;
    int centerY;
    system("open https://penzu.com/app/login?after_login=%2Fjournals");
    usleep(5000000); // Sleep for 1 second (adjust as needed)
    system("screencapture input1.png");
    // Read the input image
    cv::Mat inputImage = cv::imread("/Users/michalkielkowski/Desktop/infa-all/scripts/c++-script-dairy/mouse_input/cmake-build-debug/input1.png", cv::IMREAD_COLOR);
    if (inputImage.empty()) {
        std::cout << "Could not read the image." << std::endl;
        return -1;
    }

    // Read the template image (Facebook icon)
    cv::Mat templateImage = cv::imread("/Users/michalkielkowski/Desktop/infa-all/scripts/c++-script-dairy/mouse_input/find1.png", cv::IMREAD_COLOR);
    if (templateImage.empty()) {
        std::cout << "Could not read the template image." << std::endl;
        return -1;
    }

    // Perform template matching
    cv::Mat result;
    cv::matchTemplate(inputImage, templateImage, result, cv::TM_CCOEFF_NORMED);

    // Set a threshold for matching
    double threshold = 0.5;
    cv::Mat thresholdMask;
    cv::threshold(result, thresholdMask, threshold, 1.0, cv::THRESH_BINARY);

    // Find the location(s) of the match
    std::vector<cv::Point> locations;
    cv::findNonZero(thresholdMask, locations);

    // Draw red rectangles around the matched locations
    for (const cv::Point& point : locations) {
        cv::Rect rect(point.x, point.y, templateImage.cols, templateImage.rows);
        cv::rectangle(inputImage, rect, cv::Scalar(0, 0, 255), 2); // Red color (BGR order)

        centerX = point.x + templateImage.cols / 2;
        centerY = point.y + templateImage.rows / 2;


    }

    CGPoint cursorPosition = CGPointMake(centerX, centerY);
    CGEventRef moveEvent = CGEventCreateMouseEvent(
            NULL, kCGEventMouseMoved,
            cursorPosition, kCGMouseButtonLeft
    );
    CGEventPost(kCGHIDEventTap, moveEvent);
    CFRelease(moveEvent);

    cout << "mouse moved" << endl;
    // Rest for a moment to allow cursor movement to be visible
    usleep(1000000); // Sleep for 1 second (adjust as needed)

    // Display the result

    // Display the result in full screen using native macOS APIs
    cv::resizeWindow("Result", 1920, 1080);  // Resize the window to full screen resolution
    cv::moveWindow("Result", 0, 0);          // Move the window to the top-left corner
    cv::imshow("Result", inputImage);


    usleep(3000000); // Sleep for 5 second (adjust as needed)

    // Loop through the detected locations
//    for (const cv::Point& point : locations) {
        // Calculate the center of the matched region
//        int centerX = point.x + templateImage.cols / 2;
//        int centerY = point.y + templateImage.rows / 2;

        // Move the mouse cursor to the center of the matched region using CoreGraphics
//        CGPoint cursorPosition = CGPointMake(centerX, centerY);
//        CGEventRef moveEvent = CGEventCreateMouseEvent(
//                NULL, kCGEventMouseMoved,
//                cursorPosition, kCGMouseButtonLeft
//        );
//        CGEventPost(kCGHIDEventTap, moveEvent);
//        CFRelease(moveEvent);
//
//        cout << "mouse moved";
//        // Rest for a moment to allow cursor movement to be visible
//        usleep(1000000); // Sleep for 1 second (adjust as needed)

//    }

    // Remove the input1 image file from the system
    if (remove("/Users/michalkielkowski/Desktop/infa-all/scripts/c++-script-dairy/mouse_input/cmake-build-debug/input1.png") != 0) {
        cout << "Error deleting input1.png" << endl;
    } else {
        cout << "input1.png successfully removed" << endl;
    }
// Perform a mouse click

    CGEventRef clickEvent = CGEventCreateMouseEvent(nullptr, kCGEventLeftMouseDown,
                                                    cursorPosition, kCGMouseButtonLeft);
    CGEventPost(kCGHIDEventTap, clickEvent);
    std::chrono::seconds delayDuration(1);
    this_thread::sleep_for(delayDuration);
    CFRelease(clickEvent);

    clickEvent = CGEventCreateMouseEvent(nullptr, kCGEventLeftMouseUp,
                                         cursorPosition, kCGMouseButtonLeft);
    CGEventPost(kCGHIDEventTap, clickEvent);
    std::chrono::seconds delayDuration2(1);
    this_thread::sleep_for(delayDuration);
    CFRelease(clickEvent);

    return 0;
}
