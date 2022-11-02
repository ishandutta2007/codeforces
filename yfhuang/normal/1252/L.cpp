#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>

using namespace std;
const int INF = 1000000000;
int n, m;

const int maxn = 55;
int x[2][maxn], y[2][maxn];

map<int, int> ID[2];
int tot[2];

int X[maxn * 2], Y[maxn * 2];

struct Edge {
    int from, to, cap, flow, index;
    Edge(int from, int to, int cap, int flow, int index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct Dinic {
    int N;
    vector < vector < Edge > > G;
    vector < Edge * > dad;
    vector < int > Q;

    Dinic(int N) : N(N), G(N), dad(N), Q(N) {}

    void AddEdge(int from, int to, int cap) {
        G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
        if (from == to) G[from].back().index++;
        G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
    }

    long long BlockingFlow(int s, int t) {
        fill(dad.begin(), dad.end(), (Edge *) NULL);
        dad[s] = &G[0][0] - 1;

        int head = 0, tail = 0;
        Q[tail++] = s;

        while(head < tail){
            int x = Q[head++];
            for (int i = 0; i < G[x].size(); i++){
                Edge &e = G[x][i];
                if(!dad[e.to] && e.cap - e.flow > 0){
                    dad[e.to] = &G[x][i];
                    Q[tail++] = e.to;
                }
            }
        }
        if (!dad[t]) return 0;

        long long totflow = 0;
        for (int i = 0; i < G[t].size(); i++){
            Edge *start = &G[G[t][i].to][G[t][i].index];
            int amt = INF;
            for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]){
                if (!e) { amt = 0; break; }
                amt = min(amt, e->cap - e->flow);
            }
            if (amt == 0) continue;
            for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
                e->flow += amt;
                G[e->to][e->index].flow -= amt;
            }
            totflow += amt;
        }
        return totflow;
    }

    long long GetMaxFlow(int s, int t) {
        long long totflow = 0;
        while (long long flow = BlockingFlow(s, t)) totflow += flow;
        return totflow;
    }
};

int main(){
    cin >> n >> m;
    if(m == 0){
        cout << 0 << endl;
        return 0;
    }
    memset(tot, 0, sizeof(tot));
    for(int i = 1;i <= m;i++){
        for(int j = 0;j < 2;j++){
            scanf("%d%d", &x[j][i], &y[j][i]);
            if(j == 1){
                x[j][i]++;
                y[j][i]++;
            }
            X[i * 2 - 1 + j] = x[j][i];
            Y[i * 2 - 1 + j] = y[j][i];
        }
    }
    sort(X + 1, X + 1 + 2 * m);
    sort(Y + 1, Y + 1 + 2 * m);
    tot[0] = unique(X + 1, X + 1 + 2 * m) - X - 1;
    tot[1] = unique(Y + 1, Y + 1 + 2 * m) - Y - 1;
    tot[0]--;
    tot[1]--;
    Dinic ans(20000);
    for(int i = 1;i <= tot[0];i++){
        ans.AddEdge(0, i, X[i + 1] - X[i]);
    }
    for(int i = 1;i <= tot[1];i++){
        ans.AddEdge(tot[0] + i, tot[0] + tot[1] + 1, Y[i + 1] - Y[i]);
    }
    for(int i = 1;i <= m;i++){
        int xl = lower_bound(X + 1, X + 1 + tot[0] + 1, x[0][i]) - X;
        int xr = lower_bound(X + 1, X + 1 + tot[0] + 1, x[1][i]) - X;
        int yl = lower_bound(Y + 1, Y + 1 + tot[1] + 1, y[0][i]) - Y;
        int yr = lower_bound(Y + 1, Y + 1 + tot[1] + 1, y[1][i]) - Y;
        for(int j = xl;j < xr;j++){
            for(int k = yl;k < yr;k++){
                ans.AddEdge(j, k + tot[0], INF);
            }
        }
    }
    cout << ans.GetMaxFlow(0, tot[0] + tot[1] + 1) << endl;
    return 0;
}