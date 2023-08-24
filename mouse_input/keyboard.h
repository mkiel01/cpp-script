//
// Created by Michał Kiełkowski on 16/08/2023.
//

#ifndef MOUSE_INPUT_KEYBOARD_H
#define MOUSE_INPUT_KEYBOARD_H
#include <iostream>
#include <string>
#include <CoreGraphics/CoreGraphics.h>
#include <thread>

class keyboard {
public:
    void write_input(const std::string& message, int delayMillis);
};


#endif //MOUSE_INPUT_KEYBOARD_H
