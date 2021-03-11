/** 
 * Skye Rhomberg, Tyler Hansen, Sawyer Strong
 * CS333 Spring 2021
 * 03/11/21
 *
 * Task 3: Data Typing 
 */

package main

import "fmt"

// A struct and an associated method
type Person struct {
    name string
    age int
    hometown,homestate string
}
func(p Person) identify() {
    fmt.Printf("This is %s (age %d) from %s, %s\n",p.name,p.age,p.hometown,p.homestate)
}

// Structs can be "embedded"
// a sort of inheritance
type Student struct {
    Person
    major string
    year int
}

// The last of the 4 major classes of types is the interface type
type Intros interface{
    identify()
    details()
}
func (s Student) details() {
    fmt.Printf("%s is a %s major in the class of %d\n",s.name,s.major,s.year)
}
func main() {

    // Go has 4 levels of built-in types:

    // The first are primitives, like numeric and string types
    // The second are "aggregate" types like structs and arrays,
    // Which are stored as contiguous blocks of memory
    float_array := [3]float64{-1.23,4.56,7.89}
    // Float array
    fmt.Println("Array of floats:",float_array)

    // Slices are reference data types, i.e. they are mutable,
    // Unlike arrays which are IMMUTABLE
    // Notice also how interchangeable ints and runes are: they are aliases for one another
    // Runes are unicode chars, bytes are smaller (short for int8)
    some_ints := []int32{'A','l','a','n'}
    some_runes := []rune{0x0041,0x006C,0x0061,0x006E}

    // Strings in Go are actually also immutable, but they
    // are basically just slices of bytes or runes made immutable
    a_string := "Alan"

    // Booleans are true or false, 1-bit
    bool1 := string(some_runes) == a_string
    bool2 := a_string == string(some_ints)

    // Comparison of various types in slices with strings
    fmt.Printf("string(Runes(%T)) = String(%T):%t (%T)\n",some_ints,some_runes,bool1,bool1)
    fmt.Printf("String(%T) = string(Ints(%T)):%t (%T)\n",some_ints,some_runes,bool2,bool2)
    fmt.Println("Ints as string:",string(some_ints))

    // Structs can have methods associated with them, as declared above
    skye := Person{name: "Skye", age: 20, hometown: "Brattleboro", homestate: "VT"}
    skye.identify()
    
    // Some pseudo-inheritance
    student_x := Student{skye, "CS", 2022}
    student_x.details()

    // Go is strongly typed, and thus the operators apply very narrowly
    // This will be integer division
    t := (34 - 1) / 2 * 7
    // Go can mix ints and floats and produce a float output
    s := (34 - 1) % 2 * 7.5

    // We can use addition for string concatenation, even though strings are immutable
    // this would throw an error: ss[1]='C'
    ss := "AAAA " + "BBBB"
    // We also can't do this: st := "A" * 10

    fmt.Printf("t - %d: %T, s - %f: %T\n",t,t,s,s)
    fmt.Println(ss)
}


