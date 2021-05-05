/**
 * Test Go's Garbage Collection
 * Skye Rhomberg
 * CS333 Project 7
 * Spring 2021
 */

package main

import (
    "fmt"
    "time"
    )

type (
    kilo []byte;
    meg [1024]kilo;
    gig [1048576]kilo;
)

func mem_use(g *gig) time.Duration {
    start := time.Now()
    var worst, best time.Duration
    for i := 0; i < 1000000; i++ {
        k := make(kilo, 1024) // 1048576)
        for i := range k {
            k[i]='a'
        }
        (*g)[i%1048576] = k
        elapsed := time.Since(start)
        if elapsed > worst {
            worst = elapsed
        }
    }
    return worst
}

func main() {
    results := make([]time.Duration,100)
    var g gig
    for i, _ := range results {
        results[i] = mem_use(&g)
    }
    fmt.Println("Worst Times In Million-rep sets")
    fmt.Println(results)
}
