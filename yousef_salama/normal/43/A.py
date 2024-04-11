'''
Created on 3 Mar 2011

@author: salama
'''
a = [raw_input() for i in range(input())]
score = []
teams = []
for i in a:
    if not i in teams:
        teams.append(i)
        score.append(1)
    else:
        score[teams.index(i)] += 1
print teams[score.index(max(score))]