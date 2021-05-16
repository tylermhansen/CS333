module ParallelMergeSort
    # Define a Ruby module "merge sorted," and then send it to the definition of an array such that Arr.merge_sorted correctly returns the array after a multithreaded merge sort
    def merge_sorted
      return self if size <= 1
  
      split_idx = size / 2
  
      # Divide into sub-arrays and different threads, rescursively call down until the subarrays are of size 1.
      sub_a, sub_b = [
          Thread.new { self.slice(0, split_idx).merge_sorted },
          Thread.new { self.slice(split_idx, self.size - split_idx).merge_sorted }
      ].map(&:join).map(&:value)
  
      # Compile subarrays back together and join threads back together

      # Initialize an array
      array = self.class.new
      ptr_a, ptr_b = [0, 0]
  
      # Merging logic
      while ptr_a < sub_a.size && ptr_b < sub_b.size
        a, b = sub_a[ptr_a], sub_b[ptr_b]
  
        if a <= b
          array << a
          ptr_a += 1
        else
          array << b
          ptr_b += 1
        end
      end
  
      while ptr_a < sub_a.size
        array << sub_a[ptr_a]
        ptr_a += 1
      end
  
      while ptr_b < sub_b.size
        array << sub_b[ptr_b]
        ptr_b += 1
      end
  
      array
    end
  end

  Array.send(:include, ParallelMergeSort)

  arr = Array.new(20) { rand(1...20) }

  puts "Original array is #{arr}"

  puts "Sorted array is #{arr.merge_sorted}"