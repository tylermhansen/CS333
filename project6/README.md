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

- `/Makefile`: A simple Makefile for compiling all of the C files for this week's C code. Usage: Run the command `make` in the directory "c_work/signalexploring", then run whichever executable you want! Outputs: None
- `/floatingpointexception.c`: Generates and handles a floating point exception in C. Outputs: Heading to divide by zero... If we got here, it means the program continued afer the floating point error occurred.
- `/interrupt.c`: A C program that can be interrupted with `CTRL+C` on the keyboard. Outputs: Caught Interrupt signal. Program interrupted. (once user does CTRL+C)
- `/segfault.c`: Generates and handles a segmentation fault in C. Outputs: Heading to create some undefined behavior... Caught Segmentation Fault signal. Exiting...

##### project6/c_work/wordcounting

- `/Makefile`: A simple Makefile for compiling all of the C files for this week's C code. Usage: Run the command `make` in the directory "c_work/wordcounting", then run `./wctest {filepath}`! Outputs: None
- `/test_text.txt`: The test text file provided by Ying on the course site. Outputs: None
- `/wctest.c`: A test file for the WordCounter object that I implemented this week. Usage: After running make, run `./wctest` followed by the path to a text file to read. Outputs (with test_text.txt):

```
  This is after wc_read happens...
  the => 17
  of => 7
  and => 6
  was => 5
  with => 4
  in => 4
  a => 3
  windows => 3
  wings => 2
  portion => 2
  central => 2
  were => 2
  broken => 2
  but => 2
  up => 2
  had => 2
  been => 2
  claws => 1
  crab => 1
  thrown => 1
```

- `/wordcounter.c`: Implements all of the necessay methods for a WordCounter object. Outputs: None
- `/wordcounter.h`: Contains the function headers for describing a WordCounter object. Outputs: None

##### project6/ruby_work

- `/exceptions.rb`: A walk-through of how exceptions are handled in Ruby. Outputs:

```
  Failed :(

  File #<File:0x00007fabf7898c08> opened successfully

  This time, we successfuly opened a file with the retry keyeod! Next, let's raise an excpetion:

  Exception raised: Tyler, Sawyer, and Skye's test exception.
```

- `/fileio.rb`: An interactive walk-through script of how file input/output works in Ruby. Outputs: Depends on interaction with user. Outputs: Depends on user input.
- `/test_text.txt`: The test text file provided by Ying on the course site. Outputs: None
- `/wordcounter.rb` : A script that counts the frequency of each word in a given text file according to specs given in project details. Outputs (for test_txt.txt):

```
  the => 17
  of => 7
  and => 6
  was => 5
  with => 4
  in => 4
  a => 3
  windows => 3
  portion => 2
  been => 2
  up => 2
  wings => 2
  had => 2
  broken => 2
  were => 2
  but => 2
  central => 2
  there => 1
  into => 1
  stonework => 1
  wall => 1
  end => 1
  against => 1
  erected => 1
  scaffolding => 1
  some => 1
  resided => 1
  family => 1
  where => 1
  this => 1
  that => 1
  showed => 1
  chimneys => 1
  from => 1
  curling => 1
  smoke => 1
  blue => 1
  blinds => 1
  modern => 1
  comparatively => 1
  block => 1
  righthand => 1
  repair => 1
  better => 1
  little => 1
  ruin => 1
  picture => 1
  caved => 1
  partly => 1
  roof => 1
  while => 1
  boards => 1
  wooden => 1
  blocked => 1
  these => 1
  one => 1
  side => 1
  each => 1
  on => 1
  out => 1
  thrown => 1
  crab => 1
  claws => 1
  like => 1
  curving => 1
  two => 1
  high => 1
  stone => 1
  lichenblotched => 1
  grey => 1
  attention => 1
  deep => 1
  examined => 1
  lawn => 1
  illtrimmed => 1
  down => 1
  slowly => 1
  walked => 1
  holmes => 1
  visit => 1
  our => 1
  moment => 1
  at => 1
  workmen => 1
  any => 1
  signs => 1
  no => 1
  building => 1
  outsides => 1
```

##### project6/rust_work

    - word_counter.rs
        -- A file that takes in a text file and counts the words within it before printing out the top 20.
        -- Compile with:
            Compiled with rustc word_counter.rs
            Run with ./word_counter <text file> ex. test.txt
        -- Outputs:
            In file test.txt
            Sorted list in descending order:

            the     17
            of      7
            and     6
            was     5
            with    4
            in      4
            a       3
            windows 3
            central 2
            portion 2
            wings   2
            were    2
            broken  2
            but     2
            up      2
            had     2
            been    2
            building        1
            grey    1
            lichen-blotched 1
    - error_handling.rs
        -- A test file to examine the way rust can handle errors.
        -- Compile with:
            Compiled with rustc error_handling.rs
            Run with ./error_handling
        -- Outputs:
            3000
            thread 'main' panicked at 'called `Result::unwrap()` on an `Err` value: Os { code: 2, kind: NotFound, message: "The system cannot find the file specified." }', .\error_handling.rs:28:54
            note: run with `RUST_BACKTRACE=1` environment variable to display a backtrace
    - fileio.rs
        -- A test file to examine input and output of both command line and files
        -- Compile with:
            Compiled with rustc fileio.rs
            Run with ./fileio <text file> ex test.txt
        -- Outputs:
            The building was of grey, lichen-blotched stone, with a high central portion
            and two curving wings, like the claws of a crab, thrown out on each side. In one
            of these wings the windows were broken and blocked with wooden boards, while the
            roof was partly caved in, a picture of ruin. The central portion was in little better
            repair, but the right-hand block was comparatively modern, and the blinds in the windows,
            with the blue smoke curling up from the chimneys, showed that this was where the family
            resided. Some scaffolding had been erected against the end wall, and the stone-work had
            been broken into, but there were no signs of any workmen at the moment of our visit.
            Holmes walked slowly up and down the ill-trimmed lawn and examined with deep attention
            the outsides of the windows.

            What is your name :
            Sawyer
            Hey, Sawyer

#### Extensions:

##### C:

- Instead of just using a main method, I decided to make my word counter code importable as a WordCounter object that can be used anywhere in future projects. See `wordcounter.h` and `wordcounter.c`. This took much more effort and results in something that is reusable :)
- WordCounter object works with incompatible files, tells user to try again.
- Created my own Makefile for my C code after learning `make`, making running the code way easier. The user just has to execute "make" into the terminal in this directory, then they can immediately execute any executable they want.

##### Other Languages:

- Note that we did the project in **three** selected languages, not just one or two. (**Go, Ruby, and Rust**)
- Ruby wordcounter works with either arguments passed into it and also tells the user if a file wasn't specified, asks for it and then proceeds
- Created a Makefile for the Rust code for this week! Compiles the .rs files and using `make clean` removes the pesky executables. Just run `make` again in the directory to get them back.
