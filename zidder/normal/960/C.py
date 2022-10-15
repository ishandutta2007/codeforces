x, d = map(int,input().split())
 
def get_next(x):
    if bin(x + 1).count('1') == 1:
        return bin(x).count('1')
    return len(bin(x)) - 3
 
a = []
w = 1
while x:
    c = get_next(x)
    a += c * [w]
    w += d + 1
    x -= 2**c-1
print(len(a))
print(*a)