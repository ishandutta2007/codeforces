package main

import (
    "bufio"
    "io"
    "os"
    . "fmt"
    // . "math"
)
var input io.Reader = bufio.NewReader(os.Stdin)

var a, ans []int
func find(l int, r int, dep int) {

    if l >= r {
        return
    }

    maxn, pos := 0, 0
    for i := l; i < r; i++ {
        it := a[i]
        if it > maxn {
            maxn = it
            pos = i
        }
    }

    // Println("maxn:", maxn)
    // Println("pos:", pos)

    ans[pos] = dep
    find(l, pos, dep + 1)
    find(pos + 1, r, dep + 1)
}

func main() {   
    var t int
    Fscan(input, &t)
    for i := 0; i < t; i++ {
        var n int
        Fscan(input, &n)
        a = make([]int, n)
        ans = make([]int, n)
        for i := 0; i < n; i++ {
            Fscan(input, &a[i])
        }
        find(0, n, 0)
        for _, it := range(ans) {
            Print(it, " ")
        }
        Println()
    }
}