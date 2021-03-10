# Tyler Hansen, Sawyer Strong, Skye Rhomberg
# CS333 Spring 2021 -- Programming Languages
# 03/9/2021

# task1.rb: demonstrates the rules for identifier naming, variable declarations and identifier scoping of the Ruby programming language.

# Define a global variable C
$C = 2.99e8

# Define a class "Exoplanet"
class Exoplanet
    # Define a class variable number_of_stars
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

# Define a class "Singularity"
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

# Print out the global variable in two different classes to see that it is the same.
alpha.print_C
beta.print_C

# Create a new Expoplanet object named alpha_two
alpha_two = Exoplanet.new(24, 999, "TIRED")

# Print out the class variable in two different objects represented by the same class to show that it is shared amongst instances.
alpha.add_star
alpha_two.add_star

puts "Alpha has distance of #{alpha.star_location} while AlphaTwo has distance of #{alpha_two.star_location}"












        
