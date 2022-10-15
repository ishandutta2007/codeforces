s=input()
a=s.count('a')
b=s.count('b')
c=s.count('c')
if len(s)!=a+b+c or c not in [a,b] or s[:a]!='a'*a or s[-c:]!='c'*c or a==0 or b==0:
    print('NO')
else:
    print('YES')