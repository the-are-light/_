
#include <iostream>
#include "locale.h"
#include "date.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "russian");
    // Create Date object
    Date date(2025, 3, 14, 21, 19, 50);  // 5 October 2023 of year, 14:30:45
    int hours, minutes, seconds;
    date.time(hours, minutes, seconds);
    cout << hours << "-" << minutes << "-" << seconds << endl;
    cout << date << endl;
    date.display(); //DD.MM.YYYY
    cout << endl;
    date.displayTime(); // 
    cout << endl;
    cout << date.easter();
    return 0;
}