#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=3e5+1e3+7;

int T,n,a[N];

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair 

deque<int>v[2];

map<int,int>c[2];

signed main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        c[0].clear(),c[1].clear();
        v[0].clear();
        v[1].clear();
        v[0].push_back(0);
        c[0][0]++;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            a[i]-=a[i-1];
            int k=i&1;
            while(v[k].size()&&a[i]-v[k].back()<0)
                c[k][v[k].back()]--,v[k].pop_back();
            while(v[k^1].size()&&a[i]+v[k^1].front()<0)
                c[k^1][v[k^1].front()]--,v[k^1].pop_front();
            ans+=c[k][a[i]]+c[k^1][-a[i]];
            v[k].push_back(a[i]);
            c[k][a[i]]++;
        }
        printf("%lld\n",ans);
    }
}