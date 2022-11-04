import sys
a = [0 for i in range(100)];
f = [0 for i in range(100)];
tot = 0;
n = (int)(raw_input());
while (n > 0):
    tot += 1;
    a[tot] = n % 10;
    n /= 10;
f[tot + 1] = 1;
for i in range(tot, 0, -1):
    if (a[i] == 1 and f[i + 1] == 1):
        f[i] = 1;
    if (a[i] == 4 and a[i + 1] == 1 and f[i + 2] == 1):
        f[i] = 1;
    if (a[i] == 4 and a[i + 1] == 4 and a[i + 2] == 1 and f[i + 3] == 1):
        f[i] = 1;
if (f[1] == 1):
    print "YES";
else:
    print "NO";