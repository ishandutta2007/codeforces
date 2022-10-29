s = input();
a,b,c = s.split();
a=int(a);
b=int(b);
c=int(c);

check=False;

for i in range(0,10003) :
    n = c-a*i;
    if n>=0 and n%b==0 :
        check=True;
        print("Yes");
        break;
if check==False :
    print("No");