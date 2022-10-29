n = int(input())
ans=0

for i in range(0,n) :
    j=input()
    if j.count('1') > 1 :
        ans += 1
        
print(ans)