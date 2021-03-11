# Tyler Hansen, Sawyer Strong, Skye Rhomberg
# CS333 Spring 2021 -- Programming Languages
# 03/9/2021

# task3.rb: Demonstrates all of the basic built-in types and how to construct aggregate types. 
#           Demonstrates which of the standard suite of operators (+-/*%) manipulate which types and what the resulting type of each operation is.

# Define two constants MISSION_CONTROL and Vessel. In Ruby, constants start with capital letters. Also note that Ruby is dynamically-typed!
MISSION_CONTROL = "Houston"
Vessel = "SpaceX Dragon"

# Define a global variable C. In Ruby, a global variable starts with a dollar sign $.
$C = 2.99e8

# Define a class "Exoplanet"; this is how we construct aggregate types in Ruby.
class Exoplanet
    # Define a class variable number_of_stars. In Ruby, class variables start with two "at" signs @@.
    @@number_of_stars = 41 

    # Function: initialize
    # ----------------------
    # Sets the instance variables star_size, star_location, and star_id to the appropriate function parameters.
    #
    # Parameters: 
    # size - the size of the star
    # location - the distance from Earth to the star 
    # id - the unique id of the star
    def initialize(size, distance, id)
        @star_size = size
        @star_location = distance
        @star_id = id
    end 

    # Function: print_C
    # ----------------------
    # Simply prints out the value of the global variable C to show that it is the same across two classes.
    def print_C
        puts "Global variable C in Exoplanet class has value #$C"
    end

    # Function: add_star
    # ----------------------
    # Increments the number of stars for the Exoplanet class. Used in a demonstration of a class variable.
    def add_star
        @@number_of_stars += 1
        puts "Afer adding one, Exoplanet class variable number_of_stars has value #@@number_of_stars"
    end

    # Function: attr_reader
    # ----------------------
    # In Ruby, if you want to access an instance variable, you cannot do so with something like object.var; instead, you need to define readers/writters/accessors.
    # Here, we define a reader, so the variables cannot be edited externally but can be retrieved.
    attr_reader :star_size, :star_location, :star_id
end

# Define a class "Singularity"; this is how we construct aggregate types in Ruby.
class Singularity
    # Define a class variable photos_captured
    @@photos_captured = 0

    # Function: initialize
    # ----------------------
    # Sets the instance variables singularity_mass, singularity_location, and singularity_id to the appropriate function parameters.
    #
    # Parameters: 
    # size - the size of the black hole
    # location - the distance from Earth to the singularity 
    # id - the unique id of the singularity
    def initialize(size, distance, id)
        @singularity_mass = size
        @singularity_location = distance
        @singularity_id = id
    end 

    # Function: print_C
    # ----------------------
    # Simply prints out the value of the global variable C to show that it is the same across two classes.
    def print_C
        puts "Global variable C in Singularity class has value #$C"
    end
end

# Create a new Exoplanet object named alpha
alpha = Exoplanet.new(4242, 10000000, "SLATFATF")

# Create a new Singularity object named beta
beta = Singularity.new(420000000, 22222, "DFTBAT")

# In Ruby, there are Numbers, Booleans, Strings, Hashes, Arrays, and Symbols. Every data type is based on a class as Ruby is a pure Object-Oriented language. 

# Ruby can handle both integers...
astronauts_aboard = 7

# ... and floats...
average_age = 26.42

# Ruby, like most languages, supports strings...
statement = "This is a neat string! This time I'm using double quotes, but single quotes work too.\n"
print statement

print "--------------\n"

# Ruby has booleans that present one bit (true or false): 
if true
    puts "true is True!"
  else
    puts "true is False!"
  end
    
  if nil
    puts "nil is True!"
  else
    puts "nil is False!"
  end
    
  if 0
    puts "0 is True!"
  else
    puts "0 is False!"
  end

  if 1 
    puts "1 is True!"
  else
    puts "1 is False!"
  end

# Note that there is no inherent "truth" to 0 or 1 as integers. 

print "--------------\n"

# Ruby also supports "hashes," which holds key-value pairs like a dictionary in Python. 
hsh = colors = { "green" => 0x0f0, "red" => 0xf00, "blue" => 0x00f } 
hsh.each do |key, value| 
    print key, " is ", value, "\n"
end

print "--------------\n"

# Ruby has arrays, which we are quite familiar with: 
arr = [ "I'm the first element!", "This", "is", "an", "array", "with numbers too", 3.14, "I'm the last element of the array!" ] 
arr.each do |i| 
    puts i 
end

print "--------------\n"

# Lastly, Ruby has a data type called a "symbol," which are light-weight strings. A symbol is preceded by a colon (:). 
# They are used instead of strings because they can take up much less memory. Symbols have better performance.
symbs = {:tk => "Take a break!", :dw => "Do some work!", :gs => "Go to sleep!"} 
  
puts symbs[:tk] 
puts symbs[:dw] 
puts symbs[:gs] 

print "--------------\n" 

# Just like python, we can use + for both addition and concatenation: 
puts "Addition in ruby looks like #{astronauts_aboard + average_age}\n"
puts "Cheeky " + "Concatentation"

# We also have subraction, division, multiplication, and modulo (remainder):
puts 42 - 21
puts 42 / 21
puts 42 * 21
puts 42 % 9

# If we do any of these operations with an integer and a float, the result is a float.
puts 42 - 21.0






