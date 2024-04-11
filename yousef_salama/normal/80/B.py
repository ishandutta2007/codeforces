'''
Created on 6 Apr 2011

@author: salama
#'''
#in the name of allah
h,m = map(int,raw_input().split(':'))
n = 30
if h > 12: h -= 12
if h == 12:
    angleh = m*30/60.0
    anglem = m/5.0 * 30.0
    print angleh,anglem
else: 
    anglem = m/5.0 * 30.0
    angleh = (h*30)+((m*30)/60.0)
    print angleh,anglem