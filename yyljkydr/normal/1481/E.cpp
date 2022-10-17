#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int n,a[N],p[N],s[N];

vector<int>v;

bool cmp(int a,int b)
{
    return p[a]<p[b];
}

int c[N],f[N],cnt[N],bac[N];

void add(int x,int v)
{
    while(x<=n)
    {
        c[x]=min(c[x],v);
        x+=x&-x;
    }
}

int query(int x)
{
    int ret=1e9;
    while(x)
    {
        ret=min(ret,c[x]);
        x-=x&-x;
    }
    return ret;
}

int main()
{
    scanf("%d",&n);
    int tot=0;
    for(int i=1;i<=n;i++)
        s[i]=n+1,c[i]=1e9,f[i]=1e9;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),p[a[i]]=max(p[a[i]],i),s[a[i]]=min(s[a[i]],i);
    bac[n+1]=0;
    for(int i=n;i>=1;i--)
        cnt[a[i]]++,bac[i]=max(bac[i+1],cnt[a[i]]);
    for(int i=n;a[i]==a[n];i--)
        tot++;
    for(int i=1;i<=n;i++)
        if(p[i])
            v.push_back(i);
    sort(v.begin(),v.end(),cmp);
    int ans=1e9;
    for(auto x:v)
    {
        int mn=query(s[x]);
        mn=min(mn,0);
        f[x]=p[x]+mn-cnt[x];
        ans=min(ans,f[x]+n-p[x]-bac[p[x]+1]);
        add(p[x],f[x]-p[x]);
    }
    printf("%d\n",ans);
}