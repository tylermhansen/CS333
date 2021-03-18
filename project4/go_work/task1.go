/**
 * Go Control Flow Statements
 * Skye Rhomberg, Tyler Hansen, Sawyer Strong
 * CS333 Project 4
 */

package main

import "fmt"

func main() {
    // Go has C-like if statements
    var num int;
    num = 42;
    if num != 42 {
        fmt.Println(num, "isn't the meaning of life!")
    } else {
        fmt.Println(num, "is the answer to the ultimate question!")
    }

    // Can also use Go's short assignment
    if n := 333 * 2; n == 666 {
        fmt.Println("Devil's Number!")
    }

    // Go has for loops
    // Like C, any of the statements can be blank
    fact := 6
    out := 1
    for i:=1; i <= fact; i++ {
        out *= i
    }
    fmt.Println(fact, "factorial is", out)

    // This flexibliity is leveraged to make while loops
    // The while keyword doesn't actually exist in Go
    suma := 1
    for ; suma < 1000; {
        suma += suma
    }
    sumb := 1
    for sumb < 1000 {
        sumb += sumb
    }
    fmt.Println("suma == sumb?",suma==sumb)

    // Potentially Infinite loop
    // Also, Go has break statements
    var in string
    for {
        in = ""
        fmt.Println("Hit enter to continue")
        fmt.Scanln(&in)
        if in == "" {
            break
        }
    }

    // Go has python-like iteration over iterable objects, which C lacks
    var majors = map[string]string{"Skye":"CS/Math","Tyler":"CS/Physics","Sawyer":"CS/Economics"}
    for person, major := range majors {
        fmt.Println(person,"is majoring in",major)
    }
    // The enumerate() behavior in Python can also be captured
    primes := [6]int{2, 3, 5, 7, 11, 13}
    for i, val := range primes {
        fmt.Printf("%dth prime: %d\n",i,val)
    }
    // To leave off the indexing, use the blank variable _
    primes2 := [6]int{2, 3, 5, 7, 11, 13}
    fmt.Println("First 6 primes:")
    for _, val := range primes2 {
        fmt.Println(val)
    }

    // Go also has switch statements like in Java
    cn := 67
    nm := cn % 7

    switch nm {
        case 0:
            fmt.Println(cn,"mod 7 is 0")
        case 1:
            fmt.Println(cn,"mod 7 is 1")
        case 2:
            fmt.Println(cn,"mod 7 is 2")
        case 3:
            fmt.Println(cn,"mod 7 is 3")
        case 4:
            fmt.Println(cn,"mod 7 is 4")
        case 5:
            fmt.Println(cn,"mod 7 is 5")
        case 6:
            fmt.Println(cn,"mod 7 is 6")
    }

}

