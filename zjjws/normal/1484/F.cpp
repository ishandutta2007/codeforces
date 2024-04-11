#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#define LL long long
using namespace std;
inline LL rin()
{
    LL x=0;
    char c;
    bool tag=false;
    for(c=getchar();c>'9'||c<'0';c=getchar())if(c=='-'){c=getchar();tag=true;break;}
    for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^'0');
    if(tag)x=-x;
    return x;
}
inline void jh(int &x,int &y){if(x^y)x^=y^=x^=y;return;}
inline void jh(LL &x,LL &y){if(x^y)x^=y^=x^=y;return;}

const int N=6e2+3;
int n,m,q;
bool tag[N][N];
int len[N][N];
LL dis[N][N];
LL val[N];

vector<pair<int,int> >que[N*N>>1];
inline void work()
{
    memset(dis,0x3f,sizeof(dis));n=rin();m=rin();
    for(int i=1;i<=n;i++)dis[i][i]=0;
    for(int i=1,x,y;i<=m;i++){x=rin();y=rin();len[x][y]=len[y][x]=dis[x][y]=dis[y][x]=rin();}
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)for(int k=1;k<=n;k++)if(j!=k)dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
    q=rin();for(int i=1,x,y,z;i<=q;i++){if(x>y)jh(x,y);x=rin();y=rin();z=rin();que[x].push_back(make_pair(y,z));}
    for(int i=1;i<=n;i++)
    {
        if(que[i].empty())continue;
        for(int k=1;k<=n;k++)val[k]=-0x3f3f3f3f3f3f3f;
        for(vector<pair<int,int> >::iterator j=que[i].begin();j!=que[i].end();j++)for(int k=1;k<=n;k++)val[k]=max(val[k],j->second-dis[k][j->first]);
        // for(int j=1;j<=n;j++)printf("%lld ",val[j]);printf("\n");
        for(int j=1;j<=n;j++)for(int k=1;k<=n;k++)if(len[j][k]&&dis[i][j]+len[j][k]<=val[k])tag[j][k]=true;
    }
    int ans=0;
    // puts("len:");for(int i=1;i<=n;i++){for(int j=1;j<=n;j++)printf("%d ",len[i][j]);printf("\n");}
    // puts("tag:");for(int i=1;i<=n;i++){for(int j=1;j<=n;j++)printf("%d ",tag[i][j]);printf("\n");}
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(tag[i][j])ans++,tag[i][j]=tag[j][i]=false;
    printf("%d\n",ans);
    return;
}
int main()
{
    work();
    return 0;
}

//vjudge 