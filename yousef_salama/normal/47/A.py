'''
Created on 16 Apr 2011

@author: salama
'''
#in the name of allah
n, wrong = input(),1
def tranum(i):
    a,b = 1,1
    for i in range(i+1):
        b = (a*(a+1))/2
        yield b
        a += 1
for i in tranum(n):
    if i == n:
        print 'YES'
        wrong = 0
if wrong:print 'NO'