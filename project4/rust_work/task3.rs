

fn insertion_sort(array:  &mut[i32], arraysize: i32){
    
    let n = arraysize+1;
    let mut  j = 1;
    let mut temp = 0;

    // for each item in the array check the values and insert them into the array in the appropriate spot
    for i in 0.. (n-1){
	    j = i;
            while  j > 0 && array[(j as usize)-1] > array[j as usize]
            {	
                let index = j as usize;
                let second_ind = (j - 1 ) as usize;        
                temp     = array[index];
                array[index]   = array[second_ind];
                array[second_ind] = temp;
                j-=1;
            }
    }
    println!("Sorted list in ascending order:\n");
    for i in 0.. (n-1)
    {
        println!("{}", array[i as usize]);
    }
    return ;
}


fn main(){


    let mut arr:[i32; 15] = [8,2,3,5,6,12,45,46,36,1053,1543,7,534,18,16];
    insertion_sort(&mut arr, 15);




}