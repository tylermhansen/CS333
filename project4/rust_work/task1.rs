// This is a file to examine different control flow methods for rust



fn main() {
    
    // Rust allows for if else statements seen below
    let number = 4;
    if( number % 2 == 0){
        println!("The number is even");
    }
    else{ 
        println!("The number is even");
    }
    let mut i = 0;
    // loops are done in various ways, but this one is infinite, until broken
    loop{
        println!("Loop # {}", i);
        i+=1;
        if (i ==5){
            break;
        }
    }
    // this is a standard iterative for loop that automatically initializes j and increments it 
    for j in 0..3{
        println!("This is a finite for loop that will run {} more times", 2-j);
    }
    let mut z =0;

    //this is a while loop, similar to loop but has a break case built in
    while z < 5 {
        println!("This is a while loop on iteration: {}", z);
        z += 1;
    }

    let arr = [1,2,3,4,10, 20];

    // there are for each loops usable within rust. 
    for item in arr.iter(){
        println!("for each loop on value: {}", item);
    }

    

}