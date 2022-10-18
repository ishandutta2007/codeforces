'''
Created on 3 Mar 2011

@author: salama
'''
d , p , c, b = 1 , 0 , 0, 0 
n = input()
a = map(int,raw_input().split())
for i in range(len(a)):
    b = i
    c = i - 1
    for j in range(i+1,len(a)):
        if a[b] >= a[j]:
            d += 1
            b = j
        else:break
    b = i
    for j in range(0,i):
        if a[b] >= a[c]:
            d += 1
            b = c
            c -= 1
        else:break
    p = max(d,p)
    d = 1
print p