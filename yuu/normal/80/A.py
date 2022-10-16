n, m = list(map(int, input().split()))
 
def is_prime(value):
  for i in range(2, value):
    if value % i == 0:
      return False
  return True
 
n += 1
while not is_prime(n):
  n += 1
 
if n == m:
  print("YES")
else:
  print("NO")