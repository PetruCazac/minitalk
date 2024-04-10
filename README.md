# push_swap

This is a project that involves a sorting algorithm with very limited actions. It is supposed to behave like a stack where only the top element can be accessed. 

The allowed operations: 
* Top element can be accessed for operations (copy/delete)
* Top element can be switched with the second
* Top element can be rotated at the botom of the stack
* Bottom element can be brought at the top of the stack

The algorithm that I implemented: 
1. Check that the array of numbers are not sorted.
2. Check the size of the array, if it is 3, we can sort it in an efficient manual way, else it is sent to the sorting algorithm.
3. Create 2 data structures called "stacks", in this case I used double linked lists that will contain a number of parameters used for calculations.
   3.1  Stack A wil contain initially all the numbers, stack B will be empty.
   3.2  The initial array is sorted on the side using selection sort, and assigning each number an index. (This exercise is not about efficiency, but about number of operations on the stacks).
4. Knowing the size of the array, we can divide in a few parts, arbitrary (in my case 3), this way the numbers will be already sorted in 3 big groups by index. Perform an algorithm to pre-sort the chain of numbers and send them to the stack B. This way we reduce the number of operations. 
5. Next step consists in calculating for each number the optimal number of operations that are to be made for it to be on its place. We choose the number that has the least ammount of operations and apply the steps to bring it back to the stack A. 
6. After all the operations are completed the stack A is sorted. 
