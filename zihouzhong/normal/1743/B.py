t = int(input())

for _ in range(t):
    n = int(input())

    a = [1]
    for i in range(1, n - 1):
        a.append(i + 2)
    a.append(2)

    print(' '.join(str(x) for x in a))