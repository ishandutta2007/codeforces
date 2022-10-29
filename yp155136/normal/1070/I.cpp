#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)(x).size())

struct Dinic {
    static const int N = 12345;
    struct Edge {
        int to,cap,rev;
        Edge(int _to,int _cap,int _rev):to(_to),cap(_cap),rev(_rev){}
    };
    vector<Edge> G[N];
    void add_edge(int from,int to,int cap) {
        G[from].push_back(Edge(to,cap,SZ(G[to])));
        G[to].push_back(Edge(from,0,SZ(G[from])-1));
    }
    int n,s,t;
    void init(int _n,int _s,int _t) {
        n = _n;
        s = _s;
        t = _t;
        for (int i=0;i<=n;++i) {
            G[i].clear();
        }
    }
    int level[N],iter[N];
    void BFS() {
        /*for (int i=0;i<=n;++i) {
            level[i] = -1;
        }*/
        memset(level,-1,sizeof(level));
        level[s] = 0;
        queue<int> que;
        que.push(s);
        while (!que.empty()) {
            int t=que.front();
            que.pop();
            for (Edge e:G[t]) {
                if (e.cap > 0 && level[e.to] == -1) {
                    level[e.to] = level[t] + 1;
                    que.push(e.to);
                }
            }
        }
    }
    int dfs(int now,int flow) {
        if (now == t) return flow;
        for (int &i=iter[now];i<SZ(G[now]);++i) {
            Edge &e= G[now][i];
            if (e.cap > 0 && level[e.to] == level[now] + 1) {
                int ret = dfs(e.to,min(flow,e.cap));
                if (ret > 0) {
                    e.cap -= ret;
                    G[e.to][e.rev].cap += ret;
                    return ret;
                }
            }
        }
        return 0;
    }
    int flow() {
        int ret=0;
        while (true) {
            BFS();
            if (level[t] == -1) break;
            memset(iter,0,sizeof(iter));
            //for (int i=0;i<=n;++i) iter[i] = 0;
            int tmp;
            while ((tmp = dfs(s,123456789)) > 0) {
                ret += tmp;
            }
        }
        return ret;
    }
} dinic;

const int N = 1234;

vector<int> G[N];
int e[N];

void no_ans(int n) {
    for (int i=1;i<=n;++i) {
        cout << 0;
        if (i == n) cout << endl;
        else cout << ' ';
    }
}

int ans[N];

void solve() {
    int n,m,k;
    cin >> n >> m >> k;
    for (int i=0;i<=n;++i) {
        G[i].clear();
    }
    for (int i=1;i<=m;++i) {
        int x,y;
        scanf("%d %d",&x,&y);
        e[i] = (x^y);
        G[x].push_back(i);
        G[y].push_back(i);
    }
    int id=0;
    int id_pre = m;
    int s=0,t = m*2+2;
    dinic.init(t,s,t);
    for (int i=1;i<=m;++i) {
        dinic.add_edge(i,t,1);
    }
    int tot=0;
    for (int i=1;i<=n;++i) {
        int deg = (int)G[i].size();
        int need = deg - k;
        if (need > k) {
            no_ans(m);
            return;
        }
        while (need > 0) {
            ++id;
            dinic.add_edge(s,id_pre+id,2);
            tot += 2;
            for (int j:G[i]) {
                dinic.add_edge(id_pre+id,j,1);
            }
            --need;
        }
    }
    int ret = dinic.flow();
    if (ret == tot) {
        memset(ans,-1,sizeof(ans));
        for (int i=1;i<=id;++i) {
            for (auto j:dinic.G[i+id_pre]) {
                if (1 <= j.to && j.to <= m && j.cap == 0) {
                    ans[j.to] = i;
                }
            }
        }
        for (int i=1;i<=m;++i) {
            if (ans[i] == -1) {
                ans[i] = (++id);
            }
        }
        for (int i=1;i<=m;++i) {
            cout << ans[i];
            if (i == m) cout << endl;
            else cout << ' ';
        }
        //puts("Have answer");
    }
    else {
        no_ans(m);
    }
}

int main () {
    //ios::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}