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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    ll n, k; cin >> n >> k;
    vector<ll> c(n);
    for(int i = 0; i < n; i++) cin >> c[i];
    sort(c.begin(), c.end(), greater<ll>());

    vector<ll> sum(n);
    sum[0] = c[0];
    for(int i = 1; i < n; i++){
        sum[i] = sum[i-1]+c[i];
    }
    ll tmp = 0;
    for(ll i = 0; i < n-1; i++){
        tmp += sum[i];
    }
    ll ans = tmp;
    // cout << ans << endl;
    int cnt = 0;
    multiset<ll> st;
    for(int i = 0; i < k; i++) st.insert(0);
    if(k > 0){
        for(int i = n-2; i >= 0; i--){
            if((n-1-i)%(k+1) == 0) {
                cnt++;
                continue;
            }
            tmp -= sum[i];
            tmp -= cnt*c[i];
            ll m = *st.begin();
            tmp += c[i]*m;
            st.erase(st.find(m));
            st.insert(m+1);
            chmax(ans, tmp);
            // for(int x : st) cout << x << ' ';
            // cout << endl;
            // cout << i << ' ' << sum[i] << ' ' << c[i] << ' ' << m << ' ' << tmp << endl;
        }
    }
    cout << ans << endl;
}