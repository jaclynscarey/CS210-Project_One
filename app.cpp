/*
app.cpp

Author: Jaclyn Carey
Date: July 16, 2023
Class: CS-210-X6054
Description: This program creates a clock object and displays the time in 12-hour and 24-hour format.
*/

#include <iostream>
#include <string>


using namespace std;

// Function to format numbers as two digits
string twoDigitString(unsigned int n) {
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
string formatTime24(unsigned int h, unsigned int m, unsigned int s) {
    return twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s);
}

// Function that outputs time using 12-hour time format
string formatTime12(unsigned int h, unsigned int m, unsigned int s) {
    string ampm = (h >= 12) ? "PM" : "AM";
    h = (h % 12 == 0) ? 12 : h % 12;
    return twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " " + ampm;
}

// Function that prints out the menu illustrated in the project and functional requirements documentation
void printMenu(char * strings[], unsigned int numStrings, unsigned char width) {
    // Print width *'s followed by an endl
    cout << nCharString(width, '*') << endl;

    // Print each menu item
    for (unsigned int i = 0; i < numStrings; i++) {
        // Calculate the number of spaces needed to align the menu item
        int spaces = width - 5 - to_string(i + 1).length() - 3 - strlen(strings[i]) + 1;

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

// Function that processes user input from the menu choices in the user interface
unsigned int getMenuChoice(unsigned int maxChoice) {
    cout << "Enter your choice: ";
    unsigned int choice;
    cin >> choice;
    
    // Validate the input
    while (choice < 1 || choice > maxChoice) {
        cout << "Invalid choice. Please enter a number between 1 and " << maxChoice << ": ";
        cin >> choice;
    }

    return choice;
}

// Function that displays BOTH 12- and 24-hour time formats on the interface at the same time
void displayClocks(unsigned int h, unsigned int m, unsigned int s) {
    // cout 27 stars + 3 spaces + 27 stars + endl
    cout << nCharString(27,'*') << "   " << nCharString(27,'*') << endl;

    // cout 1 star + 6 spaces + 12-HOUR CLOCK + 6 spaces + 1 star + 3 spaces
    cout << "*      12-HOUR CLOCK      *   ";

    // cout 1 star + 6 spaces + 24-HOUR CLOCK + 6 spaces + 1 star + endl
    cout << "*      24-HOUR CLOCK      *" << endl;

    // cout an endl for a blank line
    cout << endl;

    // cout 1 star + 6 spaces + formatTime12(h, m, s) + 7 spaces + 1 star + 3 spaces
    cout << "*      " << formatTime12(h, m, s) << "       *" << "   ";

    // cout 1 star + 8 spaces + formatTime24(h, m, s) + 9 spaces + 1 star + endl
    cout << "*        " << formatTime24(h, m, s) << "         *" << endl;

    // cout 27 stars + 3 spaces + 27 stars + endl
    cout << nCharString(27,'*') << "   " << nCharString(27,'*') << endl;
}

// Function to get seconds and set to setSecond(s)
unsigned int getSecond() {
    cout << "Enter the seconds: ";
    unsigned int seconds;
    cin >> seconds;

    // Validate the input
    while (seconds < 0 || seconds > 59) {
        cout << "Invalid seconds. Please enter a number between 0 and 59: ";
        cin >> seconds;
    }

    return seconds;
}

// function to set seconds (s)
void setSecond(unsigned int s) {

}

// create addOneMinute() - addOneMinute will take care of the hours if necessary

// Function to add a second to your clock’s time
void addOneSecond() {
    int seconds = getSecond();

    // If the second has not reached the limit of 59, add 1 to the seconds variable and move to step 5. ELSE move to step 4.
    if (seconds < 59) {
        seconds++;
    } else {
        // The current second is at the 59 mark, hence reset the seconds variable to 0, and increment the minute count by 1 by calling the addOneMinute function.
        seconds = 0;
        addOneMinute();
    }

    // Update the new seconds count by calling the setSecond function and passing the seconds variable as a parameter.
    setSecond(seconds);
}

// Function to add a minute to your clock’s time
void addOneMinute() {
    // If getMinute() is between 0 and 58 inclusive, add 1 and setMinute() to the new value
    if (getMinute() >= 0 && getMinute() <= 58) {
        setMinute(getMinute() + 1);
    } else {
        // If getMinute() is 59 the minutes must be set to 0 and you must call addOneHour()
        setMinute(0);
        addOneHour();
    }
}

// Function to add an hour to your clock’s time
void addOneHour() {
    // If getHour() is between 0 and 22 inclusive, add 1 and setHour() to that
    if (getHour() >= 0 && getHour() <= 22) {
        setHour(getHour() + 1);
    } else {
        // If getHour() is 23 the next value for hour is 0 so setHour() to that
        setHour(0);
    }
}

// Main function to control the program
/**
 * repeats getting the user's choice and taking the appropriate action until the user chooses 4 for exit
 */
void mainMenu() {
  /** You may assume you have a working getMenuChoice(n), addOneHour(), addOneMinute(), and addOneSecond().
   * The test will hit 1\n2\n2\n3\n3\n3\n4\n, and expect the adding functions to be called the right number of times.
   * getMenuChoice(4) will handle the input and return 1, 2, 3, or 4.
   * Feel free to change things around in your program, but for now get this to work with these function signatures.
   */
  // TODO: Your Code here

  // nothing to return, just call the appropriate methods
}