# Assignment 3
**Due at 11:59pm on Monday, 11/11/2019**

**Demo due by 11:59pm on Monday 11/25/2019**

This assignment is intended to have you start to explore non-linear data structures by implementing a binary search tree (BST).  The requirements for the assignment are described below.

For this assignment, you are provided with some starter code that defines the structures you'll be working with and prototypes the functions you'll be writing and also provides some data structures upon which to build a BST implementation.  It's important that you don't modify the function prototypes specified in `bst.h`. To help grade your assignment, we will use a set of tests that assume these functions exist and have the same prototypes that are defined in those files. If you change the prototypes, it will cause the tests to break, and your grade for the assignment will likely suffer.

Feel free to add any additional functions you might need to `bst.c`.

## Implement a binary search tree

Your main task for this assignment is to implement a [binary search tree](https://en.wikipedia.org/wiki/Binary_search_tree) (BST).  A BST is a tree-structured data type that allows fast insertions, lookups, and removals by structuring itself in a way that encodes the behavior of binary search.  Specifically, each node in a BST has at most two children, a left child and a right child, and every node satisfies the BST property, which requires that all values stored in a node's left subtree must be less than that node's value, while all values stored in a node's right subtree must be greater than or equal to that node's value.

For this assignment, the interface for the BST you'll implement (i.e. the structures and the prototypes of functions a user of the BST interacts with) is already defined for you in the file `bst.h`.  Your first task in this assignment is to implement definitions for the functions that comprise this interface in `bst.c`.

**Note that you may not modify the interface definition with which you are provided.**  Specifically, do not modify any of the already-defined BST function prototypes.  We will use a set of tests to verify your implementation, and if you change the BST interface, it will break these tests, thereby (negatively) affecting your grade.  You may also not modify any of the existing structures defined in the starter code (i.e. `struct bst` and `struct bst_node`).  Beyond these things, though, feel free to add any additional functions or structures your BST implementation needs.

The BST functions you'll need to implement are outlined briefly below.  All of these functions use a type called `struct bst`, which is defined in `bst.c` and represents the BST itself.  For more details, including information on function parameters and expected return values, see the documentation provided in `bst.c`.

  * **`bst_create()`** - This function should allocate, initialize, and return a pointer to a new BST structure.

  * **`bst_free()`** - This function should free the memory held within a BST structure created by `bst_create()`.  Note that this function only needs to free the memory held by the BST itself.  It does not need to free the individual elements stored in the BST.  This is the responsibility of the calling function.

  * **`bst_size()`** - This function should return the total number of elements stored in a given BST.  Importantly, because you can't modify the fields of `struct bst` or `struct bst_node`, you'll have to calculate a BST's size each time this function is called.  *It could be helpful to think recursively here.*  Feel free to write any helper functions you need to make this work.

  * **`bst_insert()`** - This function should insert a new key/value pair into a given BST.  The BST should be ordered based on the specified key value.  In other words, your BST must always maintain the BST property among all keys stored in the tree.

  * **`bst_remove()`** - This function should remove the value with a specified key from a given BST.  If multiple values are stored in the tree with the same key, the first one encountered (i.e. the one closest to the root of the tree) should be removed.

  * **`bst_get()`** - This function should return the value associated with a specified key in a given BST.  If multiple values are stored in the tree with the same key, the first one encountered (i.e. the one closest to the root of the tree) should be returned.

## Storing key/value pairs

It is important to note that each data element stored in your BST will actually consist of two parts: a key and a value.  Under this scheme, the key will serve as a unique identifier for the data element, while the value will represent the rest of the data associated with that element.  For example, if you were storing information about OSU students in your BST, the key for each student element might be that student's OSU ID number, while the corresponding value might be a struct containing all other data related to that student (e.g. name, email address, GPA, etc.).  Storing data as key/value pairs is a common approach that we'll see in other data structures we explore in this course.

For your BST implementation, each data element's key will be represented as an integer value, while the associated value will be a void pointer.  This is reflected in the structure you must use to represent a single node in your BST:
```C
struct bst_node {
  int key;
  void* value;
  struct bst_node* left;
  struct bst_node* right;
};
```

Your BST should be organized *based on the keys* of the elements.  In other words, the BST property must always hold among all *keys* in the tree.  For example, when a new data element is inserted into your BST, decisions about whether to insert that element within a node's left subtree or its right subtree should be based on comparisons between the key of the element being inserted and the keys stored in the tree.  Similarly, when a user wants to lookup or remove data elements stored in your BST, they will do so by specifying the key to be found/removed.

## Testing your work

In addition to the skeleton code provided here, you are also provided with some application code in `test_bst.c` to help verify that your BST implementation, is behaving the way you want it to.  In particular, the testing code calls the functions from `bst.c`, passing them appropriate arguments, and then prints the results.  You can use the provided `Makefile` to compile all of the code in the project together, and then you can run the testing code as follows:
```
make
./test_bst
```
Example output of the testing program using a correct BST implementation is provided in the `example_output/` directory.

In order to verify that your memory freeing functions work correctly, it will be helpful to run the testing application through `valgrind`.

## Submission

As always, we'll be using GitHub Classroom for this assignment, and you will submit your assignment via GitHub. Just make sure your completed files are committed and pushed by the assignment's deadline to the master branch of the GitHub repo that was created for you by GitHub Classroom for this assignment. A good way to check whether your files are safely submitted is to look at the master branch of your assignment repo on the github.com website (i.e. https://github.com/osu-cs261-f19/assignment-3-YourGitHubUsername/). If your changes show up there, you can consider your files submitted.

## Grading criteria

Your program **MUST** compile and run on `flip.engr.oregonstate.edu`, so make sure you have tested your work there before you make your final submission, since a program that compiles and runs in one environment may not compile and run in another.  **Assignments that do not compile on `flip` will receive a grade of 0.**  If you do not have an ENGR account, you can create one at https://teach.engr.oregonstate.edu/.

The assignment is worth 100 total points, broken down as follows:

  * 10 points: `bst_create()` correctly allocates and initializes a BST
  * 10 points: `bst_free()` correctly frees the memory allocated to a BST with no memory leaks
  * 15 points: `bst_size()` correctly determines the number of elements in a BST
  * 25 points: `bst_insert()` correctly inserts a key/value pair into a BST, maintaining the BST property with respect to all keys in the tree
  * 25 points: `bst_remove()` correctly removes a key/value pair from a BST based on a specified key, maintaining the BST property with respect to all keys in the tree
  * 15 points: `bst_get()` correctly retrieves the value associated with a given key in a BST
