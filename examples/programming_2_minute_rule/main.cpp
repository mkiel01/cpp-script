#include <iostream>

using namespace std;

#include "program.h"
#include "image_recognition.h"
#include "mouse.h"
#include "keyboard.h"
#include <chrono>
#include <thread>
#include <ctime>
#include <iomanip>

int main() {


    system("open -a Clock");
    usleep(2000000); // Sleep for 5 second (adjust as needed)
    system("screencapture /Users/michalkielkowski/Desktop/infa-all/scripts/c++-web-scripting/examples/programming_2_minute_rule/cmake-build-debug/input1.png");

    program penzu(0, 0);
    usleep(1000000); // Sleep for 5 second (adjust as needed)
    penzu.temple_matching("/Users/michalkielkowski/Desktop/infa-all/scripts/c++-web-scripting/examples/programming_2_minute_rule/find1.png", "/Users/michalkielkowski/Desktop/infa-all/scripts/c++-web-scripting/examples/programming_2_minute_rule/cmake-build-debug/input1.png");

    penzu.get_x_cord();
    penzu.get_y_cord();

    penzu.move_mouse();
    usleep(1000000); // Sleep for 1 second (adjust as needed)
    penzu.left_mouse_click();
    usleep(1000000); // Sleep for 1 second (adjust as needed)
    system("open https://docs.google.com/document/d/1XLF2jUz7_OzPFjRw5jklgG_kZSZ0kxG71HC9MOkLN-o/edit");
    usleep(2000000); // Sleep for 5 second (adjust as needed)
    remove("/Users/michalkielkowski/Desktop/infa-all/scripts/c++-web-scripting/examples/programming_2_minute_rule/cmake-build-debug/input1.png");

    return 0;
}