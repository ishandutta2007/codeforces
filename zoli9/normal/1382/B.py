tests = int(input())
for test in range(tests):
    n = int(input())
    a = list(map(int, input().split()))
    big = n + 1
    for i in range(n):
        if a[i] > 1:
            big = i
            break
    if big % 2 == 1:
        print("Second")
    else:
        print("First")