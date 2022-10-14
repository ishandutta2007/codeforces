#!/usr/bin/python
from sys import *
from math import *

def solve(A, B, C):
  D = B * B - 4 * A * C
  if D >= 0:
    for tmp in range(-5, 6):
      sq = sqrt(D) + tmp
      if sq < 0: continue

      for k in [ -1, 1 ]:
        yield (int)((float)(-B + k * sq) / (2 * A))

n=int(stdin.readline())
ans=[]
for k in range(0, 80):
  A = 1
  B = 2 ** (k + 1) - 3
  C = -2 * n
  for _t in solve(A, B, C):
    for d in range(-5, 6):
      t = _t + d
      if t >= 1 and A * t * t + B * t + C == 0 and t % 2 == 1:
        ans.append(t * (2 ** k))
ans=list(set(ans))
ans=sorted(ans)
if len(ans) == 0:
  print("-1")
else:
  print("\n".join(map(str, ans)))