import sys

n = (int)(raw_input());
x = raw_input().split();
Hash = [0 for i in range(100)];

for i in range(n):
    Now = (int)(x[i]);
    s = 0;
    while (Now > 0):
        if ((Now & 1) == 1):
            s += 1;
        Now >>= 1;
    Hash[s] += 1;
Ans = 0;
for i in range(100):
    Ans += ((Hash[i] * (Hash[i] - 1) / 2));
print Ans;