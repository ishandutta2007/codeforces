#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T,n,u[N],x[N];

vector<int>v[N];

typedef long long ll;

vector<ll> s[N];

ll ans[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            s[i].clear(),s[i].push_back(0),v[i].clear(),ans[i]=0;
        for(int i=1;i<=n;i++)
            scanf("%d",&u[i]);
        for(int i=1;i<=n;i++)
            scanf("%d",&x[i]),v[u[i]].push_back(x[i]);
        for(int i=1;i<=n;i++)
        {
            sort(v[i].begin(),v[i].end(),greater<int>());
            for(auto x:v[i])
                s[i].push_back(x+s[i].back());
            for(int j=1;j<=v[i].size();j++)
                ans[j]+=s[i][v[i].size()/j*j];
        }
        for(int i=1;i<=n;i++)
            printf("%lld%c",ans[i]," \n"[i==n]);
    }
}