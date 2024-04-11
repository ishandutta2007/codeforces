s = input();
a,b = s.split();
a=int(a);
b=int(b);
def gcd(a,b) :
    if a%b==0 :
        return b;
    elif b%a==0 :
        return a;
    elif a>b :
        return gcd(a%b,b);
    elif a<b :
        return gcd(b%a,a);
ans=a;
for i in range(a+1,b+1) :
    ans =  gcd(ans,i);
    if ans==1 :
        break;
print(int(ans));