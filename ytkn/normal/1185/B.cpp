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

using P = pair<char, int>;

void solve(){
    string s, t; cin >> s >> t;
    auto make_p = [](string s){
        char pre = s[0];
        int cnt = 1;
        vector<P> ans;
        for(int i = 1; i < s.size(); i++){
            if(pre == s[i]){
                cnt++;
            }else{
                ans.push_back(P(pre, cnt));
                pre = s[i];
                cnt=1;
            }
        }
        ans.push_back(P(pre, cnt));
        return ans;
    };
    auto ps = make_p(s);
    auto pt = make_p(t);
    if(ps.size() != pt.size()){
        cout << "NO" << endl;
        return;
    }
    int m = ps.size();
    for(int i = 0; i < m; i++){
        auto [c0, x0] = ps[i];
        auto [c1, x1] = pt[i];
        if(c0 != c1){
            cout << "NO" << endl;
            return;
        }
        if(x0 > x1){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}