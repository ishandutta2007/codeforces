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
#include <stack>

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

/**
 * [maspy](https://maspypy.com/euler-tour-%E3%81%AE%E3%81%8A%E5%8B%89%E5%BC%B7#toc1)()
 */ 
class EulerTour{
    public:
    vector<vector<int>> g;
    int root;
    int n;
    vector<int> depth;
    vector<int> ord;
    vector<int> in, out;
    vector<int> ch;
    EulerTour(vector<vector<int>> g, int root): g(g), root(root){
        n = g.size();
        depth.resize(n);
        in.resize(n);
        out.resize(n);
        ch.resize(n);
        build();
    }
    private:
    void build(){
        vector<bool> seen(n, false);
        dfs(root, seen);
        for(int i = 0; i < n; i++) in[i] = 1e9;
        for(int i = 0; i < ord.size(); i++){
            chmin(in[ord[i]], i);
            chmax(out[ord[i]], i);
        }
        assert(ord.size() == 2*n);
    }
    void dfs(int v, vector<bool> &seen){
        ord.push_back(v);
        seen[v] = true;
        ch[v] = 1;
        int cnt = 0;
        for(int to: g[v]){
            if(seen[to]) continue;
            depth[to] = depth[v]+1;
            dfs(to, seen);
            ch[v] += ch[to];
            cnt++;
        }
        ord.push_back(v);
    }
};

using P = pair<int, int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<int> u(n-1), v(n-1), x(n-1);
    vector<vector<int>> indices(n);
    vector<vector<int>> g(n);
    for(int i = 0; i < n-1; i++){
        cin >> u[i] >> v[i] >> x[i]; u[i]--; v[i]--; x[i]--;
        indices[x[i]].push_back(i);
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
    }
    EulerTour et(g, 0);
    for(int i = 0; i < n-1; i++){
        if(et.depth[u[i]] > et.depth[v[i]]){
            swap(u[i], v[i]);
        }
    }
    ll ans = 0;
    for(int x = 0; x < n; x++){
        if(indices[x].empty()) continue;
        vector<P> vp;
        for(int i: indices[x]){
            vp.push_back(P(et.in[v[i]], i));
            vp.push_back(P(et.out[v[i]], i));
        }
        sort(vp.begin(), vp.end());
        stack<int> st;
        map<int, int> cnt;
        st.push(0);
        cnt[0] = n;
        for(auto [ord, idx]: vp){
            if(st.top() == v[idx]){
                st.pop();
            }else{
                int par = st.top();
                cnt[par] -= et.ch[v[idx]];
                st.push(v[idx]);
                cnt[v[idx]] = et.ch[v[idx]];
            }
        }
        for(auto [ord, idx]: vp){
            if(st.top() == v[idx]){
                st.pop();
            }else{
                int par = st.top();
                st.push(v[idx]);
                ans += (ll)cnt[par]*cnt[v[idx]];
                // cout << v[idx] << "->" << par << " " << cnt[par] << " " << cnt[v[idx]] << endl;
            }
        }
    }
    cout << ans << endl;
}