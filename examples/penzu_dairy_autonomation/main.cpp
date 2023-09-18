#include <iostream>
using namespace std;

#include "program.h"
#include "mouse.h"
#include "keyboard.h"
#include <chrono>
#include <thread>
#include <ctime>
#include <iomanip>

int main() {

    system("open https://penzu.com/app/login?after_login=%2Fjournals");
    usleep(5000000); // Sleep for 5 second (adjust as needed)
    system("screencapture /Users/michalkielkowski/Desktop/infa-all/scripts/c++-web-scripting/examples/penzu_dairy_autonomation/cmake-build-debug/input1.png");

    program penzu(0, 0);

    penzu.temple_matching("/Users/michalkielkowski/Desktop/infa-all/scripts/c++-web-scripting/examples/penzu_dairy_autonomation/find1.png", "/Users/michalkielkowski/Desktop/infa-all/scripts/c++-web-scripting/examples/penzu_dairy_autonomation/cmake-build-debug/input1.png" );

    penzu.get_x_cord();
    penzu.get_y_cord();

    penzu.move_mouse();
    usleep(1000000); // Sleep for 1 second (adjust as needed)
    penzu.left_mouse_click();
    usleep(5000000); // Sleep for 1 second (adjust as needed)
    time_t currentTime = time(nullptr);
    tm *localTime = localtime(&currentTime);
    int day = localTime->tm_mday;
    int month = localTime->tm_mon + 1;
    string formattedDate = to_string(day) + "." + (month < 10 ? "0" : "") + to_string(month);
    penzu.write_input(formattedDate, 100);
    usleep(1000000); // Sleep for 1 second (adjust as needed)
    penzu.move_mouse_to_specific_point(penzu.get_x_cord(), penzu.get_y_cord() - 200);
    usleep(1000000); // Sleep for 1 second (adjust as needed)
    penzu.left_mouse_click();
    usleep(1000000); // Sleep for 1 second (adjust as needed)
    penzu.write_input("How was your day:\nWhat did you learn today:\nHow was the day in a scale 1-10:", 100);
    remove("/Users/michalkielkowski/Desktop/infa-all/scripts/c++-web-scripting/examples/penzu_dairy_autonomation/cmake-build-debug/input1.png");
    return 0;
}