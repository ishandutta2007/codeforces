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
    vector<int> p(n), a(n);
    vector<vector<int>> g(n), g_inv(n);
    auto nx = vec2d(n, 30, 0);
    for(int i = 0; i < n; i++){
        cin >> p[i]; p[i]--;
        g[i].push_back(p[i]);
        g_inv[p[i]].push_back(i);
        nx[i][0] = p[i];
    }
    for(int j = 1; j < 30; j++){
        for(int i = 0; i < n; i++){
            nx[i][j] = nx[nx[i][j-1]][j-1];
        }
    }
    vector<int> outers;
    vector<int> goals(n, -1);
    for(int i = 0; i < n; i++){
        cin >> a[i]; a[i]--;
        if(a[i] >= n) outers.push_back(a[i]);
        else goals[a[i]] = i;
    }
    vector<int> enters;
    for(int i = 0; i < n; i++){
        if(g_inv[i].empty()) enters.push_back(i);
    }
    auto go = [&](int i, int steps){
        for(int j = 0; j < 30; j++){
            if(steps&(1<<j)){
                i = nx[i][j];
            }
        }
        return i;
    };
    int cnt_in = 0;
    if(!outers.empty()) cnt_in = (*max_element(outers.begin(), outers.end())) - (n-1);
    // debug_value(cnt_in);
    int steps = cnt_in/enters.size();
    vector<vector<int>> starts(n);
    for(int i = 0; i < n; i++){
        int t = go(i, steps);
        starts[t].push_back(i);
    }
    priority_queue<int, vector<int>, greater<int>> que;
    vector<int> ans(n);
    for(int i = 0; i < n; i++){
        if(goals[i] == -1){
            ans[i] = que.top(); que.pop();
        }else{
            ans[i] = starts[goals[i]][0];
            for(int j = 1; j < starts[goals[i]].size(); j++){
                que.push(starts[goals[i]][j]);
            }
        }
    }
    // debug_value(steps);
    vector<int> out(n);
    for(int i = 0; i < n; i++){
        out[ans[i]] = i+1;
    }
    print_vector(out);
}