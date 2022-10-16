base=998244353;
def power(x, y):
    if(y==0):
        return 1
    t=power(x, y//2)
    t=(t*t)%base
    if(y%2):
        t=(t*x)%base
    return t;
def inverse(x):
    return power(x, base-2)
ft=[0]
for i in range(0, 200000):
    ft.append(0)
def get(i):
    res=0
    while(i<=200000):
        res+=ft[i]
        i+=i&-i
    return res
def update(i, x):
    while(i):
        ft[i]+=x
        i-=i&-i
n=int(input())
a=[0]
a+=list(map(int, input().split()))
neg=[0]
non=[0]
for i in range(1, n+1):
    non.append(0)
for i in range(1, n+1):
    if(a[i]!=-1):
        non[a[i]]+=1
for i in range(1, n+1):
    non[i]+=non[i-1]
for i in range(1, n+1):
    if(a[i]==-1):
        neg.append(neg[i-1]+1)
    else: 
        neg.append(neg[i-1])
m=neg[n]
ans=0
for i in range(1, n+1):
    if(a[i]!=-1):
        ans+=get(a[i])
        update(a[i], 1)
fm=1
fs=fm
for i in range(1, m+1):
    fs=fm
    fm=(fm*i)%base
fs=(fs*inverse(fm))%base
for i in range(1, n+1):
    if(a[i]!=-1):
        less=a[i]-non[a[i]]
        more=m-less
        ans=(ans+neg[i]*more*fs)%base
        ans=(ans+(m-neg[i])*less*fs)%base
ans=(ans+m*(m-1)*inverse(4))%base
print(ans)