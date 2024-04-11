#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main ()
{
    int n;
    scanf("%d",&n);
    LL ans=0;
    priority_queue<LL,vector<LL>,greater<LL> > pq;
    for (int i=1;n>=i;i++)
    {
        LL x;
        scanf("%lld",&x);
        if (!pq.empty() && pq.top() < x)
        {
            ans += (x - pq.top());
            pq.pop();
            pq.push(x);
        }
        pq.push(x);
    }
    printf("%lld\n",ans);
}