a, b = list(map(int, input().split()))
 
if (a < b):
  a = b
 
a = 6 - a + 1
 
b = 6
 
if a%2 == 0:
  a = a // 2
  b = b // 2
if a%3 == 0:
  a = a // 3
  b = b // 3
 
print(f"{a}/{b}")