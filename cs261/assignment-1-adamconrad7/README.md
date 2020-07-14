# Assignment 1
**Due at 11:59pm on Monday, 10/14/2018**

**Demo due by 11:59pm on Monday 10/28/2018**

This assignment is intended to get you up and running with some of the tools we'll be using in this course and also to start programming in C.  It should be very straightforward.  It has a few parts, described below.

## 1. Sign up for Piazza

Use this link to sign up for CS 261 on Piazza using your ONID email address: https://piazza.com/oregonstate/fall2019/cs261

We'll be using Piazza in this course for Q&A because it's geared towards students helping other students with the class.  Anyone can post or answer a question on Piazza, even anonymously, and the instructor and TAs can revise and endorse student answers, which means you can be confident in the quality of the response.

You are *strongly encouraged* to post any class-related querstions to Piazza first instead of emailing the instructor or TAs.  You should also get in the habit of checking in to Piazza to answer other students' questions.  This will not only enable everyone to get help quickly, but it will also help you improve your understanding of the material, since teaching someone else is the best way to learn something.

As an incentive to use Piazza, extra credit will be awarded to the most active Piazza participants at the end of the term.

## 2. Familiarize yourself with Git and GitHub

The other set of tools we'll be using quite a bit for this course is Git and GitHub.  You're already here looking at this assignment, so we know you've got at least some Git/GitHub skills.  However, if you're new to Git and GitHub, take a few minutes to follow these two tutorials:
  * Git: https://try.github.io/
  * GitHub: https://guides.github.com/activities/hello-world/

We'll be using Git and GitHub heavily in this course, so it'll pay off to put in the time now to learn how to use them.

Once you feel somewhat comfortable with Git and GitHub, clone this assignment repository from GitHub onto your development machine.

## 3. Implement a dynamic array

In our assignments this term, we'll be building up a library of data structure implementations in C.  The first data structure we'll implement is a [dynamic array](https://en.wikipedia.org/wiki/Dynamic_array).  We'll then be able to use this dynamic array implementation as a building block for many of the other data structures we'll explore in this course.

As we'll explore in lecture, a dynamic array is simply an array that automatically grows to meet the demand for capacity as new elements are added.  Specifically, a dynamic array is a structure that simply manages a regular array, and, whenever a new element is inserted into the dynamic array, it checks to see whether the underlying array has enough space to hold the new element.  If it does, the dynamic array simply inserts the new element.  If there isn't enough space, however, the dynamic array increases the size of the underlying array (typically doubling it in size), so that there's room for the new element.  If you've used a vector from the C++ STL, then you've used a dynamic array, since that's what a C++ vector is.

For this assignment, the interface for the dynamic array (i.e. the structures and the prototypes of functions a user of the dynamic array interacts with) is already defined for you in the file `dynarray.h`.  Your first task in this assignment is to implement definitions for the functions that comprise this interface in `dynarray.c`.

**Importantly, you may not modify the interface definition with which you are provided.**  Specifically, do not modify any of the already-defined dynamic array function prototypes.  We will use a set of unit tests to test your implementation, and if you change the dynamic array interface, it will break these unit tests, thereby (negatively) affecting your grade.  Beyond the already-defined interface, though, feel free to add any additional functions or structures your dynamic array implementation needs.  For example, you might want to add a new function to resize the array when needed.  This would be fine.

The dynamic array functions you'll need to implement are outlined briefly below.  All of these functions use a type called `struct dynarray`, which is defined in `dynarray.c` and represents the dynamic array itself.  For more details, including information on function parameters and expected return values, see the documentation provided in `dynarray.c`.

  * **`dynarray_create()`** - This function should allocate, initialize, and return a pointer to a new dynamic array structure.

  * **`dynarray_free()`** - This function should free the memory held within a dynamic array structure created by `dynarray_create()`.  Note that this function only needs to free the `data` array itself.  It does not need to free the individual elements held within that array.  This is the responsibility of the calling function.

  * **`dynarray_size()`** - This function should return the number of elements stored in a dynamic array (*not* the capacity of the array).

  * **`dynarray_insert()`** - This function should insert a new element *at the end* of a dynamic array.  In other words, if the array currently contains `n` elements (in indices `0` through `n-1`), then the new element (the `n+1`'th element) should always be inserted at index `n`.  Also, see the information below on storing elements as `void*`.  If there is not enough space in the dynamic array to store the element being inserted, this function should double the size of the array.

  * **`dynarray_remove()`** - This function should remove the element at a specified index from a dynamic array.  After the element is removed, there will be a "hole" where the element used to be.  All elements after the removed one (i.e. with higher indices) should be moved forward one spot to fill that hole.  In other words, if the element at index `i` is removed, then the element at index `i+1` should be moved forward to index i, the element at index `i+2` should be moved forward to index `i+1`, the element at index `i+3` should be moved forward to index `i+2`, and so forth.

  * **`dynarray_get()`** - This function should return the element value stored at a specified index in a dynamic array.  Again, see the info below on using `void*` values.

  * **`dynarray_set()`** - This function should update (i.e. overwrite) the value of an element at a specified index in a dynamic array.  Again, see the info below on using `void*` values.

## 4. Implement a singly-linked list

The second data structure you'll implement, and also one that we'll also be able to use as a building block for many of the other data structures we'll implement this term, is the [linked list](https://en.wikipedia.org/wiki/Linked_list).  Specifically, you'll implement a singly-linked list.

In general, a linked list is a data structure in which each data element is stored in its own *link* structure.  A linked list is a linear data structure, like an array, where the elements are stored in sequence.  Each link in a lined list holds exactly one data element and is allocated only when needed (i.e. when the data element it contains is inserted into the list).  In addition, each link in a linked list points to either one or two adjacent links in the list.  A singly-linked list, which you'll implement here, is a list where each link points only to the next link in the list.

Again, the interface for the linked list (i.e. the structures and the prototypes of functions a user of the linked list interacts with) is already defined for you in the file `list.h`.  Your next task in this assignment is to implement definitions for the functions that comprise this interface in `list.c`.

**Again, do not modify the interface definition with which you are provided.**  This will break the unit tests we use for testing, which will cause your grade to suffer.  You may still feel free to implement any additional functions you need beyond the ones defined in the interface.

The linked list functions you'll need to implement are outlined briefly below.  The functions here will make use of two different structures:
  * **`struct link`** - This structure represents a single link in the linked list.  It has one field in which to store the data element associated with the link and one field that will point to the next link in the list.
  * **`struct list`** - This structure represents an entire list and contains a single field to represent the head of the list.  This is the structure with which the user of your list implementation will interact.
As with the dynamic array, see `list.c`  information on function parameters, expected return values, etc. for the linked list interface.

  * **`list_create()`** - This function should allocate, initialize, and return a pointer to a new linked list structure.

  * **`list_free()`** - This function should free the memory held within a linked list structure created by `list_create()`, including any memory allocated to the individual links themselves.  Note, though, that this function should not free the *values* held in the individual links.  That is the responsibility of the calling function.

  * **`list_insert()`** - This function should insert a new value *at the beginning* (i.e. as the head) of a linked list.  Importantly, this function will need to allocate a new `struct link` in which to store the new value and add that link at the head of the list.  The current head should become the next element after the new one.

  * **`list_remove()`** - This function should remove the *first instance* of a specified value from a linked list.  If multiple instances of the specified value exist in the list, only the first (i.e. the one closest to the head) should be removed.  If the specified value doesn't exist in the list, this function doesn't need to do anything.  This function will be passed a *function pointer* that you can use to determine whether the value to be removed matches any of the values stored in the list.  See the information below on function pointers for more about how they work.  Importantly, this function will also need to free the memory held by the link being removed (it does not need to free the stored value itself, just the link).

  * **`list_position()`** - This function should return the list position (i.e. the 0-based "index") of the first instance of a specified value within a linked list.  If multiple instances of the specified value exist in the list, the "index" of the first one (i.e. the one closest to the head) should be returned.  If no instances of the specified value exist in the list, this function should return the special value -1.  This function will be passed a *function pointer* that you can use to determine whether the value to be located matches any of the values stored in the list.  Again, see the information below on function pointers for more about how they work.

  * **`list_reverse()`** - This function should reverse a linked list *in place*, that is within the memory of the existing list, without allocating new memory.

## A note on using void pointers

The data structure implementations you'll write in this assignment use void pointers (i.e. `void*`) to store data.  You may not be familiar with the way void pointers work.  Simply put, void pointers are a mechanism that can be used to store *any* pointer type.  In other words, you can think of a void pointer as a generic pointer, capable of pointing to values of any type.  They are often used in C/C++ data structure implementations to allow those data structures to store data of many different types without needing to change the underlying source code of the data structure for each type.

Working with void pointers means you, the data structure implementor, don't have to worry about the *content* that's being stored in your data structures.  The structures themselves are agnostic to the content.  When outside functions call operations on your data structures, they will pass in values of *some* pointer type.  It is up to those calling functions to remember the type of data being stored in your data structures and to handle it accordingly.  In other words, when a calling function inserts data into your data structures, it will arrive as a `void*`, and your function can just take that `void*` and put it in the right place without doing anything additional to it.  Similarly, when one of your data structures returns a stored value to a calling function, it can simply return the `void*` it stored earlier without doing any additional casting, etc.

## A note on function pointers

Often, particular operations for a given data structure will need to be able to make *comparisons* involving the stored values they hold.  This can be challenging when the data structure doesn't know what *type* of values it's holding, as is the case here, where our data structures are storing `void*` values without additional type information.  It is common in these situations, where a data structure must compare values stored as `void*`, for the data structure to require the calling function itself to provide a mechanism for performing these comparisons.  In C code, this is typically done by requiring the calling function to pass the data structure *a pointer to a function* that can compare the values stored in the data structure.  This is known as a function pointer.

In this assignment, some of the linked list functions must be passed function pointers to be used when comparing values to determine what elements exist within the list.  When a pointer to a function is passed to another function, it must match a pre-specified function prototype.  The prototype required by the function pointers specified in those linked list functions looks like this:
```C
int cmp(void* a, void* b);
```
In other words, the function pointer must point to a function that returns an `int` and accepts exactly two `void*` arguments.  In this case, the function will return 0 if the argument `a` should be considered as equal to the argument `b`, and it will return a non-zero value otherwise.

It is important to note that, again, the linked list functions here can be agnostic to what the functions specified by these pointers are actually doing.  They just need to call the function at the right time, passing the right parameters and doing the right thing with the return value.  For example, within the `list_remove()` function, you'll want to use the provided function pointer to perform comparisons between the value to be removed and the values stored in the list.  In particular, if the value to be removed is stored in `val` and you're currently comparing to the value stored in a link called `link`, you can use the comparison function specified by the function pointer `cmp` like this:
```C
cmp(val, link->val)
```
This will return 0 if `val` and `link->val` are equal and a non-zero value otherwise.

It will be instructive here to look in `test.c` to see how functions are actually passed as pointers into `list_remove()` and `list_position()`.  You can also refer to these tutorials for more in function pointers in general:
  * https://www.cprogramming.com/tutorial/function-pointers.html
  * https://www.learn-c.org/en/Function_Pointers

## Testing your work

In addition to the skeleton code provided here, you are also provided with some application code in `test_dynarray.c` and `test_list.c` to help verify that your dynamic array and linked list implementations, respectively, are behaving the way you want them to.  In particular, the testing code calls the functions from `dynarray.c` and `list.c`, passing them appropriate arguments, and then prints the results.  You can use the provided `Makefile` to compile all of the code in the project together, and then you can run the testing code as follows:
```
make
./test_dynarray
./test_list
```
Example output of these two testing programs using correct implementations of the dynamic array and linked list is provided in the `example_output/` directory.

In order to verify that your memory freeing functions work correctly, it will be helpful to run the testing application through `valgrind`.

## Submission

We'll be using GitHub Classroom for this assignment, and you will submit your assignment via GitHub. Just make sure your completed files are committed and pushed by the assignment's deadline to the master branch of the GitHub repo that was created for you by GitHub Classroom. A good way to check whether your files are safely submitted is to look at the master branch of your assignment repo on the github.com website (i.e. https://github.com/osu-cs261-f19/assignment-1-YourGitHubUsername/). If your changes show up there, you can consider your files submitted.

## Grading criteria

Your program **MUST** compile and run on `flip.engr.oregonstate.edu`, so make sure you have tested your work there before you make your final submission, since a program that compiles and runs in one environment may not compile and run in another.  **Assignments that do not compile on `flip` will receive a grade of 0.**  If you do not have an ENGR account, you can create one at https://teach.engr.oregonstate.edu/.

The assignment is worth 100 total points, broken down as follows:

  * 20 points: Signed up for Piazza

  * 40 points: Correct dynamic array implementation
    * 5 points: `dynarray_create()` correctly allocates and initializes a dynamic array
    * 5 points: `dynarray_free()` correctly frees the memory allocated to a dynamic array
    * 5 points: `dynarray_size()` returns the correct size of a dynamic array
    * 10 points: `dynarray_insert()` correctly inserts a value into a dynamic array, resizing the array when appropriate
    * 5 points: `dynarray_remove()` correctly removes a value from a dynamic array
    * 5 points: `dynarray_get()` correctly returns a value from a dynamic array
    * 5 points: `dynarray_set()` correctly updates a value in a dynamic array

  * 40 points: Correct linked list implementation
    * 5 points: `list_create()` correctly allocates and initializes a linked list
    * 5 points: `list_free()` correctly frees the memory allocated to a linked list
    * 5 points: `list_insert()` correctly inserts a value into a linked list
    * 10 points: `list_remove()` correctly removes a value from a linked list
    * 5 points: `list_position()` correctly returns the position of an element in a linked list
    * 10 points: `list_reverse()` correctly reverses the order of the links in a linked list
