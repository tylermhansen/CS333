## CS333 Project 5

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
/project4
.
── README.md
├── c_work
│   ├── Makefile
│   ├── clltest.c
│   ├── linkedlist.c
│   └── linkedlist.h
├── go_work
│   ├── go.mod
│   ├── mylists
│   │   └── sll.go
│   └── proj5_tests.go
├── ruby_work
│   ├── haiku.rb
│   ├── linked_list.rb
│   └── testll.rb
└── rust_work
    └── Rust
        └── lists
            ├── Cargo.toml
            └── src
                ├── generic_append.exe
                ├── generic_append.pdb
                ├── generic_append.rs
                └── lib.rs
```

#### Compilation/Run Instructions:

For C:

```
make
./clltest
```

For Go:

```
go run project5_tests.go
-- OR --
go build project5_tests
./project5_tests
```

For Ruby:

```
ruby testll.rb
```

For Rust (in `/lists`):

```
cargo build
cargo test
```

##### project5/c_work

- `/Makefile`: A simple Makefile for compiling all of the C files for this week's C code. Usage: Run the command "make" in the directory "c_work/", then execute `./clltest`!
- `/clltest.c`: Ying's Linked List test code.
- `/linkedlist.c`: My description of the **Doubly** Linked List data structure. Implements all of the necessary methods.
- `/linkedelist.h`: Contains the heads of the necessary methods to describe a Linked list.

##### project4/go_work

- `/go.mod`: go module file defines dependencies, top-level executable
- `/mylists/sll.go`: Singly Linked List defs file
- `/proj5_tests.go`: test file for Go Tasks

##### project5/ruby_work

- `/haiku.rb`: A compilable haiku in Ruby that shows polymorphism.
- `/linked_list.rb`: Describes the Singly Linked List data structure in the Ruby programming language.
- `/testll.rb` : My test file for the Linked List written in Ruby. Showcases that each required method works as specified.

#### Extensions:

##### C:

- Created my own Makefile for my C code after learning `make`, making running the code way easier. The user just has to execute "make" into the terminal in this directory, then they can immediately execute "./cstktest" and voila, the code in C for this week is compiled and demonstrated.

##### Other Languages:

- Note that we did the project in **three** selected languages, not just one or two. (**Go, Ruby, and Rust**)
- Implemented a delete-by-node method in Ruby, not just the remove by value.
- Wrote a compilable haiku in Ruby that shows polymorphism; Ruby is a polymrphic languge, storing multiple differnet variable types in its native array syntax is highlighted.
- Utilized a new testing method for Rust -- cargo. Includes built-in test methods with extra metadata metrics. More information on the wiki.
- In addition we made sure to use Rust's iterable feature along with mutable to add different functionality and utility to the list.
- Implemented `Insert` and `Delete` methods for Go Singly Linked List.
