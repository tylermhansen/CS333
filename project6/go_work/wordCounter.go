/**
 * Go Word Counter
 * Skye Rhomberg
 * CS333 Project 6
 * Spring 2021
 */

package main

import (
    "os"
    "fmt"
    "regexp"
    "io/ioutil"
    //"net/http"
    "strings"
    "strconv"
    "sort"
)

/**
 * Errors are a built-in Go type
 * A simple construction like this simply
 * Prints the default error message for the type of error occurring
 */
func check(e error) {
    if e != nil {
        panic(e)
    }
}

// WordCount struct
type wc struct {
    Word string
    Count int
}

func main() {
    // Map String --> Int
    // Will Hold words and counts
    m := make(map[string]int);    
    // Take Filename from command-line
    a := os.Args[1:]
    if len(a) != 1 {
        fmt.Print("Usage: ./wordCounter <filename>")
        os.Exit(-1)
    }
    dat, err := ioutil.ReadFile(a[0])

    /*
    // Source words from url -- this URL will probably cause a panic due to
    // insecurity, but the functionality is there in Golang.
    resp, err := http.Get("https://cs.colby.edu/courses/S21/cs333/projects/wctest.txt")
    check(err)
    dat := make([]byte, resp.ContentLength)
    _, err = resp.Body.Read(dat) 
    check(err)
    */

    // Convert data from input []byte to properly formatted strings
    s := strings.ToLower(string(dat)) // lower-case
    t := regexp.MustCompile(`[[:space:][:punct:]]+`) // regex whitespace, punctuation
    v := t.Split(s,-1) // split on regex
    // Add each entry
    for _, w := range v {
        // Check for empty cut
        if w != "" {
            m[w] = m[w] + 1 // map access returns 0 when key not found
        }
    }

    // Turn map to list of wc structs
    var l []wc
    for w,c := range m {
        l = append(l, wc{w,c})
    }
    // Sort the list by count, descending
    sort.Slice(l, func(i, j int) bool {
        return l[i].Count > l[j].Count
    })

    // Take num top words from input
    fmt.Print("Number of Top Words to Print: ")
    var jin string
    fmt.Scanln(&jin)
    j, err := strconv.Atoi(jin) // convert input string to int
    check(err)
    // print top j words & their counts
    for i, wc := range l {
        if i < j {
            fmt.Printf("%-15s %d\n", wc.Word, wc.Count)
        }
    }
}

