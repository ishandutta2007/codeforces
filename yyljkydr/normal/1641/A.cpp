#include<bits/stdc++.h>
using namespace std;

#define int long long

int T,n,x;

multiset<int>s;

signed main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld",&n,&x);
        for(int i=1;i<=n;i++)
        {
            int p;
            scanf("%lld",&p);
            s.insert(p);
        }
        int ans=0;
        while(1)
        {
            auto it=s.begin();
            if(it==s.end())
                break;
            int nd=*it*x;
            s.erase(it);
            if(!s.count(nd))
                ans++;
            else
                s.erase(s.find(nd));
        }
        printf("%lld\n",ans);
    }
}