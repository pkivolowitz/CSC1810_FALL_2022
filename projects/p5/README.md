# Redactor-Matic

## Helpful Pointers to the Zybook

You should read and do these chapters. Use them as a resource.

| Concept | Chapter |
| ------- | ------- |
| argv / argc | 15.5 |
| cerr | not in book |
| errno / perror | not in book |
| ifstream | 9.1, 9.5 beginning |
| string.c_str | not in book |
| string.find | 5.12 |
| string.length | 5.11, 5.12 |
| string.npos | 5.12 |
| string.push_back | 5.12 |
| string.replace | 5.12 |
| terminal | kinda 15.5 |

## About This Specification

To encourage you to really read this specification closely, various
**REQUIREMENTS** are given as simple text within this document. If you
don't read the spec closely, you won't notice the required stuff and
hence will do poorly with respect to grading.

## Overview

In this project you will create the Redactor-Matic, a tool your favorite
government or other entity can use to automatically redact sensitive
phrases. How topical for these modern times!

The entire project is summarized:

1. Get a file name and target string from the command line.
2. If all arguments not given, print a message and exit.
3. If the argument for file name cannot be opened as a file, print a
message and exit.
4. Read the file, line by line.
5. Replace the target strings as many times as it occurs. **BUT, only if
it appears as a full word.**
6. Close the file.

## Signifying an Error Caused the Exit

At the end of `main()` so far in this course, you have written:

```c++
	return 0;
}
```

It is time to move beyond always returning 0.

*Just like a function can return a value, your programs also return a
value to the program that launched your program.*

Convention says a returned value of 0 means all went well. A return of a
value other than 0 means an error occurred and the program is returning
abnormally.

There are a number of places in this program where you will check for
errors that, if found, should cause your program to terminate. In these
cases, the returned value from your program should be 1.

Also, if you do detect an error, you must print a meaningful error
message.

## Arguments From the Command Line

`main()` is a function, like any other function you will write. In its
full form it takes parameters.

The first is an integer count of the number of command line arguments to
be found vai the second argument.

The second argument is an array of C-strings. C-strings are not C++
strings which have methods attached to them. C-strings are just
null-terminated arrays of `char`s.

```c++
int main(int argc, char * argv[])
```

In this case, it is OK to use the simple `int` types because this is how
`main()` is classically defined.

See Zybooks 15.15.

### A Test File Chock Full Of Text

A file you can use for testing purposes is located [here](./text.txt).

### Running Your Programs With Command Arguments

If you are running your programs from VS Code's "play" button, by
default VS Code doesn't give you access to command line arguments. The
easiest way to get this ability is to use a terminal built into VS Code.
To expose the terminal, press ^j on Windows or ⌘j on Mac.

There may be several tabs in the window that opened up. Click on
"TERMINAL".

## Opening a File For Reading

Recall the following steps:

1. Attempt to open the file.

2. Check to see if the file is really open.

   a. If it isn't open, print informative message and exit.

   b. If it is open:

      1. read from the file.

      2. close the file.

Reading from files requires this include: `<fstream>`.

Declare the file variables as an `ifstream`.

There are two ways to open a file:

```c++
	ifstream fin(filename); // declare and attempt open
```

or

```c++
	ifstream fin;			// declare
	fin.open(filename);		// attempt to open
```

See the beginning of Zybooks 9.5.

## Checking to See If A File Opened

```c++
	fin.is_open()
```

## Printing Error Messages

### Examples of **BAD** Error Messages

First, some **BAD** error messages:

A favorite from Microsoft:

```text
Error: No Error.
```

Thank you for this next message... very informative.

```text
Error 92819700.
```

Or how about this one:

```text
Error: A file didn't open.
```

Really? Which friggen file?

### What Makes a Good Error Message?

A good error message must at least give a clear reason for the error.
For example, if you run this project's program to few arguments (`argc`
is fewer than three) you should get:

```text
Too few command line arguments. Must include filename and target.
```

This error message is a good one because it states the error's cause
("too few arguments") **and** what you can do about it ("the correct
arguments are...").

Your error messages should reveal as much information for the user to
understand what went wrong to the degree they might understand it. For
example, if it's something simple like the wrong number of arguments,
you can be clear about it. For errors that are deeply technical or those
that might reveal some proprietary information then an error like:

```text
An internal error occurred. Please send the following
error message to our technical support department at
help@foobar.com.

Error code: 09001282.
```

This is marginally better than the **BAD** example above. At least it
tells the user how to move forward (contact technical support).

More elaborately, for internal errors you might prepare a full
diagnostic report and even offer to send it automatically (but this is a
lot more advanced).

### `cerr` Rather than `cout`

Command line programs have three standard input and outputs. You are
familiar with two:

* `cin` and
* `cout`

The third is reserved for error messages. It behaves in every respect
like `cout`.

It is called `cerr`.

Again, it is used exactly like `cout`. For example:

```c++
cerr << "Unable to recall doomsday missiles due to" << endl;
cout << "enemy jamming. Unfortunately, tech support" << endl;
cout << "will be unavailable after the coming" << endl;
cout << "apocalypse. Oops." << endl << endl;
cout << "Have a nice day." << endl;
```

**In this project, errors must be printed to `cerr`.**

## `errno` and `perror()`

When an error occurs using a system service (like opening a file), the
"system" sets an error code called `errno`. This integer is declared
outside your program and it "magically appears" available to you. There
are also two "system" supplied functions to deal with `errno`. These
include `perror()` which you are to use in this program if you detect a
bad file name.

For example - given a bad file name:

```text
$ ./a.out missingfile the
missingfile: No such file or directory
```

This is produced simple by doing:

```c++
perror(filename.c_str());
```

where `filename` is a `string`. Notice the `string` method `.c_str()`.
`perror` predates C++ and doesn't know about `string`. `.c_str()`
returns a C style string needed by `perror()`.

---
References for new things used:

| New Thing | Reference |
| ----- | --------- |
| cerr | NOT IN THE BOOK! |
| `getline()` | zybooks 2.14 |
| `string.push_back()` | zybooks 5.12 |
| `string.find()` | zybooks 5.12 |
| `string.replace()` | zybooks 5.12 |
| `string.length()` | zybooks 5.11 |
| `string.npos` | zybooks 5.12 |
| `ifstream` | zybooks 9.5 (beginning) |

## Building the string of asterisks

When you `find()` instances of the target phrase, you must replace them
with a string of asterisks of the same `length()`. You'll need to create
a string with the correct number of asterisks. One straightforward way
to do this is by beginning with an empty string and using `push_back()`
to add one asterisk at a time.

## Finding the target string

Use the `string` method `find()` to locate instances of the target. Note
that there may be more than one instance in the same line. You need to
pay close attention to the value returned by `find()`. Emphasizing that
there may be more than one instance in the same line is a strong hint a
loop is involved. Another strong hint are the words *strong hint* in the
previous sentence.

## The Hardest Part of the Project

You must replace the target string **only where the target appears as a
full word.**

If the data includes this line:

```text
The department of other thematic elements is the best department.
```

and the word to replace is "the", then this is the output.

```text
The department of other thematic elements is *** best department.
```

The first occurrence of "The" is not replaced due to capitalization. The
second occurrence is "other" but the "the" is part of a word. Same for
the third occurrence in "thematic". The fourth occurrence is the only
one replaced.

To solve this part of the project, you must check the character to the
left of the found text and to the right. If EITHER left and right
neighbors are letters, the found text is part of a word.

`.find()` returns the position of the found text or `.npos`. If not
`.npos`, the position corresponds to the index of the first letter of
the found text. This will help you find the left neighbor - but what if
the first position is 0?

You know the length of the target string. You know the position of the
start of the found string. Use these two facts to find the right
neighbor - but what if the found string is at the very end of the line?

Strong hint:  `.find()` takes an optional second argument where `find()`
will start looking.

Strong hint:

```c++
#include <cctype>
```

and `isalpha()`. See Zybooks 5.18.

## Reading the input

Use `getline()` to read from `cin`, placing each read line into a
`string` variable. Since there can be any number of lines to be read,
`getline()` should be part of some loop. Remember it returns a `bool`.

## Partnership rules

You may work with a partner on this program.

Use a technique called [Pair
Programming](https://en.wikipedia.org/wiki/Pair_programming). In Pair
Programming one partner drives, while the other partner navigates.
**This means you are together working together at the same time
together. Together With much TOGETHERNESS!**

## Grading

Your code *must* list your name and your partner's name (if you have a
partner).

## Turning in code

Only one partner turns in the `.cpp` file. The `.cpp` file contains both
partner's names. The other partner turns in a TEXT file listing both
partner's names.

A text file ends in `.txt` and contains just text.

* It is not a photograph.
* It is not a PDF file.
* It is not a WORD file.
* It is not a spreadsheet.
* It is not a web link.

It is a TEXT file.

## Sample Output

```text
% ./a.out text.txt the 
In *** course of my official duties, I have received information from multiple U.S. Government officials that *** President of *** United States is using *** power of his office to solicit interference from a foreign country in *** 2020 U.S. election. This interference includes, among other things, pressuring a foreign country to investigate one of *** President’s main domestic political rivals. The President’s personal lawyer, Mr. Rudolph Giuliani, is a central figure in this effort. Attorney General Barr appears to be involved as well.

Over *** past four months, more than half a dozen U.S. officials have informed me of various facts related to this effort. The information provided herein was relayed to me in *** course of official interagency business. It is routine for U.S. officials with responsibility for a particular regional or functional portfolio to share such information with one another in order to inform policymaking and analysis.

I was not a direct witness to most of *** events described. However, I found my colleagues’ accounts of these events to be credible because, in almost all cases, multiple officials recounted fact patterns that were consistent with one another. In addition, a variety of information consistent with these private accounts has been reported publicly.

I am deeply concerned that *** actions described below constitute “a serious or flagrant problem, abuse, or violation of law or Executive Order” that “does not include differences of opinions concerning public policy matters,” consistent with *** definition of an”urgent concern” in 50 U.S.C. §3033(k)(5)(G). I am therefore fulfilling my duty to report this information, through proper legal channels, to *** relevant authorities.

I am also concerned that these actions pose risks to U.S. national security and undermine *** U.S. Government’s efforts to deter and counter foreign interference in U.S. elections.

To *** best of my knowledge, *** entirety of this statement is unclassified when separated from *** classified enclosure. I have endeavored to apply *** classification standards outlined in Executive Order (EO) 13526 and to separate out information that I know or have reason to believe is classified for national security purposes.
% 
```

## Sample Bad Output

This shows running with no arguments, one argument and a missing file.

```text
% ./a.out
Too few command line arguments. Must include filename and target.
% ./a.out text.txt
Too few command line arguments. Must include filename and target.
% ./a.out foo.foo the
foo.foo: No such file or directory
```

## Other Suggestions

* Use functions to make `main()` simpler to read.

* Make use of nested loops.

* Use comments to help you understand your own code.

* Plan out the program with pencil and paper before you start coding.
