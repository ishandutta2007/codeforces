# -*- coding: utf-8 -*-
"""
Created on Wed Mar 15 23:00:22 2017

@author: Anan
"""

n,m = map(int,input().split())

if n<=m :
    print(n)
else :
    
    ans = m
    L =0
    R = 123456789123456789123
    while R-L != 1 :
        mid = (L+R)//2
        if n-mid*(mid-1)//2 <= m+mid :
            R=mid
        else :
            L=mid
    print(ans + R)