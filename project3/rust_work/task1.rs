fn main() {
    // Statements here are executed when the compiled binary is called

    // underscores are allowed and indicates that a variable will not be used again. Warnings are emitted when not using snake case and while cases do not throw an error, do give a warning
    // special characters such as &*$# etc are not allowed within variable names 
    let _test_arr:[i32;5] = [10,20,30,40,50];
    let _Tuple = (1,2,3,4,5);
    let _tuple_of_tuples = ((1, 2, 3), (4, 5), 6);

    
   
    let diff_types = (1, "hello", 4.5, true);
    let (_a, _b, _c, _d) = diff_types;
    let mut j = 0;
    for i in 0..10 {
        let z = 0; 
        j +=1;

    }
    println!("{}", j)
    // as seen above i and z exist only within the for loop, and do not exist outside of that scope, while j exists globally and is modified within the loop
}