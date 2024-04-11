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
    int n; cin >> n;
    vector<int> l(n), r(n);
    for(int i = 0; i < n; i++) cin >> l[i] >> r[i];
    vector<int> ans(n);
    vector<bool> used(n);
    auto ok = [&](){
        for(int i = 0; i < n; i++){
            if(!used[i]) return false;
        }
        return true;
    };
    while(!ok()){
        priority_queue<P> que;
        for(int i = 0; i < n; i++){
            if(used[i]) continue;
            int len = r[i]-l[i]+1;
            que.push(P(len, i));
        }
        auto [top_len, top_idx] = que.top(); que.pop();
        used[top_idx] = true;
        if(top_len == 1){
            ans[top_idx] = l[top_idx];
            continue;
        }
        int l_idx= -1, r_idx = -1;
        int l_len = 0, r_len = 0;
        while(l_len + r_len != top_len-1){
            auto [len, idx] = que.top(); que.pop();
            if(l_idx == -1 && l[idx] == l[top_idx]){
                l_idx = idx;
                l_len = r[idx]-l[idx]+1;
            }
            if(r_idx == -1 && r[idx] == r[top_idx]){
                r_idx = idx;
                r_len = r[idx]-l[idx]+1;
            }
        }
        if(l_idx == -1) {
            ans[top_idx] = l[top_idx];
        }else if(r_idx == -1){
            ans[top_idx] = r[top_idx];
        }else{
            ans[top_idx] = r[l_idx]+1;
        }
    }
    for(int i = 0; i < n; i++) cout << l[i] << ' ' << r[i] << ' ' << ans[i] << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}