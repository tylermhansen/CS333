# Tyler Hansen, Sawyer Strong, Skye Rhomberg
# CS333 Spring 2021 -- Programming Languages
# 03/14/2021

# task1.rb: Demonstrates all of the control flow statements that Ruby provides.

# Require Ruby's built-in prime checking.
require 'prime'

# Ask the user for an integer.
puts "Please enter an integer :)"
x =  gets.chomp

# If...else statement (common)
if (x.to_i % 2 == 0)
    puts "Even!"
else 
    puts "Odd!"
end

# If modifier: executes code in front of it if the expression evaluates to true
puts "Wow! You entered a prime number. Look at you go!" if Prime.prime?(x.to_i)

# Unless statement:
# unless conditional [then]
#     code
#  [else
#     code ]
#  end
# Executes code if conditional is false. If the conditional is true, code specified in the else clause is executed.
unless x.to_i == 42
    puts "The number you entered is not the answer to life, the universe, and everything."
  else
    puts "Wow... you have entered the answer to life, the universe, and everything. This computer is graced by your presence."
 end

puts "What's your favorite integer?"
y = gets.chomp.to_i

# Unless modifier: executes code in front of it if the expression evaluates to false
puts "Ahh, shame. My favorite number is not #{y}, but that is a cool one." unless y == 207

# Case statement:
case y
when 0 .. 9
   puts "Fun fact: Americans generate 4.4 pounds of trash per day."
when 10 .. 74
   puts "Fun fact: more than 10 people a year are killed by vending machines."
when 75 .. 91
   puts "Fun fact: McDonald's sells 75 burgers per second."
when 92 .. 100
   puts "Fun fact: Mcdonald's Sells 92lbs of fries per second."
else
   puts "Fun fact: In the U.S., 1,700 people become millionaires every day."
end
