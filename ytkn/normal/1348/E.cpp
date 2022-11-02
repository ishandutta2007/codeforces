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

bool ok[505][505];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    ll n, k; cin >> n >> k;
    vector<ll> a(n), b(n);
    vector<ll> ra(n), rb(n);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        ra[i] = a[i]%k;
        rb[i] = b[i]%k;
    }
    ll sum = accumulate(a.begin(), a.end(), (ll)0) + accumulate(b.begin(), b.end(), (ll)0);
    
    ok[0][0] = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            if(!ok[i][j]) continue;
            for(int s = 0; s < k && s <= a[i]; s++){
                int x = k-(ra[i]-s);
                if(x >= k) x -= k;
                int nx = (j+s);
                if(nx >= k) nx -= k;
                if(b[i] >= x) ok[i+1][nx] = true;
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i < k; i++){
        if(ok[n][i]) chmax(ans, (sum-i)/k);
    }
    cout << ans << endl;
}