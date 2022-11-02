#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cassert>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

const ll INF = 1e18;

void solve(){
    ll n, p, k; cin >> n >> p >> k;
    ll x, y;
    string a; cin >> a;
    cin >> x >> y;
    vector<int> cnt(n);
    for(int i = n-1; i >= 0; i--){
        if(a[i] == '0'){
            if(i+k < n) cnt[i] += cnt[i+k]+1;
            else cnt[i] = 1;
        }else{
            if(i+k < n) cnt[i] += cnt[i+k];
            else cnt[i] = 0;
        }
    }
    ll ans = INF;
    for(ll i = p-1; i < n; i++){
        chmin(ans, (i-p+1)*y+cnt[i]*x);
        // cout << (i-p+1)*y+cnt[i]*x << ' ';
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    for(int i = 0; i < t; i++) solve();
}