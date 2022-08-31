#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 505

using namespace std;

int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
char mp[SIZE][SIZE];
bool use[SIZE][SIZE];
int n,m,k;

void dfs(int x,int y)
{
    use[x][y]=true;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(0<=nx&&nx<n&&0<=ny&&ny<m&&mp[nx][ny]=='.'&&!use[nx][ny])
        {
            dfs(nx,ny);
        }
    }
    if(k>0)
    {
        k--;
        mp[x][y]='X';
    }
}
int main()
{
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<n;i++) scanf("%s",&mp[i]);
    int sx=-1,sy=-1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mp[i][j]=='.')
            {
                sx=i;
                sy=j;
            }
        }
    }
    if(sx>=0&&sy>=0) dfs(sx,sy);
    for(int i=0;i<n;i++) printf("%s\n",mp[i]);
    return 0;
}