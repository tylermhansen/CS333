# Tyler Hansen, Sawyer Strong, Skye Rhomberg
# CS333 Spring 2021 -- Programming Languages
# 03/31/2021

# testll.rb: Test file for the linked list data structure. Tests each method.

# require "rgl"
require_relative 'linked_list'

# Initialize a linkedlist with values 0-20. 
puts "Before Initialization"
l = LinkedList.new()
puts "After Initialization"
for i in 0..20
    l.push(i)
end
puts "After pushing 0-20:"
l.pretty_print

puts "At this point, the size of the LinkedList is #{l.length}"

l.remove(13)

puts "After removing 13:"

l.pretty_print

puts "After popping #{l.pop.data}, got:"

l.pretty_print

l.append(42)

puts "After appending 42, got:"

l.pretty_print

puts "At this point, the size of the LinkedList is #{l.length}"

l.clear

puts "After clearing, the linked list is:"

l.pretty_print

puts "At this point, the size of the LinkedList is #{l.length}"



