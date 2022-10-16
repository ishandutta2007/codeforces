s = input()
lower = s.lower()
upper = s.upper()

length = len(s)
lower_cost = 0
upper_cost = 0

for i in range(0, length):
  if lower[i] != s[i]:
     lower_cost += 1
  if upper[i] != s[i]:
     upper_cost += 1

if lower_cost <= upper_cost:
  print(lower)
else:
  print(upper)