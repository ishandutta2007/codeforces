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

vector<int> simulate(vector<int> a, vector<int> p){
    int n = a.size();
    function<void(int)> f = [&](int x){
        int lhs = (x+1)*2-1;
        int rhs = (x+1)*2;
        if(lhs >= n) {
            a[x] = 0;
            return;
        }
        if(a[lhs] > a[rhs]) {
            a[x] = a[lhs];
            f(lhs);
        } else {
            a[x] = a[rhs];
            f(rhs);
        }
    };
    for(int x: p){
        f(x);
        // print_vector(a);
    }
    return a;
}

inline int lhs(int x){
    return (x+1)*2-1;
}

inline int rhs(int x){
    return (x+1)*2;
}

using Pvv = pair<vector<int>, vector<int>>;

void list_children(vector<int> &a, int x, int h, int cur_h, vector<int> &ans){
    if(h < cur_h) return;
    ans.push_back(a[x]);
    list_children(a, lhs(x), h, cur_h+1, ans);
    list_children(a, rhs(x), h, cur_h+1, ans);
}

Pvv dfs(int x, vector<int> &a, int h, int g, int cur_h){
    if(cur_h == g){
        vector<int> ch;
        list_children(a, x, h, g, ch);
        sort(ch.begin(), ch.end(), greater<int>());
        return Pvv(ch, vector<int>(ch.size()-1, x));
    }
    int l = lhs(x);
    int r = rhs(x);
    auto [lh, lans] = dfs(l, a, h, g, cur_h+1);
    auto [rh, rans] = dfs(r, a, h, g, cur_h+1);
    int il = 0, ir = 0;
    vector<int> head, ans;
    int hd = a[x];
    while(il < lans.size() || ir < rans.size()){
        head.push_back(hd);
        bool left = false;
        if(ir == rans.size() || (il != lans.size() && lh[il] > rh[ir])) left = true;
        if(left){
            if(lans[il] == l && rh[ir] < lh[il]) {
                hd = lh[il];
                ans.push_back(x);
            }else{
                ans.push_back(lans[il]);
            }
            il++;
        }else{
            if(rans[ir] == r && lh[il] < rh[ir]) {
                hd = rh[ir];
                ans.push_back(x);
            }else{
                ans.push_back(rans[ir]);
            }
            ir++;
        }
    }
    head.push_back(hd);
    return Pvv(head, ans);
}

void solve(){
    int h, g; cin >> h >> g;
    int n = (1<<h)-1;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    auto [head, ans] = dfs(0, a, h, g, 1);
    auto result = simulate(a, ans);
    cout << accumulate(result.begin(), result.end(), 0ll) << endl;
    for(int x: ans) cout << x+1 << ' ';
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}