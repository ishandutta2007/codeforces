package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush();

	qq := 0
	fmt.Fscan(in, &qq)
	for ii := 0; ii < qq; ii++ {
		n := uint64(0)
		m := uint64(0)
		fmt.Fscan(in, &n)
		fmt.Fscan(in, &m)
		fmt.Fprintln(out, m * (m - 1) / 2 + (m + n * m) * n / 2)
	}
}