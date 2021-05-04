
use std::fs::File;
use std::io::ErrorKind;
use std::env;
use std::mem;
use std::time::{Duration, Instant};

//allocate tons of memory when making these arrays but then they are freed as they are not used again later
fn create_stuff(){
    for i in 0..2000000{
        let item:[i32;  100000];
    }
}


fn main(){
    //create a bunch of variables
    let mut v = vec![65, 122];
    let mut x = 0;
    let mut z = 1;
    // examine the scope here with ownership, garbage collection happens at the end of this if statement 
    if(z == 1){
        let mut y = 3;
        let mut g = 24;
        x = y;
    
    }  
    println!("X still exists and is {}, Y has been  swept and its ownership transferred",x);

    let mut reference = &x;

    reference = &11;
    println!("X still equals {} because it was borrowed",x); 
    let mut vec = Vec::new(); 
    let num = 2000;
    let mut arr:[u128;2000];
    let mut i = 0;
    //allocate a bunch of memory 
    for i in 0..(num+1){

        //use instant to time
        let now = Instant::now();
        create_stuff();
        let the_time= now.elapsed().as_millis();
       // add it to the vector for averaging
        vec.push(the_time);
        //println!("{} has elapsed", the_time);
        //average 100 iterations and print 
        if(i % 100 == 0 && i > 0){
            let mut sum = 0;
            for j in (i-100).. (i-1){
                sum = sum + vec[j];
                //println!("{}",j);
            }
            let avg = sum/100;
            println!("Average for iterations {} to {} is {}", i-100, i, avg);
        }
    }
    println!("Allocated memory {} times",num);
}
