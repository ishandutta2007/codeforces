#include<bits/stdc++.h>
using namespace std;

const int N=511;

int n,m;

char mp[N][N];

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

int id(int x,int y)
{
    return (x-1)*m+y;
}

vector<int>v,g[N*N];

int ans[N*N];

void dfs(int x,int c)
{
    ans[x]=c;
    for(auto v:g[x])
    {
        if(!ans[v])
            dfs(v,c^5);
        else
        {
            if(ans[v]!=(ans[x]^5))
            {
                puts("NO");
                exit(0);
            }
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%s",mp[i]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(mp[i][j]!='X')
                continue;
            int cnt=0;
            v.clear();
            for(int t=0;t<4;t++)
            {
                int nx=i+dx[t],ny=j+dy[t];
                if(nx<1||nx>n||ny<1||ny>m||mp[nx][ny]=='X')
                    continue;
                v.push_back(id(nx,ny));
            }
            if(v.size()&1)
            {
                puts("NO");
                return 0;
            }
            for(int i=0;i<v.size();i++)
            {
                g[v[i]].push_back(v[(i+1)%v.size()]);
                g[v[(i+1)%v.size()]].push_back(v[i]);
            }
            v.clear();
        }
    for(int i=1;i<=n*m;i++)
    {
        int x=(i-1)/m+1,y=(i-1)%m+1;
        if(mp[x][y]=='.')
        {
            if(!ans[i])
                dfs(i,1);
        }
    }
    
    for(int i=1;i<=n*m;i++)
    {
        int x=(i-1)/m+1,y=(i-1)%m+1;
        if(mp[x][y]=='X')
        {
            for(int t=0;t<4;t++)
            {
                int nx=x+dx[t],ny=y+dy[t];
                if(nx<1||nx>n||ny<1||ny>m||mp[nx][ny]=='X')
                    continue;
                ans[i]+=ans[id(nx,ny)];
            }
        }
    }
    puts("YES");
    for(int i=1;i<=n*m;i++)
        printf("%d%c",ans[i]," \n"[i%m==0]);
}