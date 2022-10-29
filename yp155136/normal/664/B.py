s = list(map(str, input().split()));

count1 = 1;
count2 = 0;
n = 0;
for i in range(1,len(s)) :
    if (s[i]=='+') :
        count1+=1;
    elif (s[i]=='-') :
        count2+=1;
    elif (s[i] == '?') :
        pass;
    elif (s[i]=='=') :
        pass;
    else :
        n=s[i];
        n=int(n);
max1 = count1 * n;
min1 = count1;
max2 = count2 * n;
min2 = count2 ;

def ans(a1,a2,count1,count2,s) :
    b1 = a1%count1;
    if (count2 !=0) :
        b2 = a2%count2;
    for i in range(0,len(s)) :
        if (i==0):
            s[i] = int(a1/count1);
            if b1>0 :
                b1-=1;
                s[i]+=1;
        elif s[i]=='-' :
            s[i+1] = int(a2/count2);
            if b2>0 :
                b2-=1;
                s[i+1]+=1;
        elif s[i]=='+' :
            s[i+1] = int(a1/count1);
            if b1>0 :
                b1-=1;
                s[i+1]+=1;
    for i in range(0,len(s)) :
        if i==len(s)-1 :
            print(s[i],end='');
        else :
            print(s[i],end=" ");
    print("");

if max1-min2 >= n and n>= min1-max2 :
    print("Possible");
    #todo
    #a-b=n ==> a=n+b ==>a-n = b
    x = max1-n;
    if (min2<=x and x<=max2) :
        ans(max1,x,count1,count2,s);
    else :
        t = x-max2;
        ans(max1-t,x-t,count1,count2,s);
else :
    print("Impossible");