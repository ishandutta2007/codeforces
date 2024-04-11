n,k=map(int,input().split())
s=input()
S = set(s)
if n>=k:
    for i in reversed(range(k)):
        L = filter(lambda q:s[i]<q, S)
        L = list(L)
        if len(L):
            print(s[:i]+min(L)+(k-i-1)*min(S))
            break
else:
    print(s+min(S)*(k-n))