'''
Created on 6 Apr 2011

@author: salama
'''
import re
s = raw_input()
ans = 0
for i in range(input()):
    n = raw_input()
    if re.match(s,n):
        if not ans:
            ans = n
        if ans > n:
            ans = n
print ans if ans else s