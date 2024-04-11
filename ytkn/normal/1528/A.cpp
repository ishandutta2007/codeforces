#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
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
ll l[100000], r[100000];
vector<int> g[100000];
bool used[100000];
ll dp[100000][2];

void clear(int n){
    for(int i = 0; i < n; i++){
        g[i].clear();
        used[i] = false;
        dp[i][0] = 0;
        dp[i][1] = 0;
    }
}

void dfs(int v){
    used[v] = true;
    for(int to : g[v]){
        if(used[to]) continue;
        dfs(to);
        // l
        dp[v][0] += max(dp[to][0]+abs(l[v]-l[to]), dp[to][1]+abs(l[v]-r[to]));
        // r
        dp[v][1] += max(dp[to][0]+abs(r[v]-l[to]), dp[to][1]+abs(r[v]-r[to]));
    }
}

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> l[i] >> r[i];
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0);
    cout << max(dp[0][0], dp[0][1]) << endl;
    clear(n);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}