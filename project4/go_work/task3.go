/**
 * General Sort in Go
 * Skye Rhomberg
 * CS333 Project 4
 * Spring 2021
 */

package main

import (
    "fmt"
    "math/rand"
    // "sort"
    "time"
)

// Generate a random array of given size
// Ints between -100 and 100
func makeArray(size int) []int{
    ary := make([]int, size)

    for i := 0; i <= size-1; i++ {
        ary[i] = rand.Intn(200) - 100
    }

    return ary
}

// Go isn't great about polymorphism
// It doesn't have generic types
// We can get around this by using the general interface type and 
// Having the user pass in a comparator function, the size, and a swap function
func mySort(ary interface{}, cmp func(i, j int) bool, size int, swap func(i, j int)) {
    for i:=0; i < size; i++ {
        for j:=0; j < size-i-1; j++ {
            if !cmp(j,j+1) {
                swap(j,j+1)
            }
        }
    }
}

func main() {
    // Seed random number generator
    rand.Seed(time.Now().UnixNano())
    size := 100
    ary := makeArray(size)
    // Print array for testing
    for _, val := range ary {
        fmt.Printf("%d ",val)
    }
    fmt.Println("\n")
    // Sort array
    mySort(ary, func (i, j int) bool { return ary[i] < ary[j] }, len(ary), func(i, j int) { ary[i], ary[j] = ary[j], ary[i]})
    // Print sorted array
    for _, val := range ary {
        fmt.Printf("%d ",val)
    }
    fmt.Println("")

    /* Note: go has a built-in sort library which gets around some of this
     * need for declaring the functions --> it finds a way to define array size
     * and swapping, and only requires a comparator
     */
    //sort.Slice(ary, func (i, j int) bool { return ary[i] < ary[j] })
}
