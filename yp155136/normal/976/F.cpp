#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)(x).size())

typedef pair<int,int> pii;

struct Dinic
{
    static const int N= 4006;
    struct Edge {
        int to,cap,rev;
        Edge(){}
        Edge(int _to,int _cap,int _rev) : to(_to),cap(_cap),rev(_rev){}
    };
    vector<Edge> G[N];
    void add_edge(int from,int to,int cap)
    {
        G[from].push_back(Edge(to,cap,SZ(G[to])));
        G[to].push_back(Edge(from,0,SZ(G[from])-1));
    }
    int n,s,t;
    void init(int _n,int _s,int _t)
    {
        n = _n;
        s = _s;
        t = _t;
        for (int i=0;n>=i;i++)
        {
            G[i].clear();
        }
    }
    int level[N],iter[N];
    void BFS()
    {
        queue<int> que;
        que.push(s);
        memset(level,-1,sizeof(level));
        level[s] = 0;
        while (!que.empty())
        {
            int t=que.front();
            que.pop();
            for (Edge e:G[t])
            {
                if (e.cap > 0 && level[e.to] == -1)
                {
                    level[e.to] = level[t] + 1;
                    que.push(e.to);
                }
            }
        }
    }
    int dfs(int now,int flow)
    {
        if (now == t) return flow;
        for (int &i = iter[now];SZ(G[now])>i;i++)
        {
            Edge &e = G[now][i];
            if (e.cap > 0 && level[e.to] == level[now] + 1)
            {
                int ret = dfs(e.to,min(e.cap,flow));
                if (ret > 0)
                {
                    e.cap -= ret;
                    G[e.to][e.rev].cap += ret;
                    return ret;
                }
            }
        }
        return 0;
    }
    int flow()
    {
        int ret=0;
        while (true)
        {
            BFS();
            if (level[t] == -1) break;
            memset(iter,0,sizeof(iter));
            int tmp;
            while ((tmp = dfs(s,1000000007)) > 0)
            {
                ret += tmp;
            }
        }
        return ret;
    }
} _;

const int N = 4006;

vector<int> ans[N];
vector<int> G[N];

int deg1[N];
int deg2[N];

vector<int> adj[N][N];

pii p[N];

int main ()
{
    int n1,n2,m;
    scanf("%d %d %d",&n1,&n2,&m);
    for (int i=1;m>=i;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        deg1[x]++;
        deg2[y]++;
        adj[x][y].push_back(i);
        p[i] = make_pair(x,y);
    }
    int mn_deg = 1000000007;
    int s=0,t=n1+n2+1;
    _.init(t,s,t);
    for (int i=1;n1>=i;i++)
    {
        mn_deg = min(mn_deg,deg1[i]);
        for(int j:G[i])
        {
            _.add_edge(i,j+n1,1);
        }
    }
    for (int i=1;n2>=i;i++)
    {
        mn_deg = min(mn_deg,deg2[i]);
    }
    for (int i=1;n1>=i;i++)
    {
        _.add_edge(s,i,deg1[i] - mn_deg);
    }
    for (int i=1;n2>=i;i++)
    {
        _.add_edge(i+n1,t,deg2[i] - mn_deg);
    }
    for (int k=mn_deg;k>=0;k--)
    {
        int ret = _.flow();
        //cout << "k = " << k << endl;
        //cout << "ret = " << ret << endl;
        vector<int> &v = ans[k];
        for (int i=1;n1>=i;i++)
        {
            for (auto e:_.G[i])
            {
                if (n1 + 1 <= e.to && e.to <= n1 + n2 && e.cap == 1)
                {
                    int from = i;
                    int to = e.to - n1;
                    v.push_back(adj[from][to].back());
                    adj[from][to].pop_back();
                }
            }
        }
        for (int i:v)
        {
            adj[ p[i].first ][ p[i].second ].push_back(i);
        }
        for (int i=1;n1>=i;i++)
        {
            _.add_edge(s,i,1);
        }
        for (int i=1;n2>=i;i++)
        {
            _.add_edge(i+n1,t,1);
        }
    }
    for (int k=0;mn_deg >= k;k++)
    {
        printf("%d",SZ(ans[k]));
        for (int i:ans[k])
        {
            printf(" %d",i);
        }
        puts("");
    }
}