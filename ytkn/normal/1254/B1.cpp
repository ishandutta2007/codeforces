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

bool is_prime(int n){
    for(int i = 2; i*i <= n; i++){
        if(n%i == 0) return false;
    }
    return true;
}

const ll inf = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> v;
    for(int i = 0; i < n; i++){
        if(a[i] == 1) v.push_back(i);
    }
    int asum = accumulate(a.begin(), a.end(), 0);
    if(asum == 1){
        cout << -1 << endl;
        return 0;
    }
    vector<int> facs;
    for(int x = 2; x <= asum; x++){
        if(asum%x == 0) facs.push_back(x);
    }
    auto f = [&](vector<int> &v){
        int n = v.size();
        int m = n/2;
        ll ans = 0;
        for(int i = 0; i < n; i++){
            ans += abs(v[i]-v[m]);
        }
        return ans;
    };
    auto calc = [&](int x){
        ll ans = 0;
        vector<int> u;
        for(int i: v){
            u.push_back(i);
            if(u.size() == x){
                ans += f(u);
                u.clear();
            }
        }
        return ans;
    };
    ll ans = inf;
    for(int x: facs) chmin(ans, calc(x));
    cout << ans << endl;
}