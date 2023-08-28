#include <iostream>
#include <cstdlib> // For the system function
#include <unistd.h>
#include <CoreGraphics/CoreGraphics.h>
#include <CoreFoundation/CoreFoundation.h>
#include <ApplicationServices/ApplicationServices.h>
#include <thread>
#include <chrono>

using namespace std;


int main() {
    auto start = std::chrono::steady_clock::now();
    system("open https://www.youtube.com");
    std::chrono::seconds delayDuration(4);
    this_thread::sleep_for(delayDuration);
    while (true) {
        auto now = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - start).count();



        // Get the main screen dimensions
        CGDirectDisplayID displayID = kCGDirectMainDisplay;
        CGRect screenBounds = CGDisplayBounds(displayID);

        // Calculate the center of the screen
        CGPoint center = CGPointMake(CGRectGetMidX(screenBounds), CGRectGetMidY(screenBounds));

        // Create a new mouse event to move the cursor
        CGPoint newCursorPosition =CGPointMake(center.x, center.y + 100); // Specify your desired coordinates

        CGPoint newCursorPosition1 =CGPointMake(center.x, center.y + 100); // Specify your desired coordinates

        CGEventRef event = CGEventCreate(nullptr);
        if (event) {
            // Set event type to mouse moved
            CGEventSetType(event, kCGEventMouseMoved);

            // Set event's mouse cursor position
            CGEventSetLocation(event, newCursorPosition);

            // Post the event to move the cursor
            CGEventPost(kCGHIDEventTap, event);

            // Release the event
            CFRelease(event);

            // may be wrong !!!!!!!

            // Perform a mouse click
            CGEventRef clickEvent = CGEventCreateMouseEvent(nullptr, kCGEventLeftMouseDown,
                                                            newCursorPosition, kCGMouseButtonLeft);
            CGEventPost(kCGHIDEventTap, clickEvent);
            std::chrono::seconds delayDuration(1);
            this_thread::sleep_for(delayDuration);
            CFRelease(clickEvent);

            clickEvent = CGEventCreateMouseEvent(nullptr, kCGEventLeftMouseUp,
                                                 newCursorPosition1, kCGMouseButtonLeft);
            CGEventPost(kCGHIDEventTap, clickEvent);
            std::chrono::seconds delayDuration2(1);
            this_thread::sleep_for(delayDuration);
            CFRelease(clickEvent);


            CGEventRef clickEvent2 = CGEventCreateMouseEvent(nullptr, kCGEventLeftMouseDown,
                                                            newCursorPosition1, kCGMouseButtonLeft);
            CGEventPost(kCGHIDEventTap, clickEvent2);
            std::chrono::seconds delayDuration3(1);
            this_thread::sleep_for(delayDuration);
            CFRelease(clickEvent);

            clickEvent = CGEventCreateMouseEvent(nullptr, kCGEventLeftMouseUp,
                                                 newCursorPosition1, kCGMouseButtonLeft);
            CGEventPost(kCGHIDEventTap, clickEvent2);
            std::chrono::seconds delayDuration4(1);
            this_thread::sleep_for(delayDuration);
            CFRelease(clickEvent);

        }


        if (elapsed >= 0.5) {
            cout << "function end";
            break;
        }
    }

    return 0;
}
