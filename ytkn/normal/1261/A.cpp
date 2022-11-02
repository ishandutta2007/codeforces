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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    string t;
    int m = n/2-(k-1);
    for(int i = 0; i < k-1; i++) t += "()";
    for(int i = 0; i < m; i++) t += "(";
    for(int i = 0; i < m; i++) t += ")";
    vector<P> ans;
    auto rev = [&](int l, int r){
        ans.push_back(P(l, r));
        for(int i = l; i <= r; i++){
            int j = (l+r)-i;
            if(j < i) continue;
            swap(s[i], s[j]);
        }
    };
    for(int i = 0; i < n; i++){
        if(s[i] == t[i]) continue;
        int l = i;
        int r = -1;
        for(int j = i+1; j < n; j++){
            if(s[j] == t[i]){
                r = j;
                break;
            }
        }
        assert(r != -1);
        rev(l, r);
    }
    assert(s == t);
    cout << ans.size() << endl;
    for(auto [l, r]: ans) cout << l+1 << ' ' << r+1 << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}