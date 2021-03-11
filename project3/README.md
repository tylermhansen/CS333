## CS333 Project 3

### Tyler Hansen, Sawyer Strong, Skye Rhomberg

#### Foreword

All C code was written exclusively by Tyler Hansen and compiled on Mac OS X Big Sur with the following `gcc` version information:

```
Configured with: --prefix=/Applications/Xcode.app/Contents/Developer/usr --with-gxx-include-dir=/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/c++/4.2.1
Apple clang version 12.0.0 (clang-1200.0.32.29)
Target: x86_64-apple-darwin20.2.0
Thread model: posix
InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin
flex 2.5.35 Apple(flex-32)
```

I highly recommend that this repository is [viewed on GitHub](https://github.com/tylermhansen/CS333) for the best `Markdown` reading experience.

#### Directory Guide:

```
/project3
├── README.md       <-- You are here! (If you have the README open, of course. In GitHub, you will see this if you are just in the /project3 directory.)
├── c_work          : Tyler Hansen's individual work in C for Project 3.
│   ├── Makefile    : Part of an extension for this week. Allows user to execute "make" into the terminal in this directory, then they can immediately execute
                      "./cstktest".
│   ├── cstk.c      : Describes the Stack data structure and implements the functions declared in the header file.
│   ├── cstk.h      : Declares the basic functions of the Stack data structure.
│   └── cstktest.c  : Ying's test code for the Stack.
├── go_work         : Tyler Hansen, Sawyer Strong, and Skye Rhomberg's work in Go for Project 3.
├── ruby_work       : Tyler Hansen, Sawyer Strong, and Skye Rhomberg's work in Ruby for Project 3.
│   ├── task1.rb    : Demonstrates the rules for identifier naming, variable declarations and identifier scoping of the Ruby programming language.
                      Output is rather verbose.
                      Usage: "ruby task1.rb"
│   ├── task2.rb    : Demonstrates an implementation of a binary search for element "d" in sorted array "arr" in the Ruby programming language.
                      Usage: "ruby task2.rb d arr", for example ruby "task2.rb 42 1 2 3 4 5 6 7 8 9 42 142 4242"
                      Output: The result of the binary search both recursively and iteratively as well as the time each function took to run in milliseconds.
│   └── task3.rb    : Demonstrates all of the basic built-in types and how to construct aggregate types and which of the standard suite of operators
                      (+-/*%) manipulate which types and what the resulting type of each operation is.
                      Output is rather verbose.
                      Usage: "ruby task3.rb"
└── rust_work       : Tyler Hansen, Sawyer Strong, and Skye Rhomberg's work in Rust for Project 3.
```

#### Extensions:

- Note that we did the project in **three** selected languages, not just one or two (Go, Rust, and Ruby).
- Created my own Makefile for my C code after learning `make`, making running the code way easier. The user just has to execute "make" into the terminal in this directory, then they can immediately execute "./cstktest" and voila, the code in C for this week is compiled and demonstrated.
- Implemented both recursive and iterative binary search in Ruby in `task2.rb`. Command-line input and then execution time comparison between the two.
- Implemented an insertion sort in Rust.
