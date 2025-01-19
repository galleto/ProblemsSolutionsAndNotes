# UVA 230

## What the problem asks us to do

1. Read the books available on the shelves.
2. Read the operations applied to the books.
    - When a book is borrwed and then returned, it is placed into a desk pile of books that will be later put back in the shelves.
    - every time we get the command BORROW we get a title that we'll use to take that book out of the shelve.
    - every time we get the command RETURN we put that book on the desk.
    - every time we get the command SHELVE we return the pile of books mentioned and we need to write a string to stdout the following way: Put "Title1" after "Title2" if there is no book before, we print Put "Title1" first

## Notes to tackle down the problem

- String manipulation
    - string substr method
    - string find method
- Since the `set` data structure in STL C++ has a Red Black Tree (Blanced Binary Search Tree) all the keys that are inserted into the set are going to be sorted.
- If we save a `pair` data structure inside a `set` the set is going to sort the data by the first element in the pair, and in case the first element is equal then it is going to be sorted using the second element, which matches perfectly or constraint to sort it by author and then by title.
