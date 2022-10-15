n = int(input())

i = 2
while i*i <= n:
    if n%i == 0:
        while n%i == 0:
            n //= i
        if n == 1:
            print(i)
        else:
            print(1)
        break
    i += 1
else:
    print(n)