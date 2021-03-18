/**
 * Go Function References
 * Skye Rhomberg, Tyler Hansen, Sawyer Strong
 * CS333 Project 4
 */

package main

import "fmt"

func times (i int, n int) int {
    return i * n
}
func plus(i int, n int) int {
    return i + n
}

// Go can create functions
func timesn(i int) (func(n int) (int)){
    return func (n int) (int) {
        return i*n
    }
}

// Functions as parameters
func combine(x int, y int, fn (func(x, y int) (int))) int {
    return fn(x,y)
}

func main() {
    i := 10
    n := 40
    fmt.Println(i,"times",n,"is",times(i,n))

    // Go can simply reassign names of functions
    times_alt := times
    fmt.Println(i,"times",n,"is",times_alt(i,n))

    // Functions can be returned
    times3 := timesn(3)
    fmt.Println(i,"times 3 is",times3(i))

    // Closures - don't have to name a function
    summand := 5
    func() {
        fmt.Println(summand,"+",summand,"=",summand+summand)
    }()

    // Passing functions as arguments
    x := 20
    y := 4
    fmt.Println(x,"plus",y,"is",combine(x,y,plus))
    fmt.Println(x,"times",y,"is",combine(x,y,times))
}
