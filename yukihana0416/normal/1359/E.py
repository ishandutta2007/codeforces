mod = 998244353
def fp(a, n):
    res = 1
    while n:
        if n & 1:
            res = res * a % mod
        n = n // 2
        a = a * a % mod
    return res

n, k = list(map(int, input().split()))

po = [0] * (n + 1)
rv = [0] * (n + 1)

po[0] = 1
for i in range(1, n + 1):
    po[i] = po[i - 1] * i % mod
rv[n] = fp(po[n], mod - 2)
for i in range(n - 1, -1, -1):
    rv[i] = rv[i + 1] * (i + 1) % mod

def C(n, m):
    return po[n] * rv[m] * rv[n - m] % mod

if k == 1:
    print(n)
elif k > n:
    print(0)
else:
    ans = 0
    for i in range(1, n + 1):
        t = n // i
        if t < k:
            break
        ans += C(t - 1, k - 1)
    print(ans % mod)