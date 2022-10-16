q=int(input())
for testcase in range(0, q):
    n=int(input());
    a=list(map(int, input().split()))
    sum=0;
    for x in a:
        sum+=x
    ans=sum//n
    while (ans*n<sum):
        ans+=1
    print(ans)