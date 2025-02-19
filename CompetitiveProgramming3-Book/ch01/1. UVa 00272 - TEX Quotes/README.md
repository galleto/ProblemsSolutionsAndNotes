@ The problem is solved with a simple traversal of the string 
using a boolean variable to alternate between opening and closing quotes.

@ The problem statement (if you check it on UVa Online Judge) 
describes that we need to replace all double quotes " in a text with:

Opening quotes → `` (two backticks)
                                   Closing quotes → '' (two apostrophes)
                                                                        The quotes should alternate, meaning:

@ The first quote found is replaced with (``).
@ The second quote found is replaced with ('').
@ The third quote found is replaced again with (``), and so on.

# To solve this problem efficiently #

@ Use getline(cin, line) to read the input line by line.

@ Traverse each line character by character using a for loop.

@ Use a boolean variable (openQuote) to alternate between opening and closing quotes.
