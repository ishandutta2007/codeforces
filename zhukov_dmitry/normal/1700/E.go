package main

import (
	"bufio"
	"fmt"
	"os"
)

type Pos struct { x, y int }

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var n, m int
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &m)

	dx := [4]int{1, 0, -1, 0}
	dy := [4]int{0, -1, 0, 1}


	a := make([][]int, n)
	for i := 0; i < n; i++ {
		a[i] = make([]int, m)
		for j := 0; j < m; j++ {
			fmt.Fscan(in, &a[i][j])
			a[i][j]--
		}
	}

	cl := func(x int, y int) int {
		for l := 0; l < 4; l++ {
			xn := x + dx[l]
			yn := y + dy[l]
			if xn < 0 || xn >= n || yn < 0 || yn >= m {
				continue
			}
			if a[xn][yn] < a[x][y] {
				return 1
			}
		}
		return 0
	}

	mi := n * m
	xx := 0
	yy := 0
	res := 0
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			cur := cl(i, j)
			if cur == 0 && a[i][j] > 0 && a[i][j] < mi {
				mi = a[i][j]
				xx = i
				yy = j
			}
			res += cur
		}
	}

	if (res == n * m - 1) {
		fmt.Fprintln(out, "0")
	} else {
		cnt := 0

		u := make([][]bool, n)
		for i := 0; i < n; i++ {
			u[i] = make([]bool, m)
		}

		g := func(ps [10]Pos, k int) int {
			res := 0

			for i := 0; i < k; i++ {
				x := ps[i].x
				y := ps[i].y
				if cl(x, y) > 0 {
					res++
				}
			}

			return res
		}

		f := func(ps [2]Pos) int {
			var pu [10]Pos
			k := 0

			for i := 0; i < 2; i++ {
				x := ps[i].x
				y := ps[i].y

				if !u[x][y] {
					u[x][y] = true
					pu[k] = Pos{x, y}
					k++
				}

				for l := 0; l < 4; l++ {
					xn := x + dx[l]
					yn := y + dy[l]
					if xn < 0 || xn >= n || yn < 0 || yn >= m {
						continue
					}

					if !u[xn][yn] {
						u[xn][yn] = true
						pu[k] = Pos{xn, yn}
						k++
					}
				}
			}

			for i := 0; i < k; i++ {
				u[pu[i].x][pu[i].y] = false
			}

			return g(pu, k)
		}

		for i := 0; i < n; i++ {
			for j := 0; j < m; j++ {
				if a[i][j] == a[xx][yy] {
					continue
				}
				if a[i][j] > a[xx][yy] {
					ps := [2]Pos{Pos{xx, yy}, Pos{i, j}}
					cur := res - f(ps)

					a[i][j], a[xx][yy] = a[xx][yy], a[i][j]
					cur += f(ps)

					if cur == n * m - 1 {
						cnt++
					}

					a[i][j], a[xx][yy] = a[xx][yy], a[i][j]
				} else {
					for l := 0; l < 4; l++ {
						xn := xx + dx[l]
						yn := yy + dy[l]
						if xn < 0 || xn >= n || yn < 0 || yn >= m {
							continue
						}

						ps := [2]Pos{Pos{xn, yn}, Pos{i, j}}
						cur := res - f(ps)

						a[i][j], a[xn][yn] = a[xn][yn], a[i][j]
						cur += f(ps)

						if cur == n * m - 1 {
							cnt++
						}

						a[i][j], a[xn][yn] = a[xn][yn], a[i][j]
					}
				}
			}
		}

		if cnt > 0 {
			fmt.Fprintf(out, "1 %d\n", cnt)
		} else {
			fmt.Fprintln(out, "2")
		}
	}
}