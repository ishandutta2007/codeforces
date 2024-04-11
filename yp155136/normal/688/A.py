n,m = input().split()
n=int(n)
m=int(m)
ans=0
cnt=0
for i in range(0,m) :
    s=input()
    if s.find("0") != -1 :
        cnt += 1
    else :
        ans = max(ans,cnt)
        cnt=0
print(max(ans,cnt))