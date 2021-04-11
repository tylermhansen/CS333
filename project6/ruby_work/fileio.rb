# Tyler Hansen, Sawyer Strong, Skye Rhomberg
# CS333 Spring 2021 -- Programming Languages
# 04/10/2021

# fileio.rb: A Ruby program that demonstrates the File input/output system of the language. 

require 'open-uri' # Built-in Ruby module to open web files

# Function: translate()
# ----------------------
# Parameters: 
# sent -- a sentence to translate to pig latin.
# Shoutout to user "Trey Terrell" on StackOverflow for this function; all credit goes to them for this function, I'm merely using it to demonstrate Ruby's powerful file reading capabilities. 
def translate(sentence)
    sentence.split(" ").map do |word|
      word = word.gsub("qu", " ")
      word.gsub!(/^([^aeiou]*)(.*)/,'\2\1ay')
      word = word.gsub(" ", "qu")
      return word
    end
  end

puts "In Ruby, there are many ways to open files -- including binary files types! There are two different ways to open a file:\n
f = File.new(\"fileName.rb\", \"mode\")\n
...and...\n
File.open(\"fileName.rb\", \"mode\" do |f|"

puts "\nWe can use gets.chomp to take in the next value from the command line. Please, enter a file path to a LOCAL text file:"

path = gets.chomp

f = File.open(path, "r")

puts "I used the second option here to read the file. Now that I've read in your text file using mode \"r,\" I have access to a ton of convenient methods, such as one that allows me to iterate through each line. I'm going to translate your file into Pig Latin now."

out = File.open("pig_latinized.txt", "w") do |out|
    f.each_line { |line|
        words = line.split
        #... now, for each word...
        words.each { |w|
            out.write(translate(w).gsub(/[^a-z0-9\s]/i, '') + " ")
        }
    }
end

puts "Check the directory. There should be file called pig_latinized.txt that I wrote to using Ruby's File I/O. Open it up and check it out!"

URI.open("https://s3.amazonaws.com/com.twilio.prod.twilio-docs/images/test.original.jpg") do |image|
    File.open("./rickrolled.jpg", "wb") do |file|
      file.write(image.read)
    end
  end

puts "... You might also notice another file, this time a jpg. I used Ruby's standard open-uri module to save an image from the internet into this directory. Open it up :)"

puts "As you can see, Ruby is well-equipped to handle I/O. The user can interacively input information into a Ruby script, and the files are not limited to non-binary types. URLs containing file locations also work."



