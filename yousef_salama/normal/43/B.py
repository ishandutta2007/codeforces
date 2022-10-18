'''
Created on 3 Mar 2011

@author: salama
'''
n = raw_input()
m = raw_input().replace(' ','')
wrong = 0
for i in m:
    if not i in n:
        wrong = 1
        break
    else :
        n = n[:n.index(i)] + n[n.index(i)+1:]
print 'NO' if wrong else 'YES'