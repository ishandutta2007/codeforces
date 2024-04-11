n, m = map(int, input().split())

a = []
while n:
	a.append(n % m)
	n //= m

print('YES' if len(set(a)) == len(a) else 'NO')