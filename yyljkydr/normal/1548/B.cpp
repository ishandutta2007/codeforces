#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e5+1e3+7;

int T,n,a[N];

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

vector<pii>g,ng;

signed main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        int ans=1;
        g.clear();
        for(int t=2;t<=n;t++)
        {
            int x=abs(a[t]-a[t-1]);
            ng.clear();
            for(int i=0;i<g.size();i++)
            {
                if(ng.size()&&__gcd(g[i].sd,x)==ng.back().sd)
                {
                    ng.back().fs=g[i].fs;
                    continue;
                }
                ng.push_back(mp(g[i].fs,__gcd(g[i].sd,x)));
            }
            if(ng.size()&&ng.back().sd==x)
                ng.pop_back();
            ng.push_back(mp(t,x));
            g=ng;
            int fir=2;
            for(int i=0;i<g.size();i++)
                if(g[i].sd==1)
                    fir=g[i].fs+1;
            ans=max(ans,t-fir+2);
        }  
        printf("%lld\n",ans);
    }
}