#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <random>
#include <numeric>
#include <functional>
#include <cassert>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

void solve(vector<ll> s, int n){
    ll ans = 0;
    for(int i = n-1; i >= 0; i--){
        int rem = s[i]-1;
        ll cnt = 0;
        for(int j = i+2; j < n; j++){
            ll m = min({(ll)rem, s[j]-1, (ll)j-i-1-cnt});
            s[j]-=m;
            rem-=m;
            cnt += m;
        }
    }
    for(int i = 0; i < n; i++) ans += (s[i]-1);
    
    cout << ans << endl;
}

int naive(vector<ll> s, int n){
    ll sum = accumulate(s.begin(), s.end(), (ll)0);
    ll ans = 0;
    while(sum > n){
        int cur = 0;
        ans++;
        while(cur < n){
            int nx = cur+s[cur];
            if(s[cur] > 1) {
                s[cur]--;
                sum--;
            }
            cur = nx;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<ll> s(n);
        for(int i = 0; i < n; i++) cin >> s[i];
        solve(s, n);
    }
    // int x = 10;
    // int n; cin >> n;
    // while(x--){
    //     vector<ll> v;
    //     for(int i = 0; i < n; i++) v.push_back(rand()%n+1);
        // for(int a : v) cout << a << ' ';
        // cout << endl;
    //     cout << naive(v, n) << ' ';
    //     solve(v, n);
    // }
}