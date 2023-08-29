//
// Created by Michał Kiełkowski on 16/08/2023.
//

#include "keyboard.h"

void keyboard::write_input(const std::string &message, int delayMillis) {
    for (char c : message) {
        if (c == '\n') { // Check for newline character
            // Simulate pressing the "Enter" key the value for the enter key is 36 !
            CGEventRef keyEventDown = CGEventCreateKeyboardEvent(NULL, 36, true);
            CGEventPost(kCGHIDEventTap, keyEventDown);
            CFRelease(keyEventDown);

            std::this_thread::sleep_for(std::chrono::milliseconds(delayMillis));

            CGEventRef keyEventUp = CGEventCreateKeyboardEvent(NULL, 36, false);
            CGEventPost(kCGHIDEventTap, keyEventUp);
            CFRelease(keyEventUp);

            std::this_thread::sleep_for(std::chrono::milliseconds(delayMillis));
        } else {
            CGEventRef keyEventDown = CGEventCreateKeyboardEvent(NULL, 0, true);
            UniChar oneChar = c;
            CGEventKeyboardSetUnicodeString(keyEventDown, 1, &oneChar);
            CGEventPost(kCGHIDEventTap, keyEventDown);
            CFRelease(keyEventDown);

            std::this_thread::sleep_for(std::chrono::milliseconds(delayMillis));

            CGEventRef keyEventUp = CGEventCreateKeyboardEvent(NULL, 0, false);
            CGEventKeyboardSetUnicodeString(keyEventUp, 1, &oneChar);
            CGEventPost(kCGHIDEventTap, keyEventUp);
            CFRelease(keyEventUp);

            std::this_thread::sleep_for(std::chrono::milliseconds(delayMillis));
        }
    }
}