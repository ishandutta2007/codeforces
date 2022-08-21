package main

import (
	"fmt"
//    "os"
//    "bufio"
    "strconv"
    "strings"
)
const MN = 5100
const INF = 1e8
func main() {
	var n, m int
	var b, l, r, d [MN]int64
	fmt.Scanln(&n, &m)
	for i := 0; i < m; i++ {
		fmt.Scanln(&b[i], &l[i], &r[i], &d[i])
		l[i]--
	}

	var u [MN]int64
	for i := 0; i < n; i++ {
		u[i] = INF
	}

	for i := m-1; i >= 0; i-- {
		if b[i] == 1 {
			for j := l[i]; j < r[i]; j++ {
				u[j] -= d[i]
			}
		} else {
			for j := l[i]; j < r[i]; j++ {
				if d[i] < u[j] {
					u[j] = d[i]
				}
			}
		}
	}

	var u2 [MN]int64
	copy(u2[:], u[:])
	f := true
	for i := 0; i < m; i++ {
		if b[i] == 1 {
			for j := l[i]; j < r[i]; j++ {
				u[j] += d[i]
			}
		} else {
			f1 := false
			for j := l[i]; j < r[i]; j++ {
				if u[j] == d[i] {
					f1 = true
				}
			}
			if !f1 {
				f = false
			}
		}
	}
	if f {
		fmt.Println("YES")
		s := make([]string, n)
		for i, v := range u2[:n] {
			s[i] = strconv.FormatInt(v, 10)
		}
		fmt.Println(strings.Join(s, " "))
	} else {
		fmt.Println("NO")
	}
}