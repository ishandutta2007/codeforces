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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, a, b; cin >> n >> a >> b;
    chmin(b, n);
    vector<ll> h(n), d(n);
    for(int i = 0; i < n; i++) cin >> h[i] >> d[i];
    multiset<ll> small, large;
    for(int i = 0; i < n; i++){
        large.insert(h[i]-d[i]);
    }
    while(large.size() > b){
        small.insert(*large.begin());
        large.erase(large.begin());
    }
    ll pos_sum = 0, neg_sum = 0;
    for(ll x: large){
        if(x < 0) neg_sum += x;
        else pos_sum += x;
    }
    auto del = [&](ll diff){
        if(!large.empty() && diff >= *large.begin()){
            if(diff >= 0) pos_sum -= diff;
            else neg_sum -= diff;
            large.erase(large.find(diff));
        }else{
            small.erase(small.find(diff));
        }
    };
    auto add = [&](ll diff){
        if(!large.empty() && diff >= *large.begin()){
            if(diff >= 0) pos_sum += diff;
            else neg_sum += diff;
            large.insert(diff);
        }else{
            small.insert(diff);
        }
    };
    ll sum = accumulate(d.begin(), d.end(), 0ll);
    ll ans = pos_sum+sum;
    for(int i = 0; i < n; i++){
        del(h[i]-d[i]);
        add(h[i]*(1<<a)-d[i]);
        while(large.size() > b){
            ll x = *large.begin();
            if(x >= 0) pos_sum -= x;
            else neg_sum -= x;
            large.erase(large.begin());
            small.insert(x);
        }
        while(large.size() < b){
            auto p = prev(small.end());
            ll x = *p;
            small.erase(p);
            if(x >= 0) pos_sum += x;
            else neg_sum += x;
            large.insert(x);
        }
        chmax(ans, pos_sum+sum);
        del(h[i]*(1<<a)-d[i]);
        add(h[i]-d[i]);
    }
    cout << ans << endl;
}