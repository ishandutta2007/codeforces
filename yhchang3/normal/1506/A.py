T = int(input())

for _ in range(T):
	n, m, x = [int(x) for x in input().split()]
	x -= 1
	print(x % n * m + x // n + 1)