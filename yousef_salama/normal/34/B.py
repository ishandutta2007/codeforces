'''
Created on 6 Apr 2011

@author: salama
'''
n, m = map(int,raw_input().split())
cost = filter(lambda x:x<0,map(int,raw_input().split()))
ans = 0
for i in range(m):
    if cost:
        ans += min(cost)
        del cost[cost.index(min(cost))]
    else:break
print ans*-1