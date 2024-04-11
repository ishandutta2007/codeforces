#include<bits/stdc++.h>
#define maxn 100050
using namespace std;

int n,m;
vector<int> G[maxn];

bool vis[maxn];
priority_queue<int> q;

int main()
{
    scanf("%d%d",&n,&m);
    while (m--)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    q.push(-1),vis[1]=1;
    while (!q.empty())
    {
        int i=-q.top();    q.pop();
        printf("%d ",i);
        for (int j:G[i])
        {
            if (vis[j]) continue;
            q.push(-j),vis[j]=1;
        }
    }
    return 0;
}