import sys

n = (int)(raw_input());
s = 0;
x = raw_input().split();
for i in range(n):
    s += (int)(x[i]);
Ans = 0;
for i in range(1, 6):
    if ((i + s) % (n + 1) != 1):
        Ans += 1;
print Ans;