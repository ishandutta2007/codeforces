import sys

n = (int)(raw_input());
if (n < 3):
    print -1;
else:
    for i in range(n):
        print n - i,;
    print '\n';