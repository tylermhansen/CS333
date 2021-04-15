

use std::fs::File;
use std::io::prelude::*;
use std::path::Path;
use std::env;
use std::fs;


fn main() {
    // Create a path to the desired file
    //filename from command line 
    let args: Vec<String> = env::args().collect();
    let filename = &args[1];
    let path = Path::new(filename);
    let display = path.display();

    // find and open the file 
    let mut file = match File::open(&path) {
        Err(why) => panic!("couldn't open"),
        Ok(file) => file,
    };
    //read the file to a string
    let mut s = String::new();
    match file.read_to_string(&mut s) {
        Err(why) => panic!("couldn't read {}: {}", display, why),
        Ok(_) => print!("{} contains:\n{}", display, s),
    }

    println!("");

    //dynamically get inputs from the command line
    let mut l = String::new();
    println!("What is your name :");
    let b1 = std::io::stdin().read_line(&mut l).unwrap();
    println!("Hey, {}", l);
    // `file` goes out of scope, and the "hello.txt" file gets closed
}
