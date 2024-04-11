#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <bitset>
#include <functional>
#include <cassert>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

int lsb(ll x){
    for(int i = 0; i < 30; i++){
        if(x&(1<<i)) return i;
    }
}

int msb(ll x){
    for(int i = 29; i >= 0; i--){
        if(x&(1<<i)) return i;
    }
}

void solve(ll u, ll v){
    if(lsb(v) < lsb(u)) {
        cout << "NO" << endl;
        return;
    }
    if(msb(v) < msb(u)){
        cout << "NO" << endl;
        return;
    }
    int max_large = -1;
    int max_small = -1;
    int cntu = 0;
    int cntv = 0;
    for(int i = 0; i <= 29; i++){
        int m = 1<<i;
        if(m&u) cntu++;
        if(m&v) cntv++;
        if(cntv > cntu) {
            cout << "NO" << endl;
            return;
        }
    }
    
    for(int i = 29; i >= 0; i--){
        int m = 1<<i;
        if((m&u) && !(m&v)) chmax(max_small, i);
        if(!(m&u) && (m&v)) chmax(max_large, i);
    }
    if(max_small == -1){
        cout << "YES" << endl;
        return;
    }
    if(max_small >= max_large){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
}

class naive{
    vector<vector<int>> g;
    public:
    naive(int n){
        g.resize(n);
        for(int i = 0; i < n; i++){
            for(int j = 1; j <= i; j++){
                if((i&j) == j && (i+j < n)) g[i].push_back(i+j);
            }
        }
    }
    bool judge(int u, int v){
        return dfs(u, v);
    }
    bool dfs(int v, int t){
        if(v == t) return true;
        for(int to : g[v]){
            if(dfs(to, t)) return true;
        }
        return false;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) {
        ll u, v; cin >> u >> v;
        solve(u, v);
    }

    // auto nv = naive(100);
    // for(int i = 1; i < 100; i++){
    //     for(int j = 1; j < 100; j++){
    //         cout << i << ' ' << j << ' ' << (nv.judge(i, j) ? "YES" : "NO") << ' ';
    //         solve(i, j);
    //     }
    // }
}