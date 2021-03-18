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

#### project4/c_work

`/Makefile`:

#### Extensions:

##### C:

- Created my own Makefile for my C code after learning `make`, making running the code way easier. The user just has to execute "make" into the terminal in this directory, then they can immediately execute "./cstktest" and voila, the code in C for this week is compiled and demonstrated.

##### Other Languages:

- Note that we did the project in **three** selected languages, not just one or two.
- Implemented both recursive and iterative binary search in Ruby in `task2.rb`. Command-line input and then execution time comparison between the two.
- Implemented an insertion sort in Rust.
- Created a Rust Makefile such that a user just has to execute "make" into the terminal in this directory, then they can immediately execute whichever rust file they choose since they are all compiled for them.
- Used a built-in binary search function in Go and compared it to our implementation
