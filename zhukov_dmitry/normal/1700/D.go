package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func max(a int64, b int64) int64 {
	if a < b {
		return b
	} else {
		return a
	}
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	n := 0
	fmt.Fscan(in, &n)
	a := make([]int, n)
	s := int64(0)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
		s += int64(a[i])
	}
	b := make([]int64, n)
	ma := int64(0)

	s2 := int64(0)

	for i := 0; i < n; i++ {
		cnt := int64(i + 1)
		s2 += int64(a[i])
		az := (s + cnt - 1) / cnt

		b[i] = max(az, ma)
		z := (s2 + cnt - 1) / cnt
		ma = max(ma, z)
	}

	m := 0
	fmt.Fscan(in, &m)
	for im := 0; im < m; im++ {
		t := int64(0)
		fmt.Fscan(in, &t)
		ans := sort.Search(n, func(i int) bool {
			return b[i] <= t
		})
		if ans == n {
			ans = -1
		} else {
			ans++
		}
		fmt.Fprintln(out, ans)
	}
}