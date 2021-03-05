## CS333 Project 2: Work In Ruby

### Tyler Hansen, Sawyer Strong, and Skye Rhomberg

### Directory Guide

```
/ruby_work
├── Gemfile         : The Gemfile contains all Gems used in the Ruby project. Here, we are only using the "http" gem.
├── Gemfile.lock    : Auto-generated file for package management version control purposes.
├── README.md       <-- You are here! (If you have the README open, of course. In GitHub, you will see this if you are just in the /ruby_work directory.)
├── dogfact.rb      : Dog fact generator. Run with "ruby dogfact.rb". Creates a "GET" HTTP request to a dog fact API and outputs a dog fact to the terminal.
                      Prompts the user and asks if they want more dog facts. If user inputs "Y", continues with dog facts. If the user inputs anything else,
                      dog facts stop and the program terminates.
└── helloworld.rb   : Simple hello world file. Run with "ruby helloworld.rb". Prints "Hello, World!" to the terminal.
```

This week's task for extra programming languages was to write a hello world program (found in `helloworld.rb`) and to do something cool/interesting with the language.

To run the hello world program, just run `ruby helloworld.rb` in this directory (`.../ruby_work`).

We decided to make a random dog fact generator to show how simple complicated issues like HTTP requests can be in Ruby due to `gems`. Gems are basically Ruby libraries/packages. More information can be found [here](https://en.wikipedia.org/wiki/RubyGems).

To run the dog fact generator, just run `ruby dogfact.rb` in this directory (`.../ruby_work`).

The write-up for the Ruby work is found on the Wiki.
