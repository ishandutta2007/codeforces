a = list(map(int,input().split()))
b = [0,0,0,0,0];
c = [0,0,0,0,0];
ipt = [];
ans = [];
d = {"S" : 0,"M" : 1, "L" : 2, "XL" : 3, "XXL" : 4, "XXXL" : 5}

n = int(input())

for i in range(1,n+1) :
    j = input()
    ipt.append(j)
    ans.append(j)
    if j.find(',') == -1 :
        a[d[j]] -= 1
    else :
        b[d[j[0:j.find(',')]]] += 1

ans = False;

for i in range(0,6) :
    if (a[i] < 0) and ans == False:
        ans = True
    elif i < 5:
        if i==0 :
            if b[i] > a[i] :
                c[i] = b[i] - a[i];
                b[i] -= a[i];
                a[i] = 0;
            else :
                c[i] = 0;
                a[i] -= b[i];
                b[i] = 0;
                
        else :
            if b[i-1] > 0 :
                if b[i-1] > a[i] :
                    ans = True
                else :
                    a[i] -= b[i-1];
            if b[i] > a[i] :
                c[i] = b[i] - a[i];
                b[i] -= a[i];
                a[i] = 0;
            else :
                c[i] = 0;
                a[i] -= b[i];
                b[i] = 0;
    elif i==5 :
        if a[i] < b[i-1]:
            ans = True
                
if ans == True :
    print("NO");

else :
    print("YES")
    for i in ipt :
        if i.find(',') == -1 :
            print(i)
        else :
            tmp = i[0:i.find(',')];
            if (c[d[tmp]] > 0) :
                print(i[i.find(',')+1:])
                c[d[tmp]] -= 1
            else :
                print(tmp)