## Line - alternative vector;

TO work with my array, write this:
```cpp
#include "line.h"
```

**Create object:**

To create a Line object, there is a constructor with the initial value capacity = 10;

To create an object with its own capacity value, write:
```cpp
Line line(10)
```

**Functions:**
- insert element in the array
```cpp
  insert(int elem)
  ``` 
- insert element in the array with index
```cpp
insert(int elem, int index)
```
- delete element in the array
```cpp
remove(int index)
```
- get size of the array
```cpp
getSize()
```
