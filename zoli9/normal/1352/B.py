tests = int(input())
for test in range(tests):
    n, k = map(int, (input().split()))
    if n < k:
        print("NO")
        continue
    if (n - k) % 2 == 0:
        print("YES")
        for i in range(k-1):
            print(1)
        print(n - k + 1)
        continue
    if n % 2 == 0:
        if 2 * (k-1) < n:
            print("YES")
            for i in range(k - 1):
                print(2)
            print(n-2*(k-1))
        else:
            print("NO")
    else:
        print("NO")