import sys,math,cmath;

def input():
	return sys.stdin.readline().rstrip();

def main():
	s = input();
	n = len(s);
	L = -1;
	R = n;
	for i in range(1, n):
		if s[i - 1] == s[i]:
			if s[i] == '0':
				L = max(L, i - 1);
			else:
				R = min(R, i);
	for i in range(L + 1, R):
		if i == 0 or i == n or (s[i - 1] != '1' or s[i] != '0'):
			print("Yes");
			return;
	print("No");

T = int(input());
while T:
	main();
	T -= 1;