def gcd(a,b) :
    while a%b>=1 and b%a>=1 :
        if a>b :
            a=a%b
        else :
            b=b%a
    if a>b :
        return b
    else :
        return a

n,a,b,p,q = map(int, input().split() )

if q>p :
    print(int(p * (n//a - n//(a*b // gcd(a,b)) ) + q * (n//b)))
else :
    print(int(p * (n//a) + q*(n//b - n//(a * b // gcd(a,b)))))