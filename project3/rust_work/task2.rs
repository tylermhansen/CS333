fn insertion_sort(array:  &mut[i32], arraysize: i32){
    
    let n = arraysize;
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
        println!("{}\n", array[i as usize]);
    }
    return ;
}


fn linear_search(arr: &[i32], value: i32) -> i32{
    let mut i = 0;
    let mut found = false;
    // do a linear search on unsorted data by checking the value of each element
    for i in 0 .. (arr.len()-1){
        let item = arr[i];
        if item == value{
            println!("Found {} at index {}", item, i);
            found = true;
            break;
        }

    }


    if found == false {
        println!("Did not find {} in Array", value);
    }
    i = i as i32;
    return i;
}

fn sorted_search( arr: &[i32], value: i32, old_index: i32)-> i32{
    // Recursive binary search for an array
    let index =(arr.len()-1)/2;
    let check_val = arr[index];
    // if we found the value return the index
    if value == check_val {
        println!("Found {} at index {} using a recursive search", value, index);
        return index as i32;
    }
    //Check final 2 elements to find the value
    if arr.len() == 2 {
        if arr[0] == value {
            println!("Found {} at index {} using a recursive search", value,old_index);
            return index as i32;
        }
        else if arr[1] == value{
            println!("Found {} at index {} using a recursive search", value, old_index+1);
            return index as i32;
        } 
        else{
            return -1
        }
    }
    // check if the value is greater, if it is do the search again with the top half of the array, if smaller, bottom half
    else if value > check_val{
        //println!("Greater");
        let track = old_index + (index as i32);
        let slice = &arr[index .. (arr.len()) ];  
        return sorted_search(slice, value, track);
    }  
    else if value < check_val {
        //println!("Less Than");
        let slice = &arr[0 .. (index) ];
        
        return sorted_search(slice, value, old_index);
    }
    else{
        println!("{} not found within array", value);
        return -1;
    }
}

fn main(){
    // search an unsorted array
    let mut arr:[i32; 7] = [8,2,3,5,6,12,45];

    let _index = linear_search( &arr, 6);

    //search a sorted array
    let arr_sorted:[i32;8] = [2,3,4,6,8,15,64,108];

    let _sorted_index = sorted_search(&arr_sorted, 2, 0);

    // sort the array and then search it
    insertion_sort(&mut arr, 7);

    let _new_sorted =  sorted_search(&arr, 5, 0);

}