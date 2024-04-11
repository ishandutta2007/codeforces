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

class Scc{
    public:
        int N;
        vector<vector<int>> G;
        vector<vector<int>> G_inv;
        vector<int> idx;

        Scc(int n){
            N = n;
            G = vector<vector<int>>(n, vector<int>());
            G_inv = vector<vector<int>>(n, vector<int>());
            used = vector<bool>(n, false);
            idx = vector<int>(n);
        }

        void add_edge(int from, int to){
            G[from].push_back(to);
            G_inv[to].push_back(from);
        }

        vector<vector<int>> scc(){
            vector<vector<int>> ans;
            for(int i = 0; i < N; i++){
                if(!used[i]) dfs1(i);
            }
            clear();
            int cur = 0;
            for(int i = vs.size()-1; i >= 0; i--){
                if(!used[vs[i]]) {
                    dfs2(vs[i], cur);
                    cur++;
                    ans.push_back(buf);
                    buf.clear();
                }
            }
            return ans;
        }

    private:
        vector<bool> used;
        vector<int> vs;
        vector<int> buf;
        void clear(){
            for(int i = 0; i < N; i++) used[i] = false;
        }

        void dfs1(int v){
            used[v] = true;
            for(int i = 0; i < G[v].size(); i++){
                if(!used[G[v][i]]) dfs1(G[v][i]);
            }
            vs.push_back(v);
        }

        void dfs2(int v, int k){
            used[v] = true;
            idx[v] = k;
            for(int i = 0; i < G_inv[v].size(); i++){
                if(!used[G_inv[v][i]]) dfs2(G_inv[v][i], k);
            }
            buf.push_back(v);
        }
};


void test(int n){
    vector<vector<int>> g(1<<n);
    auto popcount = [&](int s){
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(s&(1<<i)) ans++;
        }
        return ans;
    };
    Scc scc(1<<n);
    auto process = [&](int s){
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            if(s&(1<<i)) v[i] = 1;
        }
        for(int i = 0; i < n-2; i++){
            auto u = v;
            int x = v[i]^v[i+1]^v[i+2];
            u[i] = x; u[i+1] = x; u[i+2] = x;
            int t = 0;
            for(int j = 0; j < n; j++) t += (1<<j)*u[j];
            scc.add_edge(t, s);
        }
    };
    for(int s = 0; s < (1<<n); s++) process(s);
    auto u = scc.scc();
    int m = u.size();
    vector<bool> ok(m);
    ok[scc.idx[0]] = true;
    for(int i = 0; i < m; i++){
        if(!ok[i]) continue;
        auto v = u[i];
        for(int x: v){
            for(int to: scc.G[x]){
                int idx = scc.idx[to];
                ok[idx] = true;
            }
        }
    }
    for(int i = 0; i < (1<<n); i++){
        if(popcount(i)%2 == 0 && !ok[scc.idx[i]]){
            for(int j = 0; j < n; j++){
                cout << (i&(1<<j) ? 1 : 0) << ' ';
            }
            cout << endl;
        }
    }
}

vector<int> group(vector<int> v){
    int cnt = 1;
    int n = v.size();
    vector<int> ans;
    for(int i = 1; i < n; i++){
        if(v[i] == v[i-1]){
            cnt++;
        }else{
            ans.push_back(cnt);
            cnt = 1;
        }
    }
    ans.push_back(cnt);
    return ans;
}

vector<int> sub_solve(vector<int> a){
    // assert(a[0] == 0);
    vector<int> idx;
    int n = a.size();
    for(int i = 0; i < n; i++){
        if(a[i] == 1) idx.push_back(i);
    }
    int m = idx.size();
    assert(m%2 == 0);
    vector<int> ans;
    for(int i = 0; i < m; i+=2){
        int l = idx[i], r = idx[i+1];
        if((r-l)%2 == 1){ // 0
            for(int j = l; j <= r-3; j+=2){
                ans.push_back(j);
            }
            for(int j = l-1; j <= r-2; j+=2){
                ans.push_back(j);
            }
        }else{ // 0
            for(int j = l; j <= r-2; j+=2){
                ans.push_back(j);
            }
            for(int j = r-4; j >= l; j-=2){
                ans.push_back(j);
            }
        }
    }
    // for(int i: ans){
    //     assert(i+2 < n);
    //     int x = 0;
    //     for(int j = i; j <= i+2; j++){
    //         x ^= a[j];
    //     }
    //     for(int j = i; j <= i+2; j++){
    //         a[j] = x;
    //     }
    // }
    // for(int x: a) assert(x == 0);
    return ans;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int asum = accumulate(a.begin(), a.end(), 0);
    if(asum == n || asum%2 == 1){
        cout << "NO" << endl;
        return;
    }
    auto g = group(a);
    if(a[0] == 1 && a.back() == 1){
        if(g[0]%2 == 1 && g.back()%2 == 1){
            bool ng = [&](){
                for(int i = 1; i+1 < g.size(); i++){
                    if(g[i]%2 == 1) return false;
                }
                return true;
            }();
            if(ng){
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
    int c = -1;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 1) cnt++;
        else{
            if(cnt%2 == 0){
                c = i;
                break;
            }
        }
    }
    vector<int> ans;
    if(c == -1){
        int l = -1;
        for(int i = 0; i < n; i++){
            if(a[i] == 0) continue;
            if(l == -1){
                l = i;
            }else{
                int r = i;
                if((r-l)%2 == 1) {
                    l = -1;
                    continue;
                }
                for(int j = l; j <= r-2; j+=2){
                    ans.push_back(j);
                }
                for(int j = r-4; j >= l; j-=2){
                    ans.push_back(j);
                }
                a[l] = 0;
                a[r] = 0;
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(a[i] == 1) cnt++;
            else{
                if(cnt%2 == 0){
                    c = i;
                    break;
                }
            }
        }
    }
    assert(c != -1);
    vector<int> vl, vr;
    for(int i = c; i >= 0; i--){
        vl.push_back(a[i]);
    }
    for(int i = c; i < n; i++){
        vr.push_back(a[i]);
    }
    for(int i: sub_solve(vl)){
        ans.push_back(c-i-2);
    }
    for(int i: sub_solve(vr)){
        ans.push_back(c+i);
    }
    cout << ans.size() << endl;
    for(int i: ans) cout << i+1 << ' ';
    cout << endl;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
    // int n; cin >> n;
    // test(n);
}