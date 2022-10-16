s = input()
t = False
ans = ''
for c in s:
  if t:
    if c == '.':
      ans = ans + '1'
    else:
      ans = ans + '2'
    t = False
  else:
    if c == '-':
      t = True
    else:
      ans = ans + '0'
print(ans)