n = int(input())
ans = 0
for i in range(0,n) :
    x,y = map(int,input().split())
    if y-x >= 2 :
        ans += 1
        
print(ans)