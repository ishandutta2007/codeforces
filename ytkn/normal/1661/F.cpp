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

map<ll, ll> test(int n){
    map<ll, ll> ans;
    ll pre = 0;
    for(int x = 1; x <= n; x++){
        ll a = n/x; int r = n%x;
        ll sum = (a*a)*(x-r) + (a+1)*(a+1)*r;
        if(x == 1){
            pre = sum;
            continue;
        }
        ll d = pre-sum;
        pre = sum;
        if(ans.count(d)) ans[d]++;
        else ans[d] = 1;
    }
    return ans;
}

map<ll, ll> count_diff(int n){
    map<ll, ll> ans;
    if(n == 1){
        return ans;
    }
    auto calc = [&](int x){
        ll a = n/x; int r = n%x;
        return (a*a)*(x-r) + (a+1)*(a+1)*r;
    };
    auto calc_diff = [&](int x){ // x -> x+1
        assert(x < n);
        return calc(x)-calc(x+1);
    };
    int x = 1;
    while(x < n){
        int l = x, r = n-1;
        ll d = calc_diff(x);
        if(calc_diff(r) == d){
            ans[d] = r-l+1;
            break;
        }
        while(r-l > 1){
            int c = (l+r)/2;
            if(calc_diff(c) == d) l = c;
            else r = c;
        }
        ans[d] = r-x;
        x = r;
    }
    ll sum = 0;
    for(auto [x, c]: ans){
        sum += c;
    }
    assert(sum == n-1);
    return ans;
}

// (gain, n_used)
pair<ll, int> calc_gain(int n, ll th){
    if(n == 1){
        return make_pair(0, 0);
    }
    auto calc = [&](int x){
        ll a = n/x; int r = n%x;
        return (a*a)*(x-r) + (a+1)*(a+1)*r;
    };
    auto calc_diff = [&](int x){ // x -> x+1
        assert(x < n);
        return calc(x)-calc(x+1);
    };
    int l = 1, r = n-1;
    if(calc_diff(1) < th){
        return make_pair(0, 0);
    }
    if(calc_diff(r) >= th){
        return make_pair(calc(1)-calc(n), n-1);
    }
    while(r-l > 1){
        int x = (l+r)/2;
        if(calc_diff(x) >= th) l = x;
        else r = x;
    }
    return make_pair(calc(1)-calc(l+1), l);
}

template<typename T>
T ceil_div(T a, T b){
    return (a+b-1)/b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    int pre = 0;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        v.push_back(a-pre);
        pre = a;
    }
    ll m; cin >> m; 
    ll current_score = 0;
    for(ll x: v) current_score += x*x;
    auto calc_sum_gain = [&](ll x){
        ll sum = 0;
        for(int n: v) sum += calc_gain(n, x).first;
        return sum;
    };
    ll expected_gain = current_score-m;
    if(expected_gain <= 0){
        cout << 0 << endl;
        return 0;
    }
    ll l = 1, r = current_score;
    while(r-l > 1){
        ll x = (l+r)/2;
        if(calc_sum_gain(x) >= expected_gain) l = x;
        else r = x;
    }
    int n_used = 0;
    ll sum_gain = 0;
    for(int n: v){
        auto p = calc_gain(n, l+1);
        n_used += p.second;
        sum_gain += p.first;
    }
    n_used += ceil_div(expected_gain-sum_gain, l);
    cout << n_used << endl;
}