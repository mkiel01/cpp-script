#include <iostream>
#include <cstdlib> // For the system function
#include <unistd.h>
#include <CoreGraphics/CoreGraphics.h>

using namespace std;

int main() {
    auto start = std::chrono::steady_clock::now();
    while (true) {
        auto now = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - start).count();

    // Use the "open" command in the terminal to open a URL
    // This will open the default web browser and navigate to the given URL
    system("open https://penzu.com/app/login?after_login=%2Fjournals");

    // Get the main screen dimensions
    CGDirectDisplayID displayID = kCGDirectMainDisplay;
    CGRect screenBounds = CGDisplayBounds(displayID);

    // Calculate the center of the screen
    CGPoint center = CGPointMake(CGRectGetMidX(screenBounds), CGRectGetMidY(screenBounds));

    // Calculate the new mouse position 50 pixels to the left
    CGPoint newPosition = CGPointMake(center.x - 50, center.y);

    // Move the mouse
    CGEventRef moveEvent = CGEventCreateMouseEvent(nullptr, kCGEventMouseMoved,
                                                   newPosition, kCGMouseButtonLeft);
    CGEventPost(kCGHIDEventTap, moveEvent);
    CFRelease(moveEvent);

    // Wait for a short time (in microseconds)
    usleep(100000); // 100,000 microseconds = 0.1 seconds

    // Perform a mouse click
    CGEventRef clickEvent = CGEventCreateMouseEvent(nullptr, kCGEventLeftMouseDown,
                                                    newPosition, kCGMouseButtonLeft);
    CGEventPost(kCGHIDEventTap, clickEvent);
    CFRelease(clickEvent);

    clickEvent = CGEventCreateMouseEvent(nullptr, kCGEventLeftMouseUp,
                                         newPosition, kCGMouseButtonLeft);
    CGEventPost(kCGHIDEventTap, clickEvent);
    CFRelease(clickEvent);

    if (elapsed >= 0.25) {
        break;
    }
}

    return 0;
}
