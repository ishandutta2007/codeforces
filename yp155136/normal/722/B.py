n=int(input())

p =list(map(int,input().split()))

ans=True

for j in range(0,n) :
    i=input()
    tmp=i.count('a')+i.count('e')+i.count('i')+i.count('o')+i.count('u')+i.count('y')
    if tmp!=p[j] :
        ans=False
        
if ans==False :
    print("NO");
else :
    print("YES");