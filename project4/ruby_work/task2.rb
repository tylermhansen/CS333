# Tyler Hansen, Sawyer Strong, Skye Rhomberg
# CS333 Spring 2021 -- Programming Languages
# 03/14/2021

# task2.rb: Demonstrates how Ruby handles functions as data types.

# Require the HTTP gem:
require "http"

# I decided to use this as an opportunity to clean up my dog fact gejerator ode from week 2. 

# Here, I am saving a function to a variable without calling that function. 
dogfact = lambda {HTTP.get("https://dog-facts-api.herokuapp.com/api/v1/resources/dogs?number=1").to_s}
# Here, I am doing the same thing, and notice that I am actually using the variable saved in the line above when the function saved to parse_dogfact is called.
parse_dogfact = lambda {JSON.parse(dogfact.call, object_class: OpenStruct)}

# Loop until the user doesn't want anymore dogfacts.
loop do
    parsed_fact = parse_dogfact.call
    puts "Here is your random dog fact: \n" + parsed_fact[0].fact
    puts "Would you like another fact? If so, type \"Y\" and hit enter. If not, type anything to continue the program."
    user_input = gets.chomp
    if user_input != "Y"
        break
    end
end

# Use blocks to pass functions around as it is faster than the .call syntax.
# Function: do_something
# ----------------------
# A boilerplate function that simply yields to another function that is passed into it.
def do_something
    puts "I've passed a function into this block."
    yield
end 

# Function: say_goodbye
# ----------------------
# Simply prints out a thank-you goodbye message to the user.
def say_goodbye 
    puts "Thanks for running the program! This function was passed into a block using the yield keyword."
end

# This is how you execute the function using the reference.
do_something(){say_goodbye}

