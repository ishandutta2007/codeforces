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
    int n; cin >> n;
    vector<int> a(n);
    vector<ll> t(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> t[i];
    map<int, vector<ll>> mp;
    for(int i = 0; i < n; i++){
        mp[a[i]].push_back(t[i]);
    }
    int cur = 0;
    priority_queue<ll> que;
    ll sum = 0;
    auto push = [&](ll x){
        sum += x;
        que.push(x);
    };
    auto pop = [&](){
        sum -= que.top();
        que.pop();
    };
    auto is_finished = [&](){
        return mp.upper_bound(cur) == mp.end() && que.empty();
    };
    auto next_category = [&](){
        if(que.empty()){
            auto p = mp.upper_bound(cur);
            return p->first;
        }else{
            return cur + 1;
        }
    };
    ll ans = 0;
    while(!is_finished()){
        auto cat = next_category();
        for(ll x: mp[cat]) push(x);
        pop();
        ans += sum;
        cur = cat;
    }
    cout << ans << endl;
}