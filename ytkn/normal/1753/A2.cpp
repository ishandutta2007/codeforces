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
    vector<int> a(n);
    vector<int> indices;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] != 0) indices.push_back(i);
    }
    if(indices.size()%2 == 1){
        cout << -1 << endl;
        return;
    }
    vector<P> ans;
    int m = indices.size();
    vector<bool> used(n);
    for(int i = 0; i < m; i+=2){
        int l = indices[i], r = indices[i+1];
        if(a[l] == a[r]){
            if((r-l+1)%2 == 0){
                ans.push_back(P(l, r));
            }else{
                ans.push_back(P(l, l));
                ans.push_back(P(l+1, r));
            }
        }else{
            if((r-l+1)%2 == 0){
                ans.push_back(P(l, l));
                ans.push_back(P(l+1, r));
            }else{
                ans.push_back(P(l, r));
            }
        }
        for(int j = l; j <= r; j++) used[j] = true;
    }
    int l = -1;
    for(int i = 0; i < n; i++){
        if(used[i]) {
            if(l != -1){
                ans.push_back(P(l, i-1));
            }
            l = -1;
            continue;
        }
        if(!used[i]){
            if(l == -1) l = i;
        }
    }
    if(l != -1){
        ans.push_back(P(l, n-1));
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(auto [l, r]: ans) cout << l+1 << ' ' << r+1 << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}