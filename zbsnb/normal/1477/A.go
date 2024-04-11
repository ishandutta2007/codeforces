package main
import (
	. "fmt"
	"bufio"
	"os"
)

func gcd(a int64, b int64) int64 {
	if b == 0 {
		return a
	} else {
		return gcd(b,a%b)
	}
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var t int
	Fscan(in, &t)
	for t != 0 {
		t--
		var n int
		var k int64
		Fscan(in, &n, &k)
		var g int64 = 0
		var x int64
		for i:=1; i<=n; i++ {
			var tmp int64
			Fscan(in, &tmp)
			if i == 1 {
				x = tmp
			} else {
				g = gcd(g, tmp-x);
			}
		}
		k -= x
		if k % g == 0 {
			Fprintln(out, "YES")
		} else {
			Fprintln(out, "NO")
		}
	}
}