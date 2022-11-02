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

void solve(){
    int n; ll m; cin >> n >> m;
    vector<ll> a(m);
    for(int i = 0; i < m; i++){
        cin >> a[i]; a[i]--;
    }
    sort(a.begin(), a.end());
    vector<ll> b;
    for(int i = 0; i < m; i++){
        int j = (i+1)%m;
        int d = (a[j]-a[i]-1+n)%n;
        b.push_back(d);
    }
    sort(b.begin(), b.end(), greater<ll>());
    int ans = m;
    ll d = 0;
    for(int i = 0; i < m; i++){
        if(d*2 >= b[i]){
            ans += b[i];
        }else if(b[i]-d*2 >= 3){
            ans += d*2+1;
            d += 2;
        }else if(b[i]-d*2 == 1){
            ans += d*2;
            d++;
        }else{
            ans += d*2+1;
            d++;
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