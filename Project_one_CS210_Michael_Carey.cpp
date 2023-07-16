/*
 * Project One.cpp
 *
 * Date: July 16 2023
 * Author: Michael Carey
 */

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

// Function needed to format numbers as two digits
string formatTwoDigits(int number) {
    return (number < 10) ? "0" + to_string(number) : to_string(number);
}

// Function needed to repeat the '*' character
string repeatCharacter(char character, int times) {
    return string(times, character);
}

class Clock {
public:
    Clock() {
        time_t now = time(0);
        localTime = *localtime(&now);
    }

    void displayClocks() const {
        cout << "12-Hour Clock: " << formatTime12() << endl;
        cout << "24-Hour Clock: " << formatTime24() << endl;
    }

    void addHour() {
        localTime.tm_hour = (localTime.tm_hour + 1) % 24;
    }

    void addMinute() {
        localTime.tm_min = (localTime.tm_min + 1) % 60;
    }

    void addSecond() {
        localTime.tm_sec = (localTime.tm_sec + 1) % 60;
    }

private:
    struct tm localTime;

    // Function needed to format time in 12-hour format
    string formatTime12() const {
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%I:%M:%S %p", &localTime);
        return buffer;
    }

    // Function needed to format time in 24-hour format
    string formatTime24() const {
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%H:%M:%S", &localTime);
        return buffer;
    }
};

// Function for displaying the menu
void displayMenu() {
    cout << "Select an option:" << endl;
    cout << "1. Add Hour" << endl;
    cout << "2. Add Minute" << endl;
    cout << "3. Add Second" << endl;
    cout << "4. Exit" << endl;
    cout << "Choice: ";
}

// Function needed to process user input
int processUserInput() {
    int choice;
    cin >> choice;
    return choice;
}

int main() {
    Clock clocks;

    int choice;
    do {
        clocks.displayClocks();
        displayMenu();
        choice = processUserInput();

        switch (choice) {
            case 1:
                clocks.addHour();
                break;
            case 2:
                clocks.addMinute();
                break;
            case 3:
                clocks.addSecond();
                break;
            case 4:
                cout << "Exiting the program now." << endl;
                break;
            default:
                cout << "Invalid choice. Please input correctly and try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
