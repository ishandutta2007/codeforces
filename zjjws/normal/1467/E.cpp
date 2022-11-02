#include <stdio.h>
#include <vector>
#include <algorithm>
#define LL long long
using namespace std;
const int N=2e5+3;
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
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline void jh(int &x,int &y){if(x!=y)x^=y^=x^=y;return;}


int n;
struct gyq
{
    int val,num,dfn;
}a[N];
inline bool myru_gyq(gyq x,gyq y){return (x.val==y.val)?(x.dfn<y.dfn):(x.val<y.val);}
int nam;
vector<int>b[N];

int fa[20][N];
int dep[N];
int lar[N];
int dfn[N];
inline void dfs(int x,int Fa)
{
    a[x].dfn=++nam;
    dfn[x]=nam;
    dep[x]=dep[Fa]+1;
    lar[x]=1;
    fa[0][x]=Fa;
    for(int i=b[x].size()-1;i>=0;i--)
    {
        int to=b[x][i];
        if(to==Fa)continue;
        dfs(to,x);
        lar[x]+=lar[to];
    }
    return;
}

inline int Lca(int x,int y)
{
    if(dep[x]<dep[y])jh(x,y);
    for(int i=dep[x]-dep[y],j=0;i;i>>=1,j++)if(i&1)x=fa[j][x];
    for(int j=0;j>=0;)
    {
        if(fa[j][x]!=fa[j][y])x=fa[j][x],y=fa[j][y],j++;
        else j--;
    }
    if(x!=y)x=fa[0][x];
    return x;
}

int sl[N];
inline void add(int l,int r,int s){sl[l]+=s;sl[r+1]-=s;return;}
inline int work()
{
    n=rin();
    for(int i=1;i<=n;i++)a[i].val=rin(),a[i].num=i;
    for(int i=1;i<n;i++){int x=rin(),y=rin();b[x].push_back(y);b[y].push_back(x);}
    dfs(1,0);
    for(int i=1;i<20;i++)for(int j=1;j<=n;j++)fa[i][j]=fa[i-1][fa[i-1][j]];
    sort(a+1,a+n+1,myru_gyq);
    for(int i=1,j;i<=n;i=j)
    {
        for(j=i+1;j<=n&&a[j].val==a[i].val;j++)if(j!=i+1&&a[j].dfn<a[j-1].dfn+lar[a[j-1].num])return 0;
        if(j==i+1)continue;
        for(int _=i;_<j;_++)add(a[_].dfn,a[_].dfn,1);
        for(;true;)
        {
            int _;
            for(_=i+1;_<j;_++)
            {
                if(a[_].dfn>=a[i].dfn+(lar[a[i].num]))
                {
                    if(_==i+1)break;
                    return 0;
                }
            }
            if(_==j)
            {
                int z=a[i+1].num;
                for(_=i+2;_<j;_++)z=Lca(z,a[_].num);
                if(z==a[i].num)return 0;
                
                add(1,n,1);
                int lxt=z;
                for(int p=19;p>=0;p--)if(dfn[fa[p][lxt]]>a[i].dfn)lxt=fa[p][lxt];
                // printf("lxt:%d\n",lxt);
                add(dfn[lxt],dfn[lxt]+lar[lxt]-1,-1);
                // add(dfn[z],dfn[z]+lar[z]-1,1);
                i++;
            }
            break;
        }
        for(int _=i;_<j;_++)add(a[_].dfn,a[_].dfn+lar[a[_].num]-1,1);
    }
    int sum=0;
    LL cutt=0;
    for(int i=1;i<=n;i++)cutt+=sl[i],sum+=(cutt==0);
    return sum;
}
int main()
{
    int i,j;
    printf("%d\n",work());
    return 0;
}