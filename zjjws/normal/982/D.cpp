#include <set>
#include <stdio.h>
#include <algorithm>
#define LL long long
using namespace std;
inline int rin()
{
    int s=0;
    bool bj=false;
    char c=getchar();
    for(;(c>'9'||c<'0')&&c!='-';c=getchar());
    if(c=='-')bj=true,c=getchar();
    for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
    if(bj)return -s;
    return s;
}

const int N=1e5+3;
int n;
int a[N];
int b[N];
inline bool myru_b(int x,int y){return a[x]>a[y];}
struct gyq
{
    int l,r;
    gyq(int l_=0,int r_=0){l=l_;r=r_;}
    inline bool operator >(gyq y)const {return r>y.r;}
    inline bool operator <(gyq y)const {return r<y.r;}
};
set<gyq>q;
int f[N<<2];
int g[N<<2];
inline void bing(int i){f[i]=max(f[i<<1],f[(i<<1)|1]);g[i]=g[i<<1]+g[(i<<1)|1];return;}
inline void add(int l,int r,int x,int i,int tag)
{
    if(l==r){f[i]+=tag;g[i]+=tag;return;}
    if(x<=(l+r>>1))add(l,l+r>>1,x,i<<1,tag);else add((l+r>>1)+1,r,x,(i<<1)|1,tag);
    bing(i);return;
}
int main()
{
    n=rin();for(int i=1;i<=n;i++)a[i]=rin(),b[i]=i;sort(b+1,b+n+1,myru_b);
    int ans=a[b[1]]+1;q.insert(gyq(1,n));add(1,n,n,1,1);
    int maxl=1;
    for(int k=1,i;k<=n;k=i)
    {
        for(i=k;i<=n&&a[b[i]]==a[b[k]];i++)
        {
            set<gyq>::iterator j=q.lower_bound(gyq(b[i],b[i]));
            int l=j->l,r=j->r;q.erase(j);add(1,n,r-l+1,1,-1);
            if(l<b[i]){q.insert(gyq(l,b[i]-1)),add(1,n,b[i]-l,1,1);/* printf("insert [%d,%d]\n",l,b[i]-1) */;}
            if(b[i]<r){q.insert(gyq(b[i]+1,r)),add(1,n,r-b[i],1,1);/* printf("insert [%d,%d]\n",b[i]+1,r) */;}
        }
        if(f[1]==g[1]&&f[1]>=maxl)maxl=f[1],ans=a[b[i]]+1;
    }
    printf("%d\n",ans);
    return 0;
}

//vjudge 