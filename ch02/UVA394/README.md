# UVA 394

[Link to the problem](https://vjudge.net/problem/UVA-394)

## Notes to tackle down the problem

- Pre compute all the constants and store them in a one dimension array.
    - Store the bounds of each dimension in an array of pairs
    - CD it's equal to the element size
    - calculate every constant from CD to C1
    - calculate C0 by using the base address and the constants calculated before.
- Store the array with the constants in a map with the name of the array as the key and the array as the value.
- Query the array by the name using the map created before. This would take O(log N) since the map has a black red tree behind its implementation.
