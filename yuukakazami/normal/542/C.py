
def gcd(a,b):
	if b==0:
		return a
	else:
		return gcd(b,a%b)

def lcm(a,b):
	return a*b/gcd(a,b)

raw_input()
a=map(int,raw_input().split())
n=len(a)
mark=[False]*n
for i in range(n):
	a[i]-=1

for i in range(n):
	x=i
	for j in range(n):
		x=a[x]
	for j in range(n):
		mark[x]=True;
		x=a[x]

need=[0]*n
for i in range(n):
	if mark[i]:
		continue
	x=i
	while not mark[x]:
		need[i]+=1
		x=a[x]

maxNeed=0
for i in need:
	if i > maxNeed:
		maxNeed = i;

ret=1
for i in range(n):
	len=0;
	x=i;
	if not mark[x]:
		continue;
	x=a[x];
	len+=1;
	while x!=i:
		x=a[x]
		len+=1
	ret = lcm(ret,len)

ans=ret
while ans<maxNeed:
	ans+=ret

print ans