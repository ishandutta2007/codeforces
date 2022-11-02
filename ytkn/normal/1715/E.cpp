#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <cmath>
#include <numeric>
#include <functional>
#include <cassert>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

template<typename T>
vector<vector<T>> vec2d(int n, int m, T v){
    return vector<vector<T>>(n, vector<T>(m, v));
}

template<typename T>
vector<vector<vector<T>>> vec3d(int n, int m, int k, T v){
    return vector<vector<vector<T>>>(n, vector<vector<T>>(m, vector<T>(k, v)));
}

template<typename T>
void print_vector(vector<T> v, char delimiter=' '){
    if(v.empty()) {
        cout << endl;
        return;
    }
    for(int i = 0; i+1 < v.size(); i++) cout << v[i] << delimiter;
    cout << v.back() << endl;
}

template<typename T>
class ConvexHullTrick{
    public:
    T x;
    ConvexHullTrick<T>(){
        x = 0;
    }
    /**
     * x
     */ 
    void next(){
        x++;
        while(dq.size() >= 2 && f(x, dq[0]) >= f(x, dq[1])) dq.pop_front();
    }
    /**
     * x
     */ 
    void proceed(T _x){
        assert(x <= _x);
        x = _x;
        while(dq.size() >= 2 && f(x, dq[0]) >= f(x, dq[1])) dq.pop_front();
    }
    /**
     *  y = p_add*x+q ()
     */ 
    void add_line(T p_add, T q_add){
        if(!dq.empty()) assert(p_add < p[dq.back()]);
        p.push_back(p_add);
        q.push_back(q_add);
        int n_lines = p.size();
        while(dq.size() >= 2 && check(dq[dq.size()-2], dq.back(), n_lines-1)) {
            dq.pop_back();
        }
        dq.push_back(n_lines-1);
    }
    T get_min(){
        return f(x, dq[0]);
    }
    private:
    vector<T> p, q; // p[i]x+q[i]
    deque<int> dq;
    T f(int x, int i){
        return p[i]*x+q[i];
    }
    bool check(int i, int j, int k){
        return (p[j]-p[i])*(q[k]-q[j]) >= (q[j]-q[i])*(p[k]-p[j]);
    };
};


using T = tuple<ll, int, int, int>;
using P = pair<ll, int>;
const ll inf = 1e18;

struct edge{
    int to;
    ll cost;
    edge(int to, ll cost): to(to), cost(cost) {}
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m, k; cin >> n >> m >> k;
    vector<vector<edge>> g(n);
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w; u--; v--;
        g[u].push_back(edge(v, w));
        g[v].push_back(edge(u, w));
    }
    vector<ll> dist(n, inf);
    dist[0] = 0;
    for(int i_ = 0; i_ <= k; i_++){
        priority_queue<P, vector<P>, greater<P>> que;
        for(int i = 0; i < n; i++) que.push(P(dist[i], i));
        while(!que.empty()){
            auto [d, v] = que.top(); que.pop();
            if(d != dist[v]) continue;
            for(edge e: g[v]){
                if(chmin(dist[e.to], d+e.cost)) que.push(P(dist[e.to], e.to));
            }
        }
        if(i_ == k) break;
        auto cht = ConvexHullTrick<ll>();
        for(ll i = 0; i < n; i++){
            if(dist[i] == inf) continue;
            cht.add_line(-2*i, i*i+dist[i]);
        }
        for(ll i = 0; i < n; i++){
            cht.proceed(i);
            chmin(dist[i], cht.get_min()+i*i); 
        }
    }
    print_vector(dist);
}