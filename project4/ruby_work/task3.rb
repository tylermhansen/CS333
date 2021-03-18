# Tyler Hansen, Sawyer Strong, Skye Rhomberg
# CS333 Spring 2021 -- Programming Languages
# 03/17/2021

# task3.rb: Implements sorting algorithm(s). Extension: Multiple algos included, user selection and time comparison

# Function: quick_sort
# ----------------------
# A recursive implementation of 3-way quicksort in Ruby. Quicksort is O(n log n) on average.
#
# Parameters: 
# arr: the subarray being sorted
# low: the low index of the subarray being sorted
# high: the high index of the subarray being sorted
def quick_sort(arr, low, high)
    if low < high
        temp = partition(arr, low, high)
        left = temp[0]
        right = temp[1]
        quick_sort(arr, low, left - 1)
        quick_sort(arr, right + 1, high)
    end
end

# Function: partition
# ----------------------
# Used in quicksort, this partitions a given array into two subarrays according to whether they are less than or greater than the pvot element.
#
# Parameters: 
# arr: the subarray being sorted
# low: the low index of the subarray being sorted
# high: the high index of the subarray being sorted
#
# Returns: 
# less_than: a subarray of arr that is less than the pivot element, which for this implementation is the lowest index element
# greater_than: a subarray of arr that is greater than the pivot element, which for this implementation is the lowest index element
def partition(arr, low, high)
    pivot= arr[low]
    i= low + 1
    less_than = low
    greater_than = high
    
    while(i <= greater_than)
        if arr[i] < pivot
            temp = arr[less_than]
            arr[less_than] = arr[i]
            arr[i] = temp
            less_than += 1
            i += 1
        elsif arr[i] > pivot
            temp = arr[i]
            arr[i] = arr[greater_than]
            arr[greater_than] = temp
            greater_than -= 1
        else
            i+=1
        end
    end
    return less_than, greater_than
end

# Function: bubble_sort
# ----------------------
# An iterative implementation of bubble sort in Ruby. On average, bubble sort is O(n^2).
#
# Parameters: 
# arr: the subarray being sorted
#
# Returns: 
# arr: the sorted array
def bubble_sort(arr)
    n = arr.length
    for i in 0...n-1
     for j in 0...n-i-1
         if arr[j] > arr[j+1]
             temp = arr[j]
             arr[j] = arr[j+1]
             arr[j+1]=temp
         end
     end
    end
    return arr
 end

# Function: insertion_sort
# ----------------------
# An iterative implementation of insertion sort in Ruby. On average, insertion sort is O(n^2).
#
# Parameters: 
# arr: the subarray being sorted
#
# Returns: 
# arr: the sorted array
 def insertion_sort(arr)
    for i in 1 ... (arr.length)
        j = i
        while j > 0
            if arr[j - 1] > arr[j]
                temp = arr[j]
                arr[j] = arr[j - 1]
                arr[j - 1] =temp
            else
              break
            end
            j=j-1
        end
    end
    return arr
end

# Function: test_sorting_algos
# ----------------------
# Given the type of sort the user wants to run, executes the implementation of it and compares it with Ruby's .sort method. 
#
# Parameters: 
# sort_type: The type of sort chosen by the user.
def test_sorting_algos(sort_type)

    test_arr = Array[0, -42, 42, 133, 254, 5678, -1212, 20, 13, 3000, 6042, 10042, 99, -99, 43, 34, 7, 17, -23, -11]
    test_arr2 = test_arr
    # Perform the iterative search and calculate the time it took.
    t1 = Process.clock_gettime(Process::CLOCK_MONOTONIC)
    sorted = test_arr.sort
    t2 = Process.clock_gettime(Process::CLOCK_MONOTONIC) 
    delta_ruby = t2 - t1 # seconds

    case sort_type.downcase
    when "quick"
        t1 = Process.clock_gettime(Process::CLOCK_MONOTONIC)
        sorted = quick_sort(test_arr2, 0, test_arr2.length - 1)
        t2 = Process.clock_gettime(Process::CLOCK_MONOTONIC) 
    when "bubble"
        t1 = Process.clock_gettime(Process::CLOCK_MONOTONIC)
        sorted = bubble_sort(test_arr2)
        t2 = Process.clock_gettime(Process::CLOCK_MONOTONIC) 
    when "insertion"
        t1 = Process.clock_gettime(Process::CLOCK_MONOTONIC)
        sorted = insertion_sort(test_arr2)
        t2 = Process.clock_gettime(Process::CLOCK_MONOTONIC) 
    else
        puts "You didn't enter a valid sorting algorithm. Please try again."
        exit! 
    end
    delta_impl = t2 - t1 # seconds

    puts "Ruby's default sort method (which is an implementation of QuickSort) took #{delta_ruby * 1000} ms, whereas #{sort_type.downcase}sort took #{delta_impl * 1000}ms."
end

puts "Hello there! Please input 'quick' for quicksort, 'bubble' for bubblesort, or 'insertion' for insertion sort."
user_input = gets.chomp
test_sorting_algos(user_input)