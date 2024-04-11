'''
Created on 3 Mar 2011

@author: salama
'''
import re
w1 = ''.join(re.findall('[a-zA-Z]',raw_input())).lower()
w2 = ''.join(re.findall('[a-zA-Z]',raw_input())).lower()
w3 = ''.join(re.findall('[a-zA-Z]',raw_input())).lower()
a = []
for j in range(input()): 
    a.append(raw_input()) 
for i in a: 
    write = 0
    b = ''.join(re.findall('[a-zA-Z]',i)).lower()
    if w1+w2+w3 == b or w1+w3+w2 == b or w2+w1+w3 == b or w2+w3+w1 == b or w3+w1+w2 == b or w3+w2+w1 == b:
        write = 1
    print 'ACC' if write else 'WA'