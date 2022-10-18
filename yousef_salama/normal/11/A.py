'''
Created on 6 Apr 2011

@author: salama
'''
n,k = map(int,raw_input().split())
a = map(int,raw_input().split())
ans = 0
for i in range(1,n):
    if a[i-1] >= a[i]:
        z = (a[i-1]-a[i])/k + 1
        ans += z
        a[i] += k*z
print ans