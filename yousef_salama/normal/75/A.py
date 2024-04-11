'''
Created on 6 Apr 2011

@author: salama
'''
a = input()
b = input()
c = str(a + b).replace('0', '')
a = str(a).replace('0', '')
b = str(b).replace('0', '')
print 'YES' if int(a) + int(b) == int(c) else 'NO'