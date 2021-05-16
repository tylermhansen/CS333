# Tyler Hansen, Sawyer Strong, Skye Rhomberg
# CS333 Spring 2021 -- Programming Languages
# 05/14/2021

# colorize.rb: A Ruby program that demonstrates the image processing capabilities of Ruby 

require 'pnm'

def run(sa)
    for i in range(0, sa.len) do
		sa[i] = sa[i] > 128 ? (220+src[i].r)/2 : (30+src[i].r)/2;
		sa[i + 1] = sa[i] > 128 ? (220+src[i].g)/2 : (30+src[i].g)/2;
		sa[i + 2] = sa[i] > 128 ? (220+src[i].b)/2 : (30+src[i].b)/2;
	end
end

puts "Please enter the filename of the image you wish to colorize."
filename = gets.chomp
image = PNM.read(filename)

image.pixels.each do |sub_array|
    Thread.new {run(sub_array)}
end

# create the image object
out_image = PNM.create(image.pixels)
out_image.write("test.ppm")
