#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // Read the input image
    cv::Mat inputImage = cv::imread("/Users/michalkielkowski/Desktop/infa-all/scripts/c++ script penzu etc/keybord/mouse_input/input_image.png", cv::IMREAD_COLOR);
    if (inputImage.empty()) {
        std::cout << "Could not read the image." << std::endl;
        return -1;
    }

    // Read the template image (Facebook icon)
    cv::Mat templateImage = cv::imread("/Users/michalkielkowski/Desktop/infa-all/scripts/c++ script penzu etc/keybord/mouse_input/facebook_icon.png", cv::IMREAD_COLOR);
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
    }

    // Display the result
    cv::imshow("Result", inputImage);
    cv::waitKey(0);

    return 0;
}
