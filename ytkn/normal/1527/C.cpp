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

ll solve(int n, vector<int> a){
    map<int, vector<ll>> indices;
    for(int i = 0; i < n; i++){
        indices[a[i]].push_back(i+1);
    }
    ll ans = 0;
    for(auto [_, v]: indices){
        // cout << _ << ':' << v.size() << "===" << endl;
        reverse(v.begin(), v.end());
        ll sum = accumulate(v.begin(), v.end(), ll(0));
        for(ll r : v){
            sum -= r;
            // cout << sum << ' ';
            ans += sum*(n-r+1);
        }
        // cout << endl;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        cout << solve(n, a) << endl;
    }
}