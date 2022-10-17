#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T;

vector<int>v[N];

int cnt[N],x[N],y[N];

int a,b,k;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&a,&b,&k);
        for(int i=1;i<=a;i++)
            v[i].clear();
        for(int i=1;i<=b;i++)
            cnt[i]=0;
        for(int i=1;i<=k;i++)
            scanf("%d",&x[i]);
        for(int i=1;i<=k;i++)
            scanf("%d",&y[i]),v[x[i]].push_back(y[i]);
        long long ans=0,sum=0;
        for(int i=1;i<=a;i++)
        {
            for(auto x:v[i])
                ans+=sum-cnt[x];
            for(auto x:v[i])
                sum++,cnt[x]++;
        }
        printf("%lld\n",ans);
    }
}