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

	qq := 0
	fmt.Fscan(in, &qq)
	for ii := 0; ii < qq; ii++ {
		l := 0
		var s string
		fmt.Fscan(in, &l)
		fmt.Fscan(in, &s)

		if s[0] == '9' {
			var a [102400]int
			if l == 1 {
				a[0] = 2
			} else {
				add := func(pos int, k int) {
					for a[pos] += k; a[pos] > 9; pos-- {
						a[pos - 1]++
						a[pos] -= 10
					}
				}

				a[0] = 1
				for i := 1; i < l; i++ {
					a[i] = int('9' - s[i])
				}
				add(l - 1, 2)
				add(l - 2, 1)
			}
			for i := 0; i < l; i++ {
				fmt.Fprintf(out, "%d", a[i])
			}
			fmt.Fprintln(out);
		} else {
			for i := 0; i < l; i++ {
				fmt.Fprintf(out, "%c", '0' + ('9' - s[i]))
			}
			fmt.Fprintln(out);
		}
	}
}