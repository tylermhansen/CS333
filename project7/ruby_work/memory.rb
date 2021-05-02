# Tyler Hansen, Sawyer Strong, Skye Rhomberg
# CS333 Spring 2021 -- Programming Languages
# 05/01/2021

# memory.rb -- An exploration of memory management in Ruby.

# Ruby uses garbage collection. It's very pythonic; it does not require you to manage memory
# at all. There is a gem, however, called jemalloc that gives you more comtroll over the malloc
# calls underneath the top-level.

# Since everything in Ruby is an object, Ruby garbage collection is all about object management. 
# Ruby pre-allocates thousands of objects to have them ready when you need them. 
# This is called the “free list.”

# To free up the memory used by an object, Ruby first has to make sure that the object is no 
# longer needed. It does this in multiple passes. In the “mark” phase, Ruby crawls through all 
# the objects and marks the ones that are still in use. It does this by toggling a flag in a free 
# bitmap. Next comes the “sweep” phase. Ruby goes through all the objects again, cleans up the 
# unmarked objects, and returns them to the free list. It does this by just manipulating pointers, 
# so it’s pretty fast.

# While garbage collection happens in the background in Ruby, we can also access it manually 
# and conduct a thorough analysis/exploration:

# GC = Garbage Collection
GC.start # Start the Garbage Collector 
before = GC.stat(:total_freed_objects) # Measure how many objects have been freed thus far

# Retain 100000 objects
RETAINED_OBJECTS = []
100_000.times do
  RETAINED_OBJECTS << "Some String"
end

GC.start # Start Garbage Collection Again
after = GC.stat(:total_freed_objects) # Measure how many objects have been freed now

# Output number of objects freed after the 100000x loop (calculate delta).
puts "Objects Freed when retaining the objects: #{after - before}" 


GC.start # Start the Garbage Collector 
before = GC.stat(:total_freed_objects) # Measure how many objects have been freed thus far

# Now, don't retain any objects; just reassign the same message
100_000.times do
  foo = "Some String"
end
GC.start # Start Garbage Collection Again
after = GC.stat(:total_freed_objects) # Measure how many objects have been freed now

# Output number of objects freed after the 100000x loop (calculate delta).
puts "Objects Freed when just reassigning: #{after - before}" 


