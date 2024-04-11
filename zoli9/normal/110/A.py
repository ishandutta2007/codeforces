s = input()
cnt = 0
for c in s:
    if c=='4' or c=='7':
        cnt+=1
if cnt==4 or cnt==7:
    print("YES")
else:
    print("NO")