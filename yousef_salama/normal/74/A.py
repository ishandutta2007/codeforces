'''
Created on 6 Apr 2011

@author: salama
#'''
#in the name of allah
names = []
scores = []
for j in range(input()):
    i = raw_input().split()
    names.append(i[0])
    scores.append(((100*int(i[1]))-(int(i[2])*50))+ sum(map(int,i[2:])))
print names[scores.index(max(scores))]