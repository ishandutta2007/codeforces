#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e5+1e3+7;

int n,a[N],k[N];

int cnt[N];

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

pii gans[N];

pair<int,int> chk(int t)
{
    for(int i=1;i<=200000;i++)
        cnt[i]=0;
    for(int i=1;i<=n;i++)
        cnt[a[i]]+=min(t,k[i]);
    nth_element(cnt+1,cnt+200000-t,cnt+200000+1);
    pii ret=mp(0,t);
    for(int i=200000;i>=200000-t+1;i--)
        ret.fs+=cnt[i];
    return ret;
}

bool cmp(pii a,pii b)
{
    return a.fs*b.sd<a.sd*b.fs;
}

signed main()
{
    scanf("%lld",&n); 
    for(int i=1;i<=n;i++)
        scanf("%lld%lld",&a[i],&k[i]);
    pii ans=mp(0,1);
    for(int i=1;i<=200;i++)
    {
        pii tmp=chk(i);
        if(cmp(ans,tmp))
            ans=tmp;
    }
    printf("%lld\n",ans.sd);
    for(int i=1;i<=n;i++)
        gans[a[i]].fs+=min(ans.sd,k[i]);
    for(int i=1;i<=200000;i++)
        gans[i].sd=i;
    sort(gans+1,gans+200000+1,greater<pii>());
    for(int i=1;i<=ans.sd;i++)
        printf("%lld%c",gans[i].sd," \n"[i==ans.sd]);
}