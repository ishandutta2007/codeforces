t=int(input())
for i in range(t):
    n, m = map(int,input().strip().split())
    print(24*60-n*60-m)