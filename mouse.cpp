//
// Created by Michał Kiełkowski on 16/08/2023.
//

#include "mouse.h"

mouse::mouse(int curr_x_cord, int curr_y_cord) {
    x_cord = curr_x_cord;
    y_cord = curr_y_cord;
}

void mouse::move_mouse() {
    CGPoint cursorPosition = CGPointMake(x_cord, y_cord);
    CGEventRef moveEvent = CGEventCreateMouseEvent(
            NULL, kCGEventMouseMoved,
            cursorPosition, kCGMouseButtonLeft
    );
    // connected whit NULL above
    if (moveEvent) {
        CGEventPost(kCGHIDEventTap, moveEvent);
        CFRelease(moveEvent);
    }

}


void mouse::move_mouse_to_specific_point(int x, int y) {
    CGPoint cursorPosition = CGPointMake(x, y);
    CGEventRef moveEvent = CGEventCreateMouseEvent(
            NULL, kCGEventMouseMoved,
            cursorPosition, kCGMouseButtonLeft
    );
    // connected whit NULL above
    if (moveEvent) {
        CGEventPost(kCGHIDEventTap, moveEvent);
        CFRelease(moveEvent);
    }

}

void mouse::left_mouse_click() {
    CGPoint cursorPosition = CGPointMake(x_cord, y_cord);

    CGEventRef clickEvent = CGEventCreateMouseEvent(nullptr, kCGEventLeftMouseDown,

                                                    cursorPosition, kCGMouseButtonLeft);if (clickEvent) {
        CGEventPost(kCGHIDEventTap, clickEvent);
        usleep(500000);
        CFRelease(clickEvent);
    }

    clickEvent = CGEventCreateMouseEvent(nullptr, kCGEventLeftMouseUp,
                                         cursorPosition, kCGMouseButtonLeft);
    if (clickEvent) {
        CGEventPost(kCGHIDEventTap, clickEvent);
        usleep(500000);
        CFRelease(clickEvent);
    }
}

int mouse::get_x_cord() {
    cout << "x :" << x_cord << endl;
    return x_cord;
}

int mouse::get_y_cord() {
    cout << "y :" <<  y_cord << endl;
    return y_cord;

}
