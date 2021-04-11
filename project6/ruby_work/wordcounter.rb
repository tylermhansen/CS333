# Tyler Hansen, Sawyer Strong, Skye Rhomberg
# CS333 Spring 2021 -- Programming Languages
# 04/10/2021

# wordcounter.rb: A Ruby program that counts the number of occurences of each word in a given text file.

# If the user supplies a path when calling the program, then use that path. Otherwise, ask for one :)
if ARGV.length == 0
  puts "Please enter the path to a valid text file."
  path = gets.chomp
else
  path = ARGV[0]
end 

# Open the filereader with the path
f = File.open(path, "r")
# Create a hash object (stores key-value pairs, like a dictionary in Python)
h = Hash.new
# For each line... 
f.each_line { |line|
  #... convert it to downcase and strip it of special characters/punctuation...
  line = line.downcase.gsub(/[^a-z0-9\s]/i, '')
  #... split it into separate words...
  words = line.split
  #... now, for each word...
  words.each { |w|
  #... if the hash already contains the key...
    if h.has_key?(w)
      # ... update the count for that word...
      h[w] = h[w] + 1
    else
      #... otherwise, add it to the hash and make the count 1...
      h[w] = 1
    end
  }
}

# Sort the hash in descending order, then for each element (elem) print out the number of occurences
h.sort{|a,b| a[1]<=>b[1]}.reverse.each { |elem|
  printf "%-20s => %s\n", elem[0], elem[1]
}