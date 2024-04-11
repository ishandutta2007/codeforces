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

using P = pair<ll, int>;

vector<P> factorize(ll x){
    ll y = x;
    vector<P> ans;
    for(ll p = 2; p*p <= x; p++){
        if(y%p == 0){
            int cnt = 0;
            while(y%p == 0){
                y /= p;
                cnt++;
            }
            ans.push_back(P(p, cnt));
        }
    }
    if(y != 1) ans.push_back(P(y, 1));
    return ans;
}

const ll inf = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    ll x; cin >> x;
    auto v = factorize(x);
    int m = v.size();
    ll mn = inf;
    ll aa = -1, bb = -1;
    for(int s = 0; s < (1<<m); s++){
        ll a = 1;
        for(int i = 0; i < m; i++){
            if(s&(1<<i)){
                auto [p, cnt] = v[i];
                for(int j = 0; j < cnt; j++) a *= p;
            }
        }
        ll b = x/a;
        if(chmin(mn, max(a, b))){
            aa = a;
            bb = b;
        }
    }
    cout << aa << ' ' << bb << endl;
}