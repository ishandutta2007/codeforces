#include <stdio.h>
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
const int N=3e2+3;
const int Q=2e6+3;

int n,m,q;
int x[Q];
int y[Q];
int c[Q];
int lst[Q];

int col[N][N];
bool tag[N][N];
int cutt;
int st;

int X[4]={0,0,1,-1};
int Y[4]={1,-1,0,0};

int f[N*N];
inline int find(int x){return f[x]==x?x:(f[x]=find(f[x]));}
inline int num(int x,int y){return (x-1)*m+y;}
inline void dfs(int x,int y)
{
    tag[x][y]=true;f[num(x,y)]=st;
    for(int i=0;i<4;i++){int xt=x+X[i],yt=y+Y[i];if(xt<=0||yt<=0||xt>n||yt>m||col[xt][yt]!=col[x][y]||tag[xt][yt])continue;dfs(xt,yt);}
    return;
}

int sl[Q];
int sr[Q];

bool kl[N][N];
int main()
{
    n=rin();m=rin();q=rin();
    for(int i=1;i<=q;i++)x[i]=rin(),y[i]=rin(),c[i]=rin(),lst[i]=col[x[i]][y[i]],col[x[i]][y[i]]=c[i];
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(!tag[i][j])sr[q]++,st=num(i,j),dfs(i,j);
    for(int i=q,j,lt=0;i>=1;i=j)
    {
        for(j=i;j>=1&&c[j]==c[i];j--)f[num(x[j],y[j])]=num(x[j],y[j]),kl[x[j]][y[j]]=false;
        for(int _=j+1;_<=i;_++)
        {
            sl[_]+=(_==j+1)?(0):(sl[_-1]);
            if(kl[x[_]][y[_]])continue;
            sl[_]++;kl[x[_]][y[_]]=true;
            for(int i_=0;i_<4;i_++)
            {
                int xt=x[_]+X[i_],yt=y[_]+Y[i_];
                if(xt<=0||yt<=0||xt>n||yt>m||!kl[xt][yt]||find(num(xt,yt))==find(num(x[_],y[_])))continue;
                f[find(num(xt,yt))]=find(num(x[_],y[_]));sl[_]--;
            }
        }
        for(int _=j+1;_<=i;_++)kl[x[_]][y[_]]=false;
        for(int _=j+1;_<=i;_++)f[num(x[_],y[_])]=num(x[_],y[_]);
        sr[i]-=sl[i];
        for(int _=i;_>j;_--)
        {
            sr[_-1]+=sr[_];
            if(col[x[_]][y[_]]==lst[_])continue;
            sr[_-1]++;col[x[_]][y[_]]=lst[_];
            for(int i_=0;i_<4;i_++)
            {
                int xt=x[_]+X[i_],yt=y[_]+Y[i_];
                if(xt<=0||yt<=0||xt>n||yt>m||col[xt][yt]!=col[x[_]][y[_]]||find(num(xt,yt))==find(num(x[_],y[_])))continue;
                f[find(num(xt,yt))]=find(num(x[_],y[_]));sr[_-1]--;
            }
        }
    }
    for(int i=1;i<=q;i++)printf("%d\n",sl[i]+sr[i]);
    return 0;
}

//vjudge 