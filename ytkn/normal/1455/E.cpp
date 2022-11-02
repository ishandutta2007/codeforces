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

const ll INF = 1e15;

void solve(){
    ll ans = INF;
    vector<ll> x(4), y(4);
    for(int i = 0; i < 4; i++) cin >> x[i] >> y[i];
    vector<int> v = {1,2,3};
    do {
        // vector<int> u(4);
        // u[0] = 0;
        // for(int i = 1; i <= 3; i++) u[i] = v[i];
        // x -> y
        {
            ll tmp = abs(x[0]-x[v[0]])+abs(y[v[0]]-y[v[1]])+abs(x[v[1]]-x[v[2]])+abs(y[v[2]]-y[0]);
            ll lx_min = min(x[0], x[v[0]]);
            ll lx_max = max(x[0], x[v[0]]);
            ll rx_min = min(x[v[1]], x[v[2]]);
            ll rx_max = max(x[v[1]], x[v[2]]);
            ll ly_min = min(y[v[0]], y[v[1]]);
            ll ly_max = max(y[v[0]], y[v[1]]);
            ll ry_min = min(y[v[2]], y[0]);
            ll ry_max = max(y[v[2]], y[0]);
            ll w_min = min(abs(rx_max-lx_min), abs(rx_min-lx_max));
            ll w_max = max(abs(rx_max-lx_min), abs(rx_min-lx_max));

            ll h_min = min(abs(ry_max-ly_min), abs(ry_min-ly_max));
            ll h_max = max(abs(ry_max-ly_min), abs(ry_min-ly_max));
            if(h_max < w_min){
                tmp += 2*(w_min-h_max);
            }
            if(w_max < h_min){
                tmp += 2*(h_min-w_max);
            }
            chmin(ans, tmp);
        }
        // y -> x
        // x -> y
        {
            ll tmp = abs(y[0]-y[v[0]])+abs(x[v[0]]-x[v[1]])+abs(y[v[1]]-y[v[2]])+abs(x[v[2]]-x[0]);
            ll lx_min = min(y[0], y[v[0]]);
            ll lx_max = max(y[0], y[v[0]]);
            ll rx_min = min(y[v[1]], y[v[2]]);
            ll rx_max = max(y[v[1]], y[v[2]]);
            ll ly_min = min(x[v[0]], x[v[1]]);
            ll ly_max = max(x[v[0]], x[v[1]]);
            ll ry_min = min(x[v[2]], x[0]);
            ll ry_max = max(x[v[2]], x[0]);
            ll w_min = min(abs(rx_max-lx_min), abs(rx_min-lx_max));
            ll w_max = max(abs(rx_max-lx_min), abs(rx_min-lx_max));

            ll h_min = min(abs(ry_max-ly_min), abs(ry_min-ly_max));
            ll h_max = max(abs(ry_max-ly_min), abs(ry_min-ly_max));
            if(h_max < w_min){
                tmp += 2*(w_min-h_max);
            }
            if(w_max < h_min){
                tmp += 2*(h_min-w_max);
            }
            chmin(ans, tmp);
        }
    } while (next_permutation(v.begin(), v.end()));
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    for(int i = 0; i < t; i++) solve();
}