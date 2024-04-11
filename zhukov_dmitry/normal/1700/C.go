package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

func uin(a *int64, b int64) bool {
	if (b < *a) {
		*a = b
		return true
	}
	return false
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	qq := 0
	fmt.Fscan(in, &qq)
	for ii := 0; ii < qq; ii++ {
		n := 0
		fmt.Fscan(in, &n)
		a := make([]int64, n)
		ld := make([]int64, n)
		rd := make([]int64, n)
		mi := int64(math.MaxInt64)
		for i := 0; i < n; i++ {
			fmt.Fscan(in, &a[i])
			_ = uin(&mi, a[i])
		}
		s := make([]int64, 0, n)
		ans := int64(0)

		if mi < 0 {
			for i := 0; i < n; i++ {
				a[i] -= mi
			}
			ans -= mi
			mi = 0
		}

		for i := 0; i < n; i++ {
			ld[i] = math.MaxInt64
			for ; len(s) > 0 && s[len(s) - 1] >= a[i]; s = s[: len(s) - 1] {}

			if len(s) > 0 {
				ld[i] = a[i] - s[len(s) - 1]
			}
			s = append(s, a[i])
		}

		s = make([]int64, 0, n)
		for i := n - 1; i >= 0; i-- {
			rd[i] = math.MaxInt64
			for ; len(s) > 0 && s[len(s) - 1] > a[i]; s = s[: len(s) - 1] {}

			if len(s) > 0 {
				rd[i] = a[i] - s[len(s) - 1]
			}
			s = append(s, a[i])
		}

		add3 := int64(0)
		for i := 0; i < n; i++ {
			cur := ld[i]
			_ = uin(&cur, rd[i])
			if ld[i] == math.MaxInt64 && rd[i] == math.MaxInt64 {
				ans += a[i]
			} else if ld[i] != math.MaxInt64 && rd[i] != math.MaxInt64 {
				add3 += cur
				ans += cur * 3
			} else {
				ans += cur
			}
		}

//		fmt.Fprintf(out, "add3 = %d, add = %d\n", add3, mi)
		_ = uin(&add3, mi)
		ans -= add3 * 2

		fmt.Fprintln(out, ans)
	}
}