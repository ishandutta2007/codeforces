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
    int n, x, y; cin >> n >> x >> y;
    vector<int> b(n);
    vector<vector<int>> indices(n+1);
    for(int i = 0; i < n; i++){
        cin >> b[i]; b[i]--;
        indices[b[i]].push_back(i);
    }
    vector<int> ans(n, -1);
    vector<bool> is_fixed(n);
    priority_queue<P> que;
    int unused = -1;
    for(int x = 0; x <= n; x++){
        if(indices[x].empty()) unused = x;
    }
    for(int i = 0; i <= n; i++) {
        if(indices[i].empty()) continue;
        que.push(P(indices[i].size()*2, i));
    }
    for(int i = 0; i < x; i++){ // 
        auto [sz, a] = que.top(); que.pop();
        ans[indices[a].back()] = a;
        is_fixed[indices[a].back()] = true;
        indices[a].pop_back();
        if(!indices[a].empty()) que.push(P(sz-2, a));
    }
    for(int i = 0; i < n-y; i++){ // 
        auto [sz, a] = que.top(); que.pop();
        ans[indices[a].back()] = unused;
        indices[a].pop_back();
        if(!indices[a].empty()) que.push(P(sz-1, a));
    }
    for(int x = 0; x <= n; x++){
        for(int i: indices[x]) {
            ans[i] = x;
        }
    }
    int rem = n-x;
    if(!que.empty() && que.top().first > rem){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    vector<P> remaining;
    for(int i = 0; i < n; i++){
        if(is_fixed[i]) continue;
        remaining.push_back(P(b[i], i));
    }
    sort(remaining.begin(), remaining.end());
    vector<int> ans_idx;
    vector<int> buf;
    vector<int> cnt(n+1);
    for(auto [x, idx]: remaining){
        ans_idx.push_back(idx);
        buf.push_back(ans[idx]);
        cnt[x]++;
    }
    int max_cnt = *max_element(cnt.begin(), cnt.end());
    vector<int> shifted;
    for(int i = 0; i < buf.size(); i++){
        shifted.push_back(buf[(i+buf.size()-max_cnt)%buf.size()]);
    }
    for(int i = 0; i < shifted.size(); i++){
        ans[ans_idx[i]] = shifted[i];
    }
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