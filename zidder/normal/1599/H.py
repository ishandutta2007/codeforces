import sys

def flush():
    sys.stdout.flush()

def ask(x, y):
    print('?', x, y)
    flush()
    return int(input())

def answer(x, y, p, q):
    print('!', x, y, p, q)
    flush()

n = int(1e9)

_11 = ask(1, 1)  # x + y - 2 = _11      => x <= _11
_1n = ask(1, n)  # x - 1 + n - q = _1n  => x <= _1n
_n1 = ask(n, 1)  # n - p + y - 1 = _n1
_nn = ask(n, n)  # n - p + n - q = _nn

# .....
# ..a..
# ..a..
# ..a..
# .....
# 3 2 3 4

# .....
# .....
# .bbb.
# .....
# .....
# 2 3 4 3

# _11 = 3
# _1n = 3
# _n1 = 3
# _nn = 3

# ......
# .aaa..
# .aaa..
# .aaa..
# ......
# ......

x = ask(1, (_11 + n - _1n + 1) // 2) + 1
p = n - ask(n, (_n1 + n - _nn + 1) // 2)
y = ask((_11 + n - _n1 + 1) // 2, 1) + 1
q = n - ask((_1n + n - _nn + 1) // 2, n)

answer(x, y, p, q)