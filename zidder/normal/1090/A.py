n = int(input())
LL = []
m=0
for i in range(n):
    l = list(map(int, input().split()))[1:]
    LL.append(l)
    m = max(m, max(l))
s=0
for i in LL:
    s+=len(i)*(m-max(i))
print(s)