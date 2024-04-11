from collections import Counter
n=int(input())
a=list(map(int,input().split()))
c=Counter(a)
def CON():
    print('Conan')
def AGA():
    print('Agasa')
c=dict(c)
c=[[key,val]for key,val in c.items()]
c.sort()
c=c[::-1]
q=c[0][1]
b=False
for i in c:
    if i[1]%2:
        b=True
    
if b:
    CON()
else:
    AGA()