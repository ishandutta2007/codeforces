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

//1-indexed
template <typename T>
struct bit{
    int n;
    vector<T> data;

    bit(int n_){
        n = 1;
        while(n < n_) n *= 2;
        data = vector<T>(n+1);
        for(int i = 0; i <= n; i++) data[i] = 0;
    }
    
    T sum(int i){
        T ret = 0;
        while(i > 0){
            ret += data[i];
            i -= i&-i;
        }
        return ret;
    }

    void add(int i, T x){
        while(i <= n){
            data[i] += x;
            i += i&-i;
        }
    }
};

const int N = 300000;

vector<ll> sum_denominator(vector<ll> a){
    int n = a.size();
    vector<ll> ans(n);
    bit<ll> bt_sum(N);
    bit<ll> bt_cnt(N);
    for(int i = 0; i < n; i++){
        if(i > 0) ans[i] = ans[i-1];
        ans[i] += bt_sum.sum(N);
        for(int x = 0; x*a[i] <= N; x++){
            int l = x*a[i], r = (x+1)*a[i];
            ll cnt = bt_cnt.sum(min(r-1, N))-bt_cnt.sum(l-1);
            ans[i] -= cnt*a[i]*x;
        }
        bt_cnt.add(a[i], 1);
        bt_sum.add(a[i], a[i]);
    }
    return ans;
}

vector<ll> sum_numerator(vector<ll> a){
    int n = a.size();
    vector<ll> ans(n);
    bit<ll> bt_sum(N);
    for(int i = 0; i < n; i++){
        if(i > 0) ans[i] = ans[i-1];
        ans[i] += a[i]*i - bt_sum.sum(a[i]);
        for(int x = 0; x*a[i] <= N; x++){
            int l = x*a[i], r = (x+1)*a[i];
            if(l == 0) l++;
            bt_sum.add(l, a[i]*x);
            if(r <= N) bt_sum.add(r, -a[i]*x);
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    auto u = sum_denominator(a);
    auto v = sum_numerator(a);
    for(int i = 0; i < n; i++) cout << u[i]+v[i] << ' ';
    cout << endl;
}