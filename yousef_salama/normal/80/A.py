'''
Created on 6 Apr 2011

@author: salama
#'''
#in the name of allah
n,m = map(int,raw_input().split())
i = n+1
while 1:
    wrong = 0
    for j in range(2,i):
        if i % j == 0:wrong = 1
    if not wrong:
        nextprime = i
        break
    i += 1
print 'YES' if m == nextprime else 'NO'