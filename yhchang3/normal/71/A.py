T = int(input())

for _ in range(T):
	s = input()
	if len(s) > 10:
		print(s[0], len(s) - 2, s[-1], sep = '')
	else:
		print(s)