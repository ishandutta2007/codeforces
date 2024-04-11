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

ll dist(ll x0, ll x1, ll y0, ll y1){
    // debug_value(abs(x0-x1)+abs(y0-y1));
    return abs(x0-x1)+abs(y0-y1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    ll x0, y0, ax, ay, bx, by;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by;
    ll xs, ys, t; cin >> xs >> ys >> t;
    vector<ll> x, y;
    x.push_back(x0);
    y.push_back(y0);
    ll cur_x = x0, cur_y = y0;
    while(true){
        if(cur_x > INF/ax) break;
        if(cur_y > INF/ay) break;
        cur_x = cur_x*ax+bx;
        cur_y = cur_y*ay+by;
        x.push_back(cur_x);
        y.push_back(cur_y);
    }
    int ans = 0;
    int n = x.size();

    for(int i = 0; i < n; i++){
        // -
        ll cost = 0;
        ll cur_x = xs, cur_y = ys;
        for(int j = i; j >= 0; j--){
            if(cost+dist(cur_x, x[j], cur_y, y[j]) > t){
                chmax(ans, i-j);
                break;
            }
            cost+=dist(cur_x, x[j], cur_y, y[j]);
            cur_x = x[j];
            cur_y = y[j];
            if(j == 0){
                chmax(ans, i+1);
            }
        }
        // +
        cost = 0;
        cur_x = xs; cur_y = ys;
        for(int j = i; j < n; j++){
            if(cost+dist(cur_x, x[j], cur_y, y[j]) > t){
                chmax(ans, j-i);
                break;
            }
            cost+=dist(cur_x, x[j], cur_y, y[j]);
            cur_x = x[j];
            cur_y = y[j];
            if(j == n-1){
                chmax(ans, n-i);
            }
        }
    }
    cout << ans << endl;
}