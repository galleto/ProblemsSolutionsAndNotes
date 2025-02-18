# UVA 10703

[Link to the problem](https://vjudge.net/problem/UVA-10703)

## Notes to tackle down the problem

- If we sum all the areas of all the sub-boards and we substract that sum to the total board area it will not be covering overlaping sub-boards.
- Creating a boolean matrix, where `true` = `empty spot` and `false` = `spot used`
- Iterating over the matrix counting the places where there are `empty spots` or `true`.
