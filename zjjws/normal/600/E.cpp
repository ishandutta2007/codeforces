#include <stdio.h>
#include <vector>
#define LL long long
using namespace std;
const int N=1e5+3;
int n;
inline int min(int x,int y){return x<y?x:y;}
inline int max(int x,int y){return x>y?x:y;}
inline int rin()
{
    int s=0;
    bool bj=false;
    char c=getchar();
    for(;(c>'9'||c<'0')&&c!='-';c=getchar());
    if(c=='-')bj=true,c=getchar();
    for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
    if(bj)s=-s;
    return s;
}

struct milk
{
    int l,r;
    int ls,rs;
    int s;
    LL ans;
    inline void mem0(){ls=rs=s=ans=0;return;}
}t[N<<5];
int st[N];
int nam;
inline void bing(int i)
{
    if(t[t[i].ls].s==t[t[i].rs].s)t[i].ans=t[t[i].ls].ans+t[t[i].rs].ans;
    else t[i].ans=(t[t[i].ls].s>t[t[i].rs].s)?(t[t[i].ls].ans):(t[t[i].rs].ans);
    t[i].s=max(t[t[i].ls].s,t[t[i].rs].s);
    return;
}
inline void add(int i,int s)
{
    if(t[i].l==t[i].r){t[i].s=1;t[i].ans=t[i].l;return;}
    int mid=(t[i].l+t[i].r)>>1;
    if(mid>=s)t[i].ls=++nam,t[nam].l=t[i].l,t[nam].r=mid,t[nam].mem0(),add(t[i].ls,s);
    else t[i].rs=++nam,t[nam].l=mid+1,t[nam].r=t[i].r,t[nam].mem0(),add(t[i].rs,s);
    bing(i);
    return;
}
inline void joojoo(int x,int y)
{
    if(t[x].l==t[x].r){t[x].s+=t[y].s;return;}
    if(t[x].ls||t[y].ls){if(!t[x].ls)t[x].ls=t[y].ls,t[y].ls=0;else if(t[y].ls)joojoo(t[x].ls,t[y].ls);}
    if(t[x].rs||t[y].rs){if(!t[x].rs)t[x].rs=t[y].rs,t[y].rs=0;else if(t[y].rs)joojoo(t[x].rs,t[y].rs);}
    bing(x);
    return;
}

vector<int>a[N];
LL ans[N];
inline void dfs(int x,int fa)
{
    for(int i=a[x].size()-1;i>=0;i--)
    {
        int to=a[x][i];
        if(to==fa)continue;
        dfs(to,x);
        joojoo(st[x],st[to]);
    }
    ans[x]=t[st[x]].ans;
}
int main()
{
    int i,j;
    n=rin();
    for(i=1;i<=n;i++)st[i]=++nam,t[nam].l=1,t[nam].r=n,t[nam].mem0(),add(st[i],rin());
    for(i=1;i<n;i++){int x=rin(),y=rin();a[x].push_back(y);a[y].push_back(x);}
    dfs(1,0);
    for(i=1;i<=n;i++)printf("%lld ",ans[i]);printf("\n");
    return 0;
}