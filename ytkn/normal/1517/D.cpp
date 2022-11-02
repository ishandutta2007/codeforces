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

const ll INF = 1e18;

ll dp[25][505*505];
struct edge{
    int to;
    ll cost;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m, k; cin >> n >> m >> k;
    int N = n*m;
    auto to_idx = [&](int i, int j){
        return m*i+j;
    };
    vector<vector<edge>> g(N);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m-1; j++){
            int a; cin >> a;
            int s = to_idx(i, j);
            int t = to_idx(i, j+1);
            g[s].push_back(edge{t, a});
            g[t].push_back(edge{s, a});
        }
    }
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < m; j++) {
            int s = to_idx(i, j);
            int t = to_idx(i+1, j);
            int a; cin >> a;
            g[s].push_back(edge{t, a});
            g[t].push_back(edge{s, a});
        }
    }

    if(k%2 == 1){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << -1 << ' ';
            }
            cout << endl;
        }
        return 0;
    }

    for(int i = 0; i < k/2; i++){
        for(int j = 0; j < N; j++){
            dp[i+1][j] = INF;
        }
        for(int v = 0; v < N; v++){
            for(edge e : g[v]){
                chmin(dp[i+1][v], dp[i][e.to]+e.cost*2);
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int v = to_idx(i, j);
            cout << dp[k/2][v] << ' ';
        }
        cout << endl;
    }

}