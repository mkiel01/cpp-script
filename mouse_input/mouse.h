//
// Created by Michał Kiełkowski on 16/08/2023.
//

#ifndef MOUSE_INPUT_MOUSE_H
#define MOUSE_INPUT_MOUSE_H

#include <CoreGraphics/CoreGraphics.h>
#include <iostream>

using namespace std;

class mouse {
public:
    int x_cord;
    int y_cord;
    mouse(int, int);
    void move_mouse();
    void left_mouse_click();

    // variable handling
    int get_x_cord();
    int get_y_cord();
};


#endif //MOUSE_INPUT_MOUSE_H
