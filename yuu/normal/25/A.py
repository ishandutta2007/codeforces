n = int(input())
a = list(map(int, input().split()))
arr = [[], []]
for x in a:
  arr [x % 2].append(x)

if len(arr[0]) == 1:
  element = arr[0][0]
else:
  element = arr[1][0]

for i in range(0, n):
  if a[i] == element:
    print(i + 1)