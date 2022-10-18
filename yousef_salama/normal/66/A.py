'''
Created on 3 Mar 2011

@author: salama
'''
n, a  = input(),-1
names = ['byte','short','int','long']
storge = [128,32768,2147483648,9223372036854775808]
for i in range(4):
    if n < storge[i]:
        a = i
        break
print 'BigInteger' if a == -1 else names[a]