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
using Pli = pair<ll, int>;
P none(-1, -1);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int k; cin >> k;
    vector<vector<ll>> a(k);
    vector<ll> a_sum(k);
    vector<int> n(k);
    map<ll, P> pos;
    for(int i = 0; i < k; i++){
        cin >> n[i];
        a[i].resize(n[i]);
        for(int j = 0; j < n[i]; j++) {
            cin >> a[i][j];
            a_sum[i] += a[i][j];
            pos[a[i][j]] = P(i, j);
        }
    }
    ll sum_all = accumulate(a_sum.begin(), a_sum.end(), 0ll);
    if(sum_all%k != 0){
        cout << "No" << endl;
        return 0;
    }
    ll target = sum_all/k;
    vector<vector<P>> g(k);
    for(int i = 0; i < k; i++) g[i].assign(n[i], none);
    for(int i = 0; i < k; i++){
        for(int j = 0; j < n[i]; j++){
            ll nx = target-(a_sum[i]-a[i][j]);
            if(pos.count(nx) == 0) continue;
            g[i][j] = pos[nx];
        }
    }
    vector<vector<int>> loops(1<<k);
    auto add_loop = [&](int i, int j){
        int cur_i = i, cur_j = j;
        vector<int> v;
        int s = 0;
        while(true){
            v.push_back(a[cur_i][cur_j]);
            if(s&(1<<cur_i)) return;
            s += 1<<cur_i;
            auto [nx_i, nx_j] = g[cur_i][cur_j];
            if(nx_i == i && nx_j == j){
                loops[s] = v;
                return;
            }
            cur_i = nx_i;
            cur_j = nx_j;
        }
    };
    vector<vector<bool>> seen(k);
    for(int i = 0; i < k; i++) seen[i].resize(n[i]);
    for(int i = 0; i < k; i++){
        for(int j = 0; j < n[i]; j++){
            if(seen[i][j]) continue;
            P cur(i, j);
            set<P> st;
            while(true){
                auto [ii, jj] = cur;
                seen[ii][jj] = true;
                st.insert(P(ii, jj));
                if(g[ii][jj] == none) break;
                auto [inx, jnx] = g[ii][jj];
                if(seen[inx][jnx] && st.count(P(inx, jnx))){
                    add_loop(inx, jnx);
                    break;
                }
                cur = g[ii][jj];
            }
        }
    }
    int all_bit = (1<<k)-1;
    vector<int> pre(1<<k, -1);
    for(int s = 1; s < (1<<k); s++){
        if(!loops[s].empty()){
            pre[s] = 0;
            continue;
        }
        for(int t = s; t > 0; t = (t-1)&s){
            if(t == s) continue;
            int u = s^t;
            if(pre[t] != -1 && !loops[u].empty()){
                pre[s] = t;
                break;
            }
        }
    }
    if(pre[all_bit] == -1){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    int cur = all_bit;
    vector<P> ans(k);
    while(cur != 0){
        int s = cur-pre[cur];
        int m = loops[s].size();
        for(int i = 0; i < m; i++){
            int j = (i-1+m)%m;
            int idx = pos[loops[s][i]].first;
            ans[idx] = P(loops[s][i], pos[loops[s][j]].first);
        }
        cur = pre[cur];
    }
    for(int i = 0; i < k; i++){
        auto [c, p] = ans[i];
        cout << c << ' ' << p+1 << endl;
    }
}