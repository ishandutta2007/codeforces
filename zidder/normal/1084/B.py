n,s = map(int,input().split())
l = list(map(int, input().split()))

if sum(l) < s:
	print(-1)
	exit()
q = sum(l) - min(l) * n
if q>=s:
	print(min(l))
	exit()
print(min(l)-(s-q+n-1)//n)