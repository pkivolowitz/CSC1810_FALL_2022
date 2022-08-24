# Class / Struct Methods

Yay! You get to work with a partner again on this project!
You may work as a team of
at most two. At most one team member turns in code. Code files must have
the names of all team members in them at the top of the file containing
`main()`. Team members who are not submitting code must submit a **text
file** containing the names of the team members. Failure to comply with
this requirement (re: names) will result in point deductions.

One more word about partners: If your partner didn't work out on Project
5, don't use them again.

In this project you will write a program that simulates *any* number of
bingo cards (where the number is at least one) being played at the same
time.

## Determining how many cards to simulate

Your program will be told how many randomly generated cards to
simulate via the command line.

If no command line argument is given, then assume a default of 1 card.

If a bad number of cards is specified (i.e. less than 1), you must
print an error message to `cerr` and cause the program to return 1.

## Precise integers must be used

`int32_t` must be used instead of `int`.

## Required constants

```c++
const int32_t BALLS_PER_LETTER = 15;
const int32_t DIMENSION = 5;
const int32_t FREE_COORD = 2;
const int32_t FREE_VALUE = -1;
const int32_t NUM_BALLS = 75;
```

`BALLS_PER_LETTER` specifies that there are 15 possible numbers for
each BINGO letter.

`DIMENSION` specifies that a Bingo card is 5 x 5 in size.

`FREE_COORD` specifies that the cell at [2][2] is the "free" cell.

`FREE_VALUE` is the value assigned to the middle "free" cell on each
Bingo card. All other cells will have numbers from 0 to NUM_BALLS - 1
in them.

`NUM_BALLS` specifies there are 75 balls in the game.

## Plurals

You will note in the output of the game described at the bottom of this
document certain words that correctly sense whether or not they are to
be pluralized. You must do this.

You must write:

```c++
string Pluralizer(int32_t n)
```

which will return an "s" or an empty string.

## Shuffling

Everything that must be shuffled should be stored in `vector`s. You
must write the following global function:

```c++
void ShuffleVector(vector<int32_t> & v)
```

Do not attempt to use the shuffle functions found in `algorithm`.

## Classes / Structs

All the class / struct specifications given below are required.

None of these have constructors as constructors are left to
CSC 1820. Instead, where needed, the objects have a method called
`Initialize()` which must be called in order to properly set up the
object.

### Balls

```c++
struct Balls {
	void Initialize(int32_t num_balls = NUM_BALLS);
	int32_t CallBall();
	static std::string Format(int32_t bn);

private:
	std::vector<int32_t> balls;
	int32_t next_index;
};
```

A single ball is represented as an `int32_t` found in a `vector`.
The `vector` is private to the `Balls` object. `CallBall()` returns
the next ball to be called, managed internally by `next_index`. The
`vector` must be shuffled.

`Format()` is a `static` function - this means it is not part of any
specific instance of a `Balls` object. Given a ball number (zero-based)
it will return a letter followed by a ball number (1-based).

For example:

```text
Balls::Format(0)
```

returns the string "B1".

and

```text
Balls::Format(74)
```

returns the string "O75".

*The above code snippets are for example purposes only and are
exceptions to the reminder given at the very bottom of this document.*

There is one special case - the parameter being passed is FREE_VALUE.
You must detect this and return "FREE".

Use the `Balls::Format()` method when you need to turn ball numbers
into Bingo ball names.

### Cell

```c++
struct Cell {
	int32_t value;
	bool is_called;
	std::string Format();
	void Initialize(int32_t v, bool ic = false);
};
```

A Bingo `Board` is comprised of `DIMENSION` by `DIMENSION` instances
of `Cell`. Every `Cell` must be correctly `Initialize()`d. Notice that
`Initialize()` has a default value for its second parameter.

The `Format()` method in `Cell` is **not** static. It will return a
string containing the (1-based) name of the zero-based `value` of the
`Cell`. In addition to the string created by `Balls::Format()`, this
method will add `*` if the `Cell` has been called.

### Board

```c++
struct Board {
	Cell cells[DIMENSION][DIMENSION];
	void Initialize();
	bool HasWinner(string &win_string);
	int32_t ApplyBall(int32_t bn);
	void Print();
private:
	bool CheckRows(string &win_string);
	bool CheckColumns(string &win_string);
	bool CheckDiagonals(string &win_string);
};
```

An instance of `Board` represents one Bingo card.

`HasWinner()` is built from `CheckRows()`, `CheckColumns()` and
`CheckDiagonals()`. Each of these checks the indicated type of win and,
if found, will return `true` and set `win_string` to one of:

* "in a Row"

* "in a Column"

* "on a Diagonal"

`ApplyBall()` takes the zero-based ball number just called. It checks
the board for a `Cell` that contains this value. If the board contains
a matching `Cell`, the method will return a 1. Otherwise it will return
a 0. Any other value is an error.

`Initialize()` ensures every `Cell` has been properly initialized.

`Print()` prints the results of the `Board` like so (for example):

```text
B2    I29   N33   G47   O61   
B14*  I28*  N43*  G55*  O69*  
B10   I22*  FREE  G52   O60*  
B3    I26   N32*  G49*  O67   
B13   I16   N40   G57*  O70*  
```

Notice, this board is a winner along the second row.

### Boards

```text
struct Boards {
	std::vector<Board> boards;
	void Initialize(int32_t n_boards);
	bool HasWinner();
	int32_t ApplyBall(int32_t bn);
};
```

`Boards` is the object that will manage any and all `Board` instances.

`Initialize()` ensures that all `Board`s are initialized.

`HasWinner()` checks all `Board`s and returns `true` if *any* board
contains a winner. A part of winding up the game, once a winner has
been found, is to interrogate every board individually to see if
*IT* has a winner and if so, what kind of winner. Again,
`Boards::HasWinner()` returns only a `bool` and not also a `string`.

## Example of play

### Bad number of boards

```text
./a.out -1
Number of cards must be at least 1
```

### One board

```text
 ./a.out
Bingo played on 1 board
Calling ball number: 1 Value: I25 Found on: 1 board
Calling ball number: 2 Value: I21 Found on: 1 board
Calling ball number: 3 Value: I17 Found on: 0 boards
Calling ball number: 4 Value: B5 Found on: 1 board
Calling ball number: 5 Value: B6 Found on: 0 boards
Calling ball number: 6 Value: I30 Found on: 0 boards
Calling ball number: 7 Value: O61 Found on: 0 boards
Calling ball number: 8 Value: N44 Found on: 1 board
Calling ball number: 9 Value: B8 Found on: 0 boards
Calling ball number: 10 Value: N37 Found on: 0 boards
Calling ball number: 11 Value: O65 Found on: 0 boards
Calling ball number: 12 Value: O75 Found on: 1 board
Calling ball number: 13 Value: B9 Found on: 1 board
Calling ball number: 14 Value: O64 Found on: 0 boards
Calling ball number: 15 Value: I23 Found on: 1 board
Calling ball number: 16 Value: O70 Found on: 0 boards
Calling ball number: 17 Value: N32 Found on: 0 boards
Calling ball number: 18 Value: B10 Found on: 0 boards
Calling ball number: 19 Value: I27 Found on: 0 boards
Calling ball number: 20 Value: G60 Found on: 1 board
Board: 0 has a winner in a Row
B9*   I23*  N44*  G60*  O75*  
B13   I28   N34   G48   O62   
B11   I21*  FREE  G56   O69   
B5*   I20   N33   G49   O73   
B4    I25*  N42   G57   O68   
```

### Many boards

```text
 ./a.out 999
Bingo played on 999 boards
Calling ball number: 1 Value: G49 Found on: 335 boards
Calling ball number: 2 Value: G56 Found on: 311 boards
Calling ball number: 3 Value: I19 Found on: 345 boards
Calling ball number: 4 Value: I23 Found on: 343 boards
Calling ball number: 5 Value: N42 Found on: 267 boards
Calling ball number: 6 Value: O75 Found on: 320 boards
Calling ball number: 7 Value: N39 Found on: 285 boards
Calling ball number: 8 Value: G48 Found on: 320 boards
Calling ball number: 9 Value: B14 Found on: 254 boards
Board: 477 has a winner in a Row
B3    I23*  N31   G53   O65   
B10   I21   N38   G54   O61   
B6    I22   FREE  G56*  O70   
B13   I27   N34   G50   O67   
B14*  I19*  N39*  G48*  O75*  
Board: 581 has a winner in a Row
B9    I20   N44   G60   O70   
B10   I27   N32   G56*  O66   
B8    I28   FREE  G54   O71   
B14*  I23*  N42*  G48*  O75*  
B12   I17   N36   G55   O74   
```

Here, we played 999 boards. **TWO** of the boards were winners. You must
show every board that contains a winner.

## Setting expectations

My solution ran about 290 lines. This is not a challenge. Rather this
should set your level of expectation. If you find yourself writing many
times this number, you should rethink your solution.

## Random numbers

You are expected to generate different sequences of random numbers
each time the program is run.

## Pedagogical purpose of this project

Notice we have `Boards` that *contains* a collection of `Board`s that
each *contain* a collection of `Cell`s. Notice that `Boards` has, for
example, a method `HasWinner()` that functions differently than
`HasWinner()` does that is part of `Board`.

This project exercises your idea of objects and their methods.

## Write the project incrementally

Starting with the smallest part, build your code incrementally.

For example, I knew when I spec'ed in `Board::HasWinner()` I would
want separate methods that were dedicated to checking only columns,
only rows, etc. I wrote these methods as *stubs* return false so I
could concentrate on writing other parts of the project. Then, when
I had enough of the project written and debugged that it made sense
to start looking for actual winners, I implemented one way of winning
at a time, testing and debugging as I went.

## Writing tests isn't  wasted effort

You know what's wasted effort? Debugging for hours and hours to find
something that could have been caught by a test.

There are things called "Testing Frameworks" which help you write
test code called "Unit Tests". Perhaps we'll go into more detail
into one or more of them.

## Writing comments isn't wasted effort

You know what's wasted effort? Debugging for hours and hours to find
something that could have been caught if you had a comment that told
you not to do what you just did.

## Professor K says

<figure>
  <img src="professor_k_sez.jpg" style="width:60%;">
  <figcaption style="width:60%;">
  People who never comment are either lazy or know-it-alls.
  </figcaption>
</figure>

Either way,
if they worked for Professor K, they wouldn't work for Professor K
very long. Or, they'd be hammered on the Internet by a person who
hasn't lost an Internet flame-war in almost 50 years. Evidence:

```text
Tom Limoncelli wrote on Jun 26, 1990, 1:27:34 AM in the Usenet Group 
Comp.Sys.Amiga...

I wrote this late at night. I couldn't figure out who should be #1
because (1) it would make them look like the brunt of the joke (not
true!) or (2) it would make it look like I was honoring them above
everyone else. I guess you might say that anyone on this list is there
because of the good work they do; it should not be taken as an insult.
Also, I'm sorry about all the people I had to leave off this list, but a
joke gets less funny as it is dragged on. There were tons of Commodore
and non-Commodore people left off the list. I'm sure you know who you
are.

And without any further verbosity:

Top 10 Ways To Lose A net.fight On Comp.Sys.Amiga
-------------------------------------------------
10. Argue with Dave Haynie about the profitability of an Amiga 2000 without
the IBM slots.
9. Argue with Eric Lavitsky about image conversion software.
8. Argue with Chuck McManis that software can be written, produced, sold and
supported for less than $50.
7. Argue with Valentin Pepelea that it would be simple to add virtual memory
to AmigaDOS.
6. Argue with Leo Schwab that fast-action game software can't be well behaved.
5. Argue with Bryce Nesbitt that memory protection can EASILY be added to
AmigaDOS processes/tasks/etc.
4. Argue with Perry Kivolowitz about ...well, most anything.
3. Argue with Matt Dillion that freely distributable software can't be
reliable and plentiful.
2. Argue with Fred Fish that it's not possible for a hobby to eat any and
all free time that one might have.
And the number 1 way to lose a net.fight is:
1. Argue with Marco Papa about copyright law.
-Tom
P.S. Replies welcome.
```

## Reminder about the code snippets given here

Every code snippet I've provided here must be used in your project.
