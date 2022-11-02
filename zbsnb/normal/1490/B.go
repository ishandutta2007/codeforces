package main

import (
    "bufio"
    "io"
    "os"
    . "fmt"
    // . "math"
)
var input io.Reader = bufio.NewReader(os.Stdin)
func main() {
    var t int
    Fscan(input, &t)
    for i := 0; i < t; i++ {
        var n int
        Fscan(input, &n)
        a := make([]int, n)

        ans := 0
        x := make([]int, 3)
        for i := 0; i < n; i++ {
            Fscan(input, &a[i])
            x[a[i]%3] ++
        }
        
        // for i := 0; i < 3; i++ {
        //     Print(x[i], " ")
        // }
        // Println()

        for i := 0; i < 2; i++ {
            for j := 0; j < 3; j++ {
                if x[j] > n / 3 {
                    ans += x[j] - n / 3
                    x[(j + 1) % 3] += x[j] - n / 3
                    x[j] = n / 3
                }
            }
        }
        Println(ans)
    }
}