a,b,c = input().split();
a=int(a)
b=int(b);
c=int(c);

if c==0 :
    if a!=b :
        print("NO");
    else :
        print("YES");
elif c<0 :
    if b>a:
        print("NO");
    elif b==a:
        print("YES");
    elif(a-b)%(-c)!=0:
        print("NO")
    else :
        print("YES");
else :
    if b<a:
        print("NO");
    elif b==a:
        print("YES");
    elif(b-a)%(c)!=0:
        print("NO")
    else :
        print("YES");