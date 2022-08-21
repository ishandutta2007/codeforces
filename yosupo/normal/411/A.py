import string
s = input()
f1 = f2 = f3 = False
for c in s:
    if c in string.ascii_lowercase:
        f1 = True
    if c in string.ascii_uppercase:
        f2 = True
    if c in string.digits:
        f3 = True
if len(s) >= 5 and f1 and f2 and f3:
    print('Correct')
else:
    print('Too weak')