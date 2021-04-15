


use std::env;
use std::fs;
use std::string::String;



fn insertion_sort(words:  &mut[Word], arraysize: i32){
    let n = arraysize+1;

    // for each item in the array check the values and insert them into the array in the appropriate spot
    //use the count value of the word objects to do this sorting
    for i in 0.. (n-1){
	    let mut j = i;
            while  j > 0 && words[(j as usize)-1].count < words[j as usize].count
            {	
                //track the indices needed
                let index = j as usize;
                let second_ind = (j - 1 ) as usize;   
                //clone the two words who's places are being swapped     
                let temp     = words[index].clone();
                words[index]   = words[second_ind].clone();
                words[second_ind] = temp;
                j-=1;
            }
    }
    println!("Sorted list in descending order:\n");
    //print first 20
    for i in 0.. (20)
    {
        println!("{}\t{}", words[i as usize].word, words[i as usize].count);
    }
    return ;
}

fn strip_characters(original : &str, to_strip : &str) -> String {
    //check each chararacter and if it matches, remove it
    let mut result = String::new();
    for c in original.chars() {
        if !to_strip.contains(c) {
           result.push(c);
       }
    }
    result
}

//Key value pair struct that holds word and its count
struct Word{
    word:  String,
    count: i32,
}

impl Word {
    //method to clone the kvp  when sorting
    fn clone(&self) -> Word{
        return Word{word: self.word.clone(), count: self.count};
    }
}


fn main() {
    //get filename from command line
    let args: Vec<String> = env::args().collect();
    let filename = &args[1];
    println!("In file {}", filename);
    //get string from text file
    let  contents = fs::read_to_string(filename)
        .expect("Something went wrong reading the file");

    //strip the string of punctuation and then split it into words
    let  new_contents = strip_characters(&contents, ",.?!" ).to_lowercase();
    let  split_iter = new_contents.split(" ");
    // put the iterator object into vector 
    let split_contents = split_iter.collect::<Vec<&str>>();
    let mut lastword = 1;
    //create a vector of word objects to track the counts
    let mut words =  vec![Word{word: split_contents[0].to_string(), count: 0}];
    
    //check each word in the file
    for item in split_contents{
        let mut found = 0;
        //check each word already found and if it is a repeat increase the count value
        for i in 0..lastword{
            if item == words[i].word{
                words[i].count += 1;
                found = 1;
            }
        }
        //if it is not, add a value to the wordcount vector
            if found == 0{
                words.push(Word{word:item.to_string(), count:1});
                lastword+=1;
            }
    }
    //sort the words highest to lowest
    let size = words.len() as i32;
    insertion_sort(& mut words,size);
    
}