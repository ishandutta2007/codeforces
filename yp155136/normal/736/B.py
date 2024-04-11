def f(n) :
    prime=True
    for i in range(2,50000) :
        if i!=n and n%i==0 :
            prime=False
    return prime

n = int(input())

if f(n)==True :
    print(1)
else :
    if n%2==0 :
        print(2)
    elif f(n-2)==True :
        print(2)
    else :
        print(3)