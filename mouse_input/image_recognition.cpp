//
// Created by Michał Kiełkowski on 16/08/2023.
//

#include "image_recognition.h"

void image_recognition::read_image(string image_to_read) {
    // Read the input image
    cv::Mat inputImage = cv::imread(image_to_read, cv::IMREAD_COLOR);
    if (inputImage.empty()) {
        cout << "Could not read the image." << std::endl;
    }
}

void image_recognition::temple_matching(string image_to_match, string screenshot_of_whole) {
    // Read the screenshot of whole
    cv::Mat inputImage = cv::imread(screenshot_of_whole, cv::IMREAD_COLOR);
    if (inputImage.empty()) {
        cout << "Could not read the image." << std::endl;
        exit(1);
    }
    // Read the template image
    cv::Mat templateImage = cv::imread(image_to_match , cv::IMREAD_COLOR);
    if (templateImage.empty()) {
        cout << "Could not read the template image." << std::endl;
        exit(1);
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
        x_cord = point.x + templateImage.cols / 2;
        y_cord = point.y + templateImage.rows / 2;
    }
}

image_recognition::image_recognition(int i, int i1) : mouse(i, i1) {}
