n = int(input())
a = list(map(int, input().split()))
r = n-2
for d in a:
    r += d
print(max(max(a), r//(n-1)))