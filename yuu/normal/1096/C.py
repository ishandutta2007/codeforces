t=int(input())
for testcase in range(0, t):
    n=int(input())
    ans=3;
    while((ans*n%180) or ((ans*n)//180>ans-2)):
        ans+=1
    print(ans)