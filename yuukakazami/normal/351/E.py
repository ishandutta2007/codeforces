n,ans=int(raw_input()),0
a=map(lambda x:abs(int(x)),raw_input().split())
for i in range(n):
	x,y=0,0
	for j in range(n):
		if a[j]<a[i]:
			if j<i :
				x+=1
			else :
				y+=1
	ans+=min(x,y)
print ans