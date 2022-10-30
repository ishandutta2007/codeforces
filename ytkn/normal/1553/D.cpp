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

const int INF = 1e9;

void solve(){
    string s, t; cin >> s >> t;
    int n = s.size();
    int m = t.size();
    vector<vector<vector<int>>> v(2, vector<vector<int>>(26));
    for(int i = 0; i < n; i++){
        v[i%2][s[i]-'a'].push_back(i);
    }
    vector<vector<int>> dp(m+1, vector<int>(2, INF));
    dp[0][0] = -1;
    dp[0][1] = -1;
    for(int i = 0; i < m; i++){
        int x = t[i]-'a';
        for(int j = 0; j < 2; j++){
            if(dp[i][j] == INF) continue;
            auto p = upper_bound(v[j^1][x].begin(), v[j^1][x].end(), dp[i][j]);
            if(p == v[j^1][x].end()) continue;
            chmin(dp[i+1][j^1], *p);
        }
    }
    if(n%2 == 0){
        if(dp[m][1] != INF) cout << "Yes" << endl;
        else cout << "No" << endl;
    }else{
        if(dp[m][0] != INF) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}