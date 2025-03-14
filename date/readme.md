## Date - module for work with date&time;

To work with my module, write this:
```cpp
#include "date.h"
```

**Create object:**

To create a Date object, there is a constructor:
```cpp
Date date(); // default value = 0
Date date(int year, int month, int day);
Date date(int jd_data); // for julian date
Date(int year, int month, int day, int hour, int minute, int second) // datetime
```

**Functions:**
- get weekday
```cpp
Date date(2025, 2, 14);
date.weekday();
  ``` 
- get day
```cpp
Date date(2025, 2, 14);
date.day();
```
- get month
```cpp
Date date(2025, 2, 14);
date.month();
  ``` 
- get year
```cpp
Date date(2025, 2, 14);
date.year();
```
- is the year a leap year?
```cpp
Date date(2025, 2, 14);
date.isLeap();
  ``` 
- calculate julian day
```cpp
Date date(2025, 2, 14);
date.jdn();
```
- get time
```cpp
Date date(2025, 2, 14, 21, 43, 45);
int h, m, s;
date.time(h, m, s);
```
- calculating the difference between dates (in days)
```cpp
Date date(2025, 2, 14);
Date date2(2025, 2, 10);
std::cout << date - date2; // 4
```
- calculating the date of Easter
```cpp
Date date(2025, 2, 14);
std::cout << date.easter();
```

- displayTime
```cpp
Date date(2025, 2, 14);
date.jdn();
```

**Output:**
```cpp
Date date(2025, 2, 14);
std::cout << date; // DD-MM-YYYY
```
- Output with time
```cpp
Date date(2025, 2, 14, 21, 43, 45);
date.displayTime(); // 2025-2-14T9:43:45
```
- Other output
```cpp
Date date(2025, 3, 14);
date.display() // 14.03.2025
```

### Example:

```cpp

#include <iostream>
#include "date.h"
using namespace std;

int main() {
    Date date(2025, 3, 14, 21, 19, 50);  // 5 October 2023 of year, 14:30:45
    int hours, minutes, seconds;
    date.time(hours, minutes, seconds);
    cout << date << endl;
    date.display(); //output format: DD.MM.YYYY
    cout << endl;
    date.displayTime(); // output format: YYYY-MM-DDTHH:MM:SS
    cout << endl;
    cout << date.easter(); // calculate the date of Easter
    return 0;
}
```
### Output:
```output
14-03-2025
14.03.2025
2025-03-14T09:19:50
20-04-2025
  ``` 
