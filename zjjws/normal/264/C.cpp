#include <bits/stdc++.h>
#define LL long long
#define jh(a,b) a^=b^=a^=b
#define max(a,b) a>b?a:b
using namespace std;
const int N=1e5+3;
int c[N];
LL v[N];
LL f[N];
LL s[2];
int cs[2];
int n,q;
LL a,b;
int rin()
{
    int s=0;
    char c=getchar();
    bool bj=0;
    for(;(c>'9'||c<'0')&&c!='-';c=getchar());
    if(c=='-')c=getchar(),bj=true;
    for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
    if(bj)return -s;
    return s;
}
int main()
{
    int i,j;
    n=rin();q=rin();
    for(i=1;i<=n;i++)v[i]=rin();
    for(i=1;i<=n;i++)c[i]=rin();
    for(;q>0;q--)
    {
        a=rin();b=rin();
        memset(f,-0x3f,sizeof(f));
        s[0]=0;s[1]=f[0];
        cs[0]=0,cs[1]=-1;
        LL ans=0;
        for(i=1;i<=n;i++)
        {
            LL now_s=f[0];
            if(f[c[i]]!=f[0])
            {
                now_s=f[c[i]]+v[i]*a;
                if(f[c[i]]==s[0]&&s[1]!=f[0])now_s=max(now_s,s[1]+v[i]*b);
                else now_s=max(now_s,s[0]+v[i]*b);
            }
            else now_s=max(now_s,s[0]+v[i]*b);
            if(now_s>s[0])
            {
                if(cs[0]==c[i])s[0]=now_s;
                else s[1]=s[0],cs[1]=cs[0],s[0]=now_s,cs[0]=c[i];
            }
            else if(now_s>s[1]&&cs[0]!=c[i])s[1]=now_s,cs[1]=c[i];
            f[c[i]]=max(f[c[i]],now_s);
            ans=max(ans,now_s);
        }
        printf("%lld\n",ans);
    }
    return 0;
}