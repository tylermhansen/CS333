/** 
 * Skye Rhomberg, Tyler Hansen, Sawyer Strong
 * CS333 Spring 2021
 * 03/11/21
 *
 * Task 2: Binary Search 
 */
package main

import (
    "fmt"
    "sort"
)

func main() {
    arr := []int{3,7,8,14,56,90,91}
    fourteen := binary_search(arr,len(arr),14)
    ninety_one := binary_search(arr,4,91)
    fmt.Println("14 in arr?",fourteen)
    fmt.Println("91 in first half of arr?",ninety_one)
    // Go's built-in binary search returns index where
    // missing elements would go.
    thirty_three := sort.SearchInts(arr,33)
    fmt.Println("Built-in Search for 33 (Shows where it *would* go)",thirty_three)
}

// Modeled on Wikipedia's pseudocode
// Takes sorted int slice to search, 
// int for right-size idx (usually length of arr),
// int for search target
// returns idx of T in A[:n] or -1 if it's not present
func binary_search (A []int, n int, T int) int {
    L := 0
    R := n - 1
    // Go doesn't have while loops: just use for
    for L <= R {
        m := (L + R) / 2
        if A[m] < T {
            // Too low!
            L = m + 1
        } else if A[m] > T {
            // Too High!
            R = m - 1
        } else {
            // Match!
            return m
        }
    }
    return -1
}
