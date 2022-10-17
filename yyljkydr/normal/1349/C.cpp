#include<bits/stdc++.h>
using namespace std;

const int N=1e3+1e2+7;

int n,m,Q;

char mp[N][N];

queue<int>q;

int d[N*N];

int id(int x,int y)
{
    return (x-1)*m+y;
}

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

void bfs()
{
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        int x=(t-1)/m+1,y=(t-1)%m+1;
        for(int i=0;i<4;i++)
        {
            int tx=x+dx[i],ty=y+dy[i];
            if(tx<1||tx>n||ty<1||ty>m||d[id(tx,ty)]!=1e9)
                continue;
            q.push(id(tx,ty));
            d[id(tx,ty)]=d[id(x,y)]+1;
        }
    }
}

int main()
{
    scanf("%d%d%d",&n,&m,&Q);
    for(int i=1;i<=n;i++)
        scanf("%s",mp[i]+1);
    for(int i=1;i<=n*m;i++)
        d[i]=1e9;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(i-1&&mp[i-1][j]==mp[i][j])
                d[id(i,j)]=d[id(i-1,j)]=0;
            if(j-1&&mp[i][j-1]==mp[i][j])
                d[id(i,j)]=d[id(i,j-1)]=0;
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(d[id(i,j)]==0)
                q.push(id(i,j));
    bfs();
    while(Q--)
    {
        int x,y;
        long long t;
        scanf("%d%d%lld",&x,&y,&t);
        if(d[id(x,y)]==1e9||t<d[id(x,y)])
            putchar(mp[x][y]),puts("");
        else
        {
            long long rt=(t-d[id(x,y)])&1;
            int ans=(mp[x][y]-'0')^rt;
            printf("%d\n",ans);
        }
    }
}