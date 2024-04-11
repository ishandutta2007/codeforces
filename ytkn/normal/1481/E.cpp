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

const int INF = 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<int> a(n);
    vector<int> cnt(n);
    vector<int> l(n, INF);
    vector<int> r(n, -INF);
    for(int i = 0; i < n; i++){
        cin >> a[i]; a[i]--;
        cnt[a[i]]++;
        chmin(l[a[i]], i);
        chmax(r[a[i]], i);
    }
    vector<int> dp(n+1, 0);
    int ans = 0;
    for(int i = 0; i < n; i++){
        chmax(ans, dp[i]+cnt[a[i]]);
        if(l[a[i]] == i){
            chmax(dp[r[a[i]]+1], dp[i]+cnt[a[i]]);
        }
        chmax(dp[i+1], dp[i]);
        cnt[a[i]]--;
    }
    chmax(ans, dp[n]);
    cout << n-ans << endl;
}