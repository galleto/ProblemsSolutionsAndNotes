# Problem 1097B - Petr and a Combination Lock

[Link to the problem](https://codeforces.com/contest/1097/problem/B)

## Notes to tackle down the problem

- You are asked to determine if after all the rotations given the pointer will end in the initial position (0).

### Solving the problem with bitmasks

- `n` = number of rotations
- For every single angle you can go clockwise or counter clockwise, this can be represented as a bitmask of size `n`: `0 - clockwise` and `1 - counter clockwise`.
- Imagine we have two possible rotations (`n` = 2), we must cover each single case:
    - `00`
    - `01`
    - `10`
    - `11`
- To know the total possible combinations we have `2^n` since it grows exponentially as every bit is added (every rotation). Every rotation adds 2 new possibilities.
- We iterate over every rotation and we store the result of the rotations in angles.
- Substract the angle if we have a `1` at ith position (going counter clockwise) or add otherwise (`0` - going clockwise)
