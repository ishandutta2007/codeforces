n=int(input())
ans = False
s=[]
mark=-1
for i in range(0,n) :
    tmp=input()
    if tmp.find("OO") != -1 and ans==False :
        ans=True
        mark=i
    s.append(tmp)
if ans==False :
    print("NO")
else :
    print("Yes")
    for i in range(0,n) :
        if i != mark :
            print(s[i])
        else :
            if s[i][0] == 'O' and s[i][1] == 'O' :
                print("++" + s[i][2] + s[i][3] + s[i][4])
            else :
                print(s[i][0] + s[i][1] + s[i][2] + "++")