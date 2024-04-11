#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,W,w[N];

multiset<int>s;

signed main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&W);
        for(int i=1;i<=n;i++)
            scanf("%d",&w[i]),s.insert(w[i]);
        int nW=W,ans=1;
        while(!s.empty())
        {
            auto it=s.upper_bound(nW);
            if(it==s.begin())
            {
                ans++;
                nW=W;
                continue;
            }
            it--;
            nW-=*it;
            s.erase(it);
        }
        printf("%d\n",ans);
    }
}