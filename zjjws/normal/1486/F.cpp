#include <vector>
#include <stdio.h>
#include <algorithm>
#define LL long long
#pragma GCC optimize(3)
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
inline void jh(int &x,int &y){if(x^y)x^=y^=x^=y;return;}
const int N=3e5+3;
int n,m;

namespace St
{
    vector<int>nxt[N];
    int f[20][N];
    int dep[N];
    inline void dfs(int x,int fa){dep[x]=dep[fa]+1;f[0][x]=fa;for(vector<int>::iterator i=nxt[x].begin();i!=nxt[x].end();i++)if((*i)!=fa)dfs(*i,x);}
    inline int Lca(int x,int y)
    {
        if(dep[x]<dep[y])jh(x,y);
        for(int i=dep[x]-dep[y],j=0;i;i>>=1,j++)if(i&1)x=f[j][x];
        for(int j=0;j>=0;){if(f[j][x]!=f[j][y])x=f[j][x],y=f[j][y],j++;else j--;}
        if(x!=y)x=f[0][x];
        return x;
    }
    inline int find(int x,int y){for(int i=dep[x]-dep[y]-1,j=0;i>0;i>>=1,j++)if(i&1)x=f[j][x];return x;}
}
using namespace St;


vector<int>a[N];
vector<pair<int,int> >b[N];
int les[N];
int cutt[N];
int ruir[N];
int ruier[N];
LL ans;

inline void init_ans(int x,int fa)
{
    int cuts=a[x].size()+b[x].size();
    for(vector<int>::iterator i=nxt[x].begin();i!=nxt[x].end();i++)if((*i)!=fa)init_ans(*i,x),ruir[x]+=ruir[*i];
    ans+=1LL*ruir[x]*ruier[x];ans+=1LL*ruier[x]*(ruier[x]-1)>>1;
    for(vector<int>::iterator i=a[x].begin();i!=a[x].end();i++)ruir[*i]--;
    for(vector<pair<int,int> >::iterator i=b[x].begin();i!=b[x].end();i++)ruir[i->first]--,ruir[i->second]--;
    for(vector<int>::iterator i=a[x].begin();i!=a[x].end();i++)ans+=(ruir[x]-cuts-ruir[*i]);
    for(vector<pair<int,int> >::iterator i=b[x].begin();i!=b[x].end();i++)ans+=(ruir[x]-cuts-ruir[i->first]-ruir[i->second]);
    ans+=1LL*cuts*(cuts-1)>>1;
    sort(b[x].begin(),b[x].end());
    for(vector<int>::iterator j=a[x].begin();j!=a[x].end();j++)ans-=cutt[*j],cutt[*j]++;
    for(vector<pair<int,int> >::iterator j=b[x].begin(),k;j!=b[x].end();j=k)
    {
        int nows=1;
        for(k=j+1;k!=b[x].end()&&(*j)==(*k);k++)nows++;
        ans-=1LL*nows*(nows-1)>>1;
        ans-=1LL*(cutt[j->first]+cutt[j->second])*nows;
        cutt[j->first]+=nows;cutt[j->second]+=nows;
    }
    for(vector<int>::iterator j=a[x].begin();j!=a[x].end();j++)cutt[*j]--;
    for(vector<pair<int,int> >::iterator j=b[x].begin();j!=b[x].end();j++)cutt[j->first]--,cutt[j->second]--;
    ruir[x]-=les[x];
    return;
}
int main()
{
    n=rin();for(int i=1;i<n;i++){int x=rin(),y=rin();nxt[x].push_back(y);nxt[y].push_back(x);}
    dfs(1,0);for(int i=1;(1<<i)<=n;i++)for(int j=1;j<=n;j++)f[i][j]=f[i-1][f[i-1][j]];
    m=rin();
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        x=rin();y=rin();if(x==y){ruier[x]++;continue;}
        if(dep[x]<dep[y])jh(x,y);
        z=Lca(x,y);
        int x_=find(x,z),y_=find(y,z);
        if(y==z)a[z].push_back(x_);
        else b[z].push_back(make_pair(min(x_,y_),max(x_,y_)));
        ruir[x]++;ruir[y]++;ruir[z]--;les[z]++;
    }
    init_ans(1,0);
    printf("%lld\n",ans);
    return 0;
}