## CS333 Project 4

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
/project4
├── README.md
├── c_work
│   ├── Makefile
│   ├── factorial.c
│   └── quicksort.c
├── go_work
├── ruby_work
│   ├── Gemfile
│   ├── task1.rb
│   ├── task2.rb
│   └── task3.rb
└── rust_work
    ├── Makefile
    ├── task1.rs
    ├── task2.rs
    └── task3.rs
```

##### project4/c_work

- `/Makefile`: A simple Makefile for compiling all of the Rust files for this week's C code. Usage: Run the command "make" in the directory "c_work/", then execute whichever executable you want!
- `/factorial.c`: Given a number n from the command line, computes the factorial of said number. Interestingly, the program breaks down eventually. When computing 12!, 13!, 14!, and finally 15!, it is evident that the answers are no longer correct. This probably has to do with how large these quantities are and how much space is allocated for them in memory. Usage: `./factest` after `make`
- `/quicksort.c`: An implementation of the quicksort algorithm in C. Verified that the output is correct and matches Ying's. Usage: `./qcktest` after `make`

##### project4/ruby_work

- `/Gemfile`: Ruby inclufes a Gemfile that lists all of the necessary gems (packages) to run all Ruby files in a directory.
- `/task1.rb`: Demonstrates all of the control flow statements that Ruby provides.
- `/task2.rb`: Demonstrates how Ruby handles functions as data types.
- `/task3.rb`: Implements sorting algorithm(s) in Ruby. Note the extension: Multiple algos included, user selection and time comparison

##### project4/rust_work

- `/Makefile`: A simple Makefile for compiling all of the Rust files for this week's Rust code. Usage: Run the command "make" in the directory "rust_work/", then execute whichever executable you want!
- `/task1.rs`: Demonstrates all of the control flow statements that Rust provides. Usage: `./task1` after `make`
- `/task2.rs`: Demonstrates how Rust handles functions as data types. Usage: `./task1` after `make`
- `/task3.rs`: Implements insertion sort in Rust. Usage: `./task1` after `make`

#### Extensions:

##### C:

- Created my own Makefile for my C code after learning `make`, making running the code way easier. The user just has to execute "make" into the terminal in this directory, then they can immediately execute "./cstktest" and voila, the code in C for this week is compiled and demonstrated.

##### Other Languages:

- Note that we did the project in **three** selected languages, not just one or two. (Go, Ruby, and Rust)
- Implemented three different sorting algos in Ruby in `task2.rb`. Command-line input and then execution time comparison between them and Ruby's native method.
- Created a Rust Makefile such that a user just has to execute "make" into the terminal in this directory, then they can immediately execute whichever rust file they choose since they are all compiled for them.
