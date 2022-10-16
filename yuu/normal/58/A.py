s = input()
req = "hello"
for c in s:
  if c == req[0]:
    req = req[1:]
    if len(req) == 0:
      break
if len(req) == 0:
  print("YES")
else:
  print("NO")