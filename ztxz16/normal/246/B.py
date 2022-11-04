import sys

n = (int)(raw_input());
a = raw_input().split();
s = 0;
for i in a:
    s += (int)(i);
if (s % n == 0):
    print n;
else:
    print n - 1;