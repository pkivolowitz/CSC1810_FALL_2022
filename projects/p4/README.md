# File based Mad Libs

In this program you will use:

* files to read data using `ifstream` (zybooks 9.1, for example)
* vectors to hold a number of strings (zybooks 5.2)
* `substr()` (zybooks 5.12)

## Three vectors

Declare three vectors of `string` as *global variables*. A global
variable is a variable declared outside any function. The vectors will
hold, respectively, verbs, subjects and adverbs.

## The data file

You will read a data file to populate vectors holding verbs, subjects
and adverbs.

For example:

```text
sBob
sMary
sShe
sHe
sVoldemort
sGort
veats
vdrinks
vthinks
vsnores
vgroans
vwalks
vlikes
vyells
vbreaks
vbuilds
vbuys
vcoaches
vcolors
vcoughs
vcreates
vcompletes
vcries
vdances
vdescribes
vdraws
venters
vexits
vimitates
aloudly
aquickly
anoisily
aslowly
aquietly
aannoyingly
adoubtfully
adreamily
aeasily
aelegantly
aenergetically
aenormously
aenthusiastically
aequally
aespecially
aevenly
aeventually
aexactly
aexcitedly
afairly
afaithfully
afamously
```

The above list is located [here](./data.txt).

Notice each line begins with an:

* 's' for subjects
* 'v' for verbs
* 'a' for adverbs

As you read each line (using `getline()`), test the first character to
determine to which vector the remainder of the string should be
appended.

You can test the first character of a `string` the same way you can
access the first member of a `vector`. `strings` and `vectors` have a
lot in common.

You can get the first characters of `string s` like so: `s.at(0)` or
`s[0]`. Using the `.at()` syntax is typically preferable. Ask me why.

But... ![danger](./will_robinson.jpeg).

What would happen if there was no "first character" as in an empty
string?

<figure>
  <img src="professor_k_sez.jpg" style="width:60%;">
  <figcaption>Before accessing a thing, make sure the
  thing exists</figcaption>
</figure>

## Opening a file

To read from a file, it must be opened. File operations use *streams*
just like `cin` and `cout`.

Include `fstream` to get access to file streams.

Input file streams can be accessed using variables of type `ifstream`.

An `ifstream` can be opened in one of two ways:

```c++
ifstream fin("nameoffile");
```

or on two lines like:

```c++
ifstream fin;
fin.open("nameoffile");
```

## Ensuring a file stream is open

Stuff happens. Your stream might not actually open. Maybe the file is
missing, for example.

<figure>
  <img src="professor_k_sez.jpg" style="width:60%;">
  <figcaption>NEVER ASSUME A FILE OPEN SUCCEEDED!</figcaption>
</figure>

The above is a corollary of the previous "Professor K Sez": before
accessing (i.e. using) a file, make sure it exists (i.e. it's open).

Example:

```c++
ifstream fin("nameoffile");
if (fin.is_open()) {
	// all is well
	// do stuff
	// then close the file when done
	fin.close();
} else {
	// ERROR!
	// do something.
}
```

## Closing a stream

Use `close()` on the `stream` variable. See above for example. Calling
`.close()` on a `stream` that isn't open shouldn't cause any harm
except to your reputation as a master coder.

## Reading a line at a time

Use `getline()` to read a whole line at a time. `getline()` returns a
boolean value of `true` if all goes well. So the following is common:

```c++
while (getline(cin, s)) {
	// Read a line into string variable s from cin.
}
// There is no more to read.
```

or with an `ifstream` like in this project:

```c++
while (getline(fin, s)) {
	// Read a line into string variable s from cin.
}
// There is no more to read.
fin.close();
```

## Getting the tail of a string

The first letter of each line in the data file tells you which of the
three vectors to add the rest of the string to. Use `substr()` to get
access to the characters beyond a certain position.

`substr()` is found in zybooks 5.12. Note that you are allowed to leave
off the second parameter to `substr()` which means "take the rest of the
string."

Example:

```c++
string s("xJones");
cout << s.at(0) << " " << s.substr(1) << endl;
```

will print:

```text
x Jones
```

## Appending something to a `vector`

Use `push_back()` as described in zybooks 5.7.

Example:

```c++
vector<int> numbers;
numbers.push_back(18);
```

## Getting the size of a `vector`

Use `size()` just like with strings. `string` is kind of like a
`vector<char>`.

The size of the vector is vital in choosing an entry within the vector
at random.

Note that `size()` returns a `size_t` which is an `unsigned`. This can
be a problem when mixing signed and unsigned values.

## Choosing a member of a `vector` at random

Use `rand()` along with the `%` operator to choose an integer at random
which runs from 0 to the length of the vector minus 1.

## Remember to use `srand()` just once

As in:

```c++
#include <ctime>
```

and

```c++
srand((unsigned int) time(nullptr));
```

### A word about `rand()` and `srand()`

These are legacy holdovers from ancient times. C++ offers a new and
better way to generate random numbers as part of the `<random>`
include. These RNGs really do have some benefits to offer but for
now, let's stick with `rand()` and `srand()`.

## Placing the data file

Put the data file in the directory that holds your source code.

## Example output

```text
She eats noisily.
```

## Remember to ensure the file successfully opened

Remember to use `is_open()`. I will specifically look for this in your
code.

## Remember to close the file only if opened

Remember that closing the file is important and only works if the file
is truly open. I will look for this specifically.

## Remember to print an error if the file cannot be opened

Include the name of the file that failed to open. I will look for this
specifically.

## What to turn in

Just the cpp file.

## Work Rules

This work is done solo.
