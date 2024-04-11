tests = int(input())
for test in range(tests):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    was = [0]*1001
    for x in a:
        was[x] = 1
    answer = 0
    for x in b:
        if was[x]:
            answer = x
    if answer > 0:
        print("YES")
        print(1, answer)
    else:
        print("NO")