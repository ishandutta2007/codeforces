k = int(input())
for i in range(k):
    n = int(input())
    s1 = input()
    s2 = input()
    q = None
    for i in range(n):
        if s1[i] != s2[i]:
            if q is None:
                q = s1[i], s2[i]
            elif q == (s1[i], s2[i]):
                q = 1
            else:
                print('No')
                break
    else:
        if q == 1:
            print('Yes')#isinstance(q, tuple):
        else:
            print('No')