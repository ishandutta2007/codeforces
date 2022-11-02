n=input()
maxK=2000
best=0
Best=[]
for i in range(maxK+2):
	Best.append(-1)
for i in range(n):
	L=raw_input().split()
	c,k=L[0],int(L[1])
	if c=="win":
		Best[k]=best
	elif Best[k]!=-1:
		Best[maxK+1]=Best[k]+pow(2,k)
		best=max(best,Best[maxK+1])
print best