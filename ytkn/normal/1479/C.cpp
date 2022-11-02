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
struct edge{
    int to, cost;
};

void validate(vector<vector<edge>> g, int l, int r){
    int n = g.size();
    vector<vector<int>> ok(n, vector<int>(2*r+1, 0));
    ok[0][0] = 1;
    for(int v = 0; v < n; v++){
        for(edge e : g[v]){
            for(int d = 0; d <= r; d++){
                if(ok[v][d]){
                    assert(d+e.cost <= r);
                    ok[e.to][d+e.cost] += ok[v][d];
                }
            }
        }
    }
    for(int i = 0; i <= 2*r; i++) {
        // cout << ok[n-1][i] << ' ';
        if(i >= l && i <= r) assert(ok[n-1][i] == 1);
        else assert(ok[n-1][i] == 0);
    }
    // cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int l, r; cin >> l >> r;
    int n = 21;
    vector<vector<edge>> g(n+1);
    for(int k = 1; k <= n-1; k++){
        int cur = 1;
        g[n-k].push_back(edge{n, 1});
        for(int j = n-1; j >= n-k+1; j--){
            g[n-k].push_back(edge{j, cur});
            cur = cur<<1;
        }
    }
    int cur = l+1;
    int rem = r-l;
    g[0].push_back(edge{n, l});
    for(int k = 1; k <= n-1; k++){
        int j = n-k;
        int m = (1<<(k-1));
        // cout << m << ' ' << rem << endl;
        if(m&rem){
            g[0].push_back(edge{j, cur-1});
            // cout << 0 << ' ' << j << ' ' << cur-1 << endl;
            rem -= m;
            cur += m;
        }
    }
    // validate(g, l, r);
    int m = 0;
    for(auto v : g) m += v.size();
    cout << "YES" << endl;
    cout << n+1 << ' ' << m << endl;
    for(int v = 0; v <= n; v++){
        for(edge e : g[v]){
            cout << v+1 << ' ' << e.to+1 << ' ' << e.cost  << endl;
        }
    }
}