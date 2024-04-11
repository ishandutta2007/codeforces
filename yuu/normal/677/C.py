all="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz-_"
s=input()
ans=1
for c in s:
    pos=all.find(c)
    cnt=int(0)
    cnt+=(pos+1)%2
    pos//=2
    cnt+=(pos+1)%2
    pos//=2
    cnt+=(pos+1)%2
    pos//=2
    cnt+=(pos+1)%2
    pos//=2
    cnt+=(pos+1)%2
    pos//=2
    cnt+=(pos+1)%2
    pos//=2
    for i in range(0, cnt):
        ans*=3
        ans%=1000000007
print(ans)