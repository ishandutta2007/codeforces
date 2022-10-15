n, x = map(int, input().split())

xs = [set() for _ in range(62)]

xs[0].add(x)

for l in range(61):
    for x in xs[l]:
        d = set(str(x)) - set('10')
        for dig in d:
            x2 = x * int(dig)
            if len(str(x2)) == n:
                print(l + 1)
                exit(0)
            xs[l + 1].add(x2)
        if len(xs[l + 1]) > 100000:
            break
else:
    print(-1)