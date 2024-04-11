#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T,n,a[N];

vector<pair<int,int>>g;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(auto &[x,y]:g)
            x=__gcd(x,a[i]);
        g.push_back({a[i],i});
        vector<pair<int,int> >ng;
        for(auto [x,p]:g)
            if(ng.size()&&ng.back().first==x)
                ng.back().second=p;
            else
                ng.push_back({x,p});
        g=ng;
        bool ok=1;
        int l=1;
        for(int j=0;j<g.size();j++)
        {
            int r=g[j].second;
            int v=g[j].first;
            //i - v + 1 == pos
            if(l<=i-v+1&&i-v+1<=r)
                ok=0;
            l=r+1;
        }
        if(!ok)
            ans++,g={{0,0},{998244353,i}};
        printf("%d%c",ans," \n"[i==n]);
    }
}