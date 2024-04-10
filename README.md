This project involves a sorting algorithm with very limited actions, designed to behave like a stack where only the top element can be accessed.

The allowed operations are:

* The top element can be accessed for operations (copy/delete).
* The top element can be switched with the second.
* The top element can be rotated to the bottom of the stack.
* The bottom element can be brought to the top of the stack.

The algorithm that I implemented follows these steps:
1. Check that the array of numbers is not already sorted.
2. Check the size of the array; if it is 3, we can sort it efficiently in a manual way; otherwise, it is sent to the sorting algorithm.
3. Create 2 data structures called "stacks"; in this case, I used doubly linked lists that will contain a number of parameters used for calculations.
   3.1 Stack A will initially contain all the numbers, while stack B will be empty.
   3.2 The initial array is sorted on the side using selection sort, and each number is assigned an index. (This exercise is not about efficiency, but about the number of operations on the stacks).
4. Knowing the size of the array, we can divide it into a few parts, arbitrarily (in my case, 3). This way, the numbers will already be sorted into 3 large groups by index. This reduces the number of operations.
5. The next step consists of calculating for each number the optimal number of operations needed for it to be in its place. We choose the number that requires the least amount of operations and apply the steps to bring it back to stack A.
6. After all the operations are completed, stack A is sorted.
![image](https://github.com/PetruCazac/push_swap/assets/79046351/26f0a9d9-ac12-4a97-af7b-0e5274875eca)
