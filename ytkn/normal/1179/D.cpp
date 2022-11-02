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
    ConvexHullTrick<T>(T x): x(x){}
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
        assert(x >= _x);
        x = _x;
        while(dq.size() >= 2 && f(x, dq.back()) >= f(x, dq[dq.size()-2])) dq.pop_back();
    }
    /**
     *  y = p_add*x+q ()
     */ 
    void add_line(T p_add, T q_add){
        if(!dq.empty()) assert(p_add <= p[dq.back()]);
        p.push_back(p_add);
        q.push_back(q_add);
        int n_lines = p.size();
        while(dq.size() >= 2 && check(dq[dq.size()-2], dq.back(), n_lines-1)) {
            dq.pop_back();
        }
        dq.push_back(n_lines-1);
    }
    T get_min(){
        return f(x, dq.back());
    }
    private:
    vector<T> p, q; // p[i]x+q[i]
    deque<int> dq;
    T f(T x, int i){
        return p[i]*x+q[i];
    }
    bool check(int i, int j, int k){
        return (p[j]-p[i])*(q[k]-q[j]) >= (q[j]-q[i])*(p[k]-p[j]);
    };
};

ll tri(ll x){
    return (x*(x-1))/2;
}

using P = pair<int, int>;
using T = tuple<ll, ll, int>;
const ll inf = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<ll> dp(n, inf);
    vector<int> ch(n);
    ll ans = 0;
    function<void(int, int)> dfs = [&](int v, int par){
        ch[v] = 1;
        vector<T> vp;
        auto f = [&](int u){
            return dp[u] + ((ll)ch[u]*(ll)(ch[u]-2*n+1))/2;
        };
        for(int to: g[v]){
            if(to == par) continue;
            dfs(to, v);
            ch[v] += ch[to];
            vp.push_back(T(ch[to], f(to), to));
        }
        if(vp.empty()){
            dp[v] = 0;
            return;
        }
        for(int to: g[v]){
            if(to == par) continue;
            chmin(dp[v], dp[to]+tri(ch[v]-ch[to]));
        }
        sort(vp.begin(), vp.end(), greater<T>());
        
        ConvexHullTrick<ll> cht(2*n);
        int i = 0;
        for(auto [ch, fto, to]: vp){
            if(i != 0) {
                cht.proceed(ch);
                ll x = cht.get_min();
                ll tmp = -(x+f(to));
                chmax(ans, tmp);
            }
            i++;
            cht.add_line(ch, f(to));
        }

    };
    for(int i = 0; i < n; i++){
        if(g[i].size() > 1){
            dfs(i, -1);
            cout << ans+tri(n) << endl;
            return 0;
        }
    }
    cout << 2 << endl;
}