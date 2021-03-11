
struct TestStruct {
    x: i32,
    y: i32,
}

fn change_x(test: & mut TestStruct) {
    test.x += 150;
    println!("Changed X to {}", test.x );
}

fn main() {
    // Statements here are executed when the compiled binary is called


    let _test_arr:[i32;5] = [10,20,30,40,50];
    let _tuple = (1,2,3,4,5);
    let _tuple_of_tuples = ((1, 2, 3), (4, 5), 6);
    //Please note that tuples can be too long to be printed an will throw a compiler error if attempted
    // Tuples can be broken down into individual variables as seen below as well as are not limited in type like arrays
    let diff_types = (1, "hello", 4.5, true);
    let (_a, _b, _c, _d) = diff_types;

    //Rust allows for passing by reference, this means that variables can be borrowed more than once, and cannot be destroyed if borrowed again later. 
    //Once freed they can be destroyed
    let borrow_var= 13;
    let ref_to_borrow: &i32 = &borrow_var;
    

    //The following line will throw an error if uncommented due to the fact that borrow var is used later in the form of ref_to_borrow
    //drop(borrow_var);

    println!("Ref is {}", ref_to_borrow);
    
    drop(borrow_var);
    let test = TestStruct{
        x: 50,
        y: 100
    };

    let mut mutatest = test;
    change_x(&mut mutatest);
    
    // declaring the variable below will throw an error as variables are immutable by default. Mut keyword is necessary.
    //let changable = 11;
    let mut changable = 11;
    changable+=12;
    println!("Addition{}", changable);
    changable = changable * 2;
    println!("Multiplication {}", changable);
    changable = changable % 6;
    println!("Modulo Operator {}", changable);
    changable = changable / 2;
    println!("Division {}", changable);
    changable = changable - 6;
    println!("Division {}", changable);

    
    


    
}   
