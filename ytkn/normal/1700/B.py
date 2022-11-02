def solve():
    n = int(input())
    s = input()
    x = int(s)
    if s[0] == '9':
        target = ((10**(n+1))-1)//9
        print(target-x)
    else:
        print((10**n)-1-x)

t = int(input())

for _ in range(t):
    solve()