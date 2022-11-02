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
        var x int64
        Fscan(input, &x)

        flg := false
        for i := int64(1); i <= 10000; i++ {
            rest := x - i*i*i
            pred := int64(Cbrt(float64(rest)))
            if pred >= 1 && pred*pred*pred + i*i*i == x {
                flg = true
                break
            }
        }

        if flg {
            Println("YES")
        } else {
            Println("NO")
        }
    }
}