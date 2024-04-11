# -*- coding: utf-8 -*-
"""
Created on Tue Mar 14 16:53:58 2017

@author: Anan
"""

s = input()
t = input()
ans = 0
now=0
while s.find(t,now) != -1 :
    now = s.find(t,now) + len(t);
    ans += 1
print(ans)