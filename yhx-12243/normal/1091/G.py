from random import *
from math import gcd
from sys import stdout

def miller_rabin(n):
    if n % 4 != 3:
        return False
    d = n - 1
    s = 0
    while d % 2 == 0:
        d >>= 1
        s += 1
    for repeat in range(54):
        a = 0
        while a == 0:
            a = randint(0, n - 1)
        if not miller_rabin_pass(a, s, d, n):
            return False
    return True

def miller_rabin_pass(a, s, d, n):
    a_to_power = pow(a, d, n)
    if a_to_power == 1:
        return True
    for i in range(s-1):
        if a_to_power == n - 1:
            return True
        a_to_power = (a_to_power * a_to_power) % n
    return a_to_power == n - 1

def Sqrt(n):
	print('sqrt', n)
	stdout.flush()
	return int(input())

ans = []
N = 0

def solve(n):
#	print('solve', n)
	if miller_rabin(n):
		ans.append(n)
		return
	while True:
		x = N
		while gcd(x, N) != 1:
			x = randint(1, N - 1)
		y = Sqrt(x * x % N) % n
		x %= n
		if x != y and x + y != n:
			break;
	x, y = (x + y) % n, (x - y) % n
	solve(gcd(x, n))
	solve(gcd(y, n))

N = int(input())
solve(N)

ans.sort()
print('! {} {}'.format(len(ans), ' '.join(map(str, ans))))