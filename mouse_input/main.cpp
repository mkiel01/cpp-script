#include <iostream>
using namespace std;

#include "program.h"
#include "image_recognition.h"
#include "mouse.h"
#include "keyboard.h"
#include <chrono>
#include <thread>

void typeMessage(const std::string& message, int delayMillis) {
    for (char c : message) {
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

int main() {

    system("open https://penzu.com/app/login?after_login=%2Fjournals");
    usleep(5000000); // Sleep for 5 second (adjust as needed)
    system("screencapture input1.png");

    program penzu(0, 0);

    penzu.temple_matching("/Users/michalkielkowski/Desktop/infa-all/scripts/c++-script-dairy/mouse_input/find1.png", "/Users/michalkielkowski/Desktop/infa-all/scripts/c++-script-dairy/mouse_input/cmake-build-debug/input1.png" );

    penzu.get_x_cord();
    penzu.get_y_cord();

    penzu.move_mouse();
    usleep(1000000); // Sleep for 1 second (adjust as needed)
    penzu.left_mouse_click();
    usleep(5000000); // Sleep for 1 second (adjust as needed)
    typeMessage("hello world", 100);



    return 0;
}