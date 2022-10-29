# -*- coding: utf-8 -*-
"""
Created on Sat Mar 18 08:49:39 2017

@author: Anan
"""
s = ""
for i in range(0,int(input())) :
    s += input()
print((s.count('+') - s.count('-'))//2)