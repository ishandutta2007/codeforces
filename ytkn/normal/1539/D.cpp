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

using P = pair<ll, ll>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<P> vp(n);
    for(int i = 0; i < n; i++) {
        ll a, b; cin >> a >> b;
        vp[i] = P(b, a);
    }
    sort(vp.begin(), vp.end(), greater<P>());
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++){
        a[i] = vp[i].second;
        b[i] = vp[i].first;
    }
    ll sum = 0;
    ll ans = 0;
    int l = 0, r = n-1;
    vector<ll> rem(n);
    for(int i = 0; i < n; i++) rem[i] = a[i];
    while(l <= r){
        if(sum+rem[l] <= b[r]){
            ans += rem[l]*2;
            sum += rem[l];
            rem[l] = 0;
            l++;
        }else if(sum < b[r]){
            ans += (b[r]-sum)*2;
            rem[l] -= b[r]-sum;
            sum += (b[r]-sum);
            assert(sum == b[r]);
        }else{
            ans += rem[r];
            sum += rem[r];
            rem[r] = 0;
            r--;
        }
    }
    cout << ans << endl;
}