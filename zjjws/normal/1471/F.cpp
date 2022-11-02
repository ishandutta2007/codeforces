#include <stdio.h>
#define LL long long
using namespace std;
const int N=3e5+3;
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


int n,m;
int col[N];
bool vit[N];
struct gyq
{
    int to,nxt;
}a[N<<1];
int h[N];
int nam;
inline void add(int x,int y)
{
    a[++nam].to=y;a[nam].nxt=h[x];h[x]=nam;
    a[++nam].to=x;a[nam].nxt=h[y];h[y]=nam;
    return;
}

int cts;
int ans;
inline void dfs(int x,int c)
{
    col[x]=c;cts++;
    vit[x]=true;
    if(c==1)
    {
        ans++;
        for(int i=h[x];i;i=a[i].nxt)col[a[i].to]=2;
        for(int i=h[x];i;i=a[i].nxt)if(!vit[a[i].to])dfs(a[i].to,2);
    }
    else
    {
        for(int i=h[x];i;i=a[i].nxt)
        {
            if(col[a[i].to])continue;
            dfs(a[i].to,1);
        }
    }
    return;
}
inline void work()
{
    n=rin();m=rin();
    cts=nam=ans=0;
    for(int i=1;i<=n;i++)col[i]=h[i]=vit[i]=0;
    for(int i=1;i<=m;i++)add(rin(),rin());
    dfs(1,1);
    if(cts!=n){puts("NO");return;}
    puts("YES");
    printf("%d\n",ans);
    for(int i=1;i<=n;i++)if(col[i]==1)printf("%d ",i);printf("\n");
    return;
}
int main()
{
    int i,j;
    for(int T=rin();T;T--)work();
    return 0;
}