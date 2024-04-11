n = int(input() )
s = input()

pos = s.find("><")
if pos == -1 :
    print(n)
else :
    ans = 0
    for i in s :
        if i == '>' :
            break;
        else :
            ans += 1;
    for i in range(n-1,-1,-1) :
        t = s[i]
        if t=="<" :
            break;
        else :
            ans += 1;
    print(ans)