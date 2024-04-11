'''
Created on 6 Apr 2011

@author: salama
'''
n,k = map(int,raw_input().split())
c = 0
a = map(int,raw_input().split())
v = [1 if i == k else 0 for i in a]
while not all(v):
    c += 1
    b = []
    for i in range(n):
        if not a[i] in b and a[i] != k:
            b.append(a[i])
            a[i] += 1
            if a[i] == k:v[i] = 1
print c