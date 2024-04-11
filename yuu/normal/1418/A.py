def solve():
  x, y, k = list(map(int, input().split()))
  req = k * y + k
  ans = (req - 1) // (x - 1)
  while ans * (x - 1) + 1 < req:
    ans += 1
  ans += k
  print(ans)

t = int(input())
for _ in range(0, t):
  solve()