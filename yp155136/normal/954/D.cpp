#include <bits/stdc++.h>
using namespace std;

const int N = 1006;
const int INF = (1<<20);

int ds[N],dt[N];

vector<int> G[N];

void sagiri(int *dis,int s)
{
    fill(dis,dis+N,INF);
    dis[s] = 0;
    queue<int> que;
    que.push(s);
    while (!que.empty())
    {
        int t=que.front();
        que.pop();
        for (int i:G[t])
        {
            if (dis[i] > dis[t] + 1)
            {
                dis[i] = dis[t] + 1;
                que.push(i);
            }
        }
    }
}

bool adj[N][N];

int main ()
{
    int n,m,s,t;
    scanf("%d %d %d %d",&n,&m,&s,&t);
    for (int i=1;m>=i;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
        adj[x][y] = 1;
        adj[y][x] = 1;
    }
    sagiri(ds,s);
    sagiri(dt,t);
    int ans=0;
    for (int i=1;n>=i;i++)
    {
        //cout << "ds = "<<ds[i]<<" , dt = "<<dt[i]<<endl;
        for (int j=i+1;n>=j;j++)
        {
            if(i==j || adj[i][j]) continue;
            int now = min( ds[i] + 1 + dt[j],ds[j] + 1 + dt[i] );
            //cout << "i = "<<i<<" , j = "<<j<<" , now = "<<now<<endl;
            if (now >= ds[t]) ++ans;
        }
    }
    printf("%d\n",ans);
}