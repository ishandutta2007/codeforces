package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var qq int
//	fmt.Scan(&qq)
	fmt.Fscan(in, &qq)

	for ii := 0; ii < qq; ii++ {
		var n int
//		fmt.Scan(&n)
		fmt.Fscan(in, &n)
		var a [102400]int
		for i := 0; i < n; i++ {
//			fmt.Scan(&a[i])
			fmt.Fscan(in, &a[i])
		}
		var l int = 0
		var r int = n - 1
		for ; l <= r && a[l] == 0; l++ {}
		for ; l <= r && a[r] == 0; r-- {}

		allz := true
		havez := false

		for i := l; i <= r; i++ {
			if a[i] != 0 {
				allz = false
			} else {
				havez = true
			}
		}

		if allz {
			fmt.Fprintln(out, 0)
		} else if havez {
			fmt.Fprintln(out, 2)
		} else {
			fmt.Fprintln(out, 1)
		}
	}
}