#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main ()
{
    LL n,a,b;
    scanf("%lld %lld %lld",&n,&a,&b);
    priority_queue<LL> pq;
    LL tot = 0;
    LL s1=0;
    for (int i=1;n>=i;i++)
    {
        LL x;
        scanf("%lld",&x);
        if (i==1) s1 = x;
        else pq.push(x);
        tot += x;
    }
    //a * s1 / tot >= b
    int ans=0;
    while (a * s1 < tot * b)
    {
        ++ans;
        tot -= pq.top();
        pq.pop();
    }
    printf("%d\n",ans);
}