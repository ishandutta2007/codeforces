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

const ll inf = 1e18;
using P = pair<ll, ll>;

ll solve(vector<ll> a, vector<ll> b, vector<ll> c, vector<ll> d){
    int n = a.size(), m = c.size();
    vector<P> points(m);
    for(int i = 0; i < m; i++){
        points[i].first = c[i];
        points[i].second = d[i];
    }
    sort(points.begin(), points.end());
    vector<ll> y_max(m+1);
    for(int i = m-1; i >= 0; i--){
        y_max[i] = max(y_max[i+1], points[i].second);
    }
    vector<vector<int>> check(1000001);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(b[i] > d[j]) continue;
            if(c[j]+1-a[i] > 0) check[c[j]-a[i]].push_back(i);
        }
    }
    ll y = 0;
    vector<int> indices(n, m);
    auto proceed = [&](int i, ll x){
        while(indices[i] > 0 && a[i]+x <= points[indices[i]-1].first) {
            indices[i]--;
            chmax(y, y_max[indices[i]]-b[i]+1);
        }
    };
    ll ans = inf;
    for(int x = 1000000; x >= 0; x--){
        for(int i: check[x]) proceed(i, x);
        chmin(ans, x+y);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    vector<ll> a(n), b(n);
    vector<ll> c(m), d(m);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    for(int i = 0; i < m; i++){
        cin >> c[i] >> d[i];
    }
    ll ans = solve(a, b, c, d);
    swap(a, b);
    swap(c, d);
    chmin(ans, solve(a, b, c, d));
    cout << ans << endl;
}