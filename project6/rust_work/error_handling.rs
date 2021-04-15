use std::fs::File;
use std::io::ErrorKind;
use std::env;


fn main() {
    let f = File::open("hello.txt");

    let f = match f {
        Ok(file) => file,
        Err(error) => match error.kind() {
            ErrorKind::NotFound => match File::create("hello.txt") {
                Ok(fc) => fc,
                Err(e) => panic!("Problem creating the file: {:?}", e),
            },
            other_error => {
                panic!("Problem opening the file: {:?}", other_error)
            }
        },

    };

    use std::fs;

    let port = env::var("PORT").unwrap_or("3000".to_string());
    println!("{}", port);

    let content = fs::read_to_string("./Cargo.toml").unwrap();
    println!("{}", content);

    let content1 = fs::read_to_string("./Cargo.toml").expect("Cannot read Cargo.toml");

   
}