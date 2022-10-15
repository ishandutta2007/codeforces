import sys

s = list(sys.stdin.readline().split()[0])
i = 0
res = 0

for x in s:
  if x == '(' or x == '[' or x == '{' or x == '<':
    s[i] = x
    i += 1
  else:
    if not (ord(x) == 1 + ord(s[i-1]) or ord(x) == 2 + ord(s[i-1])):
      res += 1
    i -= 1
    if i < 0:
      break

if i == 0:
  print res
else:
  print "Impossible"