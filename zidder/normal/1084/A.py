n = int(input())
l = list(map(int, input().split()))

def f(x, l):
	s=0
	for i in range(len(l)):
		s+=l[i] * 2 * (abs(x-i)+abs(x)+abs(i))
	return s
q= 10**10
for x in range(n):
	q = min(f(x, l), q)
print(q)