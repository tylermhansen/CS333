# Tyler Hansen, Sawyer Strong, Skye Rhomberg
# CS333 Spring 2021 -- Programming Languages
# 03/9/2021

# task2.rb: demonstrates an implementation on binary search in the Ruby programming language.
# Usage: ruby task2.rb d arr, ex. ruby task2.rb 42 1 2 3 4 5 6


# Function: bin_search
# ----------------------
# Performs an iterative binary search for the element d in array arr.
#
# Parameters: 
# d - the element to search for
# arr - the array of elements in which we wish to search for d.
def bin_search(d, arr)
    middle = arr.length / 2
    i = 0
    j = arr.length - 1
  
    while i < j
      if arr[middle] == d
        return true
      elsif arr[middle] < d
        i = middle + 1
        middle = i + j / 2
      else
        j = middle - 1
        middle = i + j / 2
      end
    end
    return false
end 

# Function: recursive_bin_search
# ----------------------
# Performs a recursive binary search for the element d in array arr.
#
# Parameters: 
# d - the element to search for
# arr - the array of elements in which we wish to search for d.
def recursive_bin_search(d, arr, first = 0, last=arr.size-1)
    middle = (first + last) / 2
    case arr[middle] <=> d
    when  0  # arr[middle] == d
      return true
    when -1  # arr[middle] < d
      first = first + 1
      return recursive_binary_search(arr, target, first, last)
    when  1  # arr[middle] > d
      last = last - 1
      return recursive_binary_search(arr, target, first, last)
    end
  end

# Save d to a separate variable user_d, and keep the rest of the command line arguments in user_arr. Ruby is so nice in this way!
user_d, *user_arr = ARGV

# Perform the iterative search and calculate the time it took.
t1 = Process.clock_gettime(Process::CLOCK_MONOTONIC)
iterative = bin_search(user_d, user_arr)
t2 = Process.clock_gettime(Process::CLOCK_MONOTONIC) 
delta1 = t2 - t1 # seconds

# Perform the recursive search and calculate the time it took. 
t3 = Process.clock_gettime(Process::CLOCK_MONOTONIC)
recursive = recursive_bin_search(user_d, user_arr)
t4 = Process.clock_gettime(Process::CLOCK_MONOTONIC)
delta2 = t4 - t3 # seconds

puts "Iterative binary search returned #{iterative} in #{delta1 * 1000} ms"
puts "Recursive binary search returned #{recursive} in #{delta2 * 1000} ms"