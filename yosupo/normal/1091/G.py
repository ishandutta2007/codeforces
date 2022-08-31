import random
from sys import stdout
# Custom: https://rosettacode.org/wiki/Miller%E2%80%93Rabin_primality_test#Python
def is_Prime(n):
    """
    Miller-Rabin primality test.

    A return value of False means n is certainly not prime. A return value of
    True means n is very likely a prime.
    """
    #Miller-Rabin test for prime
    if n==0 or n==1 or n==4 or n==6 or n==8 or n==9:
        return False

    if n==2 or n==3 or n==5 or n==7:
        return True
    s = 0
    d = n-1
    while d%2==0:
        d>>=1
        s+=1
    assert(2**s * d == n-1)

    def trial_composite(a):
        if pow(a, d, n) == 1:
            return False
        for i in range(s):
            if pow(a, 2**i * d, n) == n-1:
                return False
        return True

    for i in range(50):#number of trials
        a = random.randint(2, n - 1)
        if trial_composite(a):
            return False

    return True

def gcd(a, b):
    if b == 0: return a
    return gcd(b, a % b)

debug = False

_n = 3 * 7 * 11 * 19 * 23 * 31 * 43

N = 0
if debug:
    N = _n
else:
    N = int(input())

gc = 0
def calc_sqrt(m):
    global gc
    gc += 1
    for i in range(0, _n):
        if i * i % _n == m:
            return i
    print('Found Error ', m)
    assert(False)
    return -1

def solve(n, maybe_last = True):
    # print('START ', n, ' ', is_Prime(n), ' ', maybe_last)
    if n == 1:
        return []
    if maybe_last and is_Prime(n):
        return [n]

    v = random.randint(1, N - 1)
    while gcd(v, N) != 1:
        v = random.randint(1, N - 1)

    if debug:
        print('start ', n, ' ', v, ' ', v * v % N)
        w = calc_sqrt(v * v % N) % n
    else:
        print('sqrt {}'.format(v * v % N))
        stdout.flush()
        w = int(input()) % n
    v %= n

    # print('get ', v, ' ', w)
    if v == w or v + w == n:
        return solve(n, False)

    z = abs(v - w)
    g0 = gcd(n, z)
    g1 = gcd(n, abs(n - v - w))
    g1 //= gcd(g0, g1)
    if g0 != 1 or g1 != 1:
        l = solve(n // (g0 * g1))
        l.extend(solve(g0))
        l.extend(solve(g1))
        return l
    return solve(n, False)


ans = solve(N, False)
print('!', len(ans), ' '.join(map(str, ans)))

if debug:
    print('gc ', gc)