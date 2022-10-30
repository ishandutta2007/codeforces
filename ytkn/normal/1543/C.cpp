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
const double eps = 1e-7;

const int SUM = 100000;
int ceil_div(int n, int m){
    return (n+m-1)/m;
}

using P = pair<int, int>;
using T = tuple<int, int, int>;

void solve(){
    double c1, m1, p1, v1; cin >> c1 >> m1 >> p1 >> v1;
    int c = (int)((c1+eps)*SUM);
    int m = (int)((m1+eps)*SUM);
    int p = (int)((p1+eps)*SUM);
    int v = (int)((v1+eps)*SUM);
    // cout << c << ' ' << m << ' ' << p << ' ' << v << endl;
    map<T, double> memo;
    function<double(int, int, int)> sub_solve = [&](int c1, int m1, int cnt){
        auto t = T(c1, m1, cnt);
        if(memo.count(t)) return memo[t];
        double ans = 0.0;
        if(c1 > 0){
            double prob = (double)c1/(double)SUM;
            if(m1 == 0){
                if(c1 > v) ans += sub_solve(c1-v, 0, cnt+1)*prob;
                else ans += sub_solve(0, 0, cnt+1)*prob;
            }else{
                if(c1 > v) ans += sub_solve(c1-v, m1+v/2, cnt+1)*prob;
                else ans += sub_solve(0, m1+c1/2, cnt+1)*prob;
            }
        }
        if(m1 > 0){
            double prob = (double)m1/(double)SUM;
            if(c1 == 0){
                if(m1 > v) ans += sub_solve(0, m1-v, cnt+1)*prob;
                else ans += sub_solve(0, 0, cnt+1)*prob;
            }else{
                if(m1 > v) ans += sub_solve(c1+v/2, m1-v, cnt+1)*prob;
                else ans += sub_solve(c1+m1/2, 0, cnt+1)*prob;
            }
        }
        int p1 = SUM-c1-m1;
        if(p1 > 0){
            double prob = (double)p1/(double)SUM;
            ans += prob*(cnt+1);
        }
        // cout << m1 << ' ' << c1 << ' ' << p1 << ' ' << cnt << ' ' << ans << endl;
        memo[t] = ans;
        return ans;
    };
    double ans = sub_solve(c, m, 0);
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}