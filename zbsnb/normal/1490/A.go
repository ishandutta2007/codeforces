package main

import (
    "bufio"
    "io"
    "os"
    . "fmt"
    . "math"
)
var input io.Reader = bufio.NewReader(os.Stdin)
func main() {
    var t int
    Fscan(input, &t)
    for i := 0; i < t; i++ {
        var n int
        Fscan(input, &n)
        a := make([]float64, n)

        ans := 0
        for i:= 0; i < n; i++ {
            Fscan(input, &a[i])
            if i != 0 && a[i-1] != a[i] {
                ans += int(Ceil(Log2(Max(a[i-1], a[i]) / 
                        Min(a[i-1], a[i])))) -1
            }
        }
        Println(ans)
    }
}