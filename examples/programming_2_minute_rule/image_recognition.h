//
// Created by Michał Kiełkowski on 16/08/2023.
//

#ifndef MOUSE_INPUT_IMAGE_RECOGNITION_H
#define MOUSE_INPUT_IMAGE_RECOGNITION_H

#include "mouse.h"
#include "keyboard.h"
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

class image_recognition: public mouse, public keyboard {
public:
    void temple_matching(string, string);
    image_recognition(int x, int y); // constructor
    void read_image(string);
};


#endif //MOUSE_INPUT_IMAGE_RECOGNITION_H
