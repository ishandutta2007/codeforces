#include <map>
#include <stdio.h>
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
    if(bj)return -s;
    return s;
}
const int N=1e5+3;
const int M=1e9+7;
const int INF=2e9+7;
int h,w,n;

struct quest
{
    int x,l,r,s;
    inline void Read(){x=rin();l=rin();r=rin();s=rin();return;}
}q[N];
inline bool myru_quest(quest x,quest y){return x.x>y.x;}

int tc;
int f[N<<2];
map<int,int>g[N];
inline void bing(int i){f[i]=min(f[i<<1],f[(i<<1)|1]);return;}
inline void make_tree(int l,int r,int i)
{
    if(l==r){g[l][h+1]=1;f[i]=h+1;return;}
    int mid=l+r>>1;make_tree(l,mid,i<<1);make_tree(mid+1,r,(i<<1)|1);bing(i);
    return;
}

inline int check(int l,int r,int i,int ql,int qr,int qy)
{
    if(f[i]>qy)return 0;
    int ans=0;
    if(l==r)
    {
        for(;!g[l].empty();)
        {
            map<int,int>::iterator i=g[l].begin();
            if(i->first>qy)break;
            ans+=i->second;ans%=M;g[l].erase(i);
        }
        if(g[l].empty())f[i]=INF;else f[i]=(g[l].begin()->first);
        return ans;
    }
    int mid=l+r>>1;
    if(mid>=ql)ans+=check(l,mid,i<<1,ql,qr,qy);
    if(mid+1<=qr)ans+=check(mid+1,r,(i<<1)|1,ql,qr,qy);ans%=M;
    bing(i);
    return ans;
}

pair<int,int>ads;
inline void add(int l,int r,int i,int x)
{
    if(l==r){g[l].insert(ads);f[i]=(g[l].begin()->first);return;}
    int mid=l+r>>1;
    if(x<=mid)add(l,mid,i<<1,x);else add(mid+1,r,(i<<1)|1,x);
    bing(i);
    return;
}
inline void work(int l,int r,int x,int y)
{
    int cutt=check(1,w,1,l,r,y);
    if(l==1||r==w)cutt=(cutt<<1)%M;
    ads.first=x;ads.second=cutt;if(l!=1)add(1,w,1,l-1);if(r!=w)add(1,w,1,r+1);
    return;
}
int main()
{
    h=rin();w=rin();n=rin();
    for(int i=1;i<=n;i++)q[i].Read();
    sort(q+1,q+n+1,myru_quest);make_tree(1,w,1);
    for(int i=1;i<=n;i++)work(q[i].l,q[i].r,q[i].x,q[i].x+q[i].s);
    int ans=0;
    for(int i=1;i<=w;i++)for(map<int,int>::iterator j=g[i].begin();j!=g[i].end();j++)ans=(ans+j->second)%M;
    printf("%d\n",ans);
    return 0;
}

//vjudge 