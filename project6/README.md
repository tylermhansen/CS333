## CS333 Project 6

### Tyler Hansen, Sawyer Strong, Skye Rhomberg

#### Foreword

All C code was written exclusively by Tyler Hansen and compiled on Mac OS X Big Sur with the following `gcc` version information:

```
C:
Configured with: --prefix=/Applications/Xcode.app/Contents/Developer/usr --with-gxx-include-dir=/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/c++/4.2.1
Apple clang version 12.0.0 (clang-1200.0.32.29)
Target: x86_64-apple-darwin20.2.0
Thread model: posix
InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin
flex 2.5.35 Apple(flex-32)

Other Languages:
go1.15.8 linux/amd64
```

I highly recommend that this repository is [viewed on GitHub](https://github.com/tylermhansen/CS333) for the best `Markdown` reading experience.

#### Directory Guide:

```
/project6
├── README.md
├── c_work
│   ├── signalexploring
│   │   ├── Makefile
│   │   ├── floatingpointexception.c
│   │   ├── interrupt.c
│   │   └── segfault.c
│   └── wordcounting
│       ├── Makefile
│       ├── test_text.txt
│       ├── wctest.c
│       ├── wordcounter.c
│       └── wordcounter.h
└── ruby_work
    ├── exceptions.rb
    ├── fileio.rb
    ├── test_text.txt
    └── wordcounter.rb
```

#### Compilation/Run Instructions:

For C:

```
make
./executable_name (depends on which executable you want to run)
```

For Ruby:

```
ruby filename.rb
```

##### project6/c_work/signalexploring

- `/Makefile`: A simple Makefile for compiling all of the C files for this week's C code. Usage: Run the command `make` in the directory "c_work/signalexploring", then run whichever executable you want!
- `/floatingpointexception.c`: Generates and handles a floating point exception in C.
- `/interrupt.c`: A C program that can be interrupted with `CTRL+C` on the keyboard.
- `/segfault.c`: Generates and handles a segmentation fault in C.

##### project6/c_work/wordcounting

- `/Makefile`: A simple Makefile for compiling all of the C files for this week's C code. Usage: Run the command `make` in the directory "c_work/wordcounting", then run `./wctest {filepath}`!
- `/test_text.txt`: The test text file provided by Ying on the course site.
- `/wctest.c`: A test file for the WordCounter object that I implemented this week. Usage: After running make, run `./wctest` followed by the path to a text file to read.
- `/wordcounter.c`: Implements all of the necessay methods for a WordCounter object.
- `/wordcounter.h`: Contains the function headers for describing a WordCounter object.

##### project5/ruby_work

- `/exceptions.rb`: A walk-through of how exceptions are handled in Ruby,
- `/fileio.rb`: An interactive walk-through script of how file input/output works in Ruby.
- `/test_text.txt`: The test text file provided by Ying on the course site.
- `/wordcounter.rb` : A script that counts the frequency of each word in a given text file according to specs given in project details.

#### Extensions:

##### C:

- Instead of just using a main method, I decided to make my word counter code importable as a WordCounter object that can be used anywhere in future projects. See `wordcounter.h` and `wordcounter.c`. This took much more effort and results in something that is reusable :)
- Created my own Makefile for my C code after learning `make`, making running the code way easier. The user just has to execute "make" into the terminal in this directory, then they can immediately execute any executable they want.

##### Other Languages:

- Note that we did the project in **three** selected languages, not just one or two. (**Go, Ruby, and Rust**)
- A massive Ruby extension is in progress..
