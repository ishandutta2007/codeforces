#include<iostream>
#include<cstdio>
#include<cmath>
#define ll long long
using namespace std;
int read()
{
    int ret=0;char c=getchar();
    while(c>'9'||c<'0')c=getchar();
    while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
    return ret;
}
const int maxn=1e5+5;
int T;
int n;
ll ans;
bool a[maxn];
int q[2][maxn],cnt[2];
int p[maxn];
struct fenwick
{
    int b[maxn];
    void clear(){for(int i=1;i<=n;i++)b[i]=0;}
    void change(int p,int x){for(int i=p;i<=n;i+=i&(-i))b[i]+=x;}
    int query(int p)
    {
        int ret=0;
        for(int i=p;i;i-=i&(-i))ret+=b[i];
        return ret;
    }
}tr;
ll calc()
{
    ll ret=0;tr.clear();
    for(int i=n;i>=1;i--){ret+=tr.query(p[i]);tr.change(p[i],1);}
    return ret;
}
int main()
{
    T=read();
    while(T--)
    {
        n=read();cnt[0]=cnt[1]=0;ans=(ll)n*n;
        for(int i=1;i<=n;i++)
        {
            a[i]=(read()&1);
            q[a[i]][++cnt[a[i]]]=i;
        }
        if(abs(cnt[0]-cnt[1])>1){printf("-1\n");continue;}
        if(cnt[0]==cnt[1])
        {
            for(int i=1;i<=cnt[0];i++)p[i*2]=q[0][i];
            for(int i=1;i<=cnt[1];i++)p[i*2-1]=q[1][i];
            ans=min(ans,calc());
            for(int i=1;i<=cnt[1];i++)p[i*2]=q[1][i];
            for(int i=1;i<=cnt[0];i++)p[i*2-1]=q[0][i];
            ans=min(ans,calc());
        }
        else
        {
            if(cnt[0]>cnt[1])
            {
                for(int i=1;i<=cnt[1];i++)p[i*2]=q[1][i];
                for(int i=1;i<=cnt[0];i++)p[i*2-1]=q[0][i];
            }
            else
            {
                for(int i=1;i<=cnt[0];i++)p[i*2]=q[0][i];
                for(int i=1;i<=cnt[1];i++)p[i*2-1]=q[1][i];
            }
            ans=min(ans,calc());
        }
        printf("%lld\n",ans);
    }
    return 0;
}