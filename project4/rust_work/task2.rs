// This file is full of different functions that rust uses and shows how to call functions, create parameters and set return values

fn void_method(){
    println!("This method does not return anything");
}

//We can see below functions have their name: type for parameter syntax
fn void_method_w_parameter(x: i32, y: i32){
    println!("Input X: {}", x);
    println!("Input Y: {}", y);
    println!("Return Nothing");
}

// -> type indicates the type of value returned
fn int_method(x:i32) -> i32 {
    println!("This method returns an integer");
    return x-12;
}
// Rust can return tuples of values but struggles with arrays. Also Rust cannot have default values for parameters. 
fn multiple_number() -> (i32, f32){
    println!("Methods can return multiple things, this one returns an integer and a float");
    let x = int_method(723);
    return (x,43.2);
}

fn main(){

    void_method();
    void_method_w_parameter(13,45);
   //Here we can see that methods can be entered directly as a parameter
    void_method_w_parameter(int_method(14), int_method(784));
    // you can return values to variables 
    let int_tuple = multiple_number();

    println!("Multiple Number returns: {} and {}", int_tuple.0, int_tuple.1)

}