# Introduction to sets

This project is a fairly gentle introduction to the C++ container implementing a *set* functionality. Sets are a dictionary-like data structure which records only whether or not a key has been added to the container. This differs from a *map* which not only records whether or not a key has been added to the container but also some *payload* that corresponds to the key.

## Use of argv and argc

Please configure your projects to use an optional command line argument. **If given**, the command line argument is the name of a file that contains an initial set of input for your testing. Manual input via the ```add``` command should still work.

Repeat: specifying an initial data file is optional on the command line. If `argc` is greater than one, then `argv[1]` should be opened and read for symbols.

### Configuring (setting) a command line argument

We did this in class:
* XCode: modify the "scheme."
* Visual Studio: modify the project settings.

## Sample files

Here are the *small* test files I used during development of this project. You can add to these or make your own.

[an empty file](./empty.txt)

[a file with bad symbols](./bad_symbols.txt)

[a file with good symbols](./small_good_symbols.txt)

You can download these using the right click on the link method in your browser.

## The set container

### Online references:

* [cppreference](http://en.cppreference.com/w/cpp/container/set)
* [cplusplus](http://www.cplusplus.com/reference/set/set/)
* [zybook 14.5](https://learn.zybooks.com/zybook/CARTHAGECSC1120KivolowitzSpring2018/chapter/14/section/5)

### Mini tutorial

You have used one ```Standard Template Library``` container quite a lot: ```vector```.

Now, let's get to know another one: ```set```.

Like ```vector```, you need to include something.

```c++
#include <set>
```

Like ```vector```, you can customize what it holds.

```c++
set<string> flavors;
```

Like ```vector```, you can add to and subtract from a ```set``` as much as you like. 

```c++
flavors.insert("vanilla");
flavors.erase("chocolate");
```

Unlike ```vector``` which **can** use ```iterators```, ```set``` containers **must** be accessed via ```iterators```. ```set``` has no ```.at()``` or ```[]``` syntax.

Unlike ```vector```, ```set``` containers are always sorted on their contents.

Unlike ```vector```, ```set``` containers can hold at most one instance of particular value.

### Iterators

You are accustomed to this:

```c++
	vector<float> f = { 1.0, 2.0, 3.0, 4.0 };
	for (size_t i = 0; i < f.size(); i++)
		cout << f.at(i) << endl;
```

Many containers offer ```iterators``` which for technical reasons can be preferable to direct indexing. For some containers like ```set``` the only way of accessing data in the container is by ```iterator```.

```c++
	for (vector<float>::iterator it = f.begin(); it < f.end(); it++)
		cout << *it << endl;
```

This loop does exactly the same thing as the previous loop. Notice how an ```iterator``` is declared. Two colons and the word ```iterator``` are preceded by the same type as the container.

C++11 adds the keyword `auto` which makes declaring variables like iterators easier. The previous example could have been written like this:

```c++
	for (auto it = f.begin(); it < f.end(); it++)
		cout << *it << endl;
```

```f.begin()``` returns an ```iterator``` for the first float in the vector. 

```f.end()``` returns an ```iterator``` for a place in the vector that is one place beyond its last entry. That's why you see the use of the "less than" operator.

Notice how the value of the ```iterator``` is accessed - using a pointer dereference.

Range-based loops also work with sets:

```c++
for (auto item : f) {
	cout << item << endl;
}
```

## This project

### Overview

You're keeping track of whether or not you've seen certain symbols. The initial symbols *can* come from a file but then the user can add and delete more symbols interactively.

The symbols have to pass some tests to be considered valid. If they're not valid, they can't go into the set.

### Starter code

In this project you can begin with some starter code. 

```c++
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <iomanip>
#include <algorithm>
#include <set>

/* 	Your name
	Your class
*/

using namespace std;

bool ValidateSymbol(string s) {
   // Your code
}

void PrintMenu() {
   // Your code
}

void List(set<string> & m) {
   // Your code
}

bool GetInput(set<string> & m) {
   // Your code
}

void Add(set<string> & s) {
   // Your code
}

void Delete(set<string> & s) {
   // Your code
}

int main()
{
	// Your code
	return 0;
}
```

### ```GetInput```

If you give your program a command line parameter, call this function to read its lines, validate symbols and insert each symbol if it is allowed.

Print an error if the file cannot be opened.

Print the size of the set after reading all the lines.

### ```ValidateSymbol```

This function returns a boolean as to whether or not the symbol should be allowed into the set.

```c++
		size_t p = s.rfind("\n");
		if (p != string::npos)
			s.erase(p);
		p = s.rfind("\r");
		if (p != string::npos)
			s.erase(p);
```

The above code looks for the presence of line feeds and carriage returns and, if found, removes them.

You need to distinguish between letters and numbers. Use ```isalpha```. This function can be found online and also by searching your zybook.

### ```PrintMenu```

This is the expected output of this function.
```
Enter command (quit exits): help
help   - prints this menu
list   - prints symbols
count  - prints number of symbols
add    - ask for symbol to add
delete - ask for symbol to remove
```

Making the text line up is done simply by inserting the right number of spaces - nothing fancy here.

### Operation of remainder of the program

#### Example of being unable to open a file (command line argument)

```text
File: "does_not_exist.txt" could not be opened for reading.
Exiting.
```

#### Example of loading a file from command line argument

In this case, the file with bad symbols is used.

```text
Skipping "1test" because first character is not alphabetic.
Skipping "te st" because of bad character.
Skipping "te$st" because of bad character.
Set size is: 0
Enter command (quit exits, help for list of commands):
```

The ```Skipping``` messages are coming from ```ValidateSymbol```.

### Reading some good symbols then listing the contents of the set

The initial symbols are read from the file given in the command line argument.

```text
Set size is: 3
Enter command (quit exits): list
1....Foo
2....i
3....index_counter
Enter command (quit exits, help for list of commands):
```

### Reading symbols then entering commands manually

The initial data comes from the file specified in the command line argument.

```text
Set size is: 3
Enter command (quit exits): add
Enter symbol: bad symbol
Skipping "bad symbol" because of bad character.
Enter command (quit exits): add
Enter symbol: good_symbol
Symbol added.
Enter command (quit exits): add
Enter symbol: good_symbol
Symbol NOT added.
Enter command (quit exits, help for list of commands):
```

Notice the second time ```good_symbol``` is added, it is rejected because it is already in the set. The ```.insert()``` method returns a templated ```pair```. In this case, the pair's ```second``` field is a boolean that says if the insert actually happened.

Some sample code using our new friend ```auto```:

```c++
	auto r = s.insert(line);
	if (r.second)
		cout << "Symbol added." << endl;
	else
		cout << "Symbol NOT added." << endl;
```

### Using the list and delete command

```text
Enter command (quit exits): list
1....Foo
2....i
3....index_counter
Enter command (quit exits): delete
Enter symbol: Foo
Enter command (quit exits): list
1....i
2....index_counter
Enter command (quit exits): delete
Enter symbol: Foo
Symbol not found.
Enter command (quit exits):
```

## Work rules

This project is to be done solo.

## Remember

Comments (or lack thereof) will be graded.

Any warnings left in the code will result in penalty.
