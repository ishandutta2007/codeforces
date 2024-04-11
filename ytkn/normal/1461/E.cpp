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
#include <random>

std::random_device rnd;
std::mt19937 mt(rnd());

int randint(const int l, const int r){
    return mt()%(r - l) + l;
}

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

const ll inf = 3e+18;

typedef pair<ll, int> P;

struct edge{
    int to;
    ll cost;
};

bool naive(ll k, ll l, ll r, ll t, ll x, ll y){
    for(int i = 0; i < t; i++){
        if(k+y <= r) k += y;
        k -= x;
        if(k < l) return false;
    }
    return true;
}

void solve(ll k, ll l, ll r, ll t, ll x, ll y){
    if(x == y){
        if(k+y <= r) k += y;
        if(k-x < l){
            cout << "No" << endl;
        }else{
            cout << "Yes" << endl;
        }
        return;
    }
    if(x > y){
        if(k+y > r) k -= y;
        ll d = x-y;
        if((k-l)/d < t){
            cout << "No" << endl;
        }else{
            cout << "Yes" << endl;
        }
        return;
    }
    if(r < l+x){
        cout << "No" << endl;
        return;
    }
    if(l+y > r){
        if((k-l)/x < t){
            cout << "No" << endl;
        }else{
            cout << "Yes" << endl;
        }
        return;
    }
    ll ngl = max(l, r-y+1)-l;
    ll ngr = min(l+x-1, r)-l;
    if(ngl > ngr){
        cout << "Yes" << endl;
        return;
    }
    vector<vector<edge>> g(x);
    for(int i = 0; i < ngl; i++){
        ll v = i+y;
        ll dist = (i+y)/x;
        int nx = (i+y)%x;
        g[nx].push_back(edge{i, dist});
        // cout << i << "->" << nx << ':' << dist << endl;
    }
    ll s = (k-l)%x;
    // debug_value(s);
    t -= (k-l)/x;
    if(t <= 0){
        cout << "Yes" << endl;
        return;
    }
    vector<ll> dist(x, inf);    
    priority_queue<P, vector<P>, greater<P>> que;
    auto push = [&](int v, ll d){
        if(chmin(dist[v], d)){
            que.push(P(d, v));
        }
    };
    for(int i = ngl; i <= ngr; i++){
        push(i, 0);
    }
    while(!que.empty()){
        auto [d, v] = que.top(); que.pop();
        if(d != dist[v]) continue;
        for(edge e: g[v]){
            push(e.to, d+e.cost);
        }
    }
    if(dist[s] >= t){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}

using P = pair<ll, int>;

void test(){
    ll k, l, r, t, x, y;
    l = 100;
    r = 300;
    k = randint(l, r);
    t = randint(100, 10000);
    x = randint(1, r-l);
    y = randint(1, r-l);
    y = x;
    cout << (naive(k, l, r, t, x, y) ? "Yes" : "No") << ' ';
    solve(k, l, r, t, x, y);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    // for(int i = 0; i < 100; i++) test();
    ll k, l, r, t, x, y;
    cin >> k >> l >> r >> t >> x >> y;
    // cout << (naive(k, l, r, t, x, y) ? "Yes" : "No") << endl;
    solve(k, l, r, t, x, y);
}