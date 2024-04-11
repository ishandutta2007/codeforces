#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

const ll INF = 1e+18;

typedef pair<ll, int> P;

void dijkstra(int s, int num_v, vector<int> G[], int d[]){
    priority_queue<P, vector<P>, greater<P>> que;
    fill(d, d+num_v, 10000000);
    d[s] = 0;
    que.push(P(0, s));
    while(!que.empty()){
        P p = que.top();que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for(int to : G[v]){
            if(d[v] + 1 < d[to]){
                d[to] = d[v] + 1;
                que.push(P(d[to], to));
            }
        }
    }
}

int N, M;
vector<int> G[200000];
ll p[200000];
ll sum[200005];
int da[200000], db[200000], dc[200000];

void solve(){
    int a, b, c;
    cin >> N >> M >> a  >> b >> c;
    a--; b--;c--;
    for(int i = 0; i < M; i++) cin >> p[i];
    sort(p, p+M);
    for(int i = 0; i < M; i++){
        sum[i+1] = sum[i]+p[i];
    }
    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dijkstra(a, N, G, da);
    dijkstra(b, N, G, db);
    dijkstra(c, N, G, dc);
    ll ans = INF;
    for(int i = 0; i < N; i++){
        if(da[i]+db[i]+dc[i] > M) continue;
        ll tmp = sum[da[i]+db[i]+dc[i]]+sum[db[i]];
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    for(int i = 0; i < N; i++) G[i].clear();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
}