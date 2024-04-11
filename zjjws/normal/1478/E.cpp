#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define LL long long
using namespace std;
inline LL rin()
{
    LL s=0;
    bool bj=false;
    char c=getchar();
    for(;(c>'9'||c<'0')&&c!='-';c=getchar());
    if(c=='-')bj=true,c=getchar();
    for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
    if(bj)s=-s;
    return s;
}
inline int gc(){char c=getchar();for(;c!='0'&&c!='1';c=getchar());return c-'0';}

const int N=3e5+3;

inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline LL max(LL x,LL y){return x>y?x:y;}
inline LL min(LL x,LL y){return x<y?x:y;}
inline void jh(int x,int y){if(x!=y)x^=y^=x^=y;return;}
inline void jh(LL x,LL y){if(x!=y)x^=y^=x^=y;return;}

int n,q;
int a[N];
int b[N];

struct gyq
{
    int l,r;
    int ls,rs;
    int tag;
    int f;
    inline void init(){ls=rs=tag=f=0;return;}
    inline void add_tag(int tag_){tag=tag_;f=(tag==1?(r-l+1):(0));return;}
}t[N<<1];
int nam;
inline void bing(int i){t[i].f=t[t[i].ls].f+t[t[i].rs].f;return;}
inline void down(int i)
{
    if(!t[i].tag)return;
    t[t[i].ls].add_tag(t[i].tag);
    t[t[i].rs].add_tag(t[i].tag);
    t[i].tag=0;
    return;
}
inline void make_tree(int l,int r,int i)
{
    t[i].l=l;t[i].r=r;t[i].init();
    if(l==r){t[i].f=b[l];return;}
    int mid=(l+r)>>1;
    make_tree(l,mid,t[i].ls=++nam);
    make_tree(mid+1,r,t[i].rs=++nam);
    bing(i);
    return;
}
inline int check(int l,int r,int i)
{
    if(l<=t[i].l&&t[i].r<=r)return t[i].f;
    down(i);
    int ans=0;
    if(t[t[i].ls].r>=l)ans+=check(l,r,t[i].ls);
    if(t[t[i].rs].l<=r)ans+=check(l,r,t[i].rs);
    return ans;
}
inline void add(int l,int r,int tag,int i)
{
    if(l<=t[i].l&&t[i].r<=r){t[i].add_tag(tag);return;}
    down(i);
    if(t[t[i].ls].r>=l)add(l,r,tag,t[i].ls);
    if(t[t[i].rs].l<=r)add(l,r,tag,t[i].rs);
    bing(i);
    return;
}

bool ans;
inline void dfs(int now)
{
    if(t[now].l==t[now].r){if(t[now].f!=a[t[now].l])ans=false;return;}
    down(now);
    dfs(t[now].ls);
    dfs(t[now].rs);
    return;
}

int l[N];
int r[N];
inline void work()
{
    n=rin();q=rin();
    for(int i=1;i<=n;i++)a[i]=gc();
    for(int i=1;i<=n;i++)b[i]=gc();
    for(int i=1;i<=q;i++)l[i]=rin(),r[i]=rin();
    make_tree(1,n,nam=1);
    for(int i=q;i>=1;i--)
    {
        int nows=check(l[i],r[i],1);
        if(((r[i]-l[i])&1)&&nows==(r[i]-l[i]+1>>1)){puts("NO");return;}
        add(l[i],r[i],(nows<=((r[i]-l[i])>>1))?2:1,1);
    }
    ans=true;dfs(1);
    puts(ans?"YES":"NO");
    return;
}
int main()
{
    for(int T=rin();T;T--)work();
    return 0;
}