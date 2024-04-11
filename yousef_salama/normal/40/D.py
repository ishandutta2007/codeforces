A = int(input())
limit = 10**600

s = set()
def dfs(i, a, b):
    assert(a <= b and a > 0 and b > 0)

    if a > limit:
        return
    if (i, a, b) in s:
        return
    
    s.add((i, a, b))
    dfs(i + 1, b, 12 * a)
    dfs(i + 1, b, 13 * b - 12 * a)

dfs(1, 2, 13)

a = set()
for p in s:
    if p[1] == A:
        a.add(p[0])

v = set()
for p in s:
    if p[0] in a and p[1] != A:
        v.add(p[1])

if len(a) == 0:
    print("NO")
else:
    print("YES")
    
    a_list = sorted(list(a))
    if(len(a_list) > 1000):
        a_list = a_list[:1000]

    print(len(a_list))
    for x in a_list:
        print(str(x) + ' ')
    
    v_list = sorted(list(v))
    if(len(v_list) > 1000):
        v_list = v_list[:1000]

    print(len(v_list))

    for x in v_list:
        print(str(x) + ' ')