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
using P = pair<int, int>;

void solve(){
    int n, m; cin >> n >> m;
    vector<int> k(m);
    vector<vector<int>> f(m);
    vector<int> cnt(n);
    vector<int> rem(n);
    vector<int> used(n);
    vector<P> p(m);
    for(int i = 0; i < m; i++){
        cin >> k[i];
        f[i].resize(k[i]);
        for(int j = 0; j < k[i]; j++) {
            cin >> f[i][j];
            f[i][j]--;
            rem[f[i][j]]++;
        }
        if(k[i] == 1){
            cnt[f[i][0]]++;
        }
        p[i] = P(k[i], i);
    }
    int c = (m+1)/2+1;
    if(*max_element(cnt.begin(), cnt.end()) >= c){
        cout << "NO" << endl;
        return;
    }
    sort(p.begin(), p.end());
    vector<int> ans(m, -1);
    for(auto [_, i]: p){
        for(int x : f[i]){
            if(used[x] < rem[x] && used[x]+1 < c){
                ans[i] = x;
                used[x]++;
                break;
            }
        }
    }
    // debug_value(used[0]);
    cout << "YES" << endl;
    for(int x : ans) cout << x+1 << ' ';
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}