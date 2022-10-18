'''
Created on 6 Apr 2011

@author: salama
'''
names = ['F','M','S']
a = [raw_input(),raw_input(),raw_input()]
ans = '?'
for i in range(3):
        if a[(i+1)%3] == a[(i+2)%3]:
            if a[i] == 'rock':
                if a[(i+1)%3] == 'scissors':
                    ans = names[i]
                    break
            elif a[i] == 'scissors':
                if a[(i+1)%3] == 'paper':
                    ans = names[i]
                    break
            else:
                if a[(i+1)%3] == 'rock':
                    ans = names[i]
                    break
print ans