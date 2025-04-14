# dac
Dynamic Array in C


| Function name  | Args                | Return type | Description                                                                        |
| -------------- | ------------------- | ----------- | ---------------------------------------------------------------------------------- |
| `da_init`      | `const size_t`      | `Da*`       | Initialises the dynamic array with a given capacity                                |
| `da_resize`    | `Da*, const size_t` | `Da*`       | Resizes (or changes) the capacity of the dynamic array to the given capacity       |
| `da_pushback`  | `Da*, int`          | `Da*`       | Adds an "element" at a new (and now highest) index of the dynamic array            |
| `da_pop`       | `Da*`               | `Da*`       | Removes the "element" at the highest index of the dynamic array                    |
| `da_print`     | `Da*`               | `void`      | Prints data inside the dynamic array                                               |
| `da_cleanup`   | `Da*`               | `void`      | Frees memory of both the argument, and the data of the argument                    |


#### Example
```c
#include <stdio.h>
#include "dac.h"

int main(void)
{
    Da* da;
    da = da_init(10); // init dynamic array with capacity of 10

    /* add 5, 10, 15 to the dynamic array */
    da = da_pushback(da, 5);
    da = da_pushback(da, 10);
    da = da_pushback(da, 15);

    da_print(da); // print contents of the dynamic array

    da = da_pop(da); // remove data at the highest index

    printf("\n");

    da_print(da); // print contents of the dynamic array

    da_cleanup(da); // free memory

    return 0;
}
```


Output:
```
0: 5
1: 10
2: 15

0: 5
1: 10
```


Notes:
- https://en.wikipedia.org/wiki/Dynamic_array
- https://cplusplus.com/reference/cstdio/printf/ 
- https://en.cppreference.com/w/c/memory/malloc
- https://www.youtube.com/watch?v=_KSKH8C9Gf0
