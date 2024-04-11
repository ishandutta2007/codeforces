#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <deque>
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

template<typename T>
vector<vector<T>> vec2d(int n, int m, T v){
    return vector<vector<T>>(n, vector<T>(m, v));
}

template<typename T>
vector<vector<vector<T>>> vec3d(int n, int m, int k, T v){
    return vector<vector<vector<T>>>(n, vector<vector<T>>(m, vector<T>(k, v)));
}

template<typename T>
void print_vector(vector<T> v, char delimiter=' '){
    if(v.empty()) {
        cout << endl;
        return;
    }
    for(int i = 0; i+1 < v.size(); i++) cout << v[i] << delimiter;
    cout << v.back() << endl;
}

ll tri(ll x){
    return (x*(x-1))/2;
}

using P = pair<int, int>;

void solve(){
    int n, m, k; cin >> n >> m >> k;
    map<int, int> xidx, yidx;
    vector<int> x(n), y(m);
    for(int i = 0; i < n; i++) {
        cin >> x[i];
        xidx[x[i]] = i;
    }
    for(int i = 0; i < m; i++) {
        cin >> y[i];
        yidx[y[i]] = i;
    }
    vector<vector<ll>> xcnt(n), ycnt(m);
    for(int i = 0; i < k; i++) {
        int px, py; cin >> px >> py;
        if(xidx.count(px) > 0 && yidx.count(py) > 0){
            continue;
        }
        if(xidx.count(px)){
            int s = xidx[px];
            int t = lower_bound(y.begin(), y.end(), py) - y.begin();
            ycnt[t].push_back(s);
        }else{
            int s = yidx[py];
            int t = lower_bound(x.begin(), x.end(), px) - x.begin();
            xcnt[t].push_back(s);
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        sort(xcnt[i].begin(), xcnt[i].end());
        ans += tri(xcnt[i].size());
        int pre = -1;
        int sum = 0;
        for(int x: xcnt[i]){
            if(x == pre){
                ans -= sum;
                sum++;
            }else{
                pre = x;
                sum = 1;
            }
        }
    }

    for(int i = 0; i < m; i++){
        sort(ycnt[i].begin(), ycnt[i].end());
        ans += tri(ycnt[i].size());
        int pre = -1;
        int sum = 0;
        for(int x: ycnt[i]){
            if(x == pre){
                ans -= sum;
                sum++;
            }else{
                pre = x;
                sum = 1;
            }
        }
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}