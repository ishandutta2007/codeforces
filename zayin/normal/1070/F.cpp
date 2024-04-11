#include<bits/stdc++.h>
#define maxn 400050
using namespace std;
typedef long long LL;

int n;
LL a[maxn];

vector<int> d[4];

char s[5];

int get()
{
    scanf("%s",s);
    return (s[0]-'0')*2+(s[1]-'0');
}

void init()
{
    LL x;
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        int c=get();
        scanf("%lld",&x);
        d[c].push_back(x);
    }
    for (int c=0;c<4;++c)
        sort(d[c].begin(),d[c].end());
}

void solve()
{
    int c=d[2].size()<d[1].size()?1:2;
    
    LL ans=0;
    for (auto x:d[3])
        ans+=x;
    for (auto x:d[c^3])
        ans+=x;
    for (int k=d[c^3].size();k--;d[c].pop_back())
        ans+=d[c].back();
    
    //cout<<ans<<endl;
    
    for (int k=d[3].size();k--;)
    {
        if (!d[c].size()&&!d[0].size()) break;
        if (d[c].size()&&(!d[0].size()||d[c].back()>d[0].back()))
            ans+=d[c].back(),d[c].pop_back();
        else
            ans+=d[0].back(),d[0].pop_back();
    }
    printf("%lld\n",ans);
}

int main()
{
    init();
    solve();
    return 0;
}