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
    vector<int> b(n+1);
    int k = 0;
    vector<vector<int>> indices(n+2);
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        indices[b[i]].push_back(i);
        if(b[i] > i) k++;
    }
    int mx = *max_element(b.begin()+1, b.end());
    int mn = *min_element(b.begin()+1, b.end());
    vector<int> pre(n+2);
    vector<int> nx(n+2);
    for(int i = 1; i <= n; i++){
        if(b[i] == 0 || b[i] == n+1) continue;
        pre[b[i]] = b[b[i]];
        nx[pre[b[i]]] = b[i];
    }
    vector<int> ans;
    int cur = mn == 0 ? 0 : n+1;
    while(true){
        if(nx[cur] != 0) {
            int nxt = nx[cur];
            for(int i = 0; i < indices[cur].size(); i++){
                if(indices[cur][i] == nxt){
                    swap(indices[cur][i], indices[cur].back());
                }
            }
        }
        for(int i: indices[cur]){
            ans.push_back(i);
        }
        if(nx[cur] == 0) break;
        cur = nx[cur];
    }
    cout << k << endl;
    print_vector(ans);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}