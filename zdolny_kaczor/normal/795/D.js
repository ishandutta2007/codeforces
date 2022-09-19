a = readline().split(' ');
n = a[0];
l = a[1];
r = a[2];
a = readline().split(' ');
b = readline().split(' ');
good = true;
for (i = 0; i < n; ++i)
  if (a[i] != b[i] && !(i >= l - 1 && i <= r - 1))
    good = false;
if (good)
  print('TRUTH');
else
  print('LIE');