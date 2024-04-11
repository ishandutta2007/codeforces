def f(s,t):
    s=s.lower()
    t=t.lower()
    if len(s)!=len(t):
        return True
    for i in range(len(s)):
        if s[i]!=t[i]:
            w=[s[i],t[i]]
            w.sort()
            if w!=sorted(['o','0']) and w!=sorted(['i','l']) and w!=sorted(['i','1']) and w!=sorted(['l','1']):
                return True
    return False
s=input()
n=int(input())
q=True
for i in range(n):
    t=input()
    q=q and f(s,t)
if q:
    print('Yes')
else:
    print('No')