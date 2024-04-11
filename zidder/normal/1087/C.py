def main():
	a = list(map(int, input().split()))
	b = list(map(int, input().split()))
	c = list(map(int, input().split()))
	a, b, c = sorted([a,b,c])
	ans = []
	for i in range(min(a[1], b[1], c[1]), max(a[1], b[1], c[1])+1):
		ans.append((b[0], i))
	for i in range(a[0], b[0]+1):
		ans.append((i, a[1]))
	for i in range(b[0], c[0]+1):
		ans.append((i, c[1]))
	ans = set(ans)
	print(len(ans))
	for i in ans:
		print(*i)

t = 1 # int(input())
for i in range(t):
	main()