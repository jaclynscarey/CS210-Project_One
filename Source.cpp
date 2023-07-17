#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int hours;
int minutes;
int seconds;

// Function to set the time
void setTime(int h, int m, int s) {
    hours = h;
    minutes = m;
    seconds = s;
}

// Function to add an hour to your clock’s time
void addOneHour() {
    // If hours is between 0 and 22 inclusive, add 1 and setHour() to that
    if (hours >= 0 && hours <= 22) {
        hours++;
    } else {
        // If hours is 23 the next value for hour is 0 so setHour() to that
        hours = 0;
    }
}

// Function to add a minute to your clock’s time
void addOneMinute() {
    // If minutes is between 0 and 58 inclusive, add 1 and setMinute() to the new value
    if (minutes >= 0 && minutes <= 58) {
        minutes++;
    } else {
        // If minutes is 59 the minutes must be set to 0 and you must call addOneHour()
        minutes = 0;
        addOneHour();
    }
}

// Function to add a second to your clock’s time
void addOneSecond() {
    // If the second has not reached the limit of 59, add 1 to the seconds variable and move to step 5. ELSE move to step 4.
    if (seconds < 59) {
        seconds++;
    } else {
        // The current second is at the 59 mark, hence reset the seconds variable to 0, and increment the minute count by 1 by calling the addOneMinute function.
        seconds = 0;
        addOneMinute();
    }
}

// Function to format numbers as two digits
string twoDigitString(int n) {
    if (n < 10) {
        return "0" + to_string(n);
    } else {
        return to_string(n);
    }
}  

// Function that repeats the ‘*’ to use in formatting your programs output
string nCharString(size_t n, char c) {
    return string(n, c);
}

// Function that outputs time using 24-hour time format
string formatTime24(int h, int m, int s) {
    return twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s);
}

// Function that outputs time using 12-hour time format
string formatTime12(int h, int m, int s) {
    string ampm = (h >= 12) ? "PM" : "AM";
    h = (h % 12 == 0) ? 12 : h % 12;
    return twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " " + ampm;
}

// Function that processes user input from the menu choices in the user interface
int getMenuChoice(int maxChoice) {
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    
    // Validate the input
    while (choice < 1 || choice > maxChoice) {
        cout << "Invalid choice. Please enter a number between 1 and " << maxChoice << ": ";
        cin >> choice;
    }

    return choice;
}

// Function that displays BOTH 12- and 24-hour time formats on the interface at the same time
void displayClocks(int h, int m, int s) {
    // cout 27 stars + 3 spaces + 27 stars + endl
    cout << "\n" << nCharString(27,'*') << "   " << nCharString(27,'*') << endl;

    // cout 1 star + 6 spaces + 12-HOUR CLOCK + 6 spaces + 1 star + 3 spaces
    cout << "*      12-HOUR CLOCK      *   ";

    // cout 1 star + 6 spaces + 24-HOUR CLOCK + 6 spaces + 1 star + endl
    cout << "*      24-HOUR CLOCK      *" << endl;

    // cout an endl for a blank line
    cout << endl;

    // cout 1 star + 6 spaces + formatTime12(h, m, s) + 7 spaces + 1 star + 3 spaces
    cout << "*      " << formatTime12(h, m, s) << "        *" << "   ";

    // cout 1 star + 8 spaces + formatTime24(h, m, s) + 9 spaces + 1 star + endl
    cout << "*        " << formatTime24(h, m, s) << "         *" << endl;

    // cout 27 stars + 3 spaces + 27 stars + endl
    cout << nCharString(27,'*') << "   " << nCharString(27,'*') << "\n" << endl;
}

// Function that prints out the menu illustrated in the project and functional requirements documentation
void printMenu(const vector<string>& strings, int numStrings, char width) {
    // Print width *'s followed by an endl
    cout << nCharString(width, '*') << endl;

    // Print each menu item
    for (int i = 0; i < numStrings; i++) {
        // Calculate the number of spaces needed to align the menu item
        int spaces = width - 5 - to_string(i + 1).length() - 3 - strings[i].length() + 1;

        // Print a line of the menu
        cout << "* " << i + 1 << " - " << strings[i] << nCharString(spaces, ' ') << " *" << endl;

        // Skip a line after each line except the last line
        if (i < numStrings - 1) {
            cout << endl;
        }
    }

    // Print another width *'s followed by an endl
    cout << nCharString(width, '*') << endl;
}

int main() {
    
    // Get user input for initial time
    cout << "\nEnter the initial hour: ";
    cin >> hours;
    cout << "\nEnter the initial minute: ";
    cin >> minutes;
    cout << "\nEnter the initial second: ";
    cin >> seconds;

    setTime(hours, minutes, seconds);
    displayClocks(hours, minutes, seconds);
    
    int width = 26;
    int userChoice;
    const vector<string> menuItems = {"Add one hour", "Add one minute", "Add one second", "Exit Program"};
    
    // Loop
    while (userChoice != 4) {
        // Display menu
        printMenu(menuItems, menuItems.size(), width);
        cout << "\nEnter your choice: ";
        cin >> userChoice;
        switch (userChoice) {
            // If add one hour
            case 1:
                // Add one hour
                addOneHour();
                // Display clocks
                displayClocks(hours, minutes, seconds);
                break;            
            // Else if add one minute
            case 2:
                // Add one minute
                addOneMinute();
                // Display clocks
                displayClocks(hours, minutes, seconds);
                break;
            // Else if add one second
            case 3:
                // Add one second
                addOneSecond();
                // Display clocks
                displayClocks(hours, minutes, seconds);
                break;
            // Else if exit
            default:
                // Exit
                break;
        }
    // End loop
    }

    return 0;
}