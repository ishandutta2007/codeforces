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

using P = pair<int, int>;

void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> segments(n, -1);
    for(int i = 0; i < m; i++){
        int l, r; cin >> l >> r; l--;
        chmax(segments[l], r);
    }
    auto max_right = segments;
    for(int i = 1; i < n; i++){
        if(max_right[i-1] > i) chmax(max_right[i], max_right[i-1]);
    }
    map<int, vector<int>> indices;
    for(int i = 0; i < n; i++){
        indices[a[i]].push_back(i);
    }
    vector<vector<P>> ps;
    for(auto [x, v]: indices) {
        int l = -1;
        for(int i = 0; i+1 < (int)v.size(); i++){
            if(max_right[v[i]] > v[i+1]){
                l = i;
                break;
            }
        }
        if(l == -1) continue;
        int r = -1;
        for(int i = (int)v.size()-1; i >= 1; i--){
            if(max_right[v[i-1]] > v[i]){
                r = i;
                break;
            }
        }
        // cout << x << ' ' << l << ' ' << r << endl;
        assert(r != -1);
        if(max_right[v[l]] > v[r]){
            ps.push_back({P(v[l], v[r-1]+1), P(v[l+1], v[r]+1)});
        }else{
            ps.push_back({P(v[l+1], v[r-1]+1), P(v[l+1], v[r-1]+1)});
        }
    }
    if(ps.empty()){
        cout << 0 << endl;
        return;
    }
    sort(ps.begin(), ps.end());
    set<int> rights;
    set<int> lefts;
    for(auto p: ps){
        auto [l0, r0] = p[0];
        auto [l1, r1] = p[1];
        lefts.insert(l0);
        rights.insert(r0);
    }
    auto get_current_ans = [&](){
        return (*prev(rights.end())) - (*lefts.begin());
    };
    int ans = get_current_ans();
    for(auto p: ps){
        auto [l0, r0] = p[0];
        auto [l1, r1] = p[1];
        lefts.erase(l0);
        rights.erase(r0);
        lefts.insert(l1);
        rights.insert(r1);
        chmin(ans, get_current_ans());
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