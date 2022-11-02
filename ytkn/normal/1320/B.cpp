#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

using namespace std;
typedef long long ll;

const ll INF = 1e+15;

typedef pair<ll, int> P;

struct edge{
    int to;
    ll cost;
};

int n, m;
int u[200000], v[200000];
int k;
int p[200000];
ll d[200000];
vector<edge> G[200000];
vector<int> G_inv[200000];

void dijkstra(int s, int num_v){
    priority_queue<P, vector<P>, greater<P>> que;
    fill(d, d+num_v, INF);
    d[s] = 0;
    que.push(P(0, s));
    while(!que.empty()){
        P p = que.top();que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for(int i = 0; i < G[v].size(); i++){
            edge e = G[v][i];
            if(d[v] + e.cost < d[e.to]){
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

void input(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> u[i] >> v[i];
        u[i]--; v[i]--;
        // 
        G[v[i]].push_back((edge){u[i], 1});

        G_inv[u[i]].push_back(v[i]);
    }
    cin >> k;
    for(int i = 0; i < k; i++){
        cin >> p[i]; p[i]--;
    }
}

void solve(){
    dijkstra(p[k-1], n);
    int ansl = 0, ansr = 0;
    for(int i = 0; i < k-1; i++){
        if(d[p[i]]-1 == d[p[i+1]]){
            int cnt = 0;
            for(int to : G_inv[p[i]]){
                if(d[to] == d[p[i]]-1) cnt++;
            }
            if(cnt >= 2) ansr++;
        }else{
            ansl++;
            ansr++;
        }
    }
    cout << ansl << ' ' << ansr << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    input();
    solve();
}