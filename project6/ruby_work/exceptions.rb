# Tyler Hansen, Sawyer Strong, Skye Rhomberg
# CS333 Spring 2021 -- Programming Languages
# 04/10/2021

# exceptions.rb: A Ruby program that highights Ruby's wonderfully simple Error Handling protocols.

# One of my favorite aspects of the Ruby programming language is how easy it is to handle exceptions.
# The syntax is as follows: we enclose the code that could raise an exception in a begin/end block and use rescue clauses to tell Ruby the types of exceptions we want to handle.

begin
    # Exceptions raised by this code will 
    # be caught by the following rescue clause
 rescue
    # This block will capture all types of exceptions
 end

# For instance, let's try to open a non-existent file:
begin
    file = open("/nonexistentfile")
    if file
       puts "File opened successfully!"
    end
 rescue
       file = "\nFailed :(\n"
 end
 print file

 # Acknowledge that file printed as "Failed," so the code in rescue executed before ending. One awesome feature Ruby has is the retry keyword:
begin
    # Exceptions raised by this code will 
    # be caught by the following rescue clause
rescue
    # This block will capture all types of exceptions
    retry  # This will move control to the beginning of begin
end

fname = "nonexistentfile"
begin
    f = File.open(fname, "r")
    if f
       puts "\nFile #{f} opened successfully\n"
    end
rescue
    fname = "fileio.rb"
    retry
end

puts "\nThis time, we successfuly opened a file with the retry keyeod! Next, let's raise an excpetion:\n\n"

# We can also raise an exception ourselves:
begin  
    raise 'Exception raised: Tyler, Sawyer, and Skye\'s test exception.'  
 rescue Exception => e  
    puts e.message  
    puts e.backtrace.inspect  
 end  