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

using T = tuple<int, int, int, int>;
using P = pair<ll, int>;
map<T, ll> memo;

// vector<int> x = {-5935, 11955, -4582, -12734, 11531, -9423, 12997, 7469, 9239, 275};
// vector<int> y = {36258, 21535, 36499, 23353, 22804, 33388, 18102, 3388, 4773, 35134};

vector<int> x = {-2, 3, -2, 1, 0, 2};
vector<int> y = {1, -1, -1, -2, 3, 2};

// #define DEBUG

ll ask(int t, int i, int j, int k){
#ifdef DEBUG
    ll x1 = x[j]-x[i];
    ll x2 = x[k]-x[i];
    ll y1 = y[j]-y[i];
    ll y2 = y[k]-y[i];
    ll s = x1*y2-x2*y1;
    if(t == 1) return abs(s);
    if(s > 0) return 1;
    else return -1;
#endif
    cout << t << ' ' << i+1 << ' ' << j+1 << ' ' << k+1 << endl;
    T query(t, i, j, k);
    if(memo.count(query)) return memo[query];
    ll ans; cin >> ans;
    memo[query] = ans;
    return ans;
}

void verify(vector<int> p){
    cout << 0 << ' ';
    for(int i: p) cout << i+1 << ' ';
    cout << endl;
}

ll inf = 4e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<ll> v(n);
    vector<int> bottom, top;
    for(int i = 2; i < n; i++){
        int sgn = ask(2, 0, 1, i);
        ll s = ask(1, 0, 1, i);
        v[i] = s;
        if(sgn == -1){
            bottom.push_back(i);
        }else{
            top.push_back(i);
        }
    }
    ll bottom_max = 0, top_max = 0;
    int bi = -1, ti = -1;
    for(int i: bottom){
        if(chmax(bottom_max, v[i])) bi = i;
    }
    for(int i: top){
        if(chmax(top_max, v[i])) ti = i;
    }
    vector<int> bottom_right, bottom_left;
    for(int i: bottom){
        if(i == bi) continue;
        if(ask(2, 0, i, bi) == 1) bottom_left.push_back(i);
        else bottom_right.push_back(i);
    }
    vector<int> top_right, top_left;
    for(int i: top){
        if(i == ti) continue;
        if(ask(2, 0, ti, i) == 1) top_left.push_back(i);
        else top_right.push_back(i);
    }
    auto sort_by = [&](vector<int> u, bool rev){ // 
        vector<P> vp;
        for(int i: u){
            vp.push_back(P(v[i], i));
        }
        if(!rev) sort(vp.begin(), vp.end());
        else sort(vp.begin(), vp.end(), greater<P>());
        vector<int> ans;
        for(auto [_, i]: vp) ans.push_back(i);
        return ans;
    };
    vector<int> ans; ans.push_back(0);
    for(int i: sort_by(bottom_left, false)) {
        ans.push_back(i);
    }
    if(bi != -1) ans.push_back(bi);
    for(int i: sort_by(bottom_right, true)) ans.push_back(i);
    ans.push_back(1);
    for(int i: sort_by(top_right, false)) ans.push_back(i);
    if(ti != -1) ans.push_back(ti);
    for(int i: sort_by(top_left, true)) ans.push_back(i);
    verify(ans);
}