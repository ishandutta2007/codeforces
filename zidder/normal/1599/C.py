from decimal import Decimal
n, p = input().split()
n = int(n)
p = Decimal(p)
N = n * (n - 1) * (n - 2) // 6

def f(m):
    if m == 0:
        return 0
    if m == n:
        return N * 2
    A3 = m * (m - 1) * (m - 2) // 6
    A2 = m * (m - 1) * (n - m) // 2
    A1 = m * (n - m) * (n - m - 1) // 2
    return (A1 + A2 * 2 + A3 * 2)

for i in range(0, n+1):
    if f(i) >= N * p * 2:
        print(i)
        break