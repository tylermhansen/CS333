/**
 * Go Linked List Test Function
 * Skye Rhomberg, Tyler Hansen, Sawyer Strong
 * CS333 Project 5
 * Spring 2021
 */

package main

import (
    "fmt"
    "proj5_tests/mylists"
)

/*
 * Test functions
 * Using general Data type
 * defined in mylists as interface{}
 * Type asserting back go int as needed
 */
func PrintVal(i *mylists.Data) {
    fmt.Println("val:",*i)
}
func SquareInt(i *mylists.Data) {
    *i = (*i).(int) * (*i).(int)
}
func cmpInt(i, j mylists.Data) int {
    return i.(int) - j.(int)
}

func main() {
    fmt.Println("Go Linked List Tests")
    l := mylists.NewSLList()
    fmt.Println("Pushing 3...")
    l.Push(3)
    fmt.Println("Pushing 4...")
    l.Push(4)
    fmt.Println("Appending 2...")
    l.Append(2)
    fmt.Println("After Pushes and Appends:")
    l.Map(PrintVal)
    l.Map(SquareInt)
    fmt.Println("After Squaring:")
    l.Map(PrintVal)
    fmt.Println("Removing 9:",l.Remove(9,cmpInt))
    fmt.Println("After Removing 9:")
    l.Map(PrintVal)
    fmt.Println("Size:",l.GetSize())
    l.Insert(1,9)
    fmt.Println("After Re-inserting 9 at index 1:")
    l.Map(PrintVal)
    fmt.Println("Delete 1:",l.Delete(1))
    fmt.Println("After Delete:")
    l.Map(PrintVal)
    fmt.Println("Pop:",l.Pop())
    fmt.Println("Pop:",l.Pop())
    fmt.Println("After Pops:")
    l.Map(PrintVal)
    fmt.Println("Size:",l.GetSize())
    fmt.Println("Appending...")
    for i := 0; i < 10; i++ {
        fmt.Printf("%d, ",i)
        l.Append(i)
    }
    fmt.Println("")
    fmt.Println("After Appending:")
    l.Map(PrintVal)
    fmt.Println("Size:",l.GetSize())
    l.Clear()
    fmt.Println("After Clearing")
    l.Map(PrintVal)
    fmt.Println("Size:",l.GetSize())
}
