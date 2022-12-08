# Author: kipa00, https://codeforces.com/contest/1091/submission/47763225

import random

n = int(input())
pick = lambda: random.randint(1, n - 1)

def gcd(x, y):
	if not y:
		return x
	t = x % y
	while t:
		x,y,t = y,t,y%t
	return y

def find_factor(_n, factor_count):
	for i in range(8):
		a = pick()
		"""
		print("* {0} {0}".format(a), flush=True)
		u = int(input())
		"""
		u = a * a % n
		print("sqrt {}".format(u), flush=True)
		b = int(input())
		if b == -1:
			factor = gcd(_n, a)
		else:
			factor = gcd(a + b, _n)
		if factor != 1 and factor != _n:
			return factor
	# this is at least 99.9% chance; we have no luck
	return -1

s = [n]
found = []
factor_count = 1
while bool(s):
	now_n = s.pop()
	factor = find_factor(now_n, factor_count)
	if factor == -1:
		found.append(now_n)
	else:
		factor_count += 1
		s.append(factor)
		s.append(now_n // factor)

found.sort()
print("! {} {}".format(len(found), ' '.join(map(str, found))), flush=True)