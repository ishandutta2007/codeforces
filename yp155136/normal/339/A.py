# -*- coding: utf-8 -*-
"""
Created on Wed May  3 21:12:12 2017

@author: Anan
"""

ls=list(map(int,input().split('+')))
ls.sort()
sz = 0
for i in ls :
    sz += 1
cnt=0
for i in ls :
    cnt += 1
    if cnt == sz :
        print(i)
    else :
        print(i,end='+')