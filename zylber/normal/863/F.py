import sys
 
def is_feasible(cnt,L,R):
	n = len(R)
	inter = [(L[i],R[i]) for i in range(n)]
	right = []
	feasible = True
	for x in range(n):
		for p in inter:
			if p[0] == x:
				right.append(p[1])
				
		while right and min(right) < x:
			right.remove(min(right))
		for quantity in range(cnt[x]):
			if right:
				right.remove(min(right))
			else:
				feasible = False
	return feasible
 
 
n,q = map(int,sys.stdin.readline().split())
L = [0 for i in range(n)]
R = [n-1 for i in range(n)]
for restriction in range(q):
	t,l,r,v = map(int,sys.stdin.readline().split())
	if t == 1:
		for k in range(l-1,r):
			L[k] = max(L[k],v-1)
	else:
		for k in range(l-1,r):
			R[k] = min(R[k],v-1)
			
is_possible = all(map(lambda x,y : x <= y,L,R))
if not is_possible:
	print(-1)
else:
	cnt = {x:0 for x in range(n)}
	for y in range(n):
		for x in range(n):
			if cnt[x] == y:
				cnt[x] += 1
				if not is_feasible(cnt,L,R):
					cnt[x] -= 1 
	ans = sum([cnt[x]*cnt[x] for x in range(n)])
	print(ans)