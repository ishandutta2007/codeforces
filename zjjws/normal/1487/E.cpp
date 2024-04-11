#include <vector>
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
    if(bj)return -s;
    return s;
}
inline void jh(int &x,int &y){if(x!=y)x^=y^=x^=y;return;}
inline void jh(LL &x,LL &y){if(x!=y)x^=y^=x^=y;return;}

const int N=1.5e5+3;
int z[N];
inline void init(){for(int i=1;i<N;i++){z[i]=z[i-1];if(i>(1<<z[i]+1))z[i]++;}return;}

int n[4];
int g[N];
int f[20][N];
int val[4][N];
inline int check(int l,int r){if(l>r)return 2e9+7;int L=z[r-l+1];return min(f[L][l],f[L][r-(1<<L)+1]);}

vector<int>nxt[N];


inline void work()
{
    for(int i=0;i<4;i++)n[i]=rin();
    for(int i=1;i<=n[0];i++)f[0][i]=rin();
    for(int i=1;i<4;i++)for(int j=1;j<=n[i];j++)val[i][j]=rin();
    for(int _=1;_<4;_++)
    {
        int now=n[_-1];
        for(int i=1;(1<<i)<=now;i++)for(int j=1;j+(1<<i)-1<=now;j++)f[i][j]=min(f[i-1][j],f[i-1][j+(1<<i-1)]);
        int m=rin();
        for(int i=1;i<=m;i++){int x=rin(),y=rin();nxt[y].push_back(x);}
        int all_f=check(1,now);
        for(int i=1;i<=n[_];i++)
        {
            if(nxt[i].empty()){g[i]=all_f;continue;}
            sort(nxt[i].begin(),nxt[i].end());
            g[i]=min(check(nxt[i].back()+1,n[_-1]),check(1,nxt[i].front()-1));
            for(int j=1;j<nxt[i].size();j++)g[i]=min(g[i],check(nxt[i][j-1]+1,nxt[i][j]-1));
            nxt[i].clear();
        }
        for(int i=1;i<=n[_];i++)f[0][i]=(g[i]>=2e9+7)?(2e9+7):(g[i]+val[_][i]);
    }
    int ans=2e9+7;
    for(int i=1;i<=n[3];i++)ans=min(ans,f[0][i]);
    printf("%d\n",(ans>4e8)?(-1):(ans));
    return;
}
int main()
{
    init();
    work();
    return 0;
}

//vjudge 