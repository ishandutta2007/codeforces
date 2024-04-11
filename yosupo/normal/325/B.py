n = int(input())*2
def calc(d):
    mi, ma = 1, n
    md = 0
    while mi != ma:
        md = (mi + ma) // 2
        if md * (md + d) < n:
            mi = md+1
        else:
            ma = md
    return ma if ma*(ma+d) == n and ma%2 else -1


d = 1
li = []
while d <= n:
    d *= 2
    u = calc(d-3)
    if u != -1:
        li.append(u*d//2)
li.sort()
if (len(li)):
    for d in li:
        print(d)
else:
    print(-1)