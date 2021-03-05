# Tyler Hansen, Sawyer Strong, Skye Rhomberg
# CS333 Spring 2021 -- Programming Languages
# 03/4/2021

# dogfact.rb: Generates as many random dog facts as the user wants! 

# Require the HTTP gem:
require "http"

loop do 
    # Send a GET request to the Dog Facts API (https://github.com/DukeNgn/Dog-facts-API)
    response = HTTP.get("https://dog-facts-api.herokuapp.com/api/v1/resources/dogs?number=1").to_s
    # Parse the JSON object that gets returned into a Ruby object named "dogfact"
    dog_fact = JSON.parse(response, object_class: OpenStruct)
    # Access the returned dog fact in the "dog_fact" object:
    puts "Here is your random dog fact: \n" + dog_fact[0].fact
    puts "Would you like another fact? If so, type \"Y\" and hit enter. If not, type anything."
    user_input = gets.chomp
    if user_input != "Y"
        break
    end
end