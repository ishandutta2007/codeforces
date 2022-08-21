package main

import (
	"fmt"
    "os"
    "io"
    "bufio"
    "strconv"
    //"strings"
)

const MN = 20
const INF = 1e9+100
var a, ab [1<<MN]uint
var num [MN+1][2]int64

func merge(l, r, k int) {
    if r - l == 1 {
        return
    }
    md := (l+r)/2
    merge(l, md, k-1)
    merge(md, r, k-1)
    u1, u2 := int64(0), int64(0)
    l1, l2 := l, md
    for i := l; i < r; i++ {
        var d1, d2 uint
        if (l1 < md) {
            d1 = a[l1]
        } else {
            d1 = INF
        }
        if (l2 < r) {
            d2 = a[l2]
        } else {
            d2 = INF
        }
        if (d1 <= d2) {
            ab[i] = d1
            l1++
        } else {
            ab[i] = d2
            l2++
            u1 += int64(md - l1)
        }
    }
    l1, l2 = l, md
    for i := l; i < r; i++ {
        var d1, d2 uint
        if (l1 < md) {
            d1 = a[l1]
        } else {
            d1 = INF
        }
        if (l2 < r) {
            d2 = a[l2]
        } else {
            d2 = INF
        }
        if (d1 < d2) {
            l1++
            u2 += int64(r - l2)
        } else {
            l2++
        }
    }
    copy(a[l:r], ab[l:r])
    num[k][0] += u1
    num[k][1] += u2

}

func getUint(b io.ByteReader) uint {
	d := uint(0)
	var c byte
	for {
		c, _ = b.ReadByte()
		if (c != ' ' && c != '\n'){
			break
		}
	}
	for {
		c -= '0'
		if 0 <= c && c <= 9 {
			d *= 10
			d += uint(c)
		} else {
			return d
		}
		c, _ = b.ReadByte()
	}
}

func main() {
	inS := bufio.NewReader(os.Stdin)
	ouS := bufio.NewWriter(os.Stdout)
	defer ouS.Flush()
    var n uint
    fmt.Fscanf(inS, "%d\n", &n)
//    n = getUint(inS)
    for i := uint(0); i < 1<<n; i++ {
    	fmt.Fscanf(inS, "%d", &a[i])
//    	a[i] = getUint(inS)
    }
    fmt.Fscanf(inS, "\n")
    var m uint
    fmt.Fscanf(inS, "%d\n", &m)
//    m = getUint(inS)
    q := make([]uint, m)
    for i := uint(0); i < m; i++ {
	    fmt.Fscanf(inS, "%d", &q[i])
//    	q[i] = getUint(inS)
    }
    fmt.Fscanf(inS, "\n")
    merge(0, 1<<n, int(n));
    for _, p := range q {
        for j := uint(1); j <= p; j++ {
            e := num[j][0]
            num[j][0] = num[j][1]
            num[j][1] = e
        }
        r := int64(0)
        for _, v := range num[:] {
            r += int64(v[0])
        }
        ouS.WriteString(strconv.FormatInt(r, 10))
        ouS.WriteByte('\n')
    }
}