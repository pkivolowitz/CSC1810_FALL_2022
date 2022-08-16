# Walkies

This project makes use of:

* `vector`
* precise types like `int32_t`
* `const` where appropriate
* `iomanip`
* additional features of `cout`
* platform independent delays

Your program will animate a single character back and forth across the
terminal in such a way that it appears to walk. OK, tumble across the
screen might be more correct but then titling this page *Tumbling*
wouldn't have the same ring.

![walkies](./walkies.gif)

## Overview

You will declare a `vector` and put characters into the vector in the
following order:

| Order | Character | Comment |
| ----- | --------- | ------- |
| 0 | \| | below delete key - this is called the pipe character |
| 1 | / | slash |
| 2 | _ | underscore |
| 3 | \\ | bash |

Notice how the characters can be repeated to approximate a tumbling
animation.

You will loop these characters in such a way that they will be drawn
marching first to the right across the screen and then back to the left
as in the animation above.

The width of the tumbling range will be 60 (the animation above shows a
width of 40 but you are to use 60).

The program runs forever... terminate it with ^c (control-c) or the
"stop" button in your IDE (if you launched it from there).

## Use `iomanip` To Do Spacing

The expanding and contracting space to the left of the character drawn
must be created using `iomanip`. You know how to set the width of a
field and how to right justify.

## Use of Carriage Return To Cause Redrawing

After emitting a full line of characters, your cursor must be forced
back to column 0. You can accomplish this by emitting `\r` as the last
thing you print. This is the carriage return... think getting to the end
of a line on an old time typewriter.

![Kermit](./ktpng.gif)

Kermit must be writing in assembly language because all the lines he's
typing are very short.

## Do You Need Any Spaces To The Right Of The Character?

Asking for a friend.

## Use of Precise Integer Types Required

I have previous discussed a generally optional practice of being very
explicit and precise in using integer types. I spoke about `int`
potentially having different meanings on different platforms. On the
other hand, precise types always mean what you wrote.

Most c++ compilers will arrange for precise integer type names to be
available to you - they aren't built into the language but come to us
from an include file.

If for some reason you get errors from the precise type, then add
`#include <cinttypes>` to your includes.

Recall the common precise integer types are:

| type | meaning | without cinttypes |
| ---- | ------- | ----------------- |
| uint8_t | unsigned 8 bit integer | unsigned char |
| uint16_t | unsigned 16 bit integer | unsigned short |
| uint32_t | unsigned 32 bit integer | unsigned int |
| uint64_t | unsigned 64 bit integer | unsigned long |
| int8_t | signed 8 bit integer* | char |
| int16_t | signed 16 bit integer | short |
| int32_t | signed 32 bit integer | int |
| int64_t | signed 64 bit integer | long |

\* maybe - the language standard doesn't precisely define the meaning of
`char`.

**In this project, you are required to use the precise integer types.**

## Forcing Output Without New Lines

You're used to this:

```c++
cout << "Foo" << endl;
```

The `endl` is doing two things for you:

1. Of course, it's giving you a new line but it is also...
2. Triggers the output to actually render on your console

Actual output via streams like `cout` and `cerr` only happens
when new lines are emitted. This is called "buffering". Buffering is
a powerful technique to increase efficiency when:

* the amount of output is a little at a time

* output is made frequently

* the cost of emitting the output is high

Imagine if we sent each letter in this sentence all the way to your
console one at a time. It would waste whole dog-years! Instead, output
only *actually* happens when you ask for a new line to be emitted
(either by printing `\n` or `endl`).

In this program, we're not using new lines at all.

Instead, after text is output, we'll emit only a carriage return ('\r')
which doesn't trigger the buffering system to send characters all the
way to the console.

To force output that's been buffered up in an output stream, (without
requiring a new line), do:

```c++
cout.flush();
```

The choice of the method name `flush()` is apropos in that you're
"flushing" any buffered characters all the way to their ultimate end
point.

Note that `cout` can be replaced with the name of any output stream.

## Causing A Delay

Since C++ 11, the standard library has provided a portable means of
delaying execution of your program, a *pause* in other words. To use
this method you need the following includes:

```c++
#include <chrono>
#include <thread>
```

When it is time to delay, use the following:

```c++
this_thread::sleep_for(chrono::milliseconds(MILLISECONDS_DELAY));
```

You declare and define `MILLISECONDS_DELAY`. To receive full credit,
this variable must be declared `const`.

## Use of `const`

In this project:

* you may not have any "magic numbers"
* any values which do not change must be declared as `const`

For example, you must declare a number of milliseconds that your program
will delay in between outputs.

You may NOT do this:

```c++
this_thread::sleep_for(chrono::milliseconds(100));
```

The value "100" is a magic number. It dropped in from who knows where
and we have no idea what it means! Instead you must:

```c++
const int32_t MILLISECONDS_DELAY = 100;
```

in some appropriate place in your code and then the following contains
no magic numbers. I KNOW what the parameter means.

```c++
this_thread::sleep_for(chrono::milliseconds(MILLISECONDS_DELAY));
```

### What's a Millisecond?

One thousandth of a second is a millisecond. The prefix "milli" means
one thousandth of something coming from the Latin "mille".

Five hundred milliseconds is half a second, for example.

## Barbara Woodhouse

[Barbara Woodhouse](https://en.wikipedia.org/wiki/Barbara_Woodhouse) was
a pre-Internet phenom world renowned dog trainer. From her, "Walkies"
and "Sit tah" entered the world's lexicon.

Here she is:

![Barbara](./bwoodhouse.png)
