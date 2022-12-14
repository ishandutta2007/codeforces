n, d = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]
ans = -n

for i in range(n):
	for j in range(n):
		if abs(a[i] - a[j]) <= d:
			ans += 1

print(ans)