#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=2e5+1e3+7;

int T,n,q;

int vis[N],a[N];

int main()
{
    scanf("%d",&T);
    for(int i=2;i<=200000;i++)
    {
        if(!vis[i])
            for(int j=i*2;j<=200000;j+=i)
                vis[j]=1;
    }
    while(T--)
    {
        scanf("%d%d",&n,&q);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        vector<int>d;
        vector<vector<ll> >v;
        vector<vector<int> >bel;
        multiset<ll>ms;
        vector<int>len;
        for(int i=2;i<=n;i++)
            if(!vis[i]&&n%i==0)
            {
                d.push_back(i);
                vector<int>use(n);
                v.push_back({});
                v.back().resize(n+1);
                bel.push_back({});
                bel.back().resize(n+1);
                len.push_back(0);
                int step=n/i;
                for(int j=0;j<n;j++)
                {
                    if(use[j])
                        continue;
                    int x=j;
                    int c=0;
                    ll s=0;
                    while(!use[x])
                    {
                        bel.back()[x]=j;
                        s+=a[x];
                        use[x]=1;
                        c++;
                        x+=step;
                        x%=n;
                    }
                    assert(n%c==0);
                    assert(x==j);
                    len.back()=n/c;
                    s*=(n/c);
                    v.back()[x]=s;
                    ms.insert(s);
                }
            }
        printf("%lld\n",*ms.rbegin());
        while(q--)
        {
            int x,w;
            scanf("%d%d",&x,&w);
            x--;
            int c=0;
            for(auto p:d)
            {
                ms.erase(ms.find(v[c][bel[c][x]]));
                v[c][bel[c][x]]+=1ll*(w-a[x])*len[c];
                ms.insert(v[c][bel[c][x]]);
                c++;
            }
            a[x]=w;
            printf("%lld\n",*ms.rbegin());
        }
    }
}