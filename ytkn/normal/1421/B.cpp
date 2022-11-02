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
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];
    auto count = [&](int i, int j){
        vector<P> ans;
        if(s[0][1]-'0' != i) ans.push_back(P(0, 1));
        if(s[1][0]-'0' != i) ans.push_back(P(1, 0));
        if(s[n-2][n-1]-'0' != j) ans.push_back(P(n-2, n-1));
        if(s[n-1][n-2]-'0' != j) ans.push_back(P(n-1, n-2));
        return ans;
    };
    if(count(0, 1).size() <= 2){
        auto ans = count(0, 1);
        cout << ans.size() << endl;
        for(auto [x, y]: ans) cout << x+1 << ' ' << y+1 << endl;
    }else{
        auto ans = count(1, 0);
        cout << ans.size() << endl;
        for(auto [x, y]: ans) cout << x+1 << ' ' << y+1 << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}