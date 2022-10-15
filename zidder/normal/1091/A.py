y,b,r = map(int, input().split())

b = min(y+1, b, r-1)

if b<0:
    print(0)
else:
    print(3*b)