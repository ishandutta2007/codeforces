import sys,math,cmath;

def input():
	return sys.stdin.readline().rstrip();

def main():
	n, k1, k2 = map(int, input().split());
	w, b = map(int, input().split());
	if k1 > k2:
		k1,k2 = k2,k1;
	if (w <= k1 + (k2 - k1) // 2) and (b <= (n - k2) + (k2 - k1) // 2):
		print("Yes");
	else:
		print("No");

T = int(input());
while T:
	main();
	T -= 1;