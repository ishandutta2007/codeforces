n = int(input())

res = 0

for _ in range(n):
	s = input()
	cnt = (s[0] == '1') + (s[2] == '1') + (s[4] == '1')
	res += (cnt >= 2)

print(res)