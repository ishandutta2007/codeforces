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
using P = pair<ll, int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<ll> x(n), y(n);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    auto dist_sq = [&](int i, int j){
        ll dx = x[i]-x[j];
        ll dy = y[i]-y[j];
        return dx*dx+dy*dy;
    };
    int cur = 0;
    vector<bool> used(n);
    used[cur] = true;
    int rem = n-1;
    cout << cur+1 << ' ';
    while(rem--){
        vector<P> v;
        for(int i = 0; i < n; i++){
            if(!used[i]) v.push_back(P(dist_sq(cur, i), i));
        }
        sort(v.begin(), v.end(), greater<P>());
        cur = v[0].second;
        used[cur] = true;
        cout << cur+1 << ' ';
    }
    cout << endl;
}