#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e5+1e3+7,P=1e9+7;

int n,q,a[N];

multiset<int>s[N];

map<int,int>cnt[N];

signed main()
{
    scanf("%lld%lld",&n,&q);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        int x=a[i];
        for(int j=2;j*j<=x;j++)
            if(x%j==0)
            {
                while(x%j==0)
                    x/=j,cnt[i][j]++;
                s[j].insert(cnt[i][j]);
            }
        if(x!=1)
        {
            int j=x;
            while(x%j==0)
                    x/=j,cnt[i][j]++;
            s[j].insert(cnt[i][j]);
        }
    }
    int ans=1;
    for(int i=1;i<=200000;i++)
        if(s[i].size()==n)
        {
            int x=*s[i].begin();
            for(int j=1;j<=x;j++)
                ans=ans*i%P;
        }
    while(q--)
    {
        int x,y;
        scanf("%lld%lld",&x,&y);
        for(int j=2;j*j<=y;j++)
            if(y%j==0)
            {
                int p=s[j].size()==n?*s[j].begin():0;
                if(cnt[x][j])
                    s[j].erase(s[j].find(cnt[x][j]));
                while(y%j==0)
                    y/=j,cnt[x][j]++;
                s[j].insert(cnt[x][j]);
                int q=*s[j].begin();
                if(s[j].size()==n)
                    for(int t=1;t<=q-p;t++)
                        ans=ans*j%P;
            }
        if(y!=1)
        {
            int j=y;
            int p=s[j].size()==n?*s[j].begin():0;
                if(cnt[x][j])
                    s[j].erase(s[j].find(cnt[x][j]));
                while(y%j==0)
                    y/=j,cnt[x][j]++;
                s[j].insert(cnt[x][j]);
                int q=*s[j].begin();
                if(s[j].size()==n)
                    for(int t=1;t<=q-p;t++)
                        ans=ans*j%P;
        }
        printf("%lld\n",ans);
    }
}