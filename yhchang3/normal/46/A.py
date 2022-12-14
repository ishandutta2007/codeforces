n = int(input())

x = 0

for i in range(1, n):
	x = (x + i) % n
	print(x + 1, end = ' ')