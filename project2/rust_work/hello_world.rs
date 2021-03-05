



fn main() {
    // Statements here are executed when the compiled binary is called

    // Print text to the console
    println!("Hello World!");

    let test_arr:[i32;5] = [10,20,30,40,50];

   for item in test_arr.iter(){
        println!(" element  of the array: {}", item);

    }

    let x = 4;
    match x {
        0 => { println!("X = 0")} // Do nothing
        4 => {println!("X = 4")} 
        _ => {println!("X Not Known") } // Matches every integer value
    }
}