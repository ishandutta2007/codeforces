s=input()

ss="abcdefghijklmnopqrstuvwxyz"

ans = 0

for i in ss:
    if s.count(str(i)) > 0 :
        ans += 1
        
if ans % 2 == 0 :
    print('CHAT WITH HER!')
else :
    print('IGNORE HIM!')