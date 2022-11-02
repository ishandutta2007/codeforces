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

vector<vector<int>> g;
vector<bool> used;
vector<int> dp;

bool dfs(int v, int k){
    used[v] = true;
    vector<int> u;
    for(int to : g[v]){
        if(!used[to]){
           if(!dfs(to, k)) return false;
            u.push_back(dp[to]);
        }
    }
    if(u.size() > 0){
        int u_min = *min_element(u.begin(), u.end());
        int u_max = *max_element(u.begin(), u.end());
        if(u_max >= k) return false;
        if(u_max == k-1) {
            int cnt = 0;
            for(int x : u){
                if(x == k-1) cnt++;
            }
            if(cnt >= 2) return false;
            dp[v] = k;
        }
        else dp[v] = u_min+1;
    }
    return true;
}

void solve(){
    int n; cin >> n;
    used.resize(n);
    g.resize(n);
    dp.resize(n);
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    auto clear = [&]{
        for(int i = 0; i < n; i++) {
            used[i] = false;
            dp[i] = 0;
        }
    };
    if(n == 2){
        cout << 1 << endl;
    }else{
        int l = 2, r = n+2;
        clear();
        if(dfs(0, l)){
            cout << 2 << endl;
        }else{
            while(r-l > 1){
                clear();
                int c = (l+r)/2;
                if(dfs(0, c)) r = c;
                else l = c;
            }
            cout << r << endl;
        }
    }
    g.clear();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}