# CSC1810 FALL 2022 SECTIONS 1 and 2

This is the class web page for CSC1810 in Fall of 2022 at Carthage
College

Most of you will not read this page. This is sad. See next.

## A Note for Incoming Freshpersons

This is not high school.

I am not a religious person. However, 1 Corinthians 13 has this to say:

*When I was a child, I spoke as a child, I understood as a child, I
thought as a child; but when I became a man, I put away childish things.*

The point being, success in college is a function of hard work and
discipline. The strategies you employed for success in school prior
to college may not work for you here. What will work:

* Hard work, by you. No one else.

* Discipline, by you. No one else.

A corollary: "I generally help those who help themselves."

The preceding
once showed up in a teaching evaluation. As. If. This. Was. A. Bad.
Thing.

## Syllabus

The syllabus is found
[here](./syllabus/CSC%201810%20Fa22%20Kivolowitz.pdf).

Most of you will not read the syllabus. This is sad. See previous.

## Meeting Times / Place

Section 1 meets MWF 10:30 to 11:35 Clausen 114.

Section 2 meets MWF 13:35 to 14:40 Clausen 114.

## Attendance

From the [syllabus](./syllabus/CSC%201810%20Fa22%20Kivolowitz.pdf):

~~For every five classes missed, your final grade will be reduced by a
full letter. Absences due to sports, music, or any other campus activity
count as an unexcused absences. To be clear: A full letter grade means
exactly that. For example, a B+ will be reduced to a C+.~~

The previous language did not convey what I intended. Instead, and to
be more clear, upon missing your sixth class (and eleventh,
sixteenth, etc) your letter grade will be reduced by one full letter.
Put another way:

* If you miss 1, 2, 3, 4 or 5 classes - there is no penalty.

* Upon your sixth miss, your letter grade will be reduced by a full
letter.

This will be updated in the syllabus as well.

## Arriving Late / Leaving Early

From the [syllabus](./syllabus/CSC%201810%20Fa22%20Kivolowitz.pdf):

**We meet for 65 minutes. There is little room to “leave early.”
Therefore, leaving a class early will be counted as a half class
missed.**

**We meet for 65 minutes. There is little room to “arrive late.”
Therefore, arriving late to a class will be counted as a half
class missed.**

## Accessing the Class Text

The text is an online service hosted at zyBooks.com. Of note is that
being online, it offers live exercises within the “book” that give
immediate feedback.

**These exercises are graded.**

Not doing these is like
tossing your grade in the trash.

1. Sign in or create an account at learn.zybooks.com

2. Enter zyBook code: CARTHAGECSC1810KivolowitzFall2022

3. Subscribe

Readings are assigned via Schoology.

## Chapters / Subchapters to be Covered

You are encouraged to read ahead. Below are the chapters and
subchapters we will cover.

**However, we will frequently cover these
out-of-order.**

| Chapter | Subchapters |
| ------- | ----------- |
| 1 | All |
| 2 | Not: 12, 15 |
| 3 | Not: 14 |
| 4 | All |
| 5 | All |
| 6 | All |
| 9 | Not 9.9 |
| 15 | Only 1, 2, 3, 11 through 18 |

There may be other chapters I have missed, that are associated with
certain projects (for instance).

### "Jumping Around" in the Book

I am **NOT** jumping around to make things more
confusing. Rather, the opposite is true. While we might have read
whole chapters only up to chapter 2, for example, you will have readings
from later chapters in support of your projects.

See [here](./reading_crossindex.md) for which chapters will be helpful
to you in which project.

Again, my ordering makes sense for teaching. Their ordering makes
sense for writing a book.

## Projects

Project specifications can be found [here](./projects).

Projects permit one grace day without penalty. After one day
of lateness, work will not be accepted without
prior authorization.

Again, [this](./reading_crossindex.md) is a mapping showing which
out-of-order chapters will be helpful doing each project.

## Installing Your Environment

Note: There is no complete agreement among the CS Professors about
what constitutes the *right* environment. I use the most Linux-like
environment I can reasonably manage. This means:

* Visual Studio Code (**so Mac, Windows and Linux are the same**).

* The terminal on Mac (almost identical to a Linux terminal).

* WSL on Windows (a Linux terminal).

Follow the steps below carefully.

### Mac

If "Notes" contains a link you must read the information to which
it leads.

| Step | Link | Notes |
| ---- | ---- | ----- |
| 1 | [Here](https://www.youtube.com/watch?v=oX654TT3ixc&list=PLnE1d1TMuFwPqZq0caXSzHM4u2UdPmhW4&index=1) | |
| 2 | [Here](https://www.youtube.com/watch?v=N_JowoS2lR8&list=PLnE1d1TMuFwPqZq0caXSzHM4u2UdPmhW4&index=2) | |
| 3 | [Here](https://www.youtube.com/watch?v=tJjDYe3_Vmg&list=PLnE1d1TMuFwPqZq0caXSzHM4u2UdPmhW4&index=3) | |
| 4 | [Here](https://www.youtube.com/watch?v=u4CQYyTWGYA&list=PLnE1d1TMuFwPqZq0caXSzHM4u2UdPmhW4&index=4) | Maybe don't do this yet |
| 5 | [Here](https://www.youtube.com/watch?v=13GEtlnAMLU&list=PLnE1d1TMuFwPqZq0caXSzHM4u2UdPmhW4&index=5) | |
| 6 | [Here](https://www.youtube.com/watch?v=dYQLs5gbUiE&list=PLnE1d1TMuFwPqZq0caXSzHM4u2UdPmhW4&index=6) | [NOTE](./README.md#installing-vs-code-on-mac) |
| 7 | See "Installing BREW on Mac" below | |
| 8 | See "Installing wget on Mac" below | |
| 9 | See "Getting the Project Creator" below | |
| 10 | Install the `codelldb` extension | |

---

#### Installing VS Code on Mac

Since this video was recorded, more choices for the Mac are
presented. If you have an "Apple Silicon", choose that (these
are the newest Macs). If you have an Intel Mac, choose that
(these are the older Macs). If you are not sure, don't click
Universal - instead click the Apple menu then click
"About This Mac" and read the overview.

---

#### *Installing BREW on Mac*

Copy this text and paste it into a terminal:

```text
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

The install asks for your password. This is fine.

The install pauses to ask if you're sure. This is fine.

Now you wait.

When complete, copy the next two lines then paste into your terminal:

```text
echo 'eval "$(/opt/homebrew/bin/brew shellenv)"' >> /Users/YOUR_USER_NAME_GOES_HERE/.zprofile
eval "$(/opt/homebrew/bin/brew shellenv)"
```

---

#### *Installing wget on Mac*

Copy this text and paste it into a terminal **after** you have
installed BREW.

```text
brew install wget
```

### Installing the Environment on Windows

I have authored a single video covering the entire process. It
is found [here](https://youtu.be/VLr2PwyxVSM). I have added an
index of the video in its description. Click "Show More" to
reveal the index allowing you to skip to what you need (after you
have seen the entire video).

### For Both Windows and Mac

#### Getting the Project Creator

On the Mac, you will first had to install `wget` using BREW. This
is described above.

On Windows, this is done in WSL. The
[video](https://youtu.be/VLr2PwyxVSM) explains doing this.

```text
wget https://www.mediafire.com/file/eew2hitafpf3pnl/create_project.command
```

## Links To Selected Videos

| Link | Content |
| ---- | ------- |
| [link](https://www.youtube.com/watch?v=9WcOS1oVoAg&list=PLnE1d1TMuFwOjEaP47aKu5n7p2Gs5HJaq&index=3) | The if statement. |
| [link](https://www.youtube.com/watch?v=oSEGPDGQVe0&list=PLnE1d1TMuFwOjEaP47aKu5n7p2Gs5HJaq&index=5) | The for loop. |
| [link](https://www.youtube.com/watch?v=fl8Ivy9or_o&list=PLnE1d1TMuFwOjEaP47aKu5n7p2Gs5HJaq&index=4) | The while loop plus rand() and srand(). |

## Recordings from Prior Year's Classes

Fall 2020 videos can be found [here](https://www.youtube.com/playlist?list=PLnE1d1TMuFwP4kvuOmj3k_lRjmsnKaG3t).

Fall 2021 videos can be found [here](https://www.youtube.com/playlist?list=PLnE1d1TMuFwOjEaP47aKu5n7p2Gs5HJaq).

## Another Resource

Our very own Professor Mark Mahoney has created a tool called
StoryTeller to explain code. He has developed a course
specifically for this class.

Please find it [here](https://markm208.github.io/cppbook/).

## Basic Types

For your convenience:

* The integer types are described [here](./integers.md)

* The floating point types are described [here](./floating_point.md)

## Info for Cool Kids

* Various keyboard symbols are named [here](./symbols.md)

## Topics Covered

| Day | Content | Out-of-Order Chapters Needed<br/>For Projects |
| --- | ------- | ---------------------------- |
| 9/7 | Syllabus and Install + Demos To Pass the Time | |
| 9/9 | `main()` and concept of functions, `namespace`, `cout`, `endl`, flow charts, signed integer types, assignment, `if`, maybe `goto`, labels | |
| 9/12 | Review, `while`, `if`, flow charts, first look at debugging, floating point types | |
| 9/14 | Review, P1 Assigned, `for`, `break`, `continue`, flow charts, `while`  | 3.1, 4.2, 7.15, 9.1 |
| 9/16 | Review, practice | |
| 9/19 | | |
| 9/21 | Review, P1 Due, P2 Assigned| 4.4, 4.5, 4.7, 9.2 |
| 9/23 | | |

## Strong Advice

<figure>
  <img src="./professor_k_sez.jpg" style="width:60%;">
  <figcaption style="width:60%;">
  	Start Early. Work Steadily.
  </figcaption>
</figure>

## More Strong Advice

<figure>
  <img src="./shoulda.jpg" style="width:60%;">
  <figcaption style="width:60%;">
  	Start Early. Work Steadily.
  </figcaption>
</figure>
