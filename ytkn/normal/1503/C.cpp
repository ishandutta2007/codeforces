#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <functional>
#include <cassert>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;
using P = pair<ll, int>;
const ll INF = 1e18;

struct edge{
    int to;
    ll cost;
};

vector<ll> dijkstra(int s, vector<vector<edge>> G){
    priority_queue<P, vector<P>, greater<P>> que;
    int n = G.size();
    vector<ll> d(n, INF);
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
    return d;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<ll> a(n), c(n);
    map<ll, int> compress;
    set<int> st;
    ll ans = 0;
    ll a_min = -INF;
    ll a_max = -INF;
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> c[i];
        st.insert(a[i]);
        st.insert(a[i]+c[i]);
        ans += c[i];
        chmin(a_min, a[i]);
        chmax(a_max, a[i]);
    }
    int cnt = 0;
    for(ll x : st){
        compress[x] = cnt;
        cnt++;
    }
    int m = compress.size();
    vector<int> inv(m);
    for(auto [x, y]: compress) inv[y] = x;
    vector<vector<edge>> g(m);
    for(int i = 0; i < n; i++){
        g[compress[a[i]]].push_back(edge{compress[a[i]+c[i]], 0});
    }
    for(int i = 0; i < m-1; i++){
        g[i].push_back(edge{ i+1, inv[i+1]-inv[i]});
        g[i+1].push_back(edge{ i, 0});
    }
    int s = compress[a_min];
    int t = compress[a_max];
    auto d = dijkstra(s, g);
    cout << ans+d[t] << endl;
}