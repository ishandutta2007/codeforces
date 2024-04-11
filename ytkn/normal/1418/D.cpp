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

const ll inf = 1e12;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, q; cin >> n >> q;
    vector<ll> p(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    multiset<ll> diffs = {2*inf};
    set<ll> st = {-inf, inf};
    auto add = [&](int x){
        st.insert(x);
        auto p = st.find(x);
        ll l = *prev(p);
        ll r = *next(p);
        diffs.erase(diffs.find(r-l));
        diffs.insert(r-x);
        diffs.insert(x-l);
    };
    auto erase = [&](int x){
        auto p = st.find(x);
        ll l = *prev(p);
        ll r = *next(p);
        diffs.insert(r-l);
        diffs.erase(diffs.find(r-x));
        diffs.erase(diffs.find(x-l));
        st.erase(x);
    };
    for(int x: p) add(x);
    auto ans = [&](){
        if(st.size() <= 4) return 0ll;
        ll mx = *prev(prev(st.end()));
        ll mn = *next(st.begin());
        ll max_diff = *prev(prev(prev(diffs.end())));
        return mx-mn-max_diff;
    };
    cout << ans() << endl;
    while(q--){
        int t, x; cin >> t >> x;
        if(t == 0) erase(x);
        else add(x);
        cout << ans() << endl;
    }
}