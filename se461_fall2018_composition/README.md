# SE 461 – Fall 2018
## Assignment #2- System Composition
### Due: 9/28/2018
In the first assignment you were introduced to some of the various features of the C++ programming
language (possibly learning what you did and didn’t really know about the language) as you created an
ADT: an Array. In this assignment you will build upon that knowledge gained and use the Array you
created to create three additional ADT’s:<br/>

   1. **__Stack:__** An ADT that contains a list of elements such that the list has last-in, first-out (LIFO)
semantics, i.e., elements are inserted into the front of the list and removed from the front of the
list.
   1. **__Queue:__** An ADT that contains a list of elements such that the list has first-in, first-out (FIFO)
semantics, i.e., elements are inserted into the front the list and removed from the front of the list.
   1. **__Fixed Array:__** An ADT that is an array, but cannot grow or shrink.<br/>

In addition, you will implement each of the ADTs listed above using **__C++ templates__**. This will allow
each ADT to work with arbitrary data types. When you download the assignment files (see below), you
will notice that there are no shell or skeleton files provided for Queue. This is because it is your job to
define and implement the Queue class in C++. <br/>

When defining the Queue, please make sure you follow the design in the figure below, and implement the
default constructor, copy constructor, destructor, and assignment operator although they are not
highlighted in the figure:<br/>

More specifically, you must implement each method in the above figure using the following specification:<br/>
   1. **__enqueue:__** Adds the element to the end of the list.
   1. **__dequeue:__** Removes the element at the front of the list. If there are not elements in the queue, this
method throws empty_exception, similar to the stack.
   1. **__is_empty:__** Test if the queue is empty. If the queue is empty, then this method returns true. Otherwise, this method returns false.
   1. **__size:__** Returns the number of elements in the queue.
   1. **__clear:__** Removes all the elements in the queue.<br/>

**Exception Handling:** Your ADTs are expected to offer **__basic exception safety__**.<br/>
**Note:** The same rules apply to use of the std library or any other libraries from assignment one.<br/>

#### Assignment Files:
The files for the assignment can downloaded from Moodle.
#### Development Process:
For this assignment, all development must take place on the **__master branch__**. It is strongly recommended
that you commit and push often!
#### Submission:
All assignments must be submitted on IU GitHub (github.butler.edu). The name of your Butler GitHub
repository must be as follows: **__se461_fall2018_composition__**.
You should submit all source, project (MPC), and Valgrind files.
Any additional files and directories can be added to the GitHub repository – for instance you will need a
driver.cpp file (**Note:** Please include this name in your MPC file for compilation purposes.) for testing
purposes, but they will not be reviewed or graded. Make sure the filenames have the correct
capitalization. Failure to do so can result in our automated system not compiling and testing your code.
You don’t want to receive a 0 on the assignment for an incorrect filename!