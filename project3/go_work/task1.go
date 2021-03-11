/** 
 * Skye Rhomberg, Tyler Hansen, Sawyer Strong
 * CS333 Spring 2021
 * 03/11/21
 *
 * Task 1: Demonstrate Identifier Naming, Variable Declarations & Scooping in Go
 */

package main

import "fmt"

func main() {
    // Variable Declaration syntax: var *name* *type* = *value
    var pi float64 = 3.14159
    var e float64 = 2.71828
    fmt.Println("pi =",pi,"e =",e)
    // Multiple declartions are allowed
    var one, two, three int = 1, 2, 3
    fmt.Printf("%d(%T),%d(%T),%d(%T)\n",one,one,two,two,three,three)
    // Or with multiple types
    var num, str, chr = 1.0, "AAAA", 'B'
    fmt.Printf("Type of num is %T, type of str is %T, type of chr is %T\n", num, str, chr)

    // Alternatively, you can do declaration and assignment at once
    // Go will actually infer the type
    meaning_of_life := 42
    // Multiple assignments with type inference
    man, bear, pig := "man", 0xBEA4, "pig"
    fmt.Printf("man, 0xBEA4, pig: %T,%T,%T\n",man,bear,pig)

    // Go doesn't have any scope-specific keywords, thus variable scope is
    // purely based on location of declaration: global (with file scope) if outside
    // any functions, local if declared inside
    // Can't declare same variable in same scope, but like C, this is allowed:
    innerFunc()
    fmt.Println("The REAL (wider scope) answer is", meaning_of_life)

    // Go never has uninitialized variables. If no declaration is given,
    // They default to their "zero value"
    var zero int;
    var empty string;
    var zeroes float64;
    fmt.Println(zero,";",empty,";",zeroes)
}
// Inner function for variable scoping example
func innerFunc() {
    meaning_of_life := 43
    fmt.Println("The Answer is", meaning_of_life)
}
