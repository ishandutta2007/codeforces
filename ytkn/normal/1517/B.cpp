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
#include <tuple>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;
using T = tuple<ll, int, int>;

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<ll>> b(n, vector<ll>(m));
    vector<vector<ll>> ans(n, vector<ll>(m, -1));
    vector<T> vt;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> b[i][j];
            vt.push_back(T(b[i][j], i, j));
        }
    }
    sort(vt.begin(), vt.end());
    for(int k = 0; k < m; k++){
        auto [x, i, _] = vt[k];
        ans[i][k] = x;
    }
    for(int k = m; k < n*m; k++){
        auto [x, i, _] = vt[k];
        for(int l = 0; l < m; l++){
            if(ans[i][l] == -1){
                ans[i][l] = x;
                break;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}