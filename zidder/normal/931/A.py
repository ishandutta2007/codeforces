a=int(input())
b=int(input())
c=(a+b)//2
def f(x):
    x=abs(x)
    return x*(x+1)//2
print(f(c-a)+f(b-c))