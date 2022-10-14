package main

import (
	"fmt"
)

func main() {
	var qq int
	fmt.Scan(&qq)

	for ii := 0; ii < qq; ii++ {
		var n, z int
		fmt.Scan(&n)
		fmt.Scan(&z)
		var ans int = 0
		for i := 0; i < n; i++ {
			var x int
			fmt.Scan(&x)
			var cur int = x | z
			if cur > ans {
				ans = cur
			}
		}

		fmt.Println(ans)
	}
}